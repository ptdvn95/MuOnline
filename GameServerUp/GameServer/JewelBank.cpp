#include "StdAfx.h"
#if (JEWEL_BANK == 1)
#include "JewelBank.h"
#include "user.h"
#include "Message.h"
#include "DSProtocol.h"
#include "Notice.h"
#include "ItemManager.h"
#include "Util.h"

JewelsBank gJewelsBank;


void JewelsBank::EnvioJewelsBank(int aIndex)
{

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	// ---
	LPOBJ lpObj = &gObj[aIndex];
	// ---
	PMSG_JEWELSBANK pMsg = { 0 };
	// ---
	pMsg.h.set(0xFB, 0xE5, sizeof(pMsg));
	// ---
#if (JEWEL_BANK == 1)
	pMsg.Zen = lpObj->Zen;
	pMsg.Chaos = lpObj->ChaosBank;
	pMsg.Bless = lpObj->BlessBank;
	pMsg.Soul = lpObj->SoulBank;
	pMsg.Life = lpObj->LifeBank;
	pMsg.CreateonBank = lpObj->CreateonBank;
	pMsg.GuardianBank = lpObj->GuardianBank;
	pMsg.HarmonyBank = lpObj->HarmonyBank;
	pMsg.LowStoneBank = lpObj->LowStoneBank;
	pMsg.HighStoneBank = lpObj->HighStoneBank;
	pMsg.GemStoneBank = lpObj->GemStoneBank;
#endif
	// ---
	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
}

int gObjGetItemCountInInventory(int aIndex, int ItemID, int ItemLevel)
{
	if (aIndex >= 15000)
		return 0;

	LPOBJ lpObj = &gObj[aIndex];

	int Count = 0;
	for (int i = INVENTORY_WEAR_SIZE; i < INVENTORY_SIZE; i++)
	{
		if (lpObj->Inventory[i].m_Index == ItemID && lpObj->Inventory[i].m_Level == ItemLevel)
			Count++;
	}
	return Count;
}

int gObjDeleteItemsCount(int aIndex, short Type, short Level, int dCount)
{
	if (aIndex >= 15000)
		return 0;

	LPOBJ lpObj = &gObj[aIndex];

	int count = 0;
	for (int i = INVENTORY_WEAR_SIZE; i < INVENTORY_SIZE; i++)
	{
		if (lpObj->Inventory[i].m_Index == Type && lpObj->Inventory[i].m_Level == Level)
		{
			gItemManager.InventoryDelItem(lpObj->Index, i);
			gItemManager.GCItemDeleteSend(lpObj->Index, i, 1);
			count++;
			if (dCount == count)
				break;
		}
	}
	return count;
}

int ExCheckInventoryEmptySpace(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	int iEmptyCount = 0;
	for (int x = 0; x<64; x++)
	{
		if (lpObj->InventoryMap[x] == 0xFF)
		{
			iEmptyCount++;
		}
	}

	for (int x = 64; x<96; x++)
	{
		if (lpObj->InventoryMap[x] == 0xFF)
		{
			iEmptyCount++;
		}
	}

	for (int x = 96; x<128; x++)
	{
		if (lpObj->InventoryMap[x] == 0xFF)
		{
			iEmptyCount++;
		}
	}

	return iEmptyCount;
}

void JewelsBank::Load()
{
	this->Enable = GetPrivateProfileInt("JewelsBank", "Enable", 0, JEWELSBANK_DIR);
}

