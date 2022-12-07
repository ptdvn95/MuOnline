// Protect.cpp: implementation of the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Protect.h"
#include "ServerInfo.h"
#include "ThemidaSDK.h"

CProtect gProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtect::CProtect() // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		srand((DWORD)time(0));

	this->m_socket = INVALID_SOCKET;

	memset(this->m_ComputerHardwareId, 0, sizeof(this->m_ComputerHardwareId));

	this->m_EncKey = rand() % 256;

	memset(&this->m_AuthInfo, 0, sizeof(this->m_AuthInfo));

	VM_END

		CLEAR_END

#endif
}

CProtect::~CProtect() // OK
{

}

bool CProtect::GetComputerHardwareId() // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		char WinDir[MAX_PATH];

	if (GetSystemDirectory(WinDir, sizeof(WinDir)) == 0)
	{
		return 0;
	}

	WinDir[3] = 0;

	DWORD VolumeSerialNumber;

	if (GetVolumeInformation(WinDir, 0, 0, &VolumeSerialNumber, 0, 0, 0, 0) == 0)
	{
		return 0;
	}

	SYSTEM_INFO SystemInfo;

	GetSystemInfo(&SystemInfo);

	DWORD ComputerHardwareId1 = (VolumeSerialNumber ^ VolumeSerialNumber) + 0x13BA2020;
	DWORD ComputerHardwareId2 = (VolumeSerialNumber * VolumeSerialNumber) - 0x13A01989;
	DWORD ComputerHardwareId3 = (VolumeSerialNumber | SystemInfo.dwNumberOfProcessors << 8) * 0x16CE1989;
	DWORD ComputerHardwareId4 = (VolumeSerialNumber | SystemInfo.wProcessorArchitecture << 4) / 8;
	DWORD ComputerHardwareId5 = ((SystemInfo.wProcessorLevel & 0xF5AB) | (SystemInfo.wProcessorRevision << 8)) ^ 0x16BACA19;

	wsprintf(this->m_ComputerHardwareId, this->GetEncryptedString(gProtectHardwareIdFormat, sizeof(gProtectHardwareIdFormat)), ComputerHardwareId1, ComputerHardwareId2, ComputerHardwareId3, ComputerHardwareId4, ComputerHardwareId5);

	VM_END

		CLEAR_END

		return 1;

#else

	return 0;

#endif
}

bool CProtect::ConnectToAuthServer(char* IpAddress, WORD port) // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		if (this->m_socket != INVALID_SOCKET)
		{
			return 0;
		}

	this->m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (this->m_socket == INVALID_SOCKET)
	{
		return 0;
	}

	SOCKADDR_IN target;

	target.sin_family = AF_INET;
	target.sin_port = htons(port);
	target.sin_addr.s_addr = inet_addr(IpAddress);

	if (target.sin_addr.s_addr == INADDR_NONE)
	{
		HOSTENT* host = gethostbyname(IpAddress);

		if (host != 0)
		{
			memcpy(&target.sin_addr.s_addr, *host->h_addr_list, host->h_length);
		}
	}

	if (connect(this->m_socket, (SOCKADDR*)& target, sizeof(target)) == SOCKET_ERROR)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			return 0;
		}
	}

	VM_END

		CLEAR_END

		return 1;

#else

	return 0;

#endif
}

bool CProtect::AuthServerDataSend(eAuthServerType ServerType) // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		if (this->GetComputerHardwareId() == 0)
		{
			return 0;
		}

	this->m_EncKey = rand() % 256;

	SDHP_AUTH_SERVER_DATA_SEND pMsg;

	pMsg.type = 0xC1;

	pMsg.size = sizeof(pMsg);

	pMsg.head = 0xF0;

	pMsg.EncKey = this->m_EncKey;

	pMsg.ServerType = ServerType;

	memcpy(pMsg.CustomerName, gServerInfo.m_CustomerName, sizeof(pMsg.CustomerName));

	memcpy(pMsg.CustomerHardwareId, this->m_ComputerHardwareId, sizeof(pMsg.CustomerHardwareId));

	for (int n = 4;n < sizeof(SDHP_AUTH_SERVER_DATA_SEND);n++)
	{
		((BYTE*)& pMsg)[n] ^= pMsg.EncKey + 0xFD;
		((BYTE*)& pMsg)[n] -= 0xA9;
	}

	if (send(this->m_socket, (char*)& pMsg, pMsg.size, 0) == SOCKET_ERROR)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			return 0;
		}
	}

	memset(this->m_AuthInfo.CustomerHardwareId, 0, sizeof(this->m_AuthInfo.CustomerHardwareId));

	VM_END

		CLEAR_END

		return 1;

