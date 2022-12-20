#include "stdafx.h"
#include "Protocol.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRankUser.h"
#include "Ranking.h"
#include "HealthBar.h"
#include "Interface.h"
#include "ItemShopValue.h"
#include "Offset.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"
#include "post_item.h"
#include "postInterface.h"
#include "PetProtocol.h"
#include "StatsAdvance.h"
#include "User.h"
#include "PartyBuffs.h"
#include "BuffIcon.h"
#include "Ruud.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "InterEx.h"
#include "JewelryBank.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "ResetSystem.h"
#include "ShopSearch.h"
#include "ConnectServer.h"
#include "Achievements.h"
#include "SmithItem.h"
#include "WindowsQuest.h"
#include "ResetSystemPanel.h"
#include "GrandResetSystem.h"
#include "PartyBar.h"
#include "HWID.h"
#include "CustomJewelBank.h"

BOOL ProtocolCoreEx(BYTE head,BYTE* lpMsg,int size,int key) // OK
{
	switch(head)
	{
		case 0x11:
			GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
			break;
			//bug no bug
		//case 0x16:
			//GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
			//break;
		case 0x17:
			GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
			break;
		case 0x26:
			GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
			break;
		case 0x27:
			GCManaRecv((PMSG_MANA_RECV*)lpMsg);
			break;
		case 0x2C:
			GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
			break;
			//no bug
		case 0x9C:
			GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
			break;
		case 0xA3:
			GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
			break;
		case 0xB1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gIconBuff.DeleteAllBuff();
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
					break;
				case 0x01:
					gIconBuff.DeleteAllBuff();
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
					break;
			}
			break;
		case 0xF1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gHwid.SendHwid();
					GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					break;
				case 0x01:
					GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					break;
				case 0x02:
					GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
					break;
			}
			break;
		case 0xF3:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gIconBuff.DeleteAllBuff();
					isHiddenPlayer = 0;
					GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
					break;
				case 0x03:
					GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
					break;
				case 0x04:
					GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
					break;
				case 0x05:
					GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0x06:
					GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
					break;
				case 0x07:
					GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
					break;
				case 0x50:
					GCMasterInfoRecv((PMSG_MASTER_INFO_RECV*)lpMsg);
					break;
				case 0x51:
					GCMasterLevelUpRecv((PMSG_MASTER_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0xE0:
					GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
					return 1;
				case 0xE1:
					GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
					return 1;
				case 0xE2:
					GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					return 1;
				case 0xE3:
					GCNewGensBattleInfoRecv((PMSG_NEW_GENS_BATTLE_INFO_RECV*)lpMsg);
					return 1;
				case 0xE4:
					GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
					return 1;
				case 0xE5:
					gCustomRankUser.GCReqRankLevelUser((PMSG_CUSTOM_RANKUSER*)lpMsg);
					return 1;				case 0xE8:
					gCustomEventTime.GCReqEventTime((PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
					return 1;
				case 0xE9:
					gItemPrice.GCItemValueRecv((PMSG_ITEM_VALUE_RECV*)lpMsg);
					return 1;
				case 0xEA:
					GCRecvCoin((PMSG_COIN_RECV*)lpMsg);
					return 1;
				case 0xEB:
					gOffTrade.RecvPShop((PMSG_OFFTRADE_RECV*)lpMsg);
					return 1;
				case 0xEC:
					gOffTrade.PShopActiveRecv((PMSG_SHOPACTIVE_RECV*)lpMsg);
					return 1;
				case 0xED:
					GCBuyConfirmRecv((PMSG_ITEM_BUY_RECV*)lpMsg);
					break;
				case 0xEE:
					SetChaosBoxState((PMSG_SET_CHAOSBOX_STATE*)lpMsg);
				return 1;
				//--------------cosas de pet
				case 0xF1:
					GCPetCharSetRecv((PMSG_NEW_PET_CHARSET_RECV*)lpMsg);
					break;
				case 0xF2:
					GCPetCharSetSelectCharacterRecv((PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV*)lpMsg);
					break;
				// ADVANCE STATS
				case 0xF3:
					g_StatsAdvance.Recv((PMSG_STATS_ADVANCE*)lpMsg);
					return 1;
				// MasterSkill
				case 0xF4:
					gCRenderEx700.RecvMasterSkill((PMSG_MASTER_SKILL_LIST_SEND *)lpMsg);
					return 1;
				case 0xF7:
					gCustomJewelBank.GCCustomJewelBankInfoRecv((PSBMSG_JEWELBANK_RECV*)lpMsg);
					return 1;
				case 0x13:
					gIconBuff.GC_BuffInfo((PMSG_SEND_BUFF_ICON_EX*)lpMsg);
					break;
					break;
				case 0xF9:
					gMiniMap.RecvPartyInfo((MINIMAP_PARTY_INFO_RECV*)lpMsg);
				break;
#if (WARE==1)
				case 0x0D:
					GCWarehouseInterfaceOpenRecv((PMSG_WAREHOUSEINTERFACE_RECV*)lpMsg);
					break;
#endif
					// partysearch
				case 0xF0:
					GCPartyListRecv((PMSG_RECV_PARTYLIST*)lpMsg);
					return 1;
			}
			break;
		case 0xFF:
			gInterface.DrawPing();
			break;
			//-- Open Ruud
		case 0xEE:
			jCRenderRuud.OpenRuudShop_Recv((PMSG_NPC_TALK_RECV*)lpMsg);
			return 1;
		case 0x7D:
			jCRenderRuud.LoadRuudShop_Recv((PMSG_RUUD_ITEM_LIST_RECV*)lpMsg);
			break;
			//--post item
		case 0x78:
			RecvPostItem((PMSG_POSTITEM*)lpMsg);
			break;
		//-- Buff Icon
		case 0x2D:
			gIconBuff.Recv((PMSG_SEND_BUFF_ICON * )lpMsg);
			break;
			//-- Party Buff
		case 0x2E:
			gPartyBuffs.RecvPartyBuffs((PMSG_PARTY_EFFECT_LIST_SEND*)lpMsg);
			break;
		case 0xFE:
			gRanking.RecvInfo((DGCharTop*)lpMsg);
			break;
#if (takumi12 == 1)
		case 0x79:
			gCentral.CGPartyLifeRecv((PMSG_PARTY_LIFE_SEND *) lpMsg);
			break;
		case 0x7A:
			gCentral.CGPartyListRecv((PMSG_PARTY_LIST_SEND *) lpMsg);
				break;
#endif
		case 0xF4:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4])){
#if(IN_DEV ==1)
			case 0x3:
				ConnectServer.ServerInfoRecv(lpMsg);
				break;
			case 0x5:
				break;
			case 0x6:
				ConnectServer.ServerListRecv(lpMsg);
				break;
#endif
			}
			break;
		case 0xFB:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0x01:
				gResetSystem.set_data((RESET_ANS_USERDATA*)lpMsg);
				return 1;
			case 0x02:
				gResetSystem.get_reset_result();
				return 1;
			case 0x03:
				gGrandResetSystem.set_data((GR_ANS_USERDATA*)lpMsg);
				return 1;
			case 0x04:
				gGrandResetSystem.get_reset_result();
				return 1;
			case 0x05:
				ResetSystem::reset_message_recv(reinterpret_cast<RESET_RESULT_SEND*>(lpMsg));
				return 1;
			case 0x12:
				gPartySearchSettings.GCPartySettingsRecv((PMSG_PARTYSETTINGS_RECV*)lpMsg);
				break;
			case 0x19:
				gSmithItem.GetInfo((SDHP_SENDSVSHOP*)lpMsg);
				break;
			case 0x23:
				UpdateLuckyWheel((ITEM_WIN_SEND*)lpMsg);
				break;
			case 0xE5:
				gJewelsBank.RecibirJewelsBank((PMSG_JEWELSBANK*)lpMsg);
				break;
			case 0xE6:
				gResetChange.RecibirResetChange((PMSG_RESET_CHANGE*)lpMsg);
				break;
			case 0xE7:
				gLuckyWheel.RecibirCostoWheel((PMSG_LUCKY_WHEEL*)lpMsg);
				break;
			case 0xE8:
				RecibirPanelMenu((PANEL_MENU*)lpMsg);
				break;