void JewelsBank::JewelBankSlot(JEWELBANKSLOT_RECV* lpMsg,int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	int Slot = lpMsg->slot;

	if(gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	if(lpObj->Interface.use != 0)
	{
		return;
	}

	if(lpObj->ChaosLock != 0)
	{
		return;
	}

	if(INVENTORY_FULL_RANGE(Slot) == 0)
	{
		return;
	}

	if(lpObj->Inventory[Slot].IsItem() == 0)
	{
		return;
	}

	int JewelIndex = this->GetJewelSimpleType(lpObj->Inventory[Slot].m_Index);
	
	if(JewelIndex >= 0)
	{
		int JewelType;
		int JewelCount;
		
		if(JewelIndex >= 10)
		{
			JewelType	= JewelIndex-10;
			JewelCount	= 10*(lpObj->Inventory[Slot].m_Level+1);
		}
		else
		{
			JewelType	= JewelIndex;
			JewelCount	= 1;
		}

		if(JewelCount < 0 || JewelCount > 160)
		{
			return;
		}

		switch(JewelType)
		{
			case 0: // Bless
				this->sendblessbankslot(aIndex, JewelCount, Slot);
			break;
			case 1: // Soul
				this->sendsoulbankslot(aIndex, JewelCount, Slot);
			break;
			case 2: // Life
				this->sendlifebankslot(aIndex, JewelCount, Slot);
			break;
			case 3: // Creation
				this->sendcreateonbankslot(aIndex, JewelCount, Slot);
			break;
			case 4: // Guardian
				this->sendGuardianBankslot(aIndex, JewelCount, Slot);
			break;
			case 5: // Gem Stone
				this->sendGemStoneBankslot(aIndex, JewelCount, Slot);
			break;
			case 6: // Harmony
				this->sendHarmonyBankslot(aIndex, JewelCount, Slot);
			break;
			case 7: // Chaos
				this->sendchaosbankslot(aIndex, JewelCount, Slot);
			break;
			case 8: // Low Stone
				this->sendLowStoneBankslot(aIndex, JewelCount, Slot);
			break;
			case 9: // High Stone
				this->sendHighStoneBankslot(aIndex, JewelCount, Slot);
			break;
		}
	}
}

int JewelsBank::GetJewelSimpleType(int ItemIndex) // OK
{
	switch(ItemIndex)
	{
		case GET_ITEM(14,13):
			return 0;
		case GET_ITEM(14,14):
			return 1;
		case GET_ITEM(14,16):
			return 2;
		case GET_ITEM(14,22):
			return 3;
		case GET_ITEM(14,31):
			return 4;
		case GET_ITEM(14,41):
			return 5;
		case GET_ITEM(14,42):
			return 6;
		case GET_ITEM(12,15):
			return 7;
		case GET_ITEM(14,43):
			return 8;
		case GET_ITEM(14,44):
			return 9;
		case GET_ITEM(12,30): // Bundled Jewel of Bless
			return 10;
		case GET_ITEM(12,31): // Bundled Jewel of Soul
			return 11;
		case GET_ITEM(12,136): // Bundled Jewel of Life
			return 12;
		case GET_ITEM(12,137): // Bundled Jewel of Creation
			return 13;
		case GET_ITEM(12,138): // Bundled Jewel of Guardian
			return 14;
		case GET_ITEM(12,139): // Bundled Gemstone
			return 15;
		case GET_ITEM(12,140): // Bundled Jewel of Harmony
			return 16;
		case GET_ITEM(12,141): // Bundled Jewel of Chaos
			return 17;
		case GET_ITEM(12,142): // Bundled Lower Refining Stone
			return 18;
		case GET_ITEM(12,143): // Bundled Higer Refining Stone
			return 19;
	}

	return -1;
}

//-----------------------------------------------------
void JewelsBank::sendzen(int aIndex, int Count)
{
	LPOBJ lpUser = &gObj[aIndex];
	unsigned int M = 1000000 * Count;
	if (M > lpUser->Money) return;
	lpUser->Money -= M;
	lpUser->Zen += Count;
	GCMoneySend(aIndex, lpUser->Money);
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
}

void JewelsBank::sendchaosbank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(12, 15), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Chaos", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(12, 15), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->ChaosBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Chaos", Count);
}

void JewelsBank::sendchaosbankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(12, 15), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->ChaosBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Chaos", Count);
}

