// CustomItem.cpp: implementation of the CLuckyWheel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LuckyWheel.h"
#include "Defines.h"
CLuckyWheel gLuckyWheel;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLuckyWheel::CLuckyWheel() // OK
{
	this->Init();
}

CLuckyWheel::~CLuckyWheel() // OK
{

}

void CLuckyWheel::Init() // OK
{
	for (int n = 0; n < MAX_ITEM; n++)
	{
		this->m_LuckyWheelInfo[n].Index = -1;
	}
}

void CLuckyWheel::Load(LUCKYWHEEL_INFO* info) // OK
{
	for (int n = 0; n < MAX_ITEM; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CLuckyWheel::SetInfo(LUCKYWHEEL_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_ITEM)
	{
		return;
	}

	this->m_LuckyWheelInfo[info.Index] = info;
}

void CLuckyWheel::RecibirCostoWheel(PMSG_LUCKY_WHEEL * aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}
	// ---
	this->CostWcoinC = aRecv->CostWcoinC;
	this->CostWcoinP = aRecv->CostWcoinP;
	this->CostGoblin = aRecv->CostGoblin;
}