#if (ARCHIVEMENT == 1)
			case 0x0C:
				gAchievements.GCPlayerData((PMSG_GC_ACH_PLAYER_DATA*)lpMsg);
				return 1;
			case 0x0D:
				gAchievements.GCCalculatorPower((PMSG_GC_ACH_POWER*)lpMsg);
				return 1;
			case 0x0F:
				gAchievements.GCConfigData((PMSG_GC_ACH_SETTINGS_DATA*)lpMsg);
				return 1;
#endif
			
			case 0x10:
				g_ExWinQuestSystem.GC_MiniInfoRecvEx((GC_ExWinMiniInfoEx*)lpMsg); //0xFD, 0x13
				return 1;
			case 0x11:
				g_ExWinQuestSystem.GC_Start((GC_ExWinStart*)lpMsg); //0xFD, 0x14
				return 1;
			case 0x14:
				g_ExWinQuestSystem.GC_RecvMain((GC_MainPacket*)lpMsg); //0xFF, 0x0C
				return 1;
			case 0x13:
				g_ExWinQuestSystem.GC_MiniInfoRecv((GC_ExWinMiniInfo*)lpMsg); //0xFF, 0x0D
				return 1;
			}
			break;
		case 0xFA:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0x09:
				g_PersonalShopEx.GC_Recv(lpMsg);
				break;
			}
			break;
	}

	return ProtocolCore(head,lpMsg,size,key);
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;

	if((lpMsg->type & 0x10) != 0)
	{
		if(ViewDamageCount < 3)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}

	if((lpMsg->type & 0x20) != 0)
	{
		if(ViewDamageCount < 4)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP==0)?ViewCurHP:lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if(lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewValue = lpMsg->ViewValue;
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	gObjUser.Refresh();
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMove(lpMsg->IpAddress,lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	ViewIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ObjectDir = lpMsg->Dir;
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;

	

	*(WORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x07E) = 0;

	*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x30C) = 0;

	switch(((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7))
	{
		case 0:
			SetByte(0x00556C38,((gProtect.m_MainInfo.DWMaxAttackSpeed>=0xFFFF)?0x06:0x0F));
			break;
		case 1:
			SetByte(0x00556C38,((gProtect.m_MainInfo.DKMaxAttackSpeed>=0xFFFF)?0x06:0x0F));;
			break;
		case 2:
			SetByte(0x00556C38,((gProtect.m_MainInfo.FEMaxAttackSpeed>=0xFFFF)?0x06:0x0F));
			break;
		case 3:
			SetByte(0x00556C38,((gProtect.m_MainInfo.MGMaxAttackSpeed>=0xFFFF)?0x06:0x0F));
			break;
		case 4:
			SetByte(0x00556C38,((gProtect.m_MainInfo.DLMaxAttackSpeed>=0xFFFF)?0x06:0x0F));
			break;
		case 5:
			SetByte(0x00556C38,((gProtect.m_MainInfo.SUMaxAttackSpeed>=0xFFFF)?0x06:0x0F)); 
			break;
		case 6:
			SetByte(0x00556C38,((gProtect.m_MainInfo.RFMaxAttackSpeed>=0xFFFF)?0x06:0x0F));
			break;
	}
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;

	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66);
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if(lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCMasterInfoRecv(PMSG_MASTER_INFO_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;

}

void GCMasterLevelUpRecv(PMSG_MASTER_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewMasterExperience = lpMsg->ViewMasterExperience;
	ViewMasterNextExperience = lpMsg->ViewMasterNextExperience;

	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66);
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E) = lpMsg->Level;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) = lpMsg->LevelUpPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x18) = lpMsg->Strength;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1A) = lpMsg->Dexterity;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1C) = lpMsg->Vitality;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1E) = lpMsg->Energy;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x20) = lpMsg->Leadership;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x22) = lpMsg->Life;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x26) = lpMsg->MaxLife;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x24) = lpMsg->Mana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x28) = lpMsg->MaxMana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x40) = lpMsg->BP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x42) = lpMsg->MaxBP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2A) = lpMsg->Shield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2C) = lpMsg->MaxShield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4C) = lpMsg->FruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4E) = lpMsg->MaxFruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x50) = lpMsg->FruitSubPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x52) = lpMsg->MaxFruitSubPoint;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x10) = lpMsg->Experience;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x14) = lpMsg->NextExperience;

	//EXTRA
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiDamageMin = lpMsg->ViewPhysiDamageMin;
	ViewPhysiDamageMax = lpMsg->ViewPhysiDamageMax;
	ViewMagicDamageMin = lpMsg->ViewMagicDamageMin;
	ViewMagicDamageMax = lpMsg->ViewMagicDamageMax;
	ViewCurseDamageMin = lpMsg->ViewCurseDamageMin;
	ViewCurseDamageMax = lpMsg->ViewCurseDamageMax;
	ViewMulPhysiDamage = lpMsg->ViewMulPhysiDamage;
	ViewDivPhysiDamage = lpMsg->ViewDivPhysiDamage;
	ViewMulMagicDamage = lpMsg->ViewMulMagicDamage;
	ViewDivMagicDamage = lpMsg->ViewDivMagicDamage;
	ViewMulCurseDamage = lpMsg->ViewMulCurseDamage;
	ViewDivCurseDamage = lpMsg->ViewDivCurseDamage;
	ViewMagicDamageRate = lpMsg->ViewMagicDamageRate;
	ViewCurseDamageRate = lpMsg->ViewCurseDamageRate;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewAttackSuccessRate = lpMsg->ViewAttackSuccessRate;
	ViewAttackSuccessRatePvP = lpMsg->ViewAttackSuccessRatePvP;
	ViewDefense = lpMsg->ViewDefense;
	ViewDefenseSuccessRate = lpMsg->ViewDefenseSuccessRate;
	ViewDefenseSuccessRatePvP = lpMsg->ViewDefenseSuccessRatePvP;
	ViewDamageMultiplier = lpMsg->ViewDamageMultiplier;
	ViewRFDamageMultiplierA = lpMsg->ViewRFDamageMultiplierA;
	ViewRFDamageMultiplierB = lpMsg->ViewRFDamageMultiplierB;
	ViewRFDamageMultiplierC = lpMsg->ViewRFDamageMultiplierC;
	ViewDarkSpiritAttackDamageMin = lpMsg->ViewDarkSpiritAttackDamageMin;
	ViewDarkSpiritAttackDamageMax = lpMsg->ViewDarkSpiritAttackDamageMax;
	ViewDarkSpiritAttackSpeed = lpMsg->ViewDarkSpiritAttackSpeed;
	ViewDarkSpiritAttackSuccessRate = lpMsg->ViewDarkSpiritAttackSuccessRate;
}