void JewelsBank::sendblessbank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 13), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Bless", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 13), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->BlessBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Bless", Count);
}

void JewelsBank::sendblessbankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 13), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->BlessBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Bless", Count);
}

void JewelsBank::sendsoulbank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 14), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Soul", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 14), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->SoulBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Soul", Count);
}

void JewelsBank::sendsoulbankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 14), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->SoulBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Soul", Count);
}

void JewelsBank::sendlifebank(int aIndex, int Count)
{
	if (!this->Enable) return;

	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 16), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Life", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 16), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->LifeBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Life", Count);
}

void JewelsBank::sendlifebankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 16), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->LifeBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Life", Count);
}

void JewelsBank::sendcreateonbank(int aIndex, int Count)
{
	if (!this->Enable) return;

	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 22), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Createon", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 22), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->CreateonBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Createon", Count);
}

void JewelsBank::sendcreateonbankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 22), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->CreateonBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Creation", Count);
}

void JewelsBank::sendGuardianBank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 31), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Guardian", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 31), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->GuardianBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Guardian", Count);
}

void JewelsBank::sendGuardianBankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 31), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->GuardianBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Guardian", Count);
}

void JewelsBank::sendHarmonyBank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 42), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d Harmony", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 42), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->HarmonyBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Harmony", Count);
}

void JewelsBank::sendHarmonyBankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 42), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->HarmonyBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d Harmony", Count);
}

void JewelsBank::sendLowStoneBank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 43), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d LowStone", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 43), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->LowStoneBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d LowStone", Count);
}

void JewelsBank::sendLowStoneBankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 43), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->LowStoneBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d LowStone", Count);
}

void JewelsBank::sendHighStoneBank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 44), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d HighStone", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 44), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->HighStoneBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d HighStone", Count);
}

void JewelsBank::sendHighStoneBankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 44), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->HighStoneBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d HighStone", Count);
}

void JewelsBank::sendGemStoneBank(int aIndex, int Count)
{
	if (!this->Enable) return;
	if (gObjGetItemCountInInventory(aIndex, GET_ITEM(14, 41), 0) < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Need %d GemStoneBank", Count);
		return;
	}
	gObjDeleteItemsCount(aIndex, GET_ITEM(14, 41), 0, Count);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->GemStoneBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d GemStoneBank", Count);
}

void JewelsBank::sendGemStoneBankslot(int aIndex, int Count, int slot)
{
	if (!this->Enable) return;
	// gObjDeleteItemsCount(aIndex, GET_ITEM(14, 41), 0, Count);
	gItemManager.InventoryDelItem(aIndex,slot);
	gItemManager.GCItemDeleteSend(aIndex,slot,1);
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->GemStoneBank += Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Send %d GemStoneBank", Count);
}

//-----------------------------------------------------
void JewelsBank::recvzen(int aIndex, int Count)
{
	LPOBJ lpUser = &gObj[aIndex];
	int M = 1000000;
	unsigned long long totalzen = M + lpUser->Money;
	if (totalzen > 2000000000) return;
	if (Count > lpUser->Zen) return;
	lpUser->Money += M;
	lpUser->Zen -= Count;
	GCMoneySend(aIndex, lpUser->Money);
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
}

void JewelsBank::recvchaosbank(int aIndex, int Count)
{
	if (!this->Enable) return;
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->ChaosBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Chaos", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(12, 15), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->ChaosBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Chaos", Count);
}

void JewelsBank::recvblessbank(int aIndex, int Count)
{
	if (!this->Enable) return;
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->BlessBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Bless", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 13), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->BlessBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Bless", Count);
}

void JewelsBank::recvsoulbank(int aIndex, int Count)
{
	if (!this->Enable) return;
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->SoulBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Soul", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 14), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->SoulBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Soul", Count);
}

