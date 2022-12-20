#pragma once
#if (JEWEL_BANK == 1)

#include "StdAfx.h"
#include "DSProtocol.h"

#define JEWELSBANK_DIR	"..\\Data\\Custom\\JewelsBank.ini"

struct PMSG_JEWELBANK
{
	PSBMSG_HEAD h;
	int Result;
};

struct PMSG_JEWELSBANK
{
#pragma pack(1)
	PSBMSG_HEAD h;
#if (JEWEL_BANK == 1)
	int Zen;
	int Chaos;
	int Bless;
	int Soul;
	int Life;
	int CreateonBank;
	int GuardianBank;
	int HarmonyBank;
	int LowStoneBank;
	int HighStoneBank;
	int GemStoneBank;
#endif
#pragma pack()
};

struct JEWELBANKSLOT_RECV
{
	PSBMSG_HEAD header; // C1:F3:F4
	int slot;
};

class JewelsBank
{
public:
	void Load();
	void EnvioJewelsBank(int aIndex);
	bool CheckItemInventorySpace(LPOBJ lpObj, int index);
	void JewelBankSlot(JEWELBANKSLOT_RECV* lpMsg,int aIndex);
	int GetJewelSimpleType(int ItemIndex);
	//Send
	void sendzen(int aIndex, int Count);
	void sendchaosbank(int aIndex, int Count);
	void sendblessbank(int aIndex, int Count);
	void sendsoulbank(int aIndex, int Count);
	void sendlifebank(int aIndex, int Count);
	void sendcreateonbank(int aIndex, int Count);
	void sendGuardianBank(int aIndex, int Count);
	void sendHarmonyBank(int aIndex, int Count);
	void sendLowStoneBank(int aIndex, int Count);
	void sendHighStoneBank(int aIndex, int Count);
	void sendGemStoneBank(int aIndex, int Count);

	// Slot
	void sendchaosbankslot(int aIndex, int Count, int slot);
	void sendblessbankslot(int aIndex, int Count, int slot);
	void sendsoulbankslot(int aIndex, int Count, int slot);
	void sendlifebankslot(int aIndex, int Count, int slot);
	void sendcreateonbankslot(int aIndex, int Count, int slot);
	void sendGuardianBankslot(int aIndex, int Count, int slot);
	void sendHarmonyBankslot(int aIndex, int Count, int slot);
	void sendLowStoneBankslot(int aIndex, int Count, int slot);
	void sendHighStoneBankslot(int aIndex, int Count, int slot);
	void sendGemStoneBankslot(int aIndex, int Count, int slot);

	// Reck
	void recvzen(int aIndex, int Count);
	void recvchaosbank(int aIndex, int Count);
	void recvblessbank(int aIndex, int Count);
	void recvsoulbank(int aIndex, int Count);
	void recvlifebank(int aIndex, int Count);
	void recvcreateonbank(int aIndex, int Count);
	void recvGuardianBank(int aIndex, int Count);
	void recvHarmonyBank(int aIndex, int Count);
	void recvLowStoneBank(int aIndex, int Count);
	void recvHighStoneBank(int aIndex, int Count);
	void recvGemStoneBank(int aIndex, int Count);

	void Packet(int aIndex, PMSG_JEWELBANK* lpMsg);
private:
	bool Enable;
	int m_LastPosX;
	int m_LastPosY;
};
extern JewelsBank gJewelsBank;

#endif