void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for(int n=0;n < lpMsg->count;n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg)+sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(PMSG_NEW_HEALTH_RECV)*n));

#if (HPTYPE == 1)
		InsertNewHealthBar(lpInfo);
#else
		InsertNewHealthBar(lpInfo->index,lpInfo->type,lpInfo->rate,lpInfo->rate2);
#endif
	}
}

void GCNewGensBattleInfoRecv(PMSG_NEW_GENS_BATTLE_INFO_RECV* lpMsg) // OK
{
	GensBattleMapCount = lpMsg->GensBattleMapCount;

	GensMoveIndexCount = lpMsg->GensMoveIndexCount;

	memcpy(GensBattleMap,lpMsg->GensBattleMap,sizeof(GensBattleMap));

	memcpy(GensMoveIndex,lpMsg->GensMoveIndex,sizeof(GensMoveIndex));
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{

}

//Cashshop Fix
void OpenCashShopSend(BYTE type)
{
	PMSG_CASH_SHOP_OPEN_RECV pMsg;
	pMsg.OpenType = type;
	pMsg.header.set(0xD2,0x02,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}

bool CashShopSwitchState()
{
	sub_861900_Addr((int)pWindowThis());

	if ( !sub_944E50_Addr() )
		return 0;

	void* v48 = sub_93F370_Addr();

	if ( sub_93FCA0_Addr((int)v48) == 1 )
	{
		if ( !sub_93F600_Addr((CHAR *)sub_93F370_Addr()) )
			return 0;
	}

	if ( sub_93FD10_Addr((int)sub_93F370_Addr()) == 1 )
	{
		if ( sub_93F950_Addr((CHAR *)sub_93F370_Addr()) == 1 )
		{
			BYTE* v53 = (BYTE *)sub_941030_Addr((BYTE*)sub_93F370_Addr());
			int v55 = sub_941000_Addr((BYTE*)sub_93F370_Addr());
			BYTE* v57 = (BYTE *)sub_861900_Addr((int)pWindowThis());
			sub_944FE0_Addr(v57, v55, v53);
		}
	}

	if ( pCheckWindow(pWindowThis(), 65) )
	{
		OpenCashShopSend(1);
		pCloseWindow(pWindowThis(), 65);
	}
	else
	{
		if ( !sub_9406C0_Addr((BYTE*)sub_93F370_Addr()) )
		{
			OpenCashShopSend(0);
			sub_9406A0_Addr((BYTE*)sub_93F370_Addr(), 1);
			char* v62 = (char *)sub_8611E0_Addr((DWORD*)pWindowThis());
			sub_815130_Addr(v62, 0, 1);
		}
	}
}

void DataSend(BYTE* lpMsg,DWORD size) // OK
{
	BYTE EncBuff[2048];

	if(gPacketManager.AddData(lpMsg,size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send,EncBuff,size);

		if(EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if(EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[2],&EncBuff[1],(size-1))+2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3],&EncBuff[2],(size-2))+3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*,BYTE*,DWORD))0x00405110)((void*)0x08793750,send,size);
	}
}

