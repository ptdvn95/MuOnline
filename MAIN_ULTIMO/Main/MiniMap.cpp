#include "stdafx.h"
#include "MiniMap.h"
#include "Import.h"
#include "Util.h"
#include "Offset.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "Common.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "InfoLog.h"
#include "PrintPlayer.h"
#include "CMacroUIEx.h"
#include "Camera.h"

int MinimizarMiniMapa = 0;

CMinimap gRenderMap;

CMinimap::CMinimap()
{
	this->DataMap.ModelID = -1;
	this->DataMap.XSW_Minimap_Frame = 0;  //-- Minimap_FrameX
	this->DataMap.YSW_Minimap_Frame = 0;  //-- Minimap_FrameY
	this->DataMap.XSW_Minimap = 545.0; //-- MiniMapX (Mover Minimapa Izquierda o Derecha)
	this->DataMap.YSW_Minimap = 10.0; //-- MiniMapY (Minimapa Arriba) (Mover Minimapa Arriba o Abajo)
	this->DataMap.XSW_Time_Frame = 0.0; //-- Time_FrameX
	this->DataMap.YSW_Time_Frame = 0.0; //-- Time_FrameY
	this->DataMap.This_92 = 0.0;
	this->DataMap.This_96 = 0.0;
	this->DataMap.DropMoveUserX = 0.0; //-- DropMoveUserX
	this->DataMap.DropMoveUserY = 0.0; //-- DropMoveUserY
	this->DataMap.This_108;
	this->DataMap.This_112;
	this->DataMap.CurrentMoveX = 0.0; //-- CurrentMoveX
	this->DataMap.CurrentMoveY = 0.0; //-- CurrentMoveY
	this->DataMap.Scale = 1; //-- Scale
	this->DataMap.TimerEventVK = 0; //-- Scale
	this->DataMap.Alpha = 1.0f; //-- Alpha
    this->Moving = false;
    this->ultimoX = 545.0;//Example of initial coordinate {X}. Coordinate that will be constantly modified.
    this->ultimoY = 10.0;//Example of initial coordinate {Y}. Coordinate that will be constantly modified.
}

CMinimap::~CMinimap()
{
}

