#pragma once

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define GAMESERVER_STATUS "STANDBY MODE"

#define GAMESERVER_STATUS_MODE "ACTIVE MODE"

#define GAMESERVER_HOST 1

#define ISPREMIUN	1

#define GAMESERVER_TYPE2 0

#if(GAMESERVER_TYPE2 == 0)
#define GAMESERVER_CLIENT "[MU DISCORD]"
#else
#define GAMESERVER_CLIENT "[MU DISCORD]"
#endif

#define UPDATE_GAMING 15
#define GAMESERVER_CLIENTE_UPDATE 17
#define GAMESERVER_CLIENTE_PREMIUM 0


#if(GAMESERVER_TYPE==0)
#define GAMESERVER_VERSION "GS"
#else
#define GAMESERVER_VERSION "GSCS"
#endif

#ifndef GAMESERVER_TYPE
#define GAMESERVER_TYPE 0
#endif

#ifndef GAMESERVER_EXTRA
#define GAMESERVER_EXTRA 1
#endif

#ifndef GAMESERVER_UPDATE
#define GAMESERVER_UPDATE 803
#endif

#if(GAMESERVER_UPDATE==401)
#define GAMESERVER_SEASON "SEASON 4"
#endif

#if(GAMESERVER_UPDATE==603)
#define GAMESERVER_SEASON "SEASON 6"
#endif

#if(GAMESERVER_UPDATE==803)
#define GAMESERVER_SEASON "SEASON 8"
#endif

#ifndef GAMESERVER_LANGUAGE
#define GAMESERVER_LANGUAGE 1
#endif

#ifndef PROTECT_STATE
#define PROTECT_STATE 1
#endif

#ifndef ENCRYPT_STATE
#define ENCRYPT_STATE 1
#endif

#if(PROTECT_STATE==0)
#define GAMESERVER_NAME "Free"
#else
#define GAMESERVER_NAME "Premium"
#endif

#define CUSTOM_PET					1
#define NEW_FENRIR					1
#define OFFLINE_MODE				1
#define ADD_OFFMODE_PICKUP			0
#define MONSTER_COINS               1
#define SOKED_HARMONY_FIX			1
//MC bot
//----------------------------
//	 ZG-Defines			     -
//	 1:ON  (CPP AND HEADER!) -
//	 2:OFF (CPP AND HEADER!) -
//----------------------------

#ifndef POINT_CUSTOM 
#define POINT_CUSTOM 1 // ShopPointEx
#endif


#define PC_POINT			 2 //Agregar algun npc o bot con PCP
#define HAPPY_HOURS			 2 //[80%]->Falta Arreglar Los Vip!
#define MASTER_HOURS		 2
#define ACHERON_GUARDIAN	 2

#define ARCA_WAR			 2	// Mix nomas!!
#define GOLDEN_ARCHER		 2	// 


//-- Need All Types
#define PG_CUSTOM			 1
#define ALLBOTSSTRUC		 1

#define JEWEL_BANK             1
#define DUEL_CUSTOM_APUESTAS   1
#define RESETCHANGE            1
#define CHANGECLASS            1
#define LUCKYWHEEL             1
#define CUSTOM_PERSONAL_SHOP   1
#define ANTIFLOOD              1
#define ARCHIVEMENT            1
#define LEVEL_PLUS             1
#define WINDOWSQUEST           1
#define HPTYPE                 0  // type 0: classic || type 1: custom

// System Include
#include <windows.h>
#include <winsock2.h>
#include <mswSock.h>
#include <commctrl.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <random>
#include <Rpc.h>
#include <algorithm>
#include <string>
#include <atltime.h>
#include <dbghelp.h>
#include <Psapi.h>
#include "..\\..\\Util\\pugixml\\pugixml.hpp"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")

#if(GAMESERVER_UPDATE>=701)
#if(NDEBUG==0)
#pragma comment(lib,"..\\..\\Util\\cryptopp\\Debug\\cryptlib.lib")
#else
#pragma comment(lib,"..\\..\\Util\\cryptopp\\Release\\cryptlib.lib")
#endif
#pragma comment(lib,"..\\..\\Util\\mapm\\mapm.lib")
#endif

typedef char chr;

typedef float flt;

typedef short shrt;

typedef unsigned __int64 QWORD;