#else

	return 0;

#endif
}

void CProtect::StartAuth(eAuthServerType ServerType) // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		static DWORD CheckProtectionValue;

	CHECK_PROTECTION(CheckProtectionValue, 0x10000000)

		if (CheckProtectionValue != 0x10000000)
		{
			memset((void*)& gProtectTable[0], 0, sizeof(gProtectTable));
			memset((void*)& gProtectInsertStart[0], 0, sizeof(gProtectInsertStart));
			memset((void*)& gProtectInsertFinal[0], 0, sizeof(gProtectInsertFinal));
			memset((void*)& gProtectRemoveStart[0], 0, sizeof(gProtectRemoveStart));
			memset((void*)& gProtectRemoveFinal[0], 0, sizeof(gProtectRemoveFinal));
		}

	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		this->ErrorMessageBox();
		return;
	}

	if (this->ConnectToAuthServer(this->GetEncryptedString(gProtectServerAddress, sizeof(gProtectServerAddress)), 1256) == 0)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	if (this->AuthServerDataSend(ServerType) == 0)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	if (recv(this->m_socket, (char*)& this->m_AuthInfo, sizeof(this->m_AuthInfo), 0) != sizeof(SDHP_AUTH_SERVER_DATA_RECV))
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	if (this->m_AuthInfo.EncKey != this->m_EncKey)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	for (int n = 4;n < sizeof(SDHP_AUTH_SERVER_DATA_RECV);n++)
	{
		((BYTE*)& this->m_AuthInfo)[n] += 0xE5;
		((BYTE*)& this->m_AuthInfo)[n] ^= this->m_AuthInfo.EncKey + 0xC4;
	}

	if (this->m_AuthInfo.Status != AUTH_SERVER_STATUS_SUCCESS)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	if (strcmp(this->m_AuthInfo.CustomerName, gServerInfo.m_CustomerName) != 0)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	if (this->GetComputerHardwareId() == 0)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	if (strcmp(this->m_AuthInfo.CustomerHardwareId, this->m_ComputerHardwareId) != 0)
	{
		closesocket(this->m_socket);
		this->m_socket = INVALID_SOCKET;
		this->ErrorMessageBox();
		return;
	}

	this->ReleaseBlock(0);

	closesocket(this->m_socket);

	this->m_socket = INVALID_SOCKET;

	memset(this->m_ComputerHardwareId, 0, sizeof(this->m_ComputerHardwareId));

	memset(this->m_AuthInfo.CustomerName, 0, sizeof(this->m_AuthInfo.CustomerName));

	memset(this->m_AuthInfo.CustomerHardwareId, 0, sizeof(this->m_AuthInfo.CustomerHardwareId));

	VM_END

		CLEAR_END

#endif
}

inline void CProtect::ErrorMessageBox() // OK
{
#if(PROTECT_STATE==1)

	memset(this->m_ComputerHardwareId, 0, sizeof(this->m_ComputerHardwareId));

	memset(&this->m_AuthInfo, 0, sizeof(this->m_AuthInfo));

	MessageBox(0, "Could not authenticate the machine", "Error", MB_ICONSTOP | MB_OK);

	this->SafeExitProcess();

#endif
}

inline void CProtect::SafeExitProcess() // OK
{
#if(PROTECT_STATE==1)

	while (true)
	{
		TerminateProcess(GetCurrentProcess(), 0);
		CRASH_APPLICATION_MACRO
	}

#endif
}