//----- (0082ABA0)
char CMinimap::MapRender(int a1)
{
	float DIRPointer;
	lpViewObj ObjectPointer;

	char result; // al@2
	float blue; // ST30_4@3
	float green; // ST2C_4@3
	float v7; // ST78_4@3
	float v8; // ST74_4@3
	float v9; // ST20_4@12
	float v10; // ST1C_4@12
	float v11; // ST70_4@12
	float v12; // ST6C_4@12
	float v13; // ST10_4@12
	float v14; // ST0C_4@12
	float v15; // ST20_4@15
	float v16; // ST1C_4@15
	float v17; // ST68_4@15
	float v18; // ST64_4@15
	float v19; // ST10_4@15
	float v20; // ST0C_4@15
	int v21; // eax@17
	int v22; // eax@19
	float v23; // ST30_4@19
	float v24; // ST60_4@19
	int v25; // eax@19
	float v26; // ST5C_4@19
	float v27; // ST58_4@19
	float v28; // ST54_4@22
	float v29; // ST50_4@22
	float v30; // ST4C_4@22
	float v31; // ST48_4@22
	int v32; // eax@23
	int v33; // eax@23
	float v34; // ST2C_4@23
	float v35; // ST44_4@23
	int v36; // eax@23
	float v37; // ST30_4@23
	float v38; // ST40_4@23
	int v39; // eax@23
	float v40; // ST30_4@23
	float v41; // ST2C_4@23
	float v42; // ST3C_4@23
	float v43; // ST38_4@23
	int v44; // [sp+78h] [bp-3Ch]@1
	float v45; // [sp+7Ch] [bp-38h]@3
	float v46; // [sp+88h] [bp-2Ch]@6
	float v47; // [sp+8Ch] [bp-28h]@1
	float v48; // [sp+90h] [bp-24h]@3
	float v49; // [sp+94h] [bp-20h]@6
	float v50; // [sp+98h] [bp-1Ch]@6
	float v51; // [sp+9Ch] [bp-18h]@3
	float v52; // [sp+A4h] [bp-10h]@3
	float v53; // [sp+A8h] [bp-Ch]@3
	signed int i; // [sp+ACh] [bp-8h]@3
	int j; // [sp+ACh] [bp-8h]@17
	int k; // [sp+ACh] [bp-8h]@20
	float v57; // [sp+B0h] [bp-4h]@3

	v44 = a1;
	v47 = 90.0;

	ObjectPointer = &*(ObjectPreview*)(*(DWORD *)0x7BC4F04);
	DIRPointer = (double) 135.0f + (45 * abs((signed int)(ObjectPointer->m_Model.WorldPos.Z / 45.0)));

	if ( *(BYTE *)(a1 + 13500) )
	{
		pSetBlend(1);
		pDrawBarForm(0.0, 0.0, 640.0, 480.0, 0.45000002, 1);
		pGLSwitch();

		pSetBlend(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		
		v53 = (double)*(signed int *)(oUserPreviewStruct + 172) / 256.0 * (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80);

		v48 = (double)*(signed int *)(oUserPreviewStruct + 176) / 256.0 * (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76);

		v52 = 0.65156251;
		v45 = 1.0;
		v57 = 35.0;
		v51 = 6.0;
		blue = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80);
		green = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76);
		v7 = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80) - v53;
		v8 = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76) - v48;
		//-- PINTA el Mapa
		pDrawMapFull(32447, v8, v7, green, blue, v47);

		//-- CICLO PARA PINTAR LOS NPC
		for ( i = 0; i < 100 && (signed int)*(BYTE *)(v44 + 116 * i + 300) > 0; ++i )
		{
			v50 = (double)*(signed int *)(v44 + 116 * i + 304) / 256.0
				* (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
			v46 = (double)*(signed int *)(v44 + 116 * i + 308) / 256.0
				* (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
			v49 = (double)*(signed int *)(v44 + 116 * i + 312);

			if ( *(BYTE *)(v44 + 116 * i + 300) == 1 )
			{
				if ( pMapNumber != 34 || (signed int)(unsigned __int8)0x986746A <= 0 || *(DWORD *)(v44 + 116 * i + 304) == 228 && *(DWORD *)(v44 + 116 * i + 308) == 48 && pMapNumber == 34 )
				{
					//-- PINTAMOS LOS NPC
					v9 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
					v10 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
					v11 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80) - v53;
					v12 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76) - v48;
					v13 = (double)25;
					v14 = (double)25;

					pDrawMapObject(32452, v46, v50, v14, v13, v12, v11, v10, v9, v47, v49, 0.546875, 0.546875, i);
				}
			}
			else if ( *(BYTE *)(v44 + 116 * i + 300) == 2 )
			{
				//-- PINTAMOS PORTAL
				v15 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
				v16 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
				v17 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80) - v53;
				v18 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76) - v48;
				v19 = (double)30;
				v20 = (double)30;

				pDrawMapObject(32451, v46, v50, v20, v19, v18, v17, v16, v15, v47, v49, 0.546875, 0.546875, i + 100);
			}
		}
		//-- PINTAMOS AL PERSONAJE
		sub_637E80( 32450, 325.0, 230.0, 15.0, 15.0, DIRPointer, 0.0, 0.0, 0.546875, 0.546875);
		
		//v21 = pMakeColor(255, 255, 255, 255);
		//RenderBitMapColored(32450, 325.0, 230.0, 15.0, 15.0, 0.0, 0.0, 0.546875, 0.546875, v21);

		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
		result = 1;
	}
	else
	{
		result = *(BYTE *)(a1 + 13500);
	}

	return result;
}

