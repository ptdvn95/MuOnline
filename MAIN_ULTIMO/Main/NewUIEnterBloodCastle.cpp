#include "stdafx.h"
#include "Util.h"
#include "NewUIEnterBloodCastle.h"

CNewUIEnterBloodCastle g_pNewEnterBloodCastle;

CNewUIEnterBloodCastle::CNewUIEnterBloodCastle(void)
{
}

CNewUIEnterBloodCastle::~CNewUIEnterBloodCastle(void)
{
}

DWORD * CNewUIEnterBloodCastle::EnterBloodCastle(DWORD *a1)
{
	DWORD * Blood = C_EnterBloodCastle(a1);
	CBloodCastle* thisa = (CBloodCastle*)Blood;
	thisa->m_iBloodCastleLimitLevel[0][0] = 15;  thisa->m_iBloodCastleLimitLevel[0][1] = 80;
	thisa->m_iBloodCastleLimitLevel[1][0] = 81;  thisa->m_iBloodCastleLimitLevel[1][1] = 130;
	thisa->m_iBloodCastleLimitLevel[2][0] = 131; thisa->m_iBloodCastleLimitLevel[2][1] = 180;
	thisa->m_iBloodCastleLimitLevel[3][0] = 181; thisa->m_iBloodCastleLimitLevel[3][1] = 230;
	thisa->m_iBloodCastleLimitLevel[4][0] = 231; thisa->m_iBloodCastleLimitLevel[4][1] = 280;
	thisa->m_iBloodCastleLimitLevel[5][0] = 281; thisa->m_iBloodCastleLimitLevel[5][1] = 330;
	thisa->m_iBloodCastleLimitLevel[6][0] = 331; thisa->m_iBloodCastleLimitLevel[6][1] = 400;
	thisa->m_iBloodCastleLimitLevel[7][0] = 0;   thisa->m_iBloodCastleLimitLevel[7][1] = 0;
	//-- mg, dl, rf
	thisa->m_iBloodCastleLimitLevel[8][0]  = 10;  thisa->m_iBloodCastleLimitLevel[8][1]  = 60;
	thisa->m_iBloodCastleLimitLevel[9][0]  = 61;  thisa->m_iBloodCastleLimitLevel[9][1]  = 110;
	thisa->m_iBloodCastleLimitLevel[10][0] = 111; thisa->m_iBloodCastleLimitLevel[10][1] = 160;
	thisa->m_iBloodCastleLimitLevel[11][0] = 161; thisa->m_iBloodCastleLimitLevel[11][1] = 210;
	thisa->m_iBloodCastleLimitLevel[12][0] = 211; thisa->m_iBloodCastleLimitLevel[12][1] = 260;
	thisa->m_iBloodCastleLimitLevel[13][0] = 261; thisa->m_iBloodCastleLimitLevel[13][1] = 310;
	thisa->m_iBloodCastleLimitLevel[14][0] = 311; thisa->m_iBloodCastleLimitLevel[14][1] = 400;
	thisa->m_iBloodCastleLimitLevel[15][0] = 0;   thisa->m_iBloodCastleLimitLevel[15][1] = 0;
	return Blood;
}

void CNewUIEnterBloodCastle::Init()
{
	SetCompleteHook(0xE8, 0x0085B00D, &CNewUIEnterBloodCastle::EnterBloodCastle); //-- Create System Blood
}