void CProtect::ProtectBlock(DWORD size) // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		static DWORD CheckProtectionValue;

	CHECK_PROTECTION(CheckProtectionValue, 0x10000000)

		if (CheckProtectionValue != 0x10000000)
		{
			memset((void*)& gProtectTable[0], 0, sizeof(gProtectTable));
			memset((void*)& gProtectInsertStart[0], 0, sizeof(gProtectInsertStart));
			memset((void*)& gProtectInsertFinal[0], 0, sizeof(gProtectInsertFinal));
			memset((void*)& gProtectRemoveStart[0], 0, sizeof(gProtectRemoveStart));
			memset((void*)& gProtectRemoveFinal[0], 0, sizeof(gProtectRemoveFinal));
		}

	MODULEINFO ModuleInfo;

	memset(&ModuleInfo, 0, sizeof(ModuleInfo));

	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &ModuleInfo, sizeof(ModuleInfo));

	DWORD start_offset = (DWORD)ModuleInfo.lpBaseOfDll;

	DWORD final_offset = (DWORD)ModuleInfo.lpBaseOfDll + ModuleInfo.SizeOfImage;

	DWORD start_block, final_block;

	while (this->GetInsertStartBlock(start_offset, final_offset, &start_block) != 0 && this->GetInsertFinalBlock(start_block, final_offset, &final_block) != 0)
	{
		this->InsertMemoryMacro((BYTE*)start_block, (BYTE*)& gProtectRemoveStart[0], sizeof(gProtectRemoveStart));

		this->InsertMemoryMacro((BYTE*)final_block, (BYTE*)& gProtectRemoveFinal[0], sizeof(gProtectRemoveFinal));

		this->EncryptBlock((BYTE*)(start_block + sizeof(gProtectInsertStart)), (final_block - (start_block + sizeof(gProtectInsertStart))));

		start_offset = final_block + sizeof(gProtectInsertFinal);
	}

	VM_END

		CLEAR_END

#endif
}

void CProtect::ReleaseBlock(DWORD size) // OK
{
#if(PROTECT_STATE==1)

	CLEAR_START

		VM_START

		static DWORD CheckProtectionValue;

	CHECK_PROTECTION(CheckProtectionValue, 0x10000000)

		if (CheckProtectionValue != 0x10000000)
		{
			memset((void*)& gProtectTable[0], 0, sizeof(gProtectTable));
			memset((void*)& gProtectInsertStart[0], 0, sizeof(gProtectInsertStart));
			memset((void*)& gProtectInsertFinal[0], 0, sizeof(gProtectInsertFinal));
			memset((void*)& gProtectRemoveStart[0], 0, sizeof(gProtectRemoveStart));
			memset((void*)& gProtectRemoveFinal[0], 0, sizeof(gProtectRemoveFinal));
		}

	MODULEINFO ModuleInfo;

	memset(&ModuleInfo, 0, sizeof(ModuleInfo));

	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &ModuleInfo, sizeof(ModuleInfo));

	DWORD start_offset = (DWORD)ModuleInfo.lpBaseOfDll;

	DWORD final_offset = (DWORD)ModuleInfo.lpBaseOfDll + ModuleInfo.SizeOfImage;

	DWORD start_block, final_block;

	while (this->GetRemoveStartBlock(start_offset, final_offset, &start_block) != 0 && this->GetRemoveFinalBlock(start_block, final_offset, &final_block) != 0)
	{
		this->RemoveMemoryMacro((BYTE*)start_block, (BYTE*)& gProtectInsertStart[0], sizeof(gProtectInsertStart));

		this->RemoveMemoryMacro((BYTE*)final_block, (BYTE*)& gProtectInsertFinal[0], sizeof(gProtectInsertFinal));

		this->DecryptBlock((BYTE*)(start_block + sizeof(gProtectRemoveStart)), (final_block - (start_block + sizeof(gProtectRemoveStart))));

		start_offset = final_block + sizeof(gProtectRemoveFinal);
	}

	VM_END

		CLEAR_END

#endif
}