void GCRecvCoin(PMSG_COIN_RECV* lpMsg) // OK
{
	Coin1 = lpMsg->Coin1;
	Coin2 = lpMsg->Coin2;
	Coin3 = lpMsg->Coin3;
	Ruud = lpMsg->Ruud;
}

void GCBuyConfirmRecv(PMSG_ITEM_BUY_RECV* lpMsg) // OK
{
	gInterface.Data[eCONFIRM_MAIN].OnShow = true;
	pSetCursorFocus = true;
	gInterface.ConfirmSlot = lpMsg->slot;
}

//======================================= lo nuevo
//--post item
bool RecvPostItem(PMSG_POSTITEM * lpMsg) {

	void * item_post = PostItem::AddItem ( &lpMsg->item_data[0] );

	if ( item_post == nullptr ) { return false; }

	char Name[11] = { '\0' };
	char Messase[61] = { '\0' };
	char Messase_API[70] = { '\0' };
	memcpy_s ( &Name[0], 10, &lpMsg->chatid[0], 10 );
	memcpy_s ( &Messase[0], 60, &lpMsg->chatmsg[0], 60 );
	int len = strlen ( Messase );
	// ----
	// Cat text Excillent
	if ( ( BYTE ) Messase[0] == 0xC4 &&
			( BYTE ) Messase[1] == 0x90 &&
			( BYTE ) Messase[2] == 0xE1 &&
			( BYTE ) Messase[3] == 0xBB &&
			( BYTE ) Messase[4] == 0x93 &&
			( BYTE ) Messase[5] == 0x20 &&
			( BYTE ) Messase[6] == 0x68 &&
			( BYTE ) Messase[7] == 0x6F &&
			( BYTE ) Messase[8] == 0xC3 &&
			( BYTE ) Messase[9] == 0xA0 &&
			( BYTE ) Messase[10] == 0x6E &&
			( BYTE ) Messase[11] == 0x20 &&
			( BYTE ) Messase[12] == 0x68 &&
			( BYTE ) Messase[13] == 0xE1 &&
			( BYTE ) Messase[14] == 0xBA &&
			( BYTE ) Messase[15] == 0xA3 &&
			( BYTE ) Messase[16] == 0x6F &&
			( BYTE ) Messase[17] == 0x20 ) {
		strcpy_s ( &Messase[0], 61, &Messase[18] );
	}
	// Cat bot ten neu qua dai
	if ( len > 35 ) {
		for ( int i = 30; i < len; ++i ) {
			if ( isalpha ( Messase[i] ) || Messase[i] == ' ' ) {
				Messase[i] = '.';
				Messase[i + 1] = '.';
				Messase[i + 2] = '.';
				Messase[i + 3] = '\0';
			}
		}
	}
	//push this node to eItemNode
	for (int i = 0; i < 19; i++)
	{
		gPostItem.eItemNode[i] = gPostItem.eItemNode[i + 1];
	}
	gPostItem.eItemNode[19] = (DWORD)item_post;
	//end eItemNode
	sprintf_s( Messase_API, "[SELL] %s_[%08X]", Messase, (DWORD)item_post);
	gPostItem.draw_character_head_chat_text_ = true;
	newInterface::DrawChat ( gPostItem.PostItemColor, &Name[0], &Messase_API[0] );
	// ----

	if ( !gPostItem.draw_character_head_chat_text_ ) 
	{ // da lay duoc base_address
		// xu ly doan chat tren dau nhan vat
		char message[256] = { 0 };
		char * chat_text_first = CharacterHeadChatTextFirst ( gPostItem.draw_character_head_chat_text_base_address_ );
		char * chat_text_last = CharacterHeadChatTextLast ( gPostItem.draw_character_head_chat_text_base_address_ );
		unsigned long msgfirst_len = strlen ( chat_text_first );
		unsigned long msglast_len = strlen ( chat_text_last );
		strcpy_s ( message, sizeof ( message ), chat_text_first );
		strcat_s ( message, chat_text_last );
		unsigned long message_len = strlen ( message );

		if ( message[message_len - 1 - 8 - 2] != '_' ||
				message[message_len - 1 - 8 - 1] != '[' ||
				message[message_len - 1] != ']' ) 
		{
		}
		else 
		{
			message[message_len - 1 - 8 - 2] = '\0';  // cat bo doan duoi

			// copy lai
			if ( msgfirst_len ) 
			{
				memcpy_s ( chat_text_first, 0x50, message, msgfirst_len );
				chat_text_first[msgfirst_len] = '\0';
			}

			if ( msglast_len ) 
			{
				memcpy_s ( chat_text_last, 0x50, &message[msgfirst_len], msglast_len );
				chat_text_last[msglast_len] = '\0';
			}
		}
	}
	return true;
}

