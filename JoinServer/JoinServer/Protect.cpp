// Protect.cpp: implementation of the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Protect.h"
#include "Util.h"
#include "ThemidaSDK.h"
#include"..//..//Util/CCRC32.H"



CProtect gProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtect::CProtect() // OK
{

}

CProtect::~CProtect() // OK
{

}


DWORD CProtect::GetCurrentVersion()
{
	char Temp[10];
	sprintf_s(Temp, gProtect.GetEncryptedString(gProtectVersion, sizeof(gProtectVersion)));
	strcpy_s(Temp, this->RemoveCharacter(Temp, '.'));
	return atoi(Temp);
}

DWORD CProtect::VersionSupport()
{
	char Temp[10];
	sprintf_s(Temp, "%s", gProtect.m_LicenceInfo.MaxUpdate);
	strcpy_s(Temp, this->RemoveCharacter(Temp, '.'));
	return atoi(Temp);
}

char* CProtect::RemoveCharacter(char* Input, char Character) //OK
{
	for (DWORD i = 0; i <= strlen(Input); i++)
	{
		if (Input[i] == Character)
		{
			for (DWORD n = i; n <= strlen(Input); n++)
			{
				Input[n] = Input[n + 1];
			}
		}
	}
	return Input;
}

char* CProtect::GetEncryptedString(BYTE* string, int size) // OK
{
	PROTECT_START

		static char buff[256];

	memset(buff, 0, sizeof(buff));

	for (int n = 0; n < size; n++)
	{
		buff[n] = string[n] ^ 0xB0;
	}

	return buff;

	PROTECT_FINAL
}

bool CProtect::ReadFileCrc(char* name) // OK
{
	VM_START
		PROTECT_START
		// ----
		CCRC32 CRC32;

	if (CRC32.FileCRC(name, &this->m_ClientFileCRC, 1024) == 0)
	{
		return 0;
	}

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if (file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	if (GetFileSize(file, 0) != sizeof(CRC_DATA))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if (ReadFile(file, &this->m_FilesCrc, sizeof(CRC_DATA), &OutSize, 0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	for (int n = 0; n < sizeof(CRC_DATA); n++)
	{

		((BYTE*)&this->m_FilesCrc)[n] += (BYTE)(0xF5 ^ HIBYTE(n));
		((BYTE*)&this->m_FilesCrc)[n] ^= (BYTE)(0x7A ^ LOBYTE(n));

	}

	CloseHandle(file);
	return 1;

	PROTECT_FINAL
		VM_END
}

void CProtect::CheckCRCJS() // OK
{
	VM_START
		PROTECT_START
		if (this->m_FilesCrc.PluginCRC32JS == 0)
		{
			return;
		}

	CCRC32 CRC32;

	DWORD PluginCRC32;

	if (CRC32.FileCRC(this->m_FilesCrc.PluginCrcJS, &PluginCRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_FilesCrc.PluginCRC32JS != PluginCRC32)
	{
		MessageBoxA(NULL, "THE JOINSERVER HAS BEEN MANIPULATED", "[ZX]GAMES WARNING", NULL);
		ExitProcess(0);
	}
	PROTECT_FINAL
		VM_END
}