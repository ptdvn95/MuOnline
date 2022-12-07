// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define PROTECT_START _asm _emit 0xEB _asm _emit 0x0E _asm _emit 0x14 _asm _emit 0x28 _asm _emit 0xCD _asm _emit 0xDB _asm _emit 0x50 _asm _emit 0x63 _asm _emit 0xAF _asm _emit 0x22 _asm _emit 0x75 _asm _emit 0xEE _asm _emit 0xB5 _asm _emit 0xD8 _asm _emit 0x43 _asm _emit 0x72
#define PROTECT_FINAL _asm _emit 0xEB _asm _emit 0x0E _asm _emit 0x37 _asm _emit 0xF2 _asm _emit 0xCD _asm _emit 0xDB _asm _emit 0x50 _asm _emit 0x63 _asm _emit 0xAF _asm _emit 0x22 _asm _emit 0x75 _asm _emit 0xEE _asm _emit 0xB5 _asm _emit 0xD8 _asm _emit 0x85 _asm _emit 0x61
#define CRASH_APPLICATION_MACRO _asm _emit 0xFF _asm _emit 0x25 _asm _emit 0x00 _asm _emit 0x00 _asm _emit 0x00 _asm _emit 0x00

enum eAuthServerType
{
	AUTH_SERVER_TYPE_NONE,
	AUTH_SERVER_TYPE_MHP,
	AUTH_SERVER_TYPE_S6_CONNECT_SERVER,
	AUTH_SERVER_TYPE_S6_JOIN_SERVER,
	AUTH_SERVER_TYPE_S6_DATA_SERVER,
	AUTH_SERVER_TYPE_S6_GAME_SERVER,
};

enum eAuthServerStatus
{
	AUTH_SERVER_STATUS_NONE = 0,
	AUTH_SERVER_STATUS_SUCCESS = 1,
};

struct SDHP_AUTH_SERVER_DATA_RECV
{
	BYTE type; // C1:00
	BYTE size;
	BYTE head;
	BYTE EncKey;
	BYTE ServerType;
	BYTE Status;
	BYTE PackageType;
	BYTE UpdateMax;
	char CustomerName[32];
	char CustomerHardwareId[45];
};

struct SDHP_AUTH_SERVER_DATA_SEND
{
	BYTE type; // C1:00
	BYTE size;
	BYTE head;
	BYTE EncKey;
	BYTE ServerType;
	char CustomerName[32];
	char CustomerHardwareId[45];
};

class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool GetComputerHardwareId();
	bool ConnectToAuthServer(char* IpAddress, WORD port);
	bool AuthServerDataSend(eAuthServerType ServerType);
	void StartAuth(eAuthServerType ServerType);
	inline void ErrorMessageBox();
	inline void SafeExitProcess();
	void ProtectBlock(DWORD size);
	void ReleaseBlock(DWORD size);
	void DecryptBlock(BYTE* data, int size);
	void EncryptBlock(BYTE* data, int size);
	inline void InsertMemoryMacro(BYTE* data, BYTE* info, int size);
	inline void RemoveMemoryMacro(BYTE* data, BYTE* info, int size);
	inline bool VerifyMemoryMacro(BYTE* data, BYTE* info, int size);
	bool GetInsertStartBlock(DWORD start_offset, DWORD final_offset, DWORD* start_block);
	bool GetInsertFinalBlock(DWORD start_offset, DWORD final_offset, DWORD* final_block);
	bool GetRemoveStartBlock(DWORD start_offset, DWORD final_offset, DWORD* start_block);
	bool GetRemoveFinalBlock(DWORD start_offset, DWORD final_offset, DWORD* final_block);
	char* GetEncryptedString(int* string, int size);
public:
	SOCKET m_socket;
	char m_ComputerHardwareId[45];
	BYTE m_EncKey;
	SDHP_AUTH_SERVER_DATA_RECV m_AuthInfo;
};

extern CProtect gProtect;

static const BYTE gProtectTable[16] = { 0x98,0x34,0xF1,0xFF,0x3C,0xB5,0x54,0x86,0x9F,0x8C,0xB1,0x9A,0x52,0x77,0x75,0x25 };
static const BYTE gProtectInsertStart[16] = { 0x5C,0xE9,0x14,0x28,0x9D,0xDA,0x28,0xE7,0x70,0x29,0x48,0x3A,0xDA,0x6A,0xAB,0x72 };
static const BYTE gProtectInsertFinal[16] = { 0x5C,0xE9,0x37,0xF2,0x9D,0xDA,0x28,0xE7,0x70,0x29,0x48,0x3A,0xDA,0x6A,0xAB,0x61 };
static const BYTE gProtectRemoveStart[16] = { 0xF1,0xD2,0xF4,0x28,0x72,0xCA,0x93,0x2F,0x23,0xE4,0x9D,0xFF,0xAF,0xC2,0x43,0x72 };
static const BYTE gProtectRemoveFinal[16] = { 0xF1,0xD2,0xF4,0xF2,0x72,0xCA,0x93,0x2F,0x23,0xE4,0x9D,0xFF,0xAF,0xC2,0x85,0x61 };

static int gProtectServerAddress[15] = { 0xCB5,0xCB1,0xCAE,0xCB2,0xCB2,0xCB2,0xCAE,0xCB2,0xCB1,0xCAE,0xCB1,0xCB5,0xCB5,0xC80 }; //"51.222.21.155"
static int gProtectHardwareIdFormat[25] = { 0xCA5,0xCB0,0xCB8,0xCD8,0xCAD,0xCA5,0xCB0,0xCB8,0xCD8,0xCAD,0xCA5,0xCB0,0xCB8,0xCD8,0xCAD,0xCA5,0xCB0,0xCB8,0xCD8,0xCAD,0xCA5,0xCB0,0xCB8,0xCD8,0xC80 }; //"%08X-%08X-%08X-%08X-%08X"