void DataMapLoad()
{
	int v4; // [sp+Ch] [bp-Ch]@5
	int v5; // [sp+10h] [bp-8h]@2
	int Type;
	int Multiplicador;
	int Scalado;

	Type = gRenderMap.DataMap.Scale;
	Multiplicador = (( Type == 1 ) ? 1 : Type - 1 );
	Scalado = (( Type == 1 ) ? 512 : 128 );

	gRenderMap.DataMap.This_92 = *(DWORD *)(*(DWORD *)0x7BC4F04 + 172) / ((Type == 1) ? 0.5 : Type - 1 ); //-- X
	gRenderMap.DataMap.This_96 = (256 - *(DWORD *)(*(DWORD *)0x7BC4F04 + 176)) / ((Type == 1) ? 0.5 :  Type - 1  ); //-- Y

	//-- X
	if ( gRenderMap.DataMap.This_92 - ( Multiplicador << 6 ) <= 0 )
		v5 = 0;
	else
		v5 = gRenderMap.DataMap.This_92 - ( Multiplicador << 6 );

	gRenderMap.DataMap.This_108 = ( v5 >= Scalado ) ? Scalado : (v5 <= 0) ? 0: gRenderMap.DataMap.This_92 + 25 - ( Multiplicador << 6 );

	//-- Y
	if ( gRenderMap.DataMap.This_96 - ( Multiplicador << 6 ) <= 0 )
		v4 = 0;
	else
		v4 = gRenderMap.DataMap.This_96 - ( Multiplicador << 6 );

	gRenderMap.DataMap.This_112 = ( v4 >= Scalado ) ? Scalado : (v4 <= 0) ? 0: gRenderMap.DataMap.This_96 + 15 - ( Multiplicador << 6 );

	gRenderMap.DataMap.DropMoveUserX = gRenderMap.DataMap.XSW_Minimap + gRenderMap.DataMap.This_92 - gRenderMap.DataMap.This_108;
	gRenderMap.DataMap.DropMoveUserY = gRenderMap.DataMap.YSW_Minimap + gRenderMap.DataMap.This_96 - gRenderMap.DataMap.This_112;

	gRenderMap.DataMap.CurrentMoveX = (double)gRenderMap.DataMap.This_108 / ((double) ((Type == 1) ? 512 : 256 ) / (double)Multiplicador );
	gRenderMap.DataMap.CurrentMoveY = (double)gRenderMap.DataMap.This_112 / ((double) ((Type == 1) ? 512 : 256 ) / (double)Multiplicador );
}