//--- pet
void GCPetCharSetRecv(PMSG_NEW_PET_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSet();

	for (int n = 0; n < lpMsg->count; n++)
	{
		NEW_PET_STRUCT* lpInfo = (NEW_PET_STRUCT*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_PET_CHARSET_RECV)+(sizeof(NEW_PET_STRUCT)*n));

		InsertNewPetCharSet(lpInfo->index, lpInfo->PetCharSet);
	}
}

void GCPetCharSetSelectCharacterRecv(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSetSelectCharacter();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_CHARACTER_CHARSET_RECV* lpInfo = (PMSG_NEW_CHARACTER_CHARSET_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV)+(sizeof(PMSG_NEW_CHARACTER_CHARSET_RECV)*n));

		InsertNewPetCharSetSelectCharacter(lpInfo->Name, lpInfo->PetCharSet);
	}
}

void SetChaosBoxState(PMSG_SET_CHAOSBOX_STATE* Data){
	pChaosBoxState = Data->state;
	return;
}

//============ RUUD
//void OpenRuudShop_Recv(PMSG_NPC_TALK_SEND * lpMsg)
//{
//	if(lpMsg->result == 150)
//	{
//		gCRuudShop.OpenWindows();

//		if(!pCheckWindow(pWindowThis(), 13))
//		{
//			pOpenWindow(pWindowThis(), 13);
//		}
//	}
//}