void CProtect::DecryptBlock(BYTE * data, int size) // OK
{
#if(PROTECT_STATE==1)

	VM_START

		DWORD OldProtect;

	VirtualProtect((void*)data, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	for (int n = 0;n < size;n++)
	{
		data[n] = (data[n] ^ gProtectTable[(n % sizeof(gProtectTable))]) - (0xAF ^ (this->m_ComputerHardwareId[(n % sizeof(this->m_ComputerHardwareId))] ^ this->m_AuthInfo.CustomerHardwareId[(n % sizeof(this->m_AuthInfo.CustomerHardwareId))]));
	}

	VirtualProtect((void*)data, size, OldProtect, &OldProtect);

	VM_END

#endif
}

void CProtect::EncryptBlock(BYTE * data, int size) // OK
{
#if(PROTECT_STATE==1)

	VM_START

		DWORD OldProtect;

	VirtualProtect((void*)data, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	for (int n = 0;n < size;n++)
	{
		data[n] = (data[n] + (0xAF ^ (this->m_ComputerHardwareId[(n % sizeof(this->m_ComputerHardwareId))] ^ this->m_AuthInfo.CustomerHardwareId[(n % sizeof(this->m_AuthInfo.CustomerHardwareId))]))) ^ gProtectTable[(n % sizeof(gProtectTable))];
	}

	VirtualProtect((void*)data, size, OldProtect, &OldProtect);

	VM_END

#endif
}

inline void CProtect::InsertMemoryMacro(BYTE * data, BYTE * info, int size) // OK
{
#if(PROTECT_STATE==1)

	DWORD OldProtect;

	VirtualProtect((void*)data, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	for (int n = 0;n < size;n++)
	{
		data[n] = info[n] ^ 0x9F;
	}

	VirtualProtect((void*)data, size, OldProtect, &OldProtect);

#endif
}

inline void CProtect::RemoveMemoryMacro(BYTE * data, BYTE * info, int size) // OK
{
#if(PROTECT_STATE==1)

	DWORD OldProtect;

	VirtualProtect((void*)data, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	for (int n = 0;n < size;n++)
	{
		data[n] = info[n] ^ 0x9F;
	}

	VirtualProtect((void*)data, size, OldProtect, &OldProtect);

#endif
}

inline bool CProtect::VerifyMemoryMacro(BYTE * data, BYTE * info, int size) // OK
{
#if(PROTECT_STATE==1)

	for (int n = 0;n < size;n++)
	{
		if (data[n] != (info[n] ^ 0x9F))
		{
			return 0;
		}
	}

	return 1;

#else

	return 0;

#endif
}

bool CProtect::GetInsertStartBlock(DWORD start_offset, DWORD final_offset, DWORD * start_block) // OK
{
#if(PROTECT_STATE==1)

	ENCODE_START

		bool result = 0;

	MEMORY_BASIC_INFORMATION mbi;

	memset(&mbi, 0, sizeof(MEMORY_BASIC_INFORMATION));

	for (DWORD offset = start_offset;offset < final_offset;offset++)
	{
		if (offset <= (((DWORD)mbi.BaseAddress) + mbi.RegionSize) || VirtualQuery((void*)offset, &mbi, sizeof(mbi)) != 0)
		{
			if ((final_offset - offset) >= sizeof(gProtectInsertStart) && ((((DWORD)mbi.BaseAddress) + mbi.RegionSize) - offset) >= sizeof(gProtectInsertStart))
			{
				if ((mbi.Protect & PAGE_READONLY) != 0 || (mbi.Protect & PAGE_READWRITE) != 0 || (mbi.Protect & PAGE_EXECUTE_READ) != 0 || (mbi.Protect & PAGE_EXECUTE_READWRITE) != 0)
				{
					if (this->VerifyMemoryMacro((BYTE*)offset, (BYTE*)& gProtectInsertStart[0], sizeof(gProtectInsertStart)) != 0)
					{
						(*start_block) = offset;
						result = 1;
						break;
					}
				}
			}
		}
	}

	ENCODE_END

		return result;

#else

	return 0;

#endif
}

bool CProtect::GetInsertFinalBlock(DWORD start_offset, DWORD final_offset, DWORD * final_block) // OK
{
#if(PROTECT_STATE==1)

	ENCODE_START

		bool result = 0;

	MEMORY_BASIC_INFORMATION mbi;

	memset(&mbi, 0, sizeof(MEMORY_BASIC_INFORMATION));

	for (DWORD offset = start_offset;offset < final_offset;offset++)
	{
		if (offset <= (((DWORD)mbi.BaseAddress) + mbi.RegionSize) || VirtualQuery((void*)offset, &mbi, sizeof(mbi)) != 0)
		{
			if ((final_offset - offset) >= sizeof(gProtectInsertFinal) && ((((DWORD)mbi.BaseAddress) + mbi.RegionSize) - offset) >= sizeof(gProtectInsertFinal))
			{
				if ((mbi.Protect & PAGE_READONLY) != 0 || (mbi.Protect & PAGE_READWRITE) != 0 || (mbi.Protect & PAGE_EXECUTE_READ) != 0 || (mbi.Protect & PAGE_EXECUTE_READWRITE) != 0)
				{
					if (this->VerifyMemoryMacro((BYTE*)offset, (BYTE*)& gProtectInsertFinal[0], sizeof(gProtectInsertFinal)) != 0)
					{
						(*final_block) = offset;
						result = 1;
						break;
					}
				}
			}
		}
	}

	ENCODE_END

		return result;

#else

	return 0;

#endif
}

bool CProtect::GetRemoveStartBlock(DWORD start_offset, DWORD final_offset, DWORD * start_block) // OK
{
#if(PROTECT_STATE==1)

	ENCODE_START

		bool result = 0;

	MEMORY_BASIC_INFORMATION mbi;

	memset(&mbi, 0, sizeof(MEMORY_BASIC_INFORMATION));

	for (DWORD offset = start_offset;offset < final_offset;offset++)
	{
		if (offset <= (((DWORD)mbi.BaseAddress) + mbi.RegionSize) || VirtualQuery((void*)offset, &mbi, sizeof(mbi)) != 0)
		{
			if ((final_offset - offset) >= sizeof(gProtectRemoveStart) && ((((DWORD)mbi.BaseAddress) + mbi.RegionSize) - offset) >= sizeof(gProtectRemoveStart))
			{
				if ((mbi.Protect & PAGE_READONLY) != 0 || (mbi.Protect & PAGE_READWRITE) != 0 || (mbi.Protect & PAGE_EXECUTE_READ) != 0 || (mbi.Protect & PAGE_EXECUTE_READWRITE) != 0)
				{
					if (this->VerifyMemoryMacro((BYTE*)offset, (BYTE*)& gProtectRemoveStart[0], sizeof(gProtectRemoveStart)) != 0)
					{
						(*start_block) = offset;
						result = 1;
						break;
					}
				}
			}
		}
	}

	ENCODE_END

		return result;

#else

	return 0;

#endif
}

bool CProtect::GetRemoveFinalBlock(DWORD start_offset, DWORD final_offset, DWORD * final_block) // OK
{
#if(PROTECT_STATE==1)

	ENCODE_START

		bool result = 0;

	MEMORY_BASIC_INFORMATION mbi;

	memset(&mbi, 0, sizeof(MEMORY_BASIC_INFORMATION));

	for (DWORD offset = start_offset;offset < final_offset;offset++)
	{
		if (offset <= (((DWORD)mbi.BaseAddress) + mbi.RegionSize) || VirtualQuery((void*)offset, &mbi, sizeof(mbi)) != 0)
		{
			if ((final_offset - offset) >= sizeof(gProtectRemoveFinal) && ((((DWORD)mbi.BaseAddress) + mbi.RegionSize) - offset) >= sizeof(gProtectRemoveFinal))
			{
				if ((mbi.Protect & PAGE_READONLY) != 0 || (mbi.Protect & PAGE_READWRITE) != 0 || (mbi.Protect & PAGE_EXECUTE_READ) != 0 || (mbi.Protect & PAGE_EXECUTE_READWRITE) != 0)
				{
					if (this->VerifyMemoryMacro((BYTE*)offset, (BYTE*)& gProtectRemoveFinal[0], sizeof(gProtectRemoveFinal)) != 0)
					{
						(*final_block) = offset;
						result = 1;
						break;
					}
				}
			}
		}
	}

	ENCODE_END

		return result;

#else

	return 0;

#endif
}

char* CProtect::GetEncryptedString(int* string, int size) // OK
{
#if(PROTECT_STATE==1)

	VM_START

		static char buff[256];

	memset(buff, 0, sizeof(buff));

	for (int n = 0;n < size;n++)
	{
		buff[n] = string[n] ^ 0xC80;
	}

	VM_END

		return buff;

#else

	return 0;

#endif
}