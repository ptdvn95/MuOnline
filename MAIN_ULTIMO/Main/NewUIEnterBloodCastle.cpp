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
	thisa->m_iBloodCastleLimitLevel[0][0] = 50;  thisa->m_iBloodCastleLimitLevel[0][1] = 199;
	thisa->m_iBloodCastleLimitLevel[1][0] = 200;  thisa->m_iBloodCastleLimitLevel[1][1] = 399;
	thisa->m_iBloodCastleLimitLevel[2][0] = 400; thisa->m_iBloodCastleLimitLevel[2][1] = 499;
	thisa->m_iBloodCastleLimitLevel[3][0] = 500; thisa->m_iBloodCastleLimitLevel[3][1] = 599;
	thisa->m_iBloodCastleLimitLevel[4][0] = 600; thisa->m_iBloodCastleLimitLevel[4][1] = 699;
	thisa->m_iBloodCastleLimitLevel[5][0] = 700; thisa->m_iBloodCastleLimitLevel[5][1] = 799;
	thisa->m_iBloodCastleLimitLevel[6][0] = 900; thisa->m_iBloodCastleLimitLevel[6][1] = 1300;
	thisa->m_iBloodCastleLimitLevel[7][0] = 0;   thisa->m_iBloodCastleLimitLevel[7][1] = 0;
	//-- mg, dl, rf
	thisa->m_iBloodCastleLimitLevel[8][0]  = 50;  thisa->m_iBloodCastleLimitLevel[8][1]  = 199;
	thisa->m_iBloodCastleLimitLevel[9][0]  = 200;  thisa->m_iBloodCastleLimitLevel[9][1]  = 399;
	thisa->m_iBloodCastleLimitLevel[10][0] = 400; thisa->m_iBloodCastleLimitLevel[10][1] = 499;
	thisa->m_iBloodCastleLimitLevel[11][0] = 500; thisa->m_iBloodCastleLimitLevel[11][1] = 599;
	thisa->m_iBloodCastleLimitLevel[12][0] = 600; thisa->m_iBloodCastleLimitLevel[12][1] = 699;
	thisa->m_iBloodCastleLimitLevel[13][0] = 700; thisa->m_iBloodCastleLimitLevel[13][1] = 799;
	thisa->m_iBloodCastleLimitLevel[14][0] = 900; thisa->m_iBloodCastleLimitLevel[14][1] = 1300;
	thisa->m_iBloodCastleLimitLevel[15][0] = 0;   thisa->m_iBloodCastleLimitLevel[15][1] = 0;
	return Blood;
}

void CNewUIEnterBloodCastle::Init()
{
	SetCompleteHook(0xE8, 0x0085B00D, &CNewUIEnterBloodCastle::EnterBloodCastle); //-- Create System Blood
}