#if (WARE==1)
void GCWarehouseInterfaceOpenRecv(PMSG_WAREHOUSEINTERFACE_RECV* lpMsg)
{
	gObjUser.m_MaxWarehouse = lpMsg->MaxWarehouse;
	gInterface.Data[eWAREHOUSE_MAIN].Open(MAX_WIN_HEIGHT, 20);
	gInterface.Data[eWAREHOUSE_MAIN].EventTick = GetTickCount();
}

void CGSendWarehouseOpen(int Number)
{
	PMSG_WAREHOUSEINTERFACE_SEND pMsg;
	pMsg.header.set(0xFD, 0x0B, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}
#endif

void GCPartyListRecv(PMSG_RECV_PARTYLIST* lpMsg)
{
	gPartySearch.ClearPartyList();

	for (int n = 0; n<lpMsg->Count; n++)
	{
		PMSG_PARTYSEARCH_PARTYLIST* lpInfo = (PMSG_PARTYSEARCH_PARTYLIST*)(((BYTE*)lpMsg) + sizeof(PMSG_RECV_PARTYLIST) + (sizeof(PMSG_PARTYSEARCH_PARTYLIST)*n));

		gPartySearch.InsertPartyList(lpInfo);
	}

	gInterface.SwitchPartySearchWindowState();
}

void RecibirPanelMenu(PANEL_MENU * aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}
	// ---
	Menu = aRecv->Menu;
	PanelButtons[0] = aRecv->PanelButtons[0];
	PanelButtons[1] = aRecv->PanelButtons[1];
	PanelButtons[2] = aRecv->PanelButtons[2];
	PanelButtons[3] = aRecv->PanelButtons[3];
	PanelButtons[4] = aRecv->PanelButtons[4];
	PanelButtons[5] = aRecv->PanelButtons[5];
	PanelButtons[6] = aRecv->PanelButtons[6];
	// ---
	Panel2Buttons[0] = aRecv->Panel2Buttons[0];
	Panel2Buttons[1] = aRecv->Panel2Buttons[1];
	Panel2Buttons[2] = aRecv->Panel2Buttons[2];
	Panel2Buttons[3] = aRecv->Panel2Buttons[3];
	// ---
}

void UpdateLuckyWheel(ITEM_WIN_SEND * lpMsg)
{
	gInterface.LuckyWheelNumber = lpMsg->number;
	gInterface.StartRoll = 0;
}

void CloseHelper()
{
	HELPER_CLOSE pMsg;
	pMsg.h.set(0xF3, 0xF2, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

