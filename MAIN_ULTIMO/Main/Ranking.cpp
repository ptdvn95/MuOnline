#include "stdafx.h"
#include "Ranking.h"
#include "Import.h"
#include "Defines.h"
#include "Interface.h"
#include "Util.h"
#include "RankingEx.h"
#include "CustomMap.h"
#include "Controller.h"
#include "PartySearch.h"
#include "Central.h"
#include "User.h"

cRanking gRanking;

cRanking::cRanking()
{
	this->Active = true;
	this->Show = false;
	this->StartX = 0;
	this->StartY = 0;
	this->Page = 1;
}

cRanking::~cRanking()
{
}


void cRanking::RecvInfo(DGCharTop * lpMsg)
{
	for(int i=0;i<MAXTOP;i++)
		{
			strncpy(this->RankingChar[i].Name,lpMsg->tp[i].Name,11);
			this->RankingChar[i].Class = lpMsg->tp[i].Class;
			this->RankingChar[i].level = lpMsg->tp[i].level;
			this->RankingChar[i].levelplus = lpMsg->tp[i].levelplus;
			this->RankingChar[i].Reset = lpMsg->tp[i].Reset;
			this->RankingChar[i].Map = lpMsg->tp[i].Map;
			strncpy(this->RankingChar[i].Guild,lpMsg->tp[i].Guild,9);
		}
}


void cRanking::Draw()
{
	if( !this->Active ) return;

	if(!this->Show) return;


	float MainWidth = 445.0;
	float MainHeight = 364.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--
	gInterface.Data[eMAIN_RANKING].MaxX = StartX + MainWidth;
	gInterface.Data[eMAIN_RANKING].MaxY = StartY + MainHeight;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gInterface.DrawFormat(eGold, (int)StartX + 130, (int)StartY + 10, 210, 3, "Ranking User");

//	pDrawGUI(100037, StartX + 100, StartY + 10, 445, 364);
	//0x7EC5, 36, 29, 415, 30);
	pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);
	int TitleX = StartX + 20;
	int TitleY = StartY + 40;

	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "(N)");

	TitleX += 20;
	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Name");

	TitleX += 80;
	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Class");

	TitleX += 70;
	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Level");

	TitleX += 40;
	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Reset");

	TitleX += 50;
	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Map");

	TitleX += 55;
	gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Guild");
	
	int InfoY = StartY + 55;

	int c = 0;

	for(int i = 0; i < 15; i++)
	{
		int InfoX = StartX + 20;
		int up = i + ( ( this->Page - 1 ) * 15 );

		if(this->RankingChar[up].Name[0] == NULL) continue;

		DWORD Color;

		if(c == 0 )
		{
			Color = eWhite;
		}
		else
		{
			Color = eShinyGreen;
		}

		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up+1);

		InfoX += 20;
		char NameID[11];
		memcpy(NameID, this->RankingChar[up].Name, sizeof(this->RankingChar[up].Name));
		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1,NameID);

		InfoX += 80;
		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingChar[up].Class));

		InfoX += 70;
		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingChar[up].level + this->RankingChar[up].levelplus);

		InfoX += 40;
		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d",this->RankingChar[up].Reset);

		InfoX += 50;
		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, gCustomMap.LoadMapName(RankingChar[up].Map));

		InfoX += 55;
		char GuildID[9];
		memcpy(GuildID, this->RankingChar[up].Guild, sizeof(this->RankingChar[up].Guild));
		gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

		InfoY+=12;
		c++;
		if(c==2)c=0;
	}

	DWORD Delay = (GetTickCount() - this->ClickTime);

	int ButX = 110;
	int ButY = 70;

	pDrawGUI(0x7BAA, StartX+60+ButX, StartY+275+ButY , 17, 17);
	
	if(gInterface.IsWorkZone2(StartX+60+ButX, StartY+275+ButY, StartX+60+17+ButX, StartY+275+17+ButY))
	{
		if (gController.wMouse == WM_LBUTTONDOWN && Delay > 300)
		{
			this->ClickTime = GetTickCount();
			if(this->Page != 1) this->Page--;
		}
		pDrawColorButton(0x7BAA, StartX+60+ButX, StartY+275+ButY, 17, 17, 0, 0, pMakeColor(255, 204, 20, 130));
	}

	gInterface.DrawFormat(eRed, StartX+96+ButX, StartY+277+ButY, 100, 1, "Page: %d/%d", this->Page,10);


	pDrawGUI(0x7BAB, StartX+150+ButX, StartY+275+ButY , 17, 17);

	if(gInterface.IsWorkZone2(StartX+150+ButX, StartY+275+ButY, StartX+150+17+ButX, StartY+275+17+ButY))
	{
		if (gController.wMouse == WM_LBUTTONDOWN && Delay > 300)
		{
			this->ClickTime = GetTickCount();
			if(this->Page != 10) this->Page++;
		}
		pDrawColorButton(0x7BAB, StartX+150+ButX, StartY+275+ButY, 17, 17, 0, 0, pMakeColor(255, 204, 20, 130));
	}

	if(gInterface.IsWorkZone2(StartX+410, StartY + 5, StartX + 446, StartY + 41))
	{
		if (gController.wMouse == WM_LBUTTONDOWN && Delay > 300)
		{
			this->ClickTime = GetTickCount();
			gRanking.Show = false;
			pSetCursorFocus = false;
		}
		pDrawColorButton(0x7EC5, StartX + 410, StartY + 5, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
	}
}