void JewelsBank::recvlifebank(int aIndex, int Count)
{
	if (!this->Enable) return;

	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->LifeBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Life", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 16), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->LifeBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Life", Count);
}

void JewelsBank::recvcreateonbank(int aIndex, int Count)
{
	if (!this->Enable) return;

	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->CreateonBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Createon", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 22), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->CreateonBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Createon", Count);
}

void JewelsBank::recvGuardianBank(int aIndex, int Count)
{
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->GuardianBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Guardian", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 31), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->GuardianBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Guardian", Count);
}

void JewelsBank::recvHarmonyBank(int aIndex, int Count)
{
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->HarmonyBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d Harmony", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 42), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->HarmonyBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d Harmony", Count);
}

void JewelsBank::recvLowStoneBank(int aIndex, int Count)
{
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->LowStoneBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d LowStone", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 43), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->LowStoneBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d LowStone", Count);
}

void JewelsBank::recvHighStoneBank(int aIndex, int Count)
{
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->HighStoneBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d HighStone", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 44), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->HighStoneBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d HighStone", Count);
}

void JewelsBank::recvGemStoneBank(int aIndex, int Count)
{
	LPOBJ lpObj = &gObj[aIndex];
	if (lpObj->GemStoneBank < Count)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] No %d GemStone", Count);
		return;
	}
	if (Count == 3)
	{
		if (gItemManager.CountEmptySlot(lpObj) < 3)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	else
	{
		if (gItemManager.CheckItemInventorySpace(lpObj, 1, 1) == 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Inventory %d", Count);
			return;
		}
	}
	for (int i = 0; i<Count; i++)
	{
		GDCreateItemSend(aIndex, 235, lpObj->X, lpObj->Y, GET_ITEM(14, 41), 0, 0, 0, 0, 0, aIndex, 0, 0, 0, 0, 0, 0, 0);
	}
	lpObj->GemStoneBank -= Count;
	EnvioJewelsBank(aIndex);
	GDCharacterInfoSaveSend(aIndex);
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[JewelsBank] Recv %d GemStone", Count);
}

//------------------------------------------------------------------
void JewelsBank::Packet(int aIndex, PMSG_JEWELBANK* lpMsg)
{
	if (!this->Enable)
	{
		return;
	}

	if (!OBJMAX_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpUser = &gObj[aIndex];

	if (lpUser->Interface.type == INTERFACE_CHAOS_BOX)  // FIX DUP JEWELS BY MAXVOLL :D
	{
		return;
	}

	switch (lpMsg->Result)
	{
	case 0:
		this->sendzen(aIndex, 1);
		break;
	case 1:
		this->sendchaosbank(aIndex, 1);
		break;
	case 2:
		this->sendblessbank(aIndex, 1);
		break;
	case 3:
		this->sendsoulbank(aIndex, 1);
		break;
	case 4:
		this->sendlifebank(aIndex, 1);
		break;
	case 5:
		this->sendcreateonbank(aIndex, 1);
		break;
	case 6:
		this->sendGuardianBank(aIndex, 1);
		break;
	case 7:
		this->sendHarmonyBank(aIndex, 1);
		break;
	case 8:
		this->sendLowStoneBank(aIndex, 1);
		break;
	case 9:
		this->sendHighStoneBank(aIndex, 1);
		break;
	case 10:
		this->sendGemStoneBank(aIndex, 1);
		break;

	case 11:
		this->recvzen(aIndex, 1);
		break;
	case 12:
		this->recvchaosbank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 13:
		this->recvblessbank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 14:
		this->recvsoulbank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 15:
		this->recvlifebank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 16:
		this->recvcreateonbank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 17:
		this->recvGuardianBank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 18:
		this->recvHarmonyBank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 19:
		this->recvLowStoneBank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 20:
		this->recvHighStoneBank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	case 21:
		this->recvGemStoneBank(aIndex, lpMsg->Triple ? 3 : 1);
		break;
	}
}
#endif