void DataViewPortMapLoad()
{
	int Model;
	int Type;
	float XNPC, YNPC;

	Type = gRenderMap.DataMap.Scale;

	for (int i = 0; i < 400; ++i )
	{
		Model = pGetPreviewStruct(pPreviewThis(), i);
		if ( Model
			&& *(BYTE *)(Model + 780)
			&& Model != *(DWORD *)0x7BC4F04
			&& (*(BYTE *)(Model + 800) == 1 || *(BYTE *)(Model + 800) == 2 || *(BYTE *)(Model + 800) == 4) )
		{
			{
				XNPC = (double) gRenderMap.ultimoX + *(DWORD *)(Model + 172) / ((Type == 1) ? 0.5 : Type - 1 );
				YNPC = (double) gRenderMap.ultimoY + (256 - *(DWORD *)(Model + 176)) / ((Type == 1) ? 0.5 : Type - 1 );

				XNPC = XNPC - gRenderMap.DataMap.This_108 - 5;
				YNPC = YNPC - gRenderMap.DataMap.This_112 - 5;
				if( pCheckMouseOver((int) XNPC, (int) YNPC, (int) 10, (int) 10) ) //Nombre Monsters
				{
					pDrawToolTip((int) XNPC, (int) YNPC - 10, (char *)(Model + 56)); //Nombre Monsters
				}
				{
					RenderBitMapColored(31471, XNPC + 2, YNPC + 2, 3.0, 3.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Monster
				}
			}
				//Aqui agregar ID de los Guard Cities
				if( *(WORD *)(Model + 132) == 249
					|| *(WORD *)(Model + 132) == 247
					|| *(WORD *)(Model + 132) == 241) 
				{
					RenderBitMapColored(31472, XNPC + 2, YNPC + 2, 3.0, 3.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Guard
				}
				//Aqui agregar ID de los Bosses o Golden
				else if( *(WORD *)(Model + 132) == 683
					|| *(WORD *)(Model + 132) == 682
					|| *(WORD *)(Model + 132) == 678 )
				{
					RenderBitMapColored(31473, XNPC + 2, YNPC + 2, 3.0, 3.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Boss/Gold
				}

				else if ( *(BYTE *)(Model + 800) == 4  &&  *(WORD *)(Model + 132) != 249 )
			{

				if( *(WORD *)(Model + 132) == 251 )
				{
					RenderBitMapColored(31466, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono NPC
				}
				else if( *(WORD *)(Model + 132) == 255 || *(WORD *)(Model + 132) == 253 )
				{
					RenderBitMapColored(31467, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono NPC
				}
				else if( *(WORD *)(Model + 132) == 240 ) //-- Baul
				{
					RenderBitMapColored(31468, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Baul
				}
				else if( *(WORD *)(Model + 132) == 229 || *(WORD *)(Model + 132) == 235 || *(WORD *)(Model + 132) == 233 || *(WORD *)(Model + 132) == 237 ) //-- Quest
				{
					RenderBitMapColored(31469, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Quest
				}
				else
				{
					RenderBitMapColored(32452,  XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Potion
				}
				if( pCheckMouseOver((int) XNPC, (int) YNPC, (int) 10, (int) 10) ) //Nombre NPC
				{
					pDrawToolTip((int) XNPC, (int) YNPC - 10, (char *)(Model + 56)); //Nombre NPC
				}
			}
		}
	}
}

int TimerEvent;

void Interface::DrawMiniMap()
{
	//--Minimizar MiniMapa
	if( MinimizarMiniMapa == 0 )
	{
	if( gRenderMap.DataMap.ModelID != -1 && MiniMap )
	{
		if(pCheckMouseOver(gRenderMap.ultimoX - 15, gRenderMap.ultimoY - 15, 120, 120))
		{
			pSetCursorFocus = true;
		}
	}
	/*if(gRenderMap.DataMap.ModelID == -1)
	{
		return;
	}*/

	if (this->MiniMapCheck() || this->CheckMap() 
		|| !MiniMap || this->CheckWindow(FullMap) 
		|| this->CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree) 
		|| gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(FastMenu))
	{
		return;
	}

	float DIRPointer;
	lpViewObj ObjectPointer;
	char Cord[256];
	float v8; // ST34_4@1
	float v9; // ST30_4@1
	float v10; // ST08_4@1
	float v11; // ST04_4@1
	int Type;
	int Multiplicador;
	int Scalado;

	ObjectPointer = &*(ObjectPreview*)(*(DWORD *)0x7BC4F04);
	DIRPointer =  180 + ( 45 * abs((signed int)(ObjectPointer->m_Model.WorldPos.Z / 45.0)));

	Type = gRenderMap.DataMap.Scale;

	DataMapLoad();

	v8 = 0.18f;
	v9 = 0.18f;

	v10 = (double) gRenderMap.DataMap.YSW_Minimap + 10;
	v11 = (double) gRenderMap.DataMap.XSW_Minimap;
	
	//--Mover Barra MiniMapa
		float InitialX = v11;
		float InitialY = v10;
		float cursorX = pCursorX >= MAX_WIN_WIDTH ? 0 : pCursorX;
		float cursorY = pCursorY >= MAX_WIN_HEIGHT ? 0 : pCursorY;

		if (gInterface.IsWorkZone(InitialX + 5, InitialY + 11, 70, 62, true)) {
			if (!gRenderMap.Moving && GetKeyState(VK_LBUTTON) & 0x8000 && GetTickCount() >= gRenderMap.DelayMove + 150) {
				gRenderMap.Moving = true;
				gRenderMap.maxX = cursorX;
				gRenderMap.maxY = cursorY;
				gRenderMap.DelayMove = GetTickCount();
			}	
		}
		if (gRenderMap.Moving) {
			InitialX = v11 + (cursorX - gRenderMap.maxX);
			InitialY = v10 + (cursorY - gRenderMap.maxY);
			InitialX = InitialX < 20 ? 20 : InitialX;
			InitialX = InitialX > 545 ? 545 : InitialX;
			InitialY = InitialY < 5 ? 5 : InitialY;
			InitialY = InitialY > 320 ? 320 : InitialY;
			gRenderMap.ultimoX = InitialX;
			gRenderMap.ultimoY = InitialY;
		}
		if (gRenderMap.Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
			gRenderMap.Moving = false;
			gRenderMap.DataMap.XSW_Minimap = InitialX;
			gRenderMap.DataMap.YSW_Minimap = InitialY;
			gRenderMap.ultimoX = InitialX;
			gRenderMap.ultimoY = InitialY;
		}

	//-- Fondo
	RenderBitmap(31459, InitialX - 8, InitialY - 9, 100, 100, 0.3699999452, 0.0625, 0.5779999495, 0.2889999151, 1, 1, 0.0); //Minimapa v2
	//-- Mapa
	RenderBitmap(31462, InitialX, InitialY, 80, 80, gRenderMap.DataMap.CurrentMoveX, gRenderMap.DataMap.CurrentMoveY, v9, v8, 1, 1, 0.0); //Minimapa v2
	//-- Usuario
	if ( gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 )
	{
		gRenderMap.DataMap.DropMoveUserX = gRenderMap.ultimoX + gRenderMap.DataMap.This_92 - gRenderMap.DataMap.This_108; //Minimapa v2
		gRenderMap.DataMap.DropMoveUserY = gRenderMap.ultimoY + gRenderMap.DataMap.This_96 - gRenderMap.DataMap.This_112; //Minimapa v2
		sub_637E80( 32450,(double)gRenderMap.DataMap.DropMoveUserX,(double)gRenderMap.DataMap.DropMoveUserY,7.5,7.5, DIRPointer, 0.0, 0.0, 0.546875, 0.546875); //Puntero personaje 97/99/s1/s2
	}
	else
	if ( gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		gRenderMap.DataMap.DropMoveUserX = gRenderMap.ultimoX + gRenderMap.DataMap.This_92 - gRenderMap.DataMap.This_108; //Minimapa v2
		gRenderMap.DataMap.DropMoveUserY = gRenderMap.ultimoY + gRenderMap.DataMap.This_96 - gRenderMap.DataMap.This_112; //Minimapa v2
		sub_637E80( 32450, (double)gRenderMap.DataMap.DropMoveUserX, (double)gRenderMap.DataMap.DropMoveUserY, 7.5, 7.5, DIRPointer, 0.0, 0.0, 0.546875, 0.546875); //Puntero personaje s3/s6/ex700/legends
	}

	//Party
	float JCPartyCoordX;
	float JCPartyCoordY;
	
	for(int i = 0; i < pPartyMemberCount ; i++){
		if( !strcmp(pGetStrutParty( i ).Name, pGetUserName) ){
			continue;
		}
	
		JCPartyCoordX = (double) InitialX + gMiniMap.gPartyInfo[ i ].x / ((Type == 1) ? 0.5 : Type - 1 );
		JCPartyCoordY = (double) InitialY + (256 - gMiniMap.gPartyInfo[ i ].y ) / ((Type == 1) ? 0.5 : Type - 1 );
	
		JCPartyCoordX = JCPartyCoordX - gRenderMap.DataMap.This_108 - 5;
		JCPartyCoordY = JCPartyCoordY - gRenderMap.DataMap.This_112 - 5;
	
		RenderBitMapColored(61520, JCPartyCoordX, JCPartyCoordY, 7.5, 7.5, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, gRenderMap.DataMap.Alpha * 255));
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, gRenderMap.DataMap.Alpha);

	DataViewPortMapLoad();
	int textAlpha;

	pGLSwitch();
	EnableAlphaTest(0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	RenderBitmap(31463, InitialX - 9, InitialY - 9, 100, 100, 0.3599999452, 0.0625, 0.5779999495, 0.2889999151, 1, 1, 0.0); //Minimapa v2 Marco Dorado
	if(TimerBar != 0)
	{
		RenderBitmap(31458, InitialX + ReturnX(TransForX(5)), InitialY + ReturnY(TransForY(71)), ReturnX(TransForX(53)), ReturnY(TransForY(26)), -0.4, -0.4, 1.2, 1.2, 0.1, 1, 0); //Minimapa v2 Timer
		//--
		time_t TimeLocal;
		struct tm * LocalT;
		time(&TimeLocal);
		// -----
		LocalT = localtime(&TimeLocal); 
		// -----
		char LocalTime[30];
		sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);
		//--
		pSetBlend(true);
		this->DrawFormat(eWhite, InitialX + ReturnX(TransForX(32)), InitialY + ReturnY(TransForY(85)), ReturnX(TransForX(100)), ReturnY(TransForY(1)), LocalTime);
		pGLSwitchBlend();
		pGLSwitch();
		pSetBlend(false);
	}

	int x1, y1, w1, h1;

	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
	//-- Boton Especial Menu
	x1 = InitialX + 66; //Minimapa v2
	y1 = InitialY + 68; //Minimapa v2
	w1 = 18;
	h1 = 18;

	//-- Config
	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		gInterface.DrawToolTip(v11 + 26, v10 - 20, "Especial Menu");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				if(!gInterface.Data[eMenu_MAIN].OnShow){
					gInterface.CloseAllWindows();
					gInterface.Data[eMenu_MAIN].OnShow = true;
					pSetCursorFocus = true;
				}else{
					gInterface.Data[eMenu_MAIN].OnShow = false;
					pSetCursorFocus = true;
				}
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}	
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		if (gInterface.Data[eMenu_MAIN].OnShow)
		{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		else
		{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	}

	//-- Boton 3D
	x1 = InitialX - 4; //Minimapa v2
	y1 = InitialY - 3; //Minimapa v2
	w1 = 18;
	h1 = 18;
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Bật camera 3D");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				gInterface.SwitchCamera();
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		if (gCamera.getEnabled())
		{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		else
		{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}

	// -- Boton Full Map
	x1 = InitialX - 5; //Minimapa v2
	y1 = InitialY + 67; //Minimapa v2
	w1 = 18;
	h1 = 18;
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 3, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo
	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Bản đồ lớn [TAB]");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.49420020828, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				gInterface.OpenWindow(FullMap);
				pSetCursorFocus = true;
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.49420020828, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.49420020828, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
	}

	//-- Boton Config(Opciones del juego)
	x1 = InitialX + 66; //Minimapa v2
	y1 = InitialY - 3; //Minimapa v2
	w1 = 18;
	h1 = 18;
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))	
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "System Option");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				gInterface.OpenConfig(0);
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
				pSetCursorFocus = true;
			}		
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		if (gInterface.CheckWindow(ObjWindow::Options))
		{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		else
		{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}

	//-- Boton Camara Reset
	x1 = InitialX - 12; //Minimapa v2
	y1 = InitialY + 9; //Minimapa v2
	w1 = 18;
	h1 = 18;
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Khôi phục camera");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.74460064924, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				gInterface.CameraInit();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.74460064924, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.74460064924, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
	}
} //-- Finaliza Minimizar Minimapa
	return;
} //--Finaliza DrawMiniMap

//--Minimap Bar Activado
DWORD VKBUTTON_DELAY3;
void Interface::MiniMapMini()
{
	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)	
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
	    || gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}

	float v10; // ST08_4@1
	float v11; // ST04_4@1
	v10 = (double) gRenderMap.DataMap.YSW_Minimap + 10;
	v11 = (double) gRenderMap.DataMap.XSW_Minimap;
	
	//--Mover MiniMapa Empieza
		float InitialX = v11;
		float InitialY = v10;
		float cursorX = pCursorX >= MAX_WIN_WIDTH ? 0 : pCursorX;
		float cursorY = pCursorY >= MAX_WIN_HEIGHT ? 0 : pCursorY;

		if(MinimizarMiniMapa == 0)
		{
		if (gInterface.IsWorkZone(InitialX + 5, InitialY + 11, 70, 62, true)) 
		{
			if (!gRenderMap.Moving && GetKeyState(VK_LBUTTON) & 0x8000 && GetTickCount() >= gRenderMap.DelayMove + 150) {
				gRenderMap.Moving = true;
				gRenderMap.maxX = cursorX;
				gRenderMap.maxY = cursorY;
				gRenderMap.DelayMove = GetTickCount();
			}	
		}
		}
		if(MinimizarMiniMapa == 1)
			{
			if(pCheckMouseOver(gRenderMap.ultimoX - 15, gRenderMap.ultimoY - 15, 120, 120))
			{
				pSetCursorFocus = false;
			}
		}
		if (gRenderMap.Moving) {
			InitialX = v11 + (cursorX - gRenderMap.maxX);
			InitialY = v10 + (cursorY - gRenderMap.maxY);
			InitialX = InitialX < 20 ? 20 : InitialX;
			InitialX = InitialX > 545 ? 545 : InitialX;
			InitialY = InitialY < 5 ? 5 : InitialY;
			InitialY = InitialY > 320 ? 320 : InitialY;
			gRenderMap.ultimoX = InitialX;
			gRenderMap.ultimoY = InitialY;
		}
		if (gRenderMap.Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
			gRenderMap.Moving = false;
			gRenderMap.DataMap.XSW_Minimap = InitialX;
			gRenderMap.DataMap.YSW_Minimap = InitialY;
			gRenderMap.ultimoX = InitialX;
			gRenderMap.ultimoY = InitialY;
		}

	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{

	int y = InitialY - 5;
	int x = InitialX + 87;

	if(pCheckMouseOver( x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14))))
	{
		if(pCursorX >= x + ReturnX(TransForX(-3)))
		{
		pSetCursorFocus = true;
		}
	}
	if(MinimizarMiniMapa == 0)
	{
		if(CheckButtonPressed( x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY3 + 200 )
			{
				MinimizarMiniMapa = 1;
				//MiniMap = 0;
				VKBUTTON_DELAY3 = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(61545, x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
		}
	}
	else
	{
		if(CheckButtonPressed( x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY3 + 200 )
			{
				MinimizarMiniMapa = 0;
				//MiniMap = 1;
				VKBUTTON_DELAY3 = GetTickCount();
			}
		}
		else
			{
			RenderBitmap(61545, x + ReturnX(TransForX(-3)), y + ReturnY(TransForY(-2)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			}
		}
	}
	else if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
	int y = InitialY - 5;
	int x = InitialX + 87;

	if(pCheckMouseOver( x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14))))
	{
		if(pCursorX >= x + ReturnX(TransForX(-1)))
		{
		pSetCursorFocus = true;
		}
	}
	if(MinimizarMiniMapa == 0)
	{
		if(CheckButtonPressed( x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.6000000238, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY3 + 200 )
			{
				MinimizarMiniMapa = 1;
				VKBUTTON_DELAY3 = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(61545, x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
		}
	}
	else
	{
		if(CheckButtonPressed( x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.1289999783, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY3 + 200 )
			{
				MinimizarMiniMapa = 0;
				VKBUTTON_DELAY3 = GetTickCount();
			}
		}
		else
			{
			RenderBitmap(61545, x + ReturnX(TransForX(-1)), y + ReturnY(TransForY(-12)), ReturnX(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			}
		}
	}
}
//--

bool MiniMapFileCheck1(int Map) // OK
{
	if(Map - 1 == 30){return 0;}
	
	char Path[64];

	wsprintf(Path, "Data\\Custom\\Maps\\World%d.ozt", Map);

	int File = rFileOpen(Path, "rb");

	if ( File )
	{
		rFileClose(File);
		return 1;
	}
	else
	{
		return 0;
	}
}

void MiniMapLoadNew() // OK
{
	if (pMapNumber < MAX_MINI_MAP && pMapNumber != 30)
	{
		char buff[32];

		wsprintf(buff, "Custom\\Maps\\World%d.tga", ( pMapNumber + 1 ));
		
		if (MiniMapFileCheck1( pMapNumber + 1 ) != 0)
		{
			gRenderMap.DataMap.ModelID = 31462;
			pLoadImage(buff, 31462, 0x2601, 0x2900, 1, 0);
		}
		else
		{
			gRenderMap.DataMap.ModelID = -1;
		}
	}
}

__declspec(naked) void LoadTexture()
{
	static DWORD Addr2_JMP = 0x0062F8A6;
	static DWORD Addr1_JMP = 0x0062F87C;
	static DWORD Map = 0x007AA331;

	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP-0x78]
		MOV Map, EAX
	}
	if ( Map == 74 || Map == 75 )
	{
		_asm
		{
			JMP[Addr2_JMP]
		}
	}
	else
	{
		MiniMapLoadNew();
		_asm
		{
			JMP[Addr1_JMP]
		}
	}
}

bool pDisabledMouseMAP(int x, int y, int w, int h)
{
	return 0;
}

void CMinimap::MiniMapLoadNew()
{
	SetCompleteHook(0xE8, 0x0082B772, &pDisabledMouseMAP); //ok

	SetCompleteHook(0xE9, 0x0062F870, &LoadTexture); //ok
	SetCompleteHook(0xE9, 0x0082ABA0, &CMinimap::MapRender);
}