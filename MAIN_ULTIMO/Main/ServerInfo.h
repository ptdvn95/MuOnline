#pragma once
#if(IN_DEV ==1)
#include "stdafx.h"

struct SERVERINFO_DATA{
	char ServerName[20];
	int SubServerNum;
	char ServerText[256];
};

class CServerInfo
{
public:
	CServerInfo();
	~CServerInfo();
	void Load();
};extern CServerInfo g_ServerInfo;
#endif