// ServerInfo.cpp: implementation of the CServerInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ServerInfo.h"
#include "380ItemOption.h"
#include "380ItemType.h"
#include "BloodCastle.h"
#include "BonusManager.h"
#include "CashShop.h"
#include "CastleDeep.h"
#include "CastleSiege.h"
#include "ChaosCastle.h"
#include "Command.h"
#include "CommandManager.h"
#include "Crywolf.h"
#include "CrywolfSync.h"
#include "CustomArena.h"
#include "CustomAttack.h"
#include "CustomBuyVip.h"
#include "CustomCommandDescription.h"
#include "CustomCombo.h"
#include "CustomDeathMessage.h"  
#include "CustomEventDrop.h"
#include "CustomJewel.h"
#include "CustomMonster.h"
#include "CustomMove.h"
#include "CustomNpcCollector.h"
#include "CustomNpcCommand.h"
#include "CustomNpcMove.h"
#include "CustomNpcQuest.h"
#include "CustomOnlineLottery.h"
#include "CustomPick.h"
#include "CustomQuiz.h"
#include "CustomQuest.h"
#include "CustomRanking.h"
#include "CustomRankUser.h"
#include "CustomStore.h"
#include "CustomWing.h"
#include "CustomWingMix.h"
#include "DefaultClassInfo.h"
#include "DevilSquare.h"
#include "DoubleGoer.h"
#include "EffectManager.h"
#include "EventTvT.h"
#include "ExperienceTable.h"
#include "Filter.h"
#include "FilterRename.h"
#include "GameMaster.h"
#include "Gate.h"
#include "Protect.h"
#include "HackPacketCheck.h"
#include "HackSkillCheck.h"
#include "IllusionTemple.h"
#include "ImperialGuardian.h"
#include "InvasionManager.h"
#include "ItemBagManager.h"
#include "ItemDrop.h"
#include "ItemMove.h"
#include "ItemOption.h"
#include "ItemOptionRate.h"
#include "ItemStack.h"
#include "ItemValue.h"
#include "ItemValueTrade.h"
#include "JewelOfHarmonyOption.h"
#include "JewelOfHarmonyType.h"
#include "Kanturu.h"
#include "KanturuMonsterMng.h"
#include "LuckyItem.h"
#include "MapManager.h"
#include "MapServerManager.h"
#include "MasterSkillTree.h"
#include "Message.h"
#include "MiniMap.h"
#include "MiningSystem.h"
#include "MonsterAIAutomata.h"
#include "MonsterAIElement.h"
#include "MonsterAIGroup.h"
#include "MonsterAIRule.h"
#include "MonsterAIUnit.h"
#include "MonsterManager.h"
#include "MonsterSetBase.h"
#include "MonsterSkillElement.h"
#include "MonsterSkillManager.h"
#include "MonsterSkillUnit.h"
#include "MossMerchant.h"
#include "Move.h"
#include "MoveSummon.h"
#include "MuunSystem.h"
#include "Notice.h"
#include "PacketManager.h"
#include "Path.h"
#include "PcPoint.h"
#include "PentagramSystem.h"
#include "Quest.h"
#include "QuestObjective.h"
#include "QuestReward.h"
#include "QuestWorld.h"
#include "QuestWorldObjective.h"
#include "QuestWorldReward.h"
#include "ReiDoMU.h"
#include "Raklion.h"
#include "ResetTable.h"
#include "SetItemOption.h"
#include "SetItemType.h"
#include "ShopManager.h"
#include "SkillHitBox.h"
#include "SkillManager.h"
#include "SocketItemOption.h"
#include "SocketItemType.h"
#include "Util.h"
//--
#include "SummonScroll.h"
#include "CustomPet.h"
#include "RespawnLocation.h"
#include "CustomMix.h"
#include "BotBuffer.h"
#include "BotTrader.h"
#include "StatsAdvance.h"
#include "CustomMonsterSkill.h"
#include "CustomPKFree.h"
#include "TeleportMarlon.h"
#include "DropReward.h"
#include "OfflineMode.h"
#include "PartySearch.h"
#include "JewelBank.h"
#include "ResetChange.h"
#include "CustomPanel.h"
#include "LuckyWheel.h"
#include "RuudTokenSellTemplate.h"
#include "ResetReward.h"
#include "MonsterKillCount.h"
#include "MonsterCoins.h"
#include "ShopSearch.h"
#include "AntiFloodSystem.h"
#include "SmithItem.h"
#include "SkillDamage.h"
#include "WindowsQuest.h"
#include "NpcRequiere.h"
#include "ResetSystem.h"
#include "GrandResetSystem.h"
#include "InvokerHelper.h"

CServerInfo gServerInfo;

bool AlreadyReaded = false;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerInfo::CServerInfo() // OK
{

}

CServerInfo::~CServerInfo() // OK
{

}

void CServerInfo::ReadInit() // OK
{
	gPath.SetMainPath(MAIN_PATH);

	this->ReadCashShopInfo();

	this->ReadChaosMixInfo();

	this->ReadCharacterInfo();

	this->ReadCustomInfo();

	this->ReadCommandInfo();

	this->ReadCommonInfo();

	this->ReadEventInfo();

	this->ReadEventItemBagInfo();

	this->ReadHackInfo();

	this->ReadItemInfo();

	this->ReadMapInfo();

	this->ReadMonsterInfo();

	this->ReadMoveInfo();

	this->ReadQuestInfo();

	this->ReadShopInfo();

	this->ReadSkillInfo();

	this->ReadUtilInfo();

	//MC bot
	this->ReloadBotInfo();
	//MC bot
	g_OfflineMode.ReadOffLine("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");
}

void CServerInfo::ReloadAll() // OK
{
	this->ReadCashShopInfo();

	this->ReadChaosMixInfo();

	this->ReadCharacterInfo();

	this->ReadCommandInfo();

	this->ReadCommonInfo();

	this->ReadCustomInfo();

	this->ReadEventInfo();

	this->ReadEventItemBagInfo();

	this->ReadHackInfo();

	//this->ReadItemInfo(); //bugado

	this->ReadMonsterInfo();

	this->ReadMoveInfo();

	this->ReadQuestInfo();

	this->ReadShopInfo();

	this->ReadSkillInfo();

	this->ReadUtilInfo();

	//MC bot
	this->ReloadBotInfo();
	//MC bot
	g_OfflineMode.ReadOffLine("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");
}

void CServerInfo::ReadCashShopInfo() // OK
{
	this->ReadCashShopInfo("GameServerInfo",".\\Data\\GameServerInfo - Common.dat");

	#if(GAMESERVER_UPDATE>=501)

	gCashShop.LoadPackage(gPath.GetFullPath("CashShop\\CashShopPackage.txt"));

	gCashShop.LoadProduct(gPath.GetFullPath("CashShop\\CashShopProduct.txt"));

	#endif
	
	LogAdd(LOG_BLUE,"[ServerInfo] CashShop loaded successfully");
}

void CServerInfo::ReadChaosMixInfo() // OK
{
	this->ReadChaosMixInfo("GameServerInfo",".\\Data\\GameServerInfo - ChaosMix.dat");

	LogAdd(LOG_BLUE,"[ServerInfo] ChaosMix loaded successfully");
}

void CServerInfo::ReadCharacterInfo() // OK
{
	this->ReadCharacterInfo("GameServerInfo",".\\Data\\GameServerInfo - Character.dat");

	gDefaultClassInfo.Load(gPath.GetFullPath("Character\\DefaultClassInfo.xml"));

	LogAdd(LOG_BLUE,"[ServerInfo] Character loaded successfully");
}

void CServerInfo::ReadCommandInfo() // OK
{
	gCommand.Load(gPath.GetFullPath("Command.txt"));

	this->ReadCommandInfo("GameServerInfo",".\\Data\\GameServerInfo - Command.dat");

	gCommandManager.Init();

	LogAdd(LOG_BLUE,"[ServerInfo] Command loaded successfully");
}

void CServerInfo::ReadCommonInfo() // OK
{
	this->ReadCommonInfo("GameServerInfo",".\\Data\\GameServerInfo - Common.dat");

	gEffectManager.Load(gPath.GetFullPath("Effect.txt"));

	gMapManager.Load(gPath.GetFullPath("MapManager.txt"));

	gMapServerManager.Load(gPath.GetFullPath("MapServerInfo.dat"));

	if (this->m_Idioma == 1)
	{
		gMessage.Load(gPath.GetFullPath("MessageENG.txt"));
	}
	if (this->m_Idioma == 2)
	{
		gMessage.Load(gPath.GetFullPath("MessageSPN.txt"));
	}
	if (this->m_Idioma == 3)
	{
		gMessage.Load(gPath.GetFullPath("MessagePOR.txt"));
	}
	if (this->m_Idioma == 4)
	{
		gMessage.Load(gPath.GetFullPath("MessageVIET.txt"));
	}

	//gMiniMap.Load(gPath.GetFullPath("MiniMap.txt"));

	#if(GAMESERVER_UPDATE>=801)

	gMiningSystem.Load(gPath.GetFullPath("Mining.txt"));

	#endif

	LogAdd(LOG_BLUE,"[ServerInfo] Common loaded successfully");
}

void CServerInfo::ReadCustomInfo() // OK
{
	// ------------------------------------------------------------
	// ADVANCE STATS
	g_StatsAdvance.Load(); //Estat�sticas de atributo
	// ------------------------------------------------------------

	this->ReadCustomInfo("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");

	gCustomArena.ReadCustomArenaInfo("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");

	gCustomAttack.ReadCustomAttackInfo("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");

	gCustomEventDrop.ReadCustomEventDropInfo("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");

	gCustomOnlineLottery.ReadCustomOnlineLotteryInfo("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");

	gCustomStore.ReadCustomStoreInfo("GameServerInfo",".\\Data\\GameServerInfo - Custom.dat");

	gCustomArena.Load(gPath.GetFullPath("Custom\\CustomArena.txt"));

	gCustomEventDrop.Load(gPath.GetFullPath("Custom\\CustomEventDrop.txt"));

	gCustomOnlineLottery.Load(gPath.GetFullPath("Custom\\CustomOnlineLottery.txt"));

	gCustomQuest.Load(gPath.GetFullPath("Custom\\CustomQuest.txt"));

	gCustomNpcCollector.Load(gPath.GetFullPath("Custom\\CustomNpcCollector.txt"));

	gCustomRankUser.Load(gPath.GetFullPath("Custom\\CustomRankUser.txt"));

	gCustomWingMix.Load(gPath.GetFullPath("Custom\\CustomWingMix.txt"));

	gCustomMix.Load(gPath.GetFullPath("Custom\\CustomMix.txt"));

	gCustomMarlon.Load(gPath.GetFullPath("Custom\\CustomMarlonTeleport.txt"));

	gPKFree.Load(gPath.GetFullPath("Custom\\CustomZonaPK.txt"));

	gCustomDeathMessage.Load(gPath.GetFullPath("Custom\\CustomDeathMessage.txt"));

	gCustomQuiz.Load(gPath.GetFullPath("Custom\\CustomQuiz.txt"));

	gCustomPick.Load(gPath.GetFullPath("Custom\\CustomPick.txt"));

	gCustomBuyVip.Load(gPath.GetFullPath("Custom\\CustomBuyVip.txt"));

	gCustomCombo.Load(gPath.GetFullPath("Custom\\CustomCombo.txt"));

	gCustomCommandDescription.Load(gPath.GetFullPath("Custom\\CustomCommandDescription.txt"));

	gCustomJewel.Load(gPath.GetFullPath("Custom\\CustomJewel.txt"));

	gCustomMonster.Load(gPath.GetFullPath("Custom\\CustomMonster.txt"));

	gDropReward.load(gPath.GetFullPath("Ruud\\DropReward.txt"));
	
	gCustomMonsterSkill.Load(gPath.GetFullPath("Custom\\CustomMonsterSkill.txt"));

	gCustomWing.Load(gPath.GetFullPath("Custom\\CustomWing.txt"));

	gCustomNpcMove.Load(gPath.GetFullPath("Custom\\CustomNpcMove.txt"));

	gCustomNpcReq.Load(gPath.GetFullPath("Custom\\CustomNpcRequeriment.txt"));

	gCustomNpcCommand.Load(gPath.GetFullPath("Custom\\CustomNpcCommand.txt"));

	gItemValueTrade.Load(gPath.GetFullPath("Item\\ItemValueTrade.txt"));

	gCustomNpcQuest.Load(gPath.GetFullPath("Custom\\CustomNpcQuest.txt"));
//---------- cosas de pet
	gCustomPet.Load(gPath.GetFullPath("Custom\\CustomPet.txt"));

	gPartySearch.Load("Config", gPath.GetFullPath("Custom\\PartySearch.txt"));

	gPanelMenu.Load(gPath.GetFullPath("Custom\\PanelMenu.txt"));

#if (JEWEL_BANK == 1)
	gJewelsBank.Load();
#endif
#if (RESETCHANGE == 1)
	gResetChange.Load(gPath.GetFullPath("Custom\\ResetChange.txt"));
#endif
#if (LUCKYWHEEL == 1)
	gLuckyWheel.Load(gPath.GetFullPath("Custom\\LuckyWheel.txt"));
#endif
#if(CUSTOM_PERSONAL_SHOP==1)
	g_PersonalShopEx.Load();
#endif
	gMonsterKillCount.Load(gPath.GetFullPath("Custom\\MonsterKillCount.xml"));
#if (ARCHIVEMENT == 1)
	gAchievements.Read(gPath.GetFullPath("Custom\\Achievements.xml"));
#endif

#if (WINDOWSQUEST==1)
	g_ExWinQuestSystem.Load();
#endif

	gResetSystem.Load();

	gGrandResetSystem.Load();

	gInvoker.Load(gPath.GetFullPath("Custom\\RingInvoker.txt"));

	LogAdd(LOG_BLUE,"[ServerInfo] Custom loaded successfully");

}



void CServerInfo::ReadEventInfo() // OK
{
	this->ReadEventInfo("GameServerInfo",".\\Data\\GameServerInfo - Event.dat");

	gBloodCastle.Load(gPath.GetFullPath("Event\\BloodCastle.dat"));

	gBonusManager.Load(gPath.GetFullPath("Event\\BonusManager.dat"));

	gCastleDeep.Load(gPath.GetFullPath("Event\\CastleDeepEvent.dat"));

	gChaosCastle.Load(gPath.GetFullPath("Event\\ChaosCastle.dat"));

    gReiDoMU.Load(gPath.GetFullPath("Event\\ReiDoMu.dat"));

	gTvTEvent.Load(gPath.GetFullPath("Event\\TvTEvent.dat"));

	gCrywolf.Load(gPath.GetFullPath("Event\\Crywolf.dat"));

	gDevilSquare.Load(gPath.GetFullPath("Event\\DevilSquare.dat"));

	gDoubleGoer.Load(gPath.GetFullPath("Event\\DoubleGoer.dat"));

	gIllusionTemple.Load(gPath.GetFullPath("Event\\IllusionTemple.dat"));

	gImperialGuardian.Load(gPath.GetFullPath("Event\\ImperialGuardian.dat"));

	gInvasionManager.Load(gPath.GetFullPath("Event\\InvasionManager.dat"));

	gKanturu.Load(gPath.GetFullPath("Event\\Kanturu.dat"));

	gMossMerchant.Load(gPath.GetFullPath("Event\\MossMerchant.dat"));

	gRaklion.Load(gPath.GetFullPath("Event\\Raklion.dat"));

	gSummonScroll.Load(gPath.GetFullPath("Event\\SummonScroll.dat"));

	#if(GAMESERVER_TYPE==1)

	if(gCastleSiege.Ready(gMapServerManager.GetMapServerGroup()) != 0)
	{
		if(gCastleSiege.LoadData(gPath.GetFullPath("Event\\MuCastleData.dat")) != 0)
		{
			gCastleSiege.LoadPreFixData(".\\Data\\GameServerInfo - Event.dat");
			gCastleSiege.SetDataLoadState(CASTLESIEGE_DATALOAD_2);
		}
	}

	#endif

	gBloodCastle.Init();

	gBonusManager.Init();

	gCastleDeep.Init();

	gChaosCastle.Init();

	gCustomArena.Init();

	gCustomEventDrop.Init();

	gCustomOnlineLottery.Init();

	gCustomQuiz.Init();

	gTvTEvent.Init();

	gDevilSquare.Init();

	gIllusionTemple.Init();

	gReiDoMU.Init();

	gInvasionManager.Init();

	gMossMerchant.Init();

	gRaklion.SetState(RAKLION_STATE_END);

	LogAdd(LOG_BLUE,"[ServerInfo] Event loaded successfully");
}

void CServerInfo::ReadEventItemBagInfo() // OK
{
	gItemBagManager.Load(gPath.GetFullPath("EventItemBagManager.txt"));

	gItemBagManager.LoadEventItemBag();

	LogAdd(LOG_BLUE,"[ServerInfo] EventItemBag loaded successfully");
}

void CServerInfo::ReadHackInfo() // OK
{
	this->ReadHackInfo("GameServerInfo",".\\Data\\GameServerInfo - Common.dat");

	gHackPacketCheck.Load(gPath.GetFullPath("Hack\\HackPacketCheck.txt"));

	gHackSkillCheck.Load(gPath.GetFullPath("Hack\\HackSkillCheck.txt"));

	gPacketManager.LoadEncryptionKey(gPath.GetFullPath("Hack\\Enc2.dat"));

	gPacketManager.LoadDecryptionKey(gPath.GetFullPath("Hack\\Dec1.dat"));
#if (ANTIFLOOD ==1)
	gAntiFlood.Initialize(gPath.GetFullPath("Hack\\AntiFlood.txt"));
#endif
	LogAdd(LOG_BLUE,"[ServerInfo] Hack loaded successfully");
}

void CServerInfo::ReadItemInfo() // OK
{
	#if(GAMESERVER_UPDATE>=201)

	g380ItemOption.Load(gPath.GetFullPath("Item\\380ItemOption.txt"));

	g380ItemType.Load(gPath.GetFullPath("Item\\380ItemType.txt"));

	#endif

	gItemManager.Load(gPath.GetFullPath("Item\\Item.txt"));

	gItemDrop.Load(gPath.GetFullPath("Item\\ItemDrop.txt"));

	gItemMove.Load(gPath.GetFullPath("Item\\ItemMove.txt"));

	gItemOption.Load(gPath.GetFullPath("Item\\ItemOption.txt"));

	gItemOptionRate.Load(gPath.GetFullPath("Item\\ItemOptionRate.txt"));

	gItemStack.Load(gPath.GetFullPath("Item\\ItemStack.txt"));

	gItemValue.Load(gPath.GetFullPath("Item\\ItemValue.txt"));

	#if(GAMESERVER_UPDATE>=201)

	gJewelOfHarmonyOption.Load(gPath.GetFullPath("Item\\JewelOfHarmonyOption.txt"));

	gJewelOfHarmonyType.Load(gPath.GetFullPath("Item\\JewelOfHarmonyType.txt"));

	#endif

	#if(GAMESERVER_UPDATE>=602)

	gLuckyItem.Load(gPath.GetFullPath("Item\\LuckyItem.txt"));

	#endif

	#if(GAMESERVER_UPDATE>=803)

	gMuunSystem.Load(gPath.GetFullPath("Item\\MuunOption.txt"));

	#endif

	#if(GAMESERVER_UPDATE>=701)

	gPentagramSystem.Load(gPath.GetFullPath("Item\\PentagramOption.txt"));

	gPentagramSystem.LoadJewel(gPath.GetFullPath("Item\\PentagramJewelOption.txt"));

	gPentagramSystem.LoadMixRate(gPath.GetFullPath("Item\\PentagramJewelMixRate.txt"));

	#endif

	gSetItemOption.Load(gPath.GetFullPath("Item\\SetItemOption.txt"));

	gSetItemType.Load(gPath.GetFullPath("Item\\SetItemType.txt"));

	#if(GAMESERVER_UPDATE>=401)

	gSocketItemOption.Load(gPath.GetFullPath("Item\\SocketItemOption.txt"));

	gSocketItemType.Load(gPath.GetFullPath("Item\\SocketItemType.txt"));

	#endif

	LogAdd(LOG_BLUE,"[ServerInfo] Item loaded successfully");
}

void CServerInfo::ReadMapInfo() // OK
{
	FILE* file;

	char path[256] = {0};

	char temp[256] = {0};

	for(int n=0;n < MAX_MAP;n++)
	{
		wsprintf(temp,"Terrain\\terrain%d.att",(n+1));

		if(fopen_s(&file,gPath.GetFullPath(temp),"r") == 0)
		{
			strcpy_s(path,temp);
			fclose(file);
		}

		gMap[n].Load(gPath.GetFullPath(path),n);
	}

	gCrywolf.LoadCrywolfMapAttr(gPath.GetFullPath("Terrain\\terrain35_PEACE.att"),0);

	gCrywolf.LoadCrywolfMapAttr(gPath.GetFullPath("Terrain\\terrain35_OCCUPIED.att"),1);

	gCrywolf.LoadCrywolfMapAttr(gPath.GetFullPath("Terrain\\terrain35_WAR.att"),2);

	gKanturu.LoadKanturuMapAttr(gPath.GetFullPath("Terrain\\terrain40_CLOSE.att"),0);

	gKanturu.LoadKanturuMapAttr(gPath.GetFullPath("Terrain\\terrain40_OPEN.att"),1);
}

void CServerInfo::ReadMonsterInfo() // OK
{
	gKanturuMonsterMng.Load(gPath.GetFullPath("Monster\\KanturuMonsterSetBase.txt"));

	CMonsterAIAutomata::LoadData(gPath.GetFullPath("Monster\\MonsterAIAutomata.txt"));

	CMonsterAIElement::LoadData(gPath.GetFullPath("Monster\\MonsterAIElement.txt"));

	CMonsterAIGroup::LoadData(gPath.GetFullPath("Monster\\MonsterAIGroup.txt"));

	CMonsterAIRule::LoadData(gPath.GetFullPath("Monster\\MonsterAIRule.txt"));

	CMonsterAIUnit::LoadData(gPath.GetFullPath("Monster\\MonsterAIUnit.txt"));

	gMonsterManager.Load(gPath.GetFullPath("Monster\\Monster.txt"));

#if (MONSTER_COINS==1)
	gShopPointEx.Load(gPath.GetFullPath("Monster\\MonsterKillCoins.txt"));
#endif

	#if(GAMESERVER_TYPE==0)

	gMonsterSetBase.Load(gPath.GetFullPath("Monster\\MonsterSetBase.txt"));

	#else

	gMonsterSetBase.Load(gPath.GetFullPath("Monster\\MonsterSetBaseCS.txt"));

	#endif

	CMonsterSkillElement::LoadData(gPath.GetFullPath("Monster\\MonsterSkillElement.txt"));

	CMonsterSkillUnit::LoadData(gPath.GetFullPath("Monster\\MonsterSkillUnit.txt"));

	CMonsterSkillManager::LoadData(gPath.GetFullPath("Monster\\MonsterSkill.txt"));

	LogAdd(LOG_BLUE,"[ServerInfo] Monster loaded successfully");
}

void CServerInfo::ReadMoveInfo() // OK
{
	gGate.Load(gPath.GetFullPath("Move\\Gate.txt"));

	gMove.Load(gPath.GetFullPath("Move\\Move.txt"));

	gCustomMove.Load(gPath.GetFullPath("Custom\\CustomMove.txt"));

	gMoveSummon.Load(gPath.GetFullPath("Move\\MoveSummon.txt"));

	gRespawnLocation.Load(gPath.GetFullPath("Move\\RespawnLocation.txt"));

	LogAdd(LOG_BLUE,"[ServerInfo] Move loaded successfully");
}

void CServerInfo::ReadQuestInfo() // OK
{
	gQuest.Load(gPath.GetFullPath("Quest\\Quest.txt"));

	gQuestObjective.Load(gPath.GetFullPath("Quest\\QuestObjective.txt"));

	gQuestReward.Load(gPath.GetFullPath("Quest\\QuestReward.txt"));

	#if(GAMESERVER_UPDATE>=501)

	gQuestWorld.Load(gPath.GetFullPath("QuestWorld\\QuestWorld.txt"));

	gQuestWorldObjective.Load(gPath.GetFullPath("QuestWorld\\QuestWorldObjective.txt"));

	gQuestWorldReward.Load(gPath.GetFullPath("QuestWorld\\QuestWorldReward.txt"));

	#endif

	LogAdd(LOG_BLUE,"[ServerInfo] Quest loaded successfully");
}

void CServerInfo::ReadShopInfo() // OK
{
	gItemValue.Load(gPath.GetFullPath("Item\\ItemValue.txt"));

	#if(GAMESERVER_UPDATE<=402)

	gPcPoint.Load(gPath.GetFullPath("PcPoint.txt"));

	#endif

	gShopManager.Load(gPath.GetFullPath("ShopManager.txt"));

	gShopManager.LoadShop();

	gShopManager.ReloadShopInterface();

	g_RuudTokenSellTemplate.Load_RuudTokenSell(gPath.GetFullPath("Ruud/ShopRuud.txt"));

	SVShop.Read(gPath.GetFullPath("SmithyShop\\CustomSmithItem.xml"));

	LogAdd(LOG_BLUE,"[ServerInfo] Shop loaded successfully");
}

void CServerInfo::ReadSkillInfo() // OK
{
	this->ReadSkillInfo("GameServerInfo",".\\Data\\GameServerInfo - Skill.dat");

	#if(GAMESERVER_UPDATE>=401)

	gMasterSkillTree.Load(gPath.GetFullPath("Skill\\MasterSkillTree.txt"));

	#endif

	gSkillDamage.Load(gPath.GetFullPath("Skill\\SkillDamage.xml"));

	gSkillHitBox.Load(gPath.GetFullPath("Skill\\SkillElect.hit"));

	gSkillManager.Load(gPath.GetFullPath("Skill\\Skill.txt"));

	LogAdd(LOG_BLUE,"[ServerInfo] Skill loaded successfully");
}

void CServerInfo::ReadUtilInfo() // OK
{
	gExperienceTable.Load(gPath.GetFullPath("Util\\ExperienceTable.txt"));

	gFilter.Load(gPath.GetFullPath("Util\\Filter.txt"));

	#if (GAMESERVER_CLIENTE_UPDATE >= 9)
	gFilterRename.Load(gPath.GetFullPath("Util\\FilterRename.txt"));
	#endif

	gGameMaster.Load(gPath.GetFullPath("Util\\GameMaster.txt"));

	gNotice.Load(gPath.GetFullPath("Util\\Notice.txt"));

	gResetTable.Load(gPath.GetFullPath("Util\\ResetTable.txt"));

	gRewardSystem.Load(gPath.GetFullPath("Util\\ResetReward.txt"));

	LogAdd(LOG_BLUE,"[ServerInfo] Util loaded successfully");
}

//MC bot
void CServerInfo::ReloadBotInfo() // OK
{

	for (int n = 0; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnectedGP(n) != 0 && gObj[n].Type == OBJECT_BOT)
		{
			gObjDel(n);
		}
	}

	gBotBuffer.Load(gPath.GetFullPath("Custom\\Bots\\BotsBuffer.xml"));

	gBotTrader.Load(gPath.GetFullPath("Custom\\Bots\\BotsTrader.xml"));

LogAdd(LOG_GREEN,"[ReadBotInfo] BotSystem loaded successfully");

}
//MC bot

void CServerInfo::ReloadMonsterInfo() // OK
{
	for(int n=0;n < MAX_OBJECT_MONSTER;n++)
	{
		if(gObj[n].Type != OBJECT_MONSTER && gObj[n].Type != OBJECT_NPC)
		{
			continue;
		}

		#if(GAMESERVER_TYPE==1)

		if(gObj[n].CsNpcType != 0)
		{
			continue;
		}

		#endif

		gObjDel(n);
	}

	gObjMonCount = 0;

	gCrywolf.m_ObjCommonNPC.Reset();

	gCrywolf.m_ObjSpecialNPC.Reset();

	gCrywolf.m_ObjCommonMonster.Reset();

	gCrywolf.m_ObjSpecialMonster.Reset();

	this->ReadMonsterInfo();

	gMonsterManager.SetMonsterData();
}

void CServerInfo::ReadStartupInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	GetPrivateProfileString(section,"CustomerName","",this->m_CustomerName,sizeof(this->m_CustomerName),path);

	GetPrivateProfileString(section,"CustomerHardwareId","",this->m_CustomerHardwareId,sizeof(this->m_CustomerHardwareId),path);

	GetPrivateProfileString(section,"ServerName","",this->m_ServerName,sizeof(this->m_ServerName),path);

	this->m_ServerCode = GetPrivateProfileInt(section,"ServerCode",0,path);

	this->m_ServerLock = GetPrivateProfileInt(section,"ServerLock",0,path);

	this->m_ServerPort = GetPrivateProfileInt(section,"ServerPort",0,path);

	wsprintf(this->m_ServerMutex,"WZ_MU_GS_MUTEX_%d",this->m_ServerCode);

	GetPrivateProfileString(section,"ServerVersion","",GameServerInfo,sizeof(GameServerInfo),path);

	gServerInfo.m_ServerVersion[0] = GameServerInfo[0];

	gServerInfo.m_ServerVersion[1] = GameServerInfo[2];

	gServerInfo.m_ServerVersion[2] = GameServerInfo[3];

	gServerInfo.m_ServerVersion[3] = GameServerInfo[5];

	gServerInfo.m_ServerVersion[4] = GameServerInfo[6];

	gServerInfo.m_ServerVersion[5] = 0;

	GetPrivateProfileString(section,"ServerSerial","",this->m_ServerSerial,sizeof(this->m_ServerSerial),path);

	this->m_ServerMaxUserNumber = GetPrivateProfileInt(section, "ServerMaxUserNumber", 0, path);

	this->m_ServerMaxUserNumber = ((this->m_ServerMaxUserNumber > MAX_OBJECT_USER) ? MAX_OBJECT_USER : this->m_ServerMaxUserNumber);

	GetPrivateProfileString(section,"DataServerAddress","",this->m_DataServerAddress,sizeof(this->m_DataServerAddress),path);

	this->m_DataServerPort = GetPrivateProfileInt(section,"DataServerPort",0,path);

	GetPrivateProfileString(section,"JoinServerAddress","",this->m_JoinServerAddress,sizeof(this->m_JoinServerAddress),path);

	this->m_JoinServerPort = GetPrivateProfileInt(section,"JoinServerPort",0,path);

	GetPrivateProfileString(section,"ConnectServerAddress","",this->m_ConnectServerAddress,sizeof(this->m_ConnectServerAddress),path);

	this->m_ConnectServerPort = GetPrivateProfileInt(section,"ConnectServerPort",0,path);

	this->m_WriteChatLog = GetPrivateProfileInt(section,"WriteChatLog",0,path);

	this->m_WriteCommandLog = GetPrivateProfileInt(section,"WriteCommandLog",0,path);

	this->m_WriteTradeLog = GetPrivateProfileInt(section,"WriteTradeLog",0,path);

	this->m_WriteConnectLog = GetPrivateProfileInt(section,"WriteConnectLog",0,path);

	this->m_WriteHackLog = GetPrivateProfileInt(section,"WriteHackLog",0,path);

	this->m_WriteCashShopLog = GetPrivateProfileInt(section,"WriteCashShopLog",0,path);

	this->m_WriteChaosMixLog = GetPrivateProfileInt(section,"WriteChaosMixLog",0,path);

	this->m_WriteAntifloodLog = GetPrivateProfileInt(section,"WriteSystemAntifloodLog",0,path);
}

void CServerInfo::ReadCashShopInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	#if(GAMESERVER_UPDATE>=501)

	this->m_CashShopSwitch = GetPrivateProfileInt(section,"CashShopSwitch",0,path);

	this->m_CashShopScriptVersion1 = GetPrivateProfileInt(section,"CashShopScriptVersion1",0,path);

	this->m_CashShopScriptVersion2 = GetPrivateProfileInt(section,"CashShopScriptVersion2",0,path);

	this->m_CashShopScriptVersion3 = GetPrivateProfileInt(section,"CashShopScriptVersion3",0,path);

	this->m_CashShopBannerVersion1 = GetPrivateProfileInt(section,"CashShopBannerVersion1",0,path);

	this->m_CashShopBannerVersion2 = GetPrivateProfileInt(section,"CashShopBannerVersion2",0,path);

	this->m_CashShopBannerVersion3 = GetPrivateProfileInt(section,"CashShopBannerVersion3",0,path);

	this->m_CashShopGoblinPointDelay = GetPrivateProfileInt(section,"CashShopGoblinPointDelay",0,path);

	this->m_CashShopGoblinPointValue[0] = GetPrivateProfileInt(section,"CashShopGoblinPointValue_AL0",0,path);

	this->m_CashShopGoblinPointValue[1] = GetPrivateProfileInt(section,"CashShopGoblinPointValue_AL1",0,path);

	this->m_CashShopGoblinPointValue[2] = GetPrivateProfileInt(section,"CashShopGoblinPointValue_AL2",0,path);

	this->m_CashShopGoblinPointValue[3] = GetPrivateProfileInt(section,"CashShopGoblinPointValue_AL3",0,path);

	//Auto Reward Online Users System
	this->m_CashShopCoinsDelay = GetPrivateProfileInt(section,"OnlineRewardCoinsDelay",0,path);

	this->m_CashShopWCoinCValue[0] = GetPrivateProfileInt(section,"OnlineRewardWCoinCValue_AL0",0,path);

	this->m_CashShopWCoinCValue[1] = GetPrivateProfileInt(section,"OnlineRewardWCoinCValue_AL1",0,path);

	this->m_CashShopWCoinCValue[2] = GetPrivateProfileInt(section,"OnlineRewardWCoinCValue_AL2",0,path);

	this->m_CashShopWCoinCValue[3] = GetPrivateProfileInt(section,"OnlineRewardWCoinCValue_AL3",0,path);

	this->m_CashShopWCoinPValue[0] = GetPrivateProfileInt(section,"OnlineRewardWCoinPValue_AL0",0,path);

	this->m_CashShopWCoinPValue[1] = GetPrivateProfileInt(section,"OnlineRewardWCoinPValue_AL1",0,path);

	this->m_CashShopWCoinPValue[2] = GetPrivateProfileInt(section,"OnlineRewardWCoinPValue_AL2",0,path);

	this->m_CashShopWCoinPValue[3] = GetPrivateProfileInt(section,"OnlineRewardWCoinPValue_AL3",0,path);

	this->m_CashShopGoblinPointValue[0] = GetPrivateProfileInt(section,"OnlineRewardGoblinPointValue_AL0",0,path);

	this->m_CashShopGoblinPointValue[1] = GetPrivateProfileInt(section,"OnlineRewardGoblinPointValue_AL1",0,path);

	this->m_CashShopGoblinPointValue[2] = GetPrivateProfileInt(section,"OnlineRewardGoblinPointValue_AL2",0,path);

	this->m_CashShopGoblinPointValue[3] = GetPrivateProfileInt(section,"OnlineRewardGoblinPointValue_AL3",0,path);

	this->m_CashShopRuudValue[0] = GetPrivateProfileInt(section,"OnlineRewardRuudValue_AL0",0,path);

	this->m_CashShopRuudValue[1] = GetPrivateProfileInt(section,"OnlineRewardRuudValue_AL1",0,path);

	this->m_CashShopRuudValue[2] = GetPrivateProfileInt(section,"OnlineRewardRuudValue_AL2",0,path);

	this->m_CashShopRuudValue[3] = GetPrivateProfileInt(section,"OnlineRewardRuudValue_AL3",0,path);
	//--

	#endif
}

void CServerInfo::ReadChaosMixInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	this->m_ChaosItemMixRate[0] = GetPrivateProfileInt(section,"ChaosItemMixRate_AL0",0,path);

	this->m_ChaosItemMixRate[1] = GetPrivateProfileInt(section,"ChaosItemMixRate_AL1",0,path);

	this->m_ChaosItemMixRate[2] = GetPrivateProfileInt(section,"ChaosItemMixRate_AL2",0,path);

	this->m_ChaosItemMixRate[3] = GetPrivateProfileInt(section,"ChaosItemMixRate_AL3",0,path);

	this->m_DevilSquareMixRate1[0] = GetPrivateProfileInt(section,"DevilSquareMixRate1_AL0",0,path);

	this->m_DevilSquareMixRate1[1] = GetPrivateProfileInt(section,"DevilSquareMixRate1_AL1",0,path);

	this->m_DevilSquareMixRate1[2] = GetPrivateProfileInt(section,"DevilSquareMixRate1_AL2",0,path);

	this->m_DevilSquareMixRate1[3] = GetPrivateProfileInt(section,"DevilSquareMixRate1_AL3",0,path);

	this->m_DevilSquareMixRate2[0] = GetPrivateProfileInt(section,"DevilSquareMixRate2_AL0",0,path);

	this->m_DevilSquareMixRate2[1] = GetPrivateProfileInt(section,"DevilSquareMixRate2_AL1",0,path);

	this->m_DevilSquareMixRate2[2] = GetPrivateProfileInt(section,"DevilSquareMixRate2_AL2",0,path);

	this->m_DevilSquareMixRate2[3] = GetPrivateProfileInt(section,"DevilSquareMixRate2_AL3",0,path);

	this->m_DevilSquareMixRate3[0] = GetPrivateProfileInt(section,"DevilSquareMixRate3_AL0",0,path);

	this->m_DevilSquareMixRate3[1] = GetPrivateProfileInt(section,"DevilSquareMixRate3_AL1",0,path);

	this->m_DevilSquareMixRate3[2] = GetPrivateProfileInt(section,"DevilSquareMixRate3_AL2",0,path);

	this->m_DevilSquareMixRate3[3] = GetPrivateProfileInt(section,"DevilSquareMixRate3_AL3",0,path);

	this->m_DevilSquareMixRate4[0] = GetPrivateProfileInt(section,"DevilSquareMixRate4_AL0",0,path);

	this->m_DevilSquareMixRate4[1] = GetPrivateProfileInt(section,"DevilSquareMixRate4_AL1",0,path);

	this->m_DevilSquareMixRate4[2] = GetPrivateProfileInt(section,"DevilSquareMixRate4_AL2",0,path);

	this->m_DevilSquareMixRate4[3] = GetPrivateProfileInt(section,"DevilSquareMixRate4_AL3",0,path);

	this->m_DevilSquareMixRate5[0] = GetPrivateProfileInt(section,"DevilSquareMixRate5_AL0",0,path);

	this->m_DevilSquareMixRate5[1] = GetPrivateProfileInt(section,"DevilSquareMixRate5_AL1",0,path);

	this->m_DevilSquareMixRate5[2] = GetPrivateProfileInt(section,"DevilSquareMixRate5_AL2",0,path);

	this->m_DevilSquareMixRate5[3] = GetPrivateProfileInt(section,"DevilSquareMixRate5_AL3",0,path);

	this->m_DevilSquareMixRate6[0] = GetPrivateProfileInt(section,"DevilSquareMixRate6_AL0",0,path);

	this->m_DevilSquareMixRate6[1] = GetPrivateProfileInt(section,"DevilSquareMixRate6_AL1",0,path);

	this->m_DevilSquareMixRate6[2] = GetPrivateProfileInt(section,"DevilSquareMixRate6_AL2",0,path);

	this->m_DevilSquareMixRate6[3] = GetPrivateProfileInt(section,"DevilSquareMixRate6_AL3",0,path);

	this->m_DevilSquareMixRate7[0] = GetPrivateProfileInt(section,"DevilSquareMixRate7_AL0",0,path);

	this->m_DevilSquareMixRate7[1] = GetPrivateProfileInt(section,"DevilSquareMixRate7_AL1",0,path);

	this->m_DevilSquareMixRate7[2] = GetPrivateProfileInt(section,"DevilSquareMixRate7_AL2",0,path);

	this->m_DevilSquareMixRate7[3] = GetPrivateProfileInt(section,"DevilSquareMixRate7_AL3",0,path);

	this->m_PlusItemLevelMixRate1[0] = GetPrivateProfileInt(section,"PlusItemLevelMixRate1_AL0",0,path);

	this->m_PlusItemLevelMixRate1[1] = GetPrivateProfileInt(section,"PlusItemLevelMixRate1_AL1",0,path);

	this->m_PlusItemLevelMixRate1[2] = GetPrivateProfileInt(section,"PlusItemLevelMixRate1_AL2",0,path);

	this->m_PlusItemLevelMixRate1[3] = GetPrivateProfileInt(section,"PlusItemLevelMixRate1_AL3",0,path);

	this->m_PlusItemLevelMixRate2[0] = GetPrivateProfileInt(section,"PlusItemLevelMixRate2_AL0",0,path);

	this->m_PlusItemLevelMixRate2[1] = GetPrivateProfileInt(section,"PlusItemLevelMixRate2_AL1",0,path);

	this->m_PlusItemLevelMixRate2[2] = GetPrivateProfileInt(section,"PlusItemLevelMixRate2_AL2",0,path);

	this->m_PlusItemLevelMixRate2[3] = GetPrivateProfileInt(section,"PlusItemLevelMixRate2_AL3",0,path);

	this->m_PlusItemLevelMixRate3[0] = GetPrivateProfileInt(section,"PlusItemLevelMixRate3_AL0",0,path);

	this->m_PlusItemLevelMixRate3[1] = GetPrivateProfileInt(section,"PlusItemLevelMixRate3_AL1",0,path);

	this->m_PlusItemLevelMixRate3[2] = GetPrivateProfileInt(section,"PlusItemLevelMixRate3_AL2",0,path);

	this->m_PlusItemLevelMixRate3[3] = GetPrivateProfileInt(section,"PlusItemLevelMixRate3_AL3",0,path);

	this->m_PlusItemLevelMixRate4[0] = GetPrivateProfileInt(section,"PlusItemLevelMixRate4_AL0",0,path);

	this->m_PlusItemLevelMixRate4[1] = GetPrivateProfileInt(section,"PlusItemLevelMixRate4_AL1",0,path);

	this->m_PlusItemLevelMixRate4[2] = GetPrivateProfileInt(section,"PlusItemLevelMixRate4_AL2",0,path);

	this->m_PlusItemLevelMixRate4[3] = GetPrivateProfileInt(section,"PlusItemLevelMixRate4_AL3",0,path);

	#if(GAMESERVER_UPDATE>=501)

	this->m_PlusItemLevelMixRate5[0] = GetPrivateProfileInt(section,"PlusItemLevelMixRate5_AL0",0,path);

	this->m_PlusItemLevelMixRate5[1] = GetPrivateProfileInt(section,"PlusItemLevelMixRate5_AL1",0,path);

	this->m_PlusItemLevelMixRate5[2] = GetPrivateProfileInt(section,"PlusItemLevelMixRate5_AL2",0,path);

	this->m_PlusItemLevelMixRate5[3] = GetPrivateProfileInt(section,"PlusItemLevelMixRate5_AL3",0,path);

	this->m_PlusItemLevelMixRate6[0] = GetPrivateProfileInt(section,"PlusItemLevelMixRate6_AL0",0,path);

	this->m_PlusItemLevelMixRate6[1] = GetPrivateProfileInt(section,"PlusItemLevelMixRate6_AL1",0,path);

	this->m_PlusItemLevelMixRate6[2] = GetPrivateProfileInt(section,"PlusItemLevelMixRate6_AL2",0,path);

	this->m_PlusItemLevelMixRate6[3] = GetPrivateProfileInt(section,"PlusItemLevelMixRate6_AL3",0,path);

	#endif

	this->m_DinorantMixRate[0] = GetPrivateProfileInt(section,"DinorantMixRate_AL0",0,path);

	this->m_DinorantMixRate[1] = GetPrivateProfileInt(section,"DinorantMixRate_AL1",0,path);

	this->m_DinorantMixRate[2] = GetPrivateProfileInt(section,"DinorantMixRate_AL2",0,path);

	this->m_DinorantMixRate[3] = GetPrivateProfileInt(section,"DinorantMixRate_AL3",0,path);

	this->m_FruitMixRate[0] = GetPrivateProfileInt(section,"FruitMixRate_AL0",0,path);

	this->m_FruitMixRate[1] = GetPrivateProfileInt(section,"FruitMixRate_AL1",0,path);

	this->m_FruitMixRate[2] = GetPrivateProfileInt(section,"FruitMixRate_AL2",0,path);

	this->m_FruitMixRate[3] = GetPrivateProfileInt(section,"FruitMixRate_AL3",0,path);

	this->m_Wing2MixRate[0] = GetPrivateProfileInt(section,"Wing2MixRate_AL0",0,path);

	this->m_Wing2MixRate[1] = GetPrivateProfileInt(section,"Wing2MixRate_AL1",0,path);

	this->m_Wing2MixRate[2] = GetPrivateProfileInt(section,"Wing2MixRate_AL2",0,path);

	this->m_Wing2MixRate[3] = GetPrivateProfileInt(section,"Wing2MixRate_AL3",0,path);

	this->m_BloodCastleMixRate1[0] = GetPrivateProfileInt(section,"BloodCastleMixRate1_AL0",0,path);

	this->m_BloodCastleMixRate1[1] = GetPrivateProfileInt(section,"BloodCastleMixRate1_AL1",0,path);

	this->m_BloodCastleMixRate1[2] = GetPrivateProfileInt(section,"BloodCastleMixRate1_AL2",0,path);

	this->m_BloodCastleMixRate1[3] = GetPrivateProfileInt(section,"BloodCastleMixRate1_AL3",0,path);

	this->m_BloodCastleMixRate2[0] = GetPrivateProfileInt(section,"BloodCastleMixRate2_AL0",0,path);

	this->m_BloodCastleMixRate2[1] = GetPrivateProfileInt(section,"BloodCastleMixRate2_AL1",0,path);

	this->m_BloodCastleMixRate2[2] = GetPrivateProfileInt(section,"BloodCastleMixRate2_AL2",0,path);

	this->m_BloodCastleMixRate2[3] = GetPrivateProfileInt(section,"BloodCastleMixRate2_AL3",0,path);

	this->m_BloodCastleMixRate3[0] = GetPrivateProfileInt(section,"BloodCastleMixRate3_AL0",0,path);

	this->m_BloodCastleMixRate3[1] = GetPrivateProfileInt(section,"BloodCastleMixRate3_AL1",0,path);

	this->m_BloodCastleMixRate3[2] = GetPrivateProfileInt(section,"BloodCastleMixRate3_AL2",0,path);

	this->m_BloodCastleMixRate3[3] = GetPrivateProfileInt(section,"BloodCastleMixRate3_AL3",0,path);

	this->m_BloodCastleMixRate4[0] = GetPrivateProfileInt(section,"BloodCastleMixRate4_AL0",0,path);

	this->m_BloodCastleMixRate4[1] = GetPrivateProfileInt(section,"BloodCastleMixRate4_AL1",0,path);

	this->m_BloodCastleMixRate4[2] = GetPrivateProfileInt(section,"BloodCastleMixRate4_AL2",0,path);

	this->m_BloodCastleMixRate4[3] = GetPrivateProfileInt(section,"BloodCastleMixRate4_AL3",0,path);

	this->m_BloodCastleMixRate5[0] = GetPrivateProfileInt(section,"BloodCastleMixRate5_AL0",0,path);

	this->m_BloodCastleMixRate5[1] = GetPrivateProfileInt(section,"BloodCastleMixRate5_AL1",0,path);

	this->m_BloodCastleMixRate5[2] = GetPrivateProfileInt(section,"BloodCastleMixRate5_AL2",0,path);

	this->m_BloodCastleMixRate5[3] = GetPrivateProfileInt(section,"BloodCastleMixRate5_AL3",0,path);

	this->m_BloodCastleMixRate6[0] = GetPrivateProfileInt(section,"BloodCastleMixRate6_AL0",0,path);

	this->m_BloodCastleMixRate6[1] = GetPrivateProfileInt(section,"BloodCastleMixRate6_AL1",0,path);

	this->m_BloodCastleMixRate6[2] = GetPrivateProfileInt(section,"BloodCastleMixRate6_AL2",0,path);

	this->m_BloodCastleMixRate6[3] = GetPrivateProfileInt(section,"BloodCastleMixRate6_AL3",0,path);

	this->m_BloodCastleMixRate7[0] = GetPrivateProfileInt(section,"BloodCastleMixRate7_AL0",0,path);

	this->m_BloodCastleMixRate7[1] = GetPrivateProfileInt(section,"BloodCastleMixRate7_AL1",0,path);

	this->m_BloodCastleMixRate7[2] = GetPrivateProfileInt(section,"BloodCastleMixRate7_AL2",0,path);

	this->m_BloodCastleMixRate7[3] = GetPrivateProfileInt(section,"BloodCastleMixRate7_AL3",0,path);

	this->m_BloodCastleMixRate8[0] = GetPrivateProfileInt(section,"BloodCastleMixRate8_AL0",0,path);

	this->m_BloodCastleMixRate8[1] = GetPrivateProfileInt(section,"BloodCastleMixRate8_AL1",0,path);

	this->m_BloodCastleMixRate8[2] = GetPrivateProfileInt(section,"BloodCastleMixRate8_AL2",0,path);

	this->m_BloodCastleMixRate8[3] = GetPrivateProfileInt(section,"BloodCastleMixRate8_AL3",0,path);

	this->m_Wing1MixRate[0] = GetPrivateProfileInt(section,"Wing1MixRate_AL0",0,path);

	this->m_Wing1MixRate[1] = GetPrivateProfileInt(section,"Wing1MixRate_AL1",0,path);

	this->m_Wing1MixRate[2] = GetPrivateProfileInt(section,"Wing1MixRate_AL2",0,path);

	this->m_Wing1MixRate[3] = GetPrivateProfileInt(section,"Wing1MixRate_AL3",0,path);

	this->m_PetMixRate[0] = GetPrivateProfileInt(section,"PetMixRate_AL0",0,path);

	this->m_PetMixRate[1] = GetPrivateProfileInt(section,"PetMixRate_AL1",0,path);

	this->m_PetMixRate[2] = GetPrivateProfileInt(section,"PetMixRate_AL2",0,path);

	this->m_PetMixRate[3] = GetPrivateProfileInt(section,"PetMixRate_AL3",0,path);

	this->m_PieceOfHornMixRate[0] = GetPrivateProfileInt(section,"PieceOfHornMixRate_AL0",0,path);

	this->m_PieceOfHornMixRate[1] = GetPrivateProfileInt(section,"PieceOfHornMixRate_AL1",0,path);

	this->m_PieceOfHornMixRate[2] = GetPrivateProfileInt(section,"PieceOfHornMixRate_AL2",0,path);

	this->m_PieceOfHornMixRate[3] = GetPrivateProfileInt(section,"PieceOfHornMixRate_AL3",0,path);

	this->m_BrokenHornMixRate[0] = GetPrivateProfileInt(section,"BrokenHornMixRate_AL0",0,path);

	this->m_BrokenHornMixRate[1] = GetPrivateProfileInt(section,"BrokenHornMixRate_AL1",0,path);

	this->m_BrokenHornMixRate[2] = GetPrivateProfileInt(section,"BrokenHornMixRate_AL2",0,path);

	this->m_BrokenHornMixRate[3] = GetPrivateProfileInt(section,"BrokenHornMixRate_AL3",0,path);

	this->m_HornOfFenrirMixRate[0] = GetPrivateProfileInt(section,"HornOfFenrirMixRate_AL0",0,path);

	this->m_HornOfFenrirMixRate[1] = GetPrivateProfileInt(section,"HornOfFenrirMixRate_AL1",0,path);

	this->m_HornOfFenrirMixRate[2] = GetPrivateProfileInt(section,"HornOfFenrirMixRate_AL2",0,path);

	this->m_HornOfFenrirMixRate[3] = GetPrivateProfileInt(section,"HornOfFenrirMixRate_AL3",0,path);

	this->m_HornOfFenrirUpgradeMixRate[0] = GetPrivateProfileInt(section,"HornOfFenrirUpgradeMixRate_AL0",0,path);

	this->m_HornOfFenrirUpgradeMixRate[1] = GetPrivateProfileInt(section,"HornOfFenrirUpgradeMixRate_AL1",0,path);

	this->m_HornOfFenrirUpgradeMixRate[2] = GetPrivateProfileInt(section,"HornOfFenrirUpgradeMixRate_AL2",0,path);

	this->m_HornOfFenrirUpgradeMixRate[3] = GetPrivateProfileInt(section,"HornOfFenrirUpgradeMixRate_AL3",0,path);

	this->m_ShieldPotionMixRate1[0] = GetPrivateProfileInt(section,"ShieldPotionMixRate1_AL0",0,path);

	this->m_ShieldPotionMixRate1[1] = GetPrivateProfileInt(section,"ShieldPotionMixRate1_AL1",0,path);

	this->m_ShieldPotionMixRate1[2] = GetPrivateProfileInt(section,"ShieldPotionMixRate1_AL2",0,path);

	this->m_ShieldPotionMixRate1[3] = GetPrivateProfileInt(section,"ShieldPotionMixRate1_AL3",0,path);

	this->m_ShieldPotionMixRate2[0] = GetPrivateProfileInt(section,"ShieldPotionMixRate2_AL0",0,path);

	this->m_ShieldPotionMixRate2[1] = GetPrivateProfileInt(section,"ShieldPotionMixRate2_AL1",0,path);

	this->m_ShieldPotionMixRate2[2] = GetPrivateProfileInt(section,"ShieldPotionMixRate2_AL2",0,path);

	this->m_ShieldPotionMixRate2[3] = GetPrivateProfileInt(section,"ShieldPotionMixRate2_AL3",0,path);

	this->m_ShieldPotionMixRate3[0] = GetPrivateProfileInt(section,"ShieldPotionMixRate3_AL0",0,path);

	this->m_ShieldPotionMixRate3[1] = GetPrivateProfileInt(section,"ShieldPotionMixRate3_AL1",0,path);

	this->m_ShieldPotionMixRate3[2] = GetPrivateProfileInt(section,"ShieldPotionMixRate3_AL2",0,path);

	this->m_ShieldPotionMixRate3[3] = GetPrivateProfileInt(section,"ShieldPotionMixRate3_AL3",0,path);

	this->m_JewelOfHarmonyItemPurityMixRate[0] = GetPrivateProfileInt(section,"JewelOfHarmonyItemPurityMixRate_AL0",0,path);

	this->m_JewelOfHarmonyItemPurityMixRate[1] = GetPrivateProfileInt(section,"JewelOfHarmonyItemPurityMixRate_AL1",0,path);

	this->m_JewelOfHarmonyItemPurityMixRate[2] = GetPrivateProfileInt(section,"JewelOfHarmonyItemPurityMixRate_AL2",0,path);

	this->m_JewelOfHarmonyItemPurityMixRate[3] = GetPrivateProfileInt(section,"JewelOfHarmonyItemPurityMixRate_AL3",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate1[0] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate1_AL0",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate1[1] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate1_AL1",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate1[2] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate1_AL2",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate1[3] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate1_AL3",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate2[0] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate2_AL0",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate2[1] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate2_AL1",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate2[2] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate2_AL2",0,path);

	this->m_JewelOfHarmonyItemSmeltMixRate2[3] = GetPrivateProfileInt(section,"JewelOfHarmonyItemSmeltMixRate2_AL3",0,path);

	this->m_JewelOfHarmonyItemRestoreMixRate[0] = GetPrivateProfileInt(section,"JewelOfHarmonyItemRestoreMixRate_AL0",0,path);

	this->m_JewelOfHarmonyItemRestoreMixRate[1] = GetPrivateProfileInt(section,"JewelOfHarmonyItemRestoreMixRate_AL1",0,path);

	this->m_JewelOfHarmonyItemRestoreMixRate[2] = GetPrivateProfileInt(section,"JewelOfHarmonyItemRestoreMixRate_AL2",0,path);

	this->m_JewelOfHarmonyItemRestoreMixRate[3] = GetPrivateProfileInt(section,"JewelOfHarmonyItemRestoreMixRate_AL3",0,path);

	this->m_Item380MixRate1[0] = GetPrivateProfileInt(section,"Item380MixRate1_AL0",0,path);

	this->m_Item380MixRate1[1] = GetPrivateProfileInt(section,"Item380MixRate1_AL1",0,path);

	this->m_Item380MixRate1[2] = GetPrivateProfileInt(section,"Item380MixRate1_AL2",0,path);

	this->m_Item380MixRate1[3] = GetPrivateProfileInt(section,"Item380MixRate1_AL3",0,path);

	this->m_Item380MixRate2[0] = GetPrivateProfileInt(section,"Item380MixRate2_AL0",0,path);

	this->m_Item380MixRate2[1] = GetPrivateProfileInt(section,"Item380MixRate2_AL1",0,path);

	this->m_Item380MixRate2[2] = GetPrivateProfileInt(section,"Item380MixRate2_AL2",0,path);

	this->m_Item380MixRate2[3] = GetPrivateProfileInt(section,"Item380MixRate2_AL3",0,path);

	this->m_IllusionTempleMixRate1[0] = GetPrivateProfileInt(section,"IllusionTempleMixRate1_AL0",0,path);

	this->m_IllusionTempleMixRate1[1] = GetPrivateProfileInt(section,"IllusionTempleMixRate1_AL1",0,path);

	this->m_IllusionTempleMixRate1[2] = GetPrivateProfileInt(section,"IllusionTempleMixRate1_AL2",0,path);

	this->m_IllusionTempleMixRate1[3] = GetPrivateProfileInt(section,"IllusionTempleMixRate1_AL3",0,path);

	this->m_IllusionTempleMixRate2[0] = GetPrivateProfileInt(section,"IllusionTempleMixRate2_AL0",0,path);

	this->m_IllusionTempleMixRate2[1] = GetPrivateProfileInt(section,"IllusionTempleMixRate2_AL1",0,path);

	this->m_IllusionTempleMixRate2[2] = GetPrivateProfileInt(section,"IllusionTempleMixRate2_AL2",0,path);

	this->m_IllusionTempleMixRate2[3] = GetPrivateProfileInt(section,"IllusionTempleMixRate2_AL3",0,path);

	this->m_IllusionTempleMixRate3[0] = GetPrivateProfileInt(section,"IllusionTempleMixRate3_AL0",0,path);

	this->m_IllusionTempleMixRate3[1] = GetPrivateProfileInt(section,"IllusionTempleMixRate3_AL1",0,path);

	this->m_IllusionTempleMixRate3[2] = GetPrivateProfileInt(section,"IllusionTempleMixRate3_AL2",0,path);

	this->m_IllusionTempleMixRate3[3] = GetPrivateProfileInt(section,"IllusionTempleMixRate3_AL3",0,path);

	this->m_IllusionTempleMixRate4[0] = GetPrivateProfileInt(section,"IllusionTempleMixRate4_AL0",0,path);

	this->m_IllusionTempleMixRate4[1] = GetPrivateProfileInt(section,"IllusionTempleMixRate4_AL1",0,path);

	this->m_IllusionTempleMixRate4[2] = GetPrivateProfileInt(section,"IllusionTempleMixRate4_AL2",0,path);

	this->m_IllusionTempleMixRate4[3] = GetPrivateProfileInt(section,"IllusionTempleMixRate4_AL3",0,path);

	this->m_IllusionTempleMixRate5[0] = GetPrivateProfileInt(section,"IllusionTempleMixRate5_AL0",0,path);

	this->m_IllusionTempleMixRate5[1] = GetPrivateProfileInt(section,"IllusionTempleMixRate5_AL1",0,path);

	this->m_IllusionTempleMixRate5[2] = GetPrivateProfileInt(section,"IllusionTempleMixRate5_AL2",0,path);

	this->m_IllusionTempleMixRate5[3] = GetPrivateProfileInt(section,"IllusionTempleMixRate5_AL3",0,path);

	this->m_IllusionTempleMixRate6[0] = GetPrivateProfileInt(section,"IllusionTempleMixRate6_AL0",0,path);

	this->m_IllusionTempleMixRate6[1] = GetPrivateProfileInt(section,"IllusionTempleMixRate6_AL1",0,path);

	this->m_IllusionTempleMixRate6[2] = GetPrivateProfileInt(section,"IllusionTempleMixRate6_AL2",0,path);

	this->m_IllusionTempleMixRate6[3] = GetPrivateProfileInt(section,"IllusionTempleMixRate6_AL3",0,path);

	this->m_FeatherOfCondorMixRate[0] = GetPrivateProfileInt(section,"FeatherOfCondorMixRate_AL0",0,path);

	this->m_FeatherOfCondorMixRate[1] = GetPrivateProfileInt(section,"FeatherOfCondorMixRate_AL1",0,path);

	this->m_FeatherOfCondorMixRate[2] = GetPrivateProfileInt(section,"FeatherOfCondorMixRate_AL2",0,path);

	this->m_FeatherOfCondorMixRate[3] = GetPrivateProfileInt(section,"FeatherOfCondorMixRate_AL3",0,path);

	this->m_Wing3MixRate[0] = GetPrivateProfileInt(section,"Wing3MixRate_AL0",0,path);

	this->m_Wing3MixRate[1] = GetPrivateProfileInt(section,"Wing3MixRate_AL1",0,path);

	this->m_Wing3MixRate[2] = GetPrivateProfileInt(section,"Wing3MixRate_AL2",0,path);

	this->m_Wing3MixRate[3] = GetPrivateProfileInt(section,"Wing3MixRate_AL3",0,path);
//garuda feather
	this->m_GarudaFeatherMixRate[0] = GetPrivateProfileInt(section,"GarudaFeatherMixRate_AL0",0,path);

	this->m_GarudaFeatherMixRate[1] = GetPrivateProfileInt(section,"GarudaFeatherMixRate_AL1",0,path);

	this->m_GarudaFeatherMixRate[2] = GetPrivateProfileInt(section,"GarudaFeatherMixRate_AL2",0,path);

	this->m_GarudaFeatherMixRate[3] = GetPrivateProfileInt(section,"GarudaFeatherMixRate_AL3",0,path);
//alas level 4 + garuda

	this->m_Wing4MixRate[0] = GetPrivateProfileInt(section,"Wing4MixRate_AL0",0,path);

	this->m_Wing4MixRate[1] = GetPrivateProfileInt(section,"Wing4MixRate_AL1",0,path);

	this->m_Wing4MixRate[2] = GetPrivateProfileInt(section,"Wing4MixRate_AL2",0,path);

	this->m_Wing4MixRate[3] = GetPrivateProfileInt(section,"Wing4MixRate_AL3",0,path);

	#if(GAMESERVER_UPDATE>=401)

	this->m_SocketItemCreateSeedMixRate[0] = GetPrivateProfileInt(section,"SocketItemCreateSeedMixRate_AL0",0,path);

	this->m_SocketItemCreateSeedMixRate[1] = GetPrivateProfileInt(section,"SocketItemCreateSeedMixRate_AL1",0,path);

	this->m_SocketItemCreateSeedMixRate[2] = GetPrivateProfileInt(section,"SocketItemCreateSeedMixRate_AL2",0,path);

	this->m_SocketItemCreateSeedMixRate[3] = GetPrivateProfileInt(section,"SocketItemCreateSeedMixRate_AL3",0,path);

	this->m_SocketItemCreateSeedSphereMixRate[0] = GetPrivateProfileInt(section,"SocketItemCreateSeedSphereMixRate_AL0",0,path);

	this->m_SocketItemCreateSeedSphereMixRate[1] = GetPrivateProfileInt(section,"SocketItemCreateSeedSphereMixRate_AL1",0,path);

	this->m_SocketItemCreateSeedSphereMixRate[2] = GetPrivateProfileInt(section,"SocketItemCreateSeedSphereMixRate_AL2",0,path);

	this->m_SocketItemCreateSeedSphereMixRate[3] = GetPrivateProfileInt(section,"SocketItemCreateSeedSphereMixRate_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=801)

	this->m_SummonScrollMixRate1[0] = GetPrivateProfileInt(section,"SummonScrollMixRate1_AL0",0,path);

	this->m_SummonScrollMixRate1[1] = GetPrivateProfileInt(section,"SummonScrollMixRate1_AL1",0,path);

	this->m_SummonScrollMixRate1[2] = GetPrivateProfileInt(section,"SummonScrollMixRate1_AL2",0,path);

	this->m_SummonScrollMixRate1[3] = GetPrivateProfileInt(section,"SummonScrollMixRate1_AL3",0,path);

	this->m_SummonScrollMixRate2[0] = GetPrivateProfileInt(section,"SummonScrollMixRate2_AL0",0,path);

	this->m_SummonScrollMixRate2[1] = GetPrivateProfileInt(section,"SummonScrollMixRate2_AL1",0,path);

	this->m_SummonScrollMixRate2[2] = GetPrivateProfileInt(section,"SummonScrollMixRate2_AL2",0,path);

	this->m_SummonScrollMixRate2[3] = GetPrivateProfileInt(section,"SummonScrollMixRate2_AL3",0,path);

	this->m_SummonScrollMixRate3[0] = GetPrivateProfileInt(section,"SummonScrollMixRate3_AL0",0,path);

	this->m_SummonScrollMixRate3[1] = GetPrivateProfileInt(section,"SummonScrollMixRate3_AL1",0,path);

	this->m_SummonScrollMixRate3[2] = GetPrivateProfileInt(section,"SummonScrollMixRate3_AL2",0,path);

	this->m_SummonScrollMixRate3[3] = GetPrivateProfileInt(section,"SummonScrollMixRate3_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=602)

	this->m_LuckyItemRefineMixRate1[0] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate1_AL0",0,path);

	this->m_LuckyItemRefineMixRate1[1] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate1_AL1",0,path);

	this->m_LuckyItemRefineMixRate1[2] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate1_AL2",0,path);

	this->m_LuckyItemRefineMixRate1[3] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate1_AL3",0,path);

	this->m_LuckyItemRefineMixRate2[0] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate2_AL0",0,path);

	this->m_LuckyItemRefineMixRate2[1] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate2_AL1",0,path);

	this->m_LuckyItemRefineMixRate2[2] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate2_AL2",0,path);

	this->m_LuckyItemRefineMixRate2[3] = GetPrivateProfileInt(section,"LuckyItemRefineMixRate2_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=701)

	this->m_MonsterWingMixRate[0] = GetPrivateProfileInt(section,"MonsterWingMixRate_AL0",0,path);

	this->m_MonsterWingMixRate[1] = GetPrivateProfileInt(section,"MonsterWingMixRate_AL1",0,path);

	this->m_MonsterWingMixRate[2] = GetPrivateProfileInt(section,"MonsterWingMixRate_AL2",0,path);

	this->m_MonsterWingMixRate[3] = GetPrivateProfileInt(section,"MonsterWingMixRate_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=701)

	this->m_SocketWeaponMixRate[0] = GetPrivateProfileInt(section,"SocketWeaponMixRate_AL0",0,path);

	this->m_SocketWeaponMixRate[1] = GetPrivateProfileInt(section,"SocketWeaponMixRate_AL1",0,path);

	this->m_SocketWeaponMixRate[2] = GetPrivateProfileInt(section,"SocketWeaponMixRate_AL2",0,path);

	this->m_SocketWeaponMixRate[3] = GetPrivateProfileInt(section,"SocketWeaponMixRate_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=701)

	this->m_PentagramMithrilMixRate[0] = GetPrivateProfileInt(section,"PentagramMithrilMixRate_AL0",0,path);

	this->m_PentagramMithrilMixRate[1] = GetPrivateProfileInt(section,"PentagramMithrilMixRate_AL1",0,path);

	this->m_PentagramMithrilMixRate[2] = GetPrivateProfileInt(section,"PentagramMithrilMixRate_AL2",0,path);

	this->m_PentagramMithrilMixRate[3] = GetPrivateProfileInt(section,"PentagramMithrilMixRate_AL3",0,path);

	this->m_PentagramElixirMixRate[0] = GetPrivateProfileInt(section,"PentagramElixirMixRate_AL0",0,path);

	this->m_PentagramElixirMixRate[1] = GetPrivateProfileInt(section,"PentagramElixirMixRate_AL1",0,path);

	this->m_PentagramElixirMixRate[2] = GetPrivateProfileInt(section,"PentagramElixirMixRate_AL2",0,path);

	this->m_PentagramElixirMixRate[3] = GetPrivateProfileInt(section,"PentagramElixirMixRate_AL3",0,path);

	this->m_PentagramJewelMixRate[0] = GetPrivateProfileInt(section,"PentagramJewelMixRate_AL0",0,path);

	this->m_PentagramJewelMixRate[1] = GetPrivateProfileInt(section,"PentagramJewelMixRate_AL1",0,path);

	this->m_PentagramJewelMixRate[2] = GetPrivateProfileInt(section,"PentagramJewelMixRate_AL2",0,path);

	this->m_PentagramJewelMixRate[3] = GetPrivateProfileInt(section,"PentagramJewelMixRate_AL3",0,path);

	this->m_PentagramDecompositeMixRate[0] = GetPrivateProfileInt(section,"PentagramDecompositeMixRate_AL0",0,path);

	this->m_PentagramDecompositeMixRate[1] = GetPrivateProfileInt(section,"PentagramDecompositeMixRate_AL1",0,path);

	this->m_PentagramDecompositeMixRate[2] = GetPrivateProfileInt(section,"PentagramDecompositeMixRate_AL2",0,path);

	this->m_PentagramDecompositeMixRate[3] = GetPrivateProfileInt(section,"PentagramDecompositeMixRate_AL3",0,path);

	#endif
}

void CServerInfo::ReadCharacterInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	this->m_DuelDamageRate = GetPrivateProfileInt(section,"DuelDamageRate",0,path);

	#if(GAMESERVER_UPDATE>=501)

	this->m_GensDamageRate = GetPrivateProfileInt(section,"GensDamageRate",0,path);

	#endif

	this->m_CustomArenaDamageRate = GetPrivateProfileInt(section,"CustomArenaDamageRate",0,path);

	this->m_ChaosCastleDamageRate = GetPrivateProfileInt(section,"ChaosCastleDamageRate",0,path);

	this->m_IllusionTempleDamageRate = GetPrivateProfileInt(section,"IllusionTempleDamageRate",0,path);

	this->m_CastleSiegeDamageRate1 = GetPrivateProfileInt(section,"CastleSiegeDamageRate1",0,path);

	this->m_CastleSiegeDamageRate2 = GetPrivateProfileInt(section,"CastleSiegeDamageRate2",0,path);

	this->m_CastleSiegeDamageRate3 = GetPrivateProfileInt(section,"CastleSiegeDamageRate3",0,path);

	this->m_GeneralDamageRatePvP = GetPrivateProfileInt(section,"GeneralDamageRatePvP",0,path);

	this->m_GeneralDamageRatePvM = GetPrivateProfileInt(section,"GeneralDamageRatePvM",0,path);

	this->m_ReflectDamageRatePvP = GetPrivateProfileInt(section,"ReflectDamageRatePvP",0,path);

	this->m_ReflectDamageRatePvM = GetPrivateProfileInt(section,"ReflectDamageRatePvM",0,path);

	this->m_DamageRatePvP[0] = GetPrivateProfileInt(section,"DWDamageRatePvP",0,path);

	this->m_DamageRatePvP[1] = GetPrivateProfileInt(section,"DKDamageRatePvP",0,path);

	this->m_DamageRatePvP[2] = GetPrivateProfileInt(section,"FEDamageRatePvP",0,path);

	this->m_DamageRatePvP[3] = GetPrivateProfileInt(section,"MGDamageRatePvP",0,path);

	this->m_DamageRatePvP[4] = GetPrivateProfileInt(section,"DLDamageRatePvP",0,path);

	this->m_DamageRatePvP[5] = GetPrivateProfileInt(section,"SUDamageRatePvP",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRatePvP[6] = GetPrivateProfileInt(section,"RFDamageRatePvP",0,path);

	#endif

	this->m_DamageRatePvM[0] = GetPrivateProfileInt(section,"DWDamageRatePvM",0,path);

	this->m_DamageRatePvM[1] = GetPrivateProfileInt(section,"DKDamageRatePvM",0,path);

	this->m_DamageRatePvM[2] = GetPrivateProfileInt(section,"FEDamageRatePvM",0,path);

	this->m_DamageRatePvM[3] = GetPrivateProfileInt(section,"MGDamageRatePvM",0,path);

	this->m_DamageRatePvM[4] = GetPrivateProfileInt(section,"DLDamageRatePvM",0,path);

	this->m_DamageRatePvM[5] = GetPrivateProfileInt(section,"SUDamageRatePvM",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRatePvM[6] = GetPrivateProfileInt(section,"RFDamageRatePvM",0,path);

	#endif

	this->m_DamageRateTo[0][0] = GetPrivateProfileInt(section,"DWDamageRateToDW",0,path);

	this->m_DamageRateTo[0][1] = GetPrivateProfileInt(section,"DWDamageRateToDK",0,path);

	this->m_DamageRateTo[0][2] = GetPrivateProfileInt(section,"DWDamageRateToFE",0,path);

	this->m_DamageRateTo[0][3] = GetPrivateProfileInt(section,"DWDamageRateToMG",0,path);

	this->m_DamageRateTo[0][4] = GetPrivateProfileInt(section,"DWDamageRateToDL",0,path);

	this->m_DamageRateTo[0][5] = GetPrivateProfileInt(section,"DWDamageRateToSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[0][6] = GetPrivateProfileInt(section,"DWDamageRateToRF",0,path);

	#endif

	this->m_DamageRateTo[1][0] = GetPrivateProfileInt(section,"DKDamageRateToDW",0,path);

	this->m_DamageRateTo[1][1] = GetPrivateProfileInt(section,"DKDamageRateToDK",0,path);

	this->m_DamageRateTo[1][2] = GetPrivateProfileInt(section,"DKDamageRateToFE",0,path);

	this->m_DamageRateTo[1][3] = GetPrivateProfileInt(section,"DKDamageRateToMG",0,path);

	this->m_DamageRateTo[1][4] = GetPrivateProfileInt(section,"DKDamageRateToDL",0,path);

	this->m_DamageRateTo[1][5] = GetPrivateProfileInt(section,"DKDamageRateToSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[1][6] = GetPrivateProfileInt(section,"DKDamageRateToRF",0,path);

	#endif

	this->m_DamageRateTo[2][0] = GetPrivateProfileInt(section,"FEDamageRateToDW",0,path);

	this->m_DamageRateTo[2][1] = GetPrivateProfileInt(section,"FEDamageRateToDK",0,path);

	this->m_DamageRateTo[2][2] = GetPrivateProfileInt(section,"FEDamageRateToFE",0,path);

	this->m_DamageRateTo[2][3] = GetPrivateProfileInt(section,"FEDamageRateToMG",0,path);

	this->m_DamageRateTo[2][4] = GetPrivateProfileInt(section,"FEDamageRateToDL",0,path);

	this->m_DamageRateTo[2][5] = GetPrivateProfileInt(section,"FEDamageRateToSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[2][6] = GetPrivateProfileInt(section,"FEDamageRateToRF",0,path);

	#endif

	this->m_DamageRateTo[3][0] = GetPrivateProfileInt(section,"MGDamageRateToDW",0,path);

	this->m_DamageRateTo[3][1] = GetPrivateProfileInt(section,"MGDamageRateToDK",0,path);

	this->m_DamageRateTo[3][2] = GetPrivateProfileInt(section,"MGDamageRateToFE",0,path);

	this->m_DamageRateTo[3][3] = GetPrivateProfileInt(section,"MGDamageRateToMG",0,path);

	this->m_DamageRateTo[3][4] = GetPrivateProfileInt(section,"MGDamageRateToDL",0,path);

	this->m_DamageRateTo[3][5] = GetPrivateProfileInt(section,"MGDamageRateToSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[3][6] = GetPrivateProfileInt(section,"MGDamageRateToRF",0,path);

	#endif

	this->m_DamageRateTo[4][0] = GetPrivateProfileInt(section,"DLDamageRateToDW",0,path);

	this->m_DamageRateTo[4][1] = GetPrivateProfileInt(section,"DLDamageRateToDK",0,path);

	this->m_DamageRateTo[4][2] = GetPrivateProfileInt(section,"DLDamageRateToFE",0,path);

	this->m_DamageRateTo[4][3] = GetPrivateProfileInt(section,"DLDamageRateToMG",0,path);

	this->m_DamageRateTo[4][4] = GetPrivateProfileInt(section,"DLDamageRateToDL",0,path);

	this->m_DamageRateTo[4][5] = GetPrivateProfileInt(section,"DLDamageRateToSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[4][6] = GetPrivateProfileInt(section,"DLDamageRateToRF",0,path);

	#endif

	this->m_DamageRateTo[5][0] = GetPrivateProfileInt(section,"SUDamageRateToDW",0,path);

	this->m_DamageRateTo[5][1] = GetPrivateProfileInt(section,"SUDamageRateToDK",0,path);

	this->m_DamageRateTo[5][2] = GetPrivateProfileInt(section,"SUDamageRateToFE",0,path);

	this->m_DamageRateTo[5][3] = GetPrivateProfileInt(section,"SUDamageRateToMG",0,path);

	this->m_DamageRateTo[5][4] = GetPrivateProfileInt(section,"SUDamageRateToDL",0,path);

	this->m_DamageRateTo[5][5] = GetPrivateProfileInt(section,"SUDamageRateToSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[5][6] = GetPrivateProfileInt(section,"SUDamageRateToRF",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageRateTo[6][0] = GetPrivateProfileInt(section,"RFDamageRateToDW",0,path);

	this->m_DamageRateTo[6][1] = GetPrivateProfileInt(section,"RFDamageRateToDK",0,path);

	this->m_DamageRateTo[6][2] = GetPrivateProfileInt(section,"RFDamageRateToFE",0,path);

	this->m_DamageRateTo[6][3] = GetPrivateProfileInt(section,"RFDamageRateToMG",0,path);

	this->m_DamageRateTo[6][4] = GetPrivateProfileInt(section,"RFDamageRateToDL",0,path);

	this->m_DamageRateTo[6][5] = GetPrivateProfileInt(section,"RFDamageRateToSU",0,path);

	this->m_DamageRateTo[6][6] = GetPrivateProfileInt(section,"RFDamageRateToRF",0,path);

	#endif

	this->m_DamageStuckRate[0] = GetPrivateProfileInt(section,"DWDamageStuckRate",0,path);

	this->m_DamageStuckRate[1] = GetPrivateProfileInt(section,"DKDamageStuckRate",0,path);

	this->m_DamageStuckRate[2] = GetPrivateProfileInt(section,"FEDamageStuckRate",0,path);

	this->m_DamageStuckRate[3] = GetPrivateProfileInt(section,"MGDamageStuckRate",0,path);

	this->m_DamageStuckRate[4] = GetPrivateProfileInt(section,"DLDamageStuckRate",0,path);

	this->m_DamageStuckRate[5] = GetPrivateProfileInt(section,"SUDamageStuckRate",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_DamageStuckRate[6] = GetPrivateProfileInt(section,"RFDamageStuckRate",0,path);

	#endif

	this->m_DKDamageMultiplierConstA = GetPrivateProfileInt(section,"DKDamageMultiplierConstA",0,path);

	this->m_DLDamageMultiplierConstA = GetPrivateProfileInt(section,"DLDamageMultiplierConstA",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFDamageMultiplierConstA = GetPrivateProfileInt(section,"RFDamageMultiplierConstA",0,path);

	this->m_RFDamageMultiplierConstB = GetPrivateProfileInt(section,"RFDamageMultiplierConstB",0,path);

	this->m_RFDamageMultiplierConstC = GetPrivateProfileInt(section,"RFDamageMultiplierConstC",0,path);

	#endif

	this->m_DKDamageMultiplierMaxRate = GetPrivateProfileInt(section,"DKDamageMultiplierMaxRate",0,path);

	this->m_DLDamageMultiplierMaxRate = GetPrivateProfileInt(section,"DLDamageMultiplierMaxRate",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFDamageMultiplierMaxRate = GetPrivateProfileInt(section,"RFDamageMultiplierMaxRate",0,path);

	#endif

	this->m_DarkSpiritRangeAttackRate = GetPrivateProfileInt(section,"DarkSpiritRangeAttackRate",0,path);

	this->m_DarkSpiritCriticalDamageRate = GetPrivateProfileInt(section,"DarkSpiritCriticalDamageRate",0,path);

	this->m_DarkSpiritExcellentDamageRate = GetPrivateProfileInt(section,"DarkSpiritExcellentDamageRate",0,path);

	this->m_DarkSpiritAttackDamageMinConstA = GetPrivateProfileInt(section,"DarkSpiritAttackDamageMinConstA",0,path);

	this->m_DarkSpiritAttackDamageMinConstB = GetPrivateProfileInt(section,"DarkSpiritAttackDamageMinConstB",0,path);

	this->m_DarkSpiritAttackDamageMinConstC = GetPrivateProfileInt(section,"DarkSpiritAttackDamageMinConstC",0,path);

	this->m_DarkSpiritAttackDamageMaxConstA = GetPrivateProfileInt(section,"DarkSpiritAttackDamageMaxConstA",0,path);

	this->m_DarkSpiritAttackDamageMaxConstB = GetPrivateProfileInt(section,"DarkSpiritAttackDamageMaxConstB",0,path);

	this->m_DarkSpiritAttackDamageMaxConstC = GetPrivateProfileInt(section,"DarkSpiritAttackDamageMaxConstC",0,path);

	this->m_DarkSpiritAttackSpeedConstA = GetPrivateProfileInt(section,"DarkSpiritAttackSpeedConstA",0,path);

	this->m_DarkSpiritAttackSpeedConstB = GetPrivateProfileInt(section,"DarkSpiritAttackSpeedConstB",0,path);

	this->m_DarkSpiritAttackSpeedConstC = GetPrivateProfileInt(section,"DarkSpiritAttackSpeedConstC",0,path);

	this->m_DarkSpiritAttackSpeedConstD = GetPrivateProfileInt(section,"DarkSpiritAttackSpeedConstD",0,path);

	this->m_DarkSpiritAttackSuccessRateConstA = GetPrivateProfileInt(section,"DarkSpiritAttackSuccessRateConstA",0,path);

	this->m_DarkSpiritAttackSuccessRateConstB = GetPrivateProfileInt(section,"DarkSpiritAttackSuccessRateConstB",0,path);

	this->m_DarkSpiritAttackSuccessRateConstC = GetPrivateProfileInt(section,"DarkSpiritAttackSuccessRateConstC",0,path);

	this->m_SatanIncDamageConstA = GetPrivateProfileInt(section,"SatanIncDamageConstA",0,path);

	this->m_DinorantIncDamageConstA = GetPrivateProfileInt(section,"DinorantIncDamageConstA",0,path);

	this->m_BlackFenrirIncDamageConstA = GetPrivateProfileInt(section,"BlackFenrirIncDamageConstA",0,path);

	this->m_DemonIncDamageConstA = GetPrivateProfileInt(section,"DemonIncDamageConstA",0,path);

	this->m_SkeletonIncDamageConstA = GetPrivateProfileInt(section,"SkeletonIncDamageConstA",0,path);

	this->m_AngelDecDamageConstA = GetPrivateProfileInt(section,"AngelDecDamageConstA",0,path);

	this->m_DinorantDecDamageConstA = GetPrivateProfileInt(section,"DinorantDecDamageConstA",0,path);

	this->m_DinorantDecDamageConstB = GetPrivateProfileInt(section,"DinorantDecDamageConstB",0,path);

	this->m_DarkHorseDecDamageConstA = GetPrivateProfileInt(section,"DarkHorseDecDamageConstA",0,path);

	this->m_DarkHorseDecDamageConstB = GetPrivateProfileInt(section,"DarkHorseDecDamageConstB",0,path);

	this->m_BlueFenrirDecDamageConstA = GetPrivateProfileInt(section,"BlueFenrirDecDamageConstA",0,path);

	this->m_MariaDecDamageConstA = GetPrivateProfileInt(section,"MariaDecDamageConstA",0,path);

	this->m_ComboDamageConstA = GetPrivateProfileInt(section,"ComboDamageConstA",0,path);

	this->m_ComboDamageConstB = GetPrivateProfileInt(section,"ComboDamageConstB",0,path);

	this->m_EarthquakeDamageConstA = GetPrivateProfileInt(section,"EarthquakeDamageConstA",0,path);

	this->m_EarthquakeDamageConstB = GetPrivateProfileInt(section,"EarthquakeDamageConstB",0,path);

	this->m_EarthquakeDamageConstC = GetPrivateProfileInt(section,"EarthquakeDamageConstC",0,path);

	this->m_ElectricSparkDamageConstA = GetPrivateProfileInt(section,"ElectricSparkDamageConstA",0,path);

	this->m_ElectricSparkDamageConstB = GetPrivateProfileInt(section,"ElectricSparkDamageConstB",0,path);

	this->m_DLSkillDamageConstA = GetPrivateProfileInt(section,"DLSkillDamageConstA",0,path);

	this->m_DLSkillDamageConstB = GetPrivateProfileInt(section,"DLSkillDamageConstB",0,path);

	this->m_NovaDamageConstA = GetPrivateProfileInt(section,"NovaDamageConstA",0,path);

	this->m_NovaDamageConstB = GetPrivateProfileInt(section,"NovaDamageConstB",0,path);

	this->m_NovaDamageConstC = GetPrivateProfileInt(section,"NovaDamageConstC",0,path);

	this->m_HPRecoveryRate[0] = GetPrivateProfileInt(section,"DWHPRecoveryRate",0,path);

	this->m_HPRecoveryRate[1] = GetPrivateProfileInt(section,"DKHPRecoveryRate",0,path);

	this->m_HPRecoveryRate[2] = GetPrivateProfileInt(section,"FEHPRecoveryRate",0,path);

	this->m_HPRecoveryRate[3] = GetPrivateProfileInt(section,"MGHPRecoveryRate",0,path);

	this->m_HPRecoveryRate[4] = GetPrivateProfileInt(section,"DLHPRecoveryRate",0,path);

	this->m_HPRecoveryRate[5] = GetPrivateProfileInt(section,"SUHPRecoveryRate",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_HPRecoveryRate[6] = GetPrivateProfileInt(section,"RFHPRecoveryRate",0,path);

	#endif

	this->m_MPRecoveryRate[0] = GetPrivateProfileInt(section,"DWMPRecoveryRate",0,path);

	this->m_MPRecoveryRate[1] = GetPrivateProfileInt(section,"DKMPRecoveryRate",0,path);

	this->m_MPRecoveryRate[2] = GetPrivateProfileInt(section,"FEMPRecoveryRate",0,path);

	this->m_MPRecoveryRate[3] = GetPrivateProfileInt(section,"MGMPRecoveryRate",0,path);

	this->m_MPRecoveryRate[4] = GetPrivateProfileInt(section,"DLMPRecoveryRate",0,path);

	this->m_MPRecoveryRate[5] = GetPrivateProfileInt(section,"SUMPRecoveryRate",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_MPRecoveryRate[6] = GetPrivateProfileInt(section,"RFMPRecoveryRate",0,path);

	#endif

	this->m_BPRecoveryRate[0] = GetPrivateProfileInt(section,"DWBPRecoveryRate",0,path);

	this->m_BPRecoveryRate[1] = GetPrivateProfileInt(section,"DKBPRecoveryRate",0,path);

	this->m_BPRecoveryRate[2] = GetPrivateProfileInt(section,"FEBPRecoveryRate",0,path);

	this->m_BPRecoveryRate[3] = GetPrivateProfileInt(section,"MGBPRecoveryRate",0,path);

	this->m_BPRecoveryRate[4] = GetPrivateProfileInt(section,"DLBPRecoveryRate",0,path);

	this->m_BPRecoveryRate[5] = GetPrivateProfileInt(section,"SUBPRecoveryRate",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_BPRecoveryRate[6] = GetPrivateProfileInt(section,"RFBPRecoveryRate",0,path);

	#endif

	this->m_SDRecoveryRate[0] = GetPrivateProfileInt(section,"DWSDRecoveryRate",0,path);

	this->m_SDRecoveryRate[1] = GetPrivateProfileInt(section,"DKSDRecoveryRate",0,path);

	this->m_SDRecoveryRate[2] = GetPrivateProfileInt(section,"FESDRecoveryRate",0,path);

	this->m_SDRecoveryRate[3] = GetPrivateProfileInt(section,"MGSDRecoveryRate",0,path);

	this->m_SDRecoveryRate[4] = GetPrivateProfileInt(section,"DLSDRecoveryRate",0,path);

	this->m_SDRecoveryRate[5] = GetPrivateProfileInt(section,"SUSDRecoveryRate",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_SDRecoveryRate[6] = GetPrivateProfileInt(section,"RFSDRecoveryRate",0,path);

	#endif

	this->m_DWPlasmaStormDamageConstA = GetPrivateProfileInt(section,"DWPlasmaStormDamageConstA",0,path);

	this->m_DWPlasmaStormDamageConstB = GetPrivateProfileInt(section,"DWPlasmaStormDamageConstB",0,path);

	this->m_DWPlasmaStormDamageConstC = GetPrivateProfileInt(section,"DWPlasmaStormDamageConstC",0,path);

	this->m_DWPlasmaStormDamageConstD = GetPrivateProfileInt(section,"DWPlasmaStormDamageConstD",0,path);

	this->m_DKPlasmaStormDamageConstA = GetPrivateProfileInt(section,"DKPlasmaStormDamageConstA",0,path);

	this->m_DKPlasmaStormDamageConstB = GetPrivateProfileInt(section,"DKPlasmaStormDamageConstB",0,path);

	this->m_DKPlasmaStormDamageConstC = GetPrivateProfileInt(section,"DKPlasmaStormDamageConstC",0,path);

	this->m_DKPlasmaStormDamageConstD = GetPrivateProfileInt(section,"DKPlasmaStormDamageConstD",0,path);

	this->m_FEPlasmaStormDamageConstA = GetPrivateProfileInt(section,"FEPlasmaStormDamageConstA",0,path);

	this->m_FEPlasmaStormDamageConstB = GetPrivateProfileInt(section,"FEPlasmaStormDamageConstB",0,path);

	this->m_FEPlasmaStormDamageConstC = GetPrivateProfileInt(section,"FEPlasmaStormDamageConstC",0,path);

	this->m_FEPlasmaStormDamageConstD = GetPrivateProfileInt(section,"FEPlasmaStormDamageConstD",0,path);

	this->m_MGPlasmaStormDamageConstA = GetPrivateProfileInt(section,"MGPlasmaStormDamageConstA",0,path);

	this->m_MGPlasmaStormDamageConstB = GetPrivateProfileInt(section,"MGPlasmaStormDamageConstB",0,path);

	this->m_MGPlasmaStormDamageConstC = GetPrivateProfileInt(section,"MGPlasmaStormDamageConstC",0,path);

	this->m_MGPlasmaStormDamageConstD = GetPrivateProfileInt(section,"MGPlasmaStormDamageConstD",0,path);

	this->m_DLPlasmaStormDamageConstA = GetPrivateProfileInt(section,"DLPlasmaStormDamageConstA",0,path);

	this->m_DLPlasmaStormDamageConstB = GetPrivateProfileInt(section,"DLPlasmaStormDamageConstB",0,path);

	this->m_DLPlasmaStormDamageConstC = GetPrivateProfileInt(section,"DLPlasmaStormDamageConstC",0,path);

	this->m_DLPlasmaStormDamageConstD = GetPrivateProfileInt(section,"DLPlasmaStormDamageConstD",0,path);

	this->m_DLPlasmaStormDamageConstE = GetPrivateProfileInt(section,"DLPlasmaStormDamageConstE",0,path);

	this->m_SUPlasmaStormDamageConstA = GetPrivateProfileInt(section,"SUPlasmaStormDamageConstA",0,path);

	this->m_SUPlasmaStormDamageConstB = GetPrivateProfileInt(section,"SUPlasmaStormDamageConstB",0,path);

	this->m_SUPlasmaStormDamageConstC = GetPrivateProfileInt(section,"SUPlasmaStormDamageConstC",0,path);

	this->m_SUPlasmaStormDamageConstD = GetPrivateProfileInt(section,"SUPlasmaStormDamageConstD",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFPlasmaStormDamageConstA = GetPrivateProfileInt(section,"RFPlasmaStormDamageConstA",0,path);

	this->m_RFPlasmaStormDamageConstB = GetPrivateProfileInt(section,"RFPlasmaStormDamageConstB",0,path);

	this->m_RFPlasmaStormDamageConstC = GetPrivateProfileInt(section,"RFPlasmaStormDamageConstC",0,path);

	this->m_RFPlasmaStormDamageConstD = GetPrivateProfileInt(section,"RFPlasmaStormDamageConstD",0,path);

	#endif

	this->m_DWPhysiDamageMinConstA = GetPrivateProfileInt(section,"DWPhysiDamageMinConstA",0,path);

	this->m_DWPhysiDamageMaxConstA = GetPrivateProfileInt(section,"DWPhysiDamageMaxConstA",0,path);

	this->m_DWMagicDamageMinConstA = GetPrivateProfileInt(section,"DWMagicDamageMinConstA",0,path);

	this->m_DWMagicDamageMaxConstA = GetPrivateProfileInt(section,"DWMagicDamageMaxConstA",0,path);

	this->m_DKPhysiDamageMinConstA = GetPrivateProfileInt(section,"DKPhysiDamageMinConstA",0,path);

	this->m_DKPhysiDamageMaxConstA = GetPrivateProfileInt(section,"DKPhysiDamageMaxConstA",0,path);

	this->m_DKMagicDamageMinConstA = GetPrivateProfileInt(section,"DKMagicDamageMinConstA",0,path);

	this->m_DKMagicDamageMaxConstA = GetPrivateProfileInt(section,"DKMagicDamageMaxConstA",0,path);

	this->m_FEPhysiDamageMinConstA = GetPrivateProfileInt(section,"FEPhysiDamageMinConstA",0,path);

	this->m_FEPhysiDamageMaxConstA = GetPrivateProfileInt(section,"FEPhysiDamageMaxConstA",0,path);

	this->m_FEPhysiDamageMinBowConstA = GetPrivateProfileInt(section,"FEPhysiDamageMinBowConstA",0,path);

	this->m_FEPhysiDamageMinBowConstB = GetPrivateProfileInt(section,"FEPhysiDamageMinBowConstB",0,path);

	this->m_FEPhysiDamageMaxBowConstA = GetPrivateProfileInt(section,"FEPhysiDamageMaxBowConstA",0,path);

	this->m_FEPhysiDamageMaxBowConstB = GetPrivateProfileInt(section,"FEPhysiDamageMaxBowConstB",0,path);

	this->m_FEMagicDamageMinConstA = GetPrivateProfileInt(section,"FEMagicDamageMinConstA",0,path);

	this->m_FEMagicDamageMaxConstA = GetPrivateProfileInt(section,"FEMagicDamageMaxConstA",0,path);

	this->m_MGPhysiDamageMinConstA = GetPrivateProfileInt(section,"MGPhysiDamageMinConstA",0,path);

	this->m_MGPhysiDamageMinConstB = GetPrivateProfileInt(section,"MGPhysiDamageMinConstB",0,path);

	this->m_MGPhysiDamageMaxConstA = GetPrivateProfileInt(section,"MGPhysiDamageMaxConstA",0,path);

	this->m_MGPhysiDamageMaxConstB = GetPrivateProfileInt(section,"MGPhysiDamageMaxConstB",0,path);

	this->m_MGMagicDamageMinConstA = GetPrivateProfileInt(section,"MGMagicDamageMinConstA",0,path);

	this->m_MGMagicDamageMaxConstA = GetPrivateProfileInt(section,"MGMagicDamageMaxConstA",0,path);

	this->m_DLPhysiDamageMinConstA = GetPrivateProfileInt(section,"DLPhysiDamageMinConstA",0,path);

	this->m_DLPhysiDamageMinConstB = GetPrivateProfileInt(section,"DLPhysiDamageMinConstB",0,path);

	this->m_DLPhysiDamageMaxConstA = GetPrivateProfileInt(section,"DLPhysiDamageMaxConstA",0,path);

	this->m_DLPhysiDamageMaxConstB = GetPrivateProfileInt(section,"DLPhysiDamageMaxConstB",0,path);

	this->m_DLMagicDamageMinConstA = GetPrivateProfileInt(section,"DLMagicDamageMinConstA",0,path);

	this->m_DLMagicDamageMaxConstA = GetPrivateProfileInt(section,"DLMagicDamageMaxConstA",0,path);

	this->m_SUPhysiDamageMinConstA = GetPrivateProfileInt(section,"SUPhysiDamageMinConstA",0,path);

	this->m_SUPhysiDamageMaxConstA = GetPrivateProfileInt(section,"SUPhysiDamageMaxConstA",0,path);

	this->m_SUMagicDamageMinConstA = GetPrivateProfileInt(section,"SUMagicDamageMinConstA",0,path);

	this->m_SUMagicDamageMaxConstA = GetPrivateProfileInt(section,"SUMagicDamageMaxConstA",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFPhysiDamageMinConstA = GetPrivateProfileInt(section,"RFPhysiDamageMinConstA",0,path);

	this->m_RFPhysiDamageMinConstB = GetPrivateProfileInt(section,"RFPhysiDamageMinConstB",0,path);

	this->m_RFPhysiDamageMaxConstA = GetPrivateProfileInt(section,"RFPhysiDamageMaxConstA",0,path);

	this->m_RFPhysiDamageMaxConstB = GetPrivateProfileInt(section,"RFPhysiDamageMaxConstB",0,path);

	this->m_RFMagicDamageMinConstA = GetPrivateProfileInt(section,"RFMagicDamageMinConstA",0,path);

	this->m_RFMagicDamageMaxConstA = GetPrivateProfileInt(section,"RFMagicDamageMaxConstA",0,path);

	#endif

	this->m_DWAttackSuccessRateConstA = GetPrivateProfileInt(section,"DWAttackSuccessRateConstA",0,path);

	this->m_DWAttackSuccessRateConstB = GetPrivateProfileInt(section,"DWAttackSuccessRateConstB",0,path);

	this->m_DWAttackSuccessRateConstC = GetPrivateProfileInt(section,"DWAttackSuccessRateConstC",0,path);

	this->m_DWAttackSuccessRateConstD = GetPrivateProfileInt(section,"DWAttackSuccessRateConstD",0,path);

	this->m_DKAttackSuccessRateConstA = GetPrivateProfileInt(section,"DKAttackSuccessRateConstA",0,path);

	this->m_DKAttackSuccessRateConstB = GetPrivateProfileInt(section,"DKAttackSuccessRateConstB",0,path);

	this->m_DKAttackSuccessRateConstC = GetPrivateProfileInt(section,"DKAttackSuccessRateConstC",0,path);

	this->m_DKAttackSuccessRateConstD = GetPrivateProfileInt(section,"DKAttackSuccessRateConstD",0,path);

	this->m_FEAttackSuccessRateConstA = GetPrivateProfileInt(section,"FEAttackSuccessRateConstA",0,path);

	this->m_FEAttackSuccessRateConstB = GetPrivateProfileInt(section,"FEAttackSuccessRateConstB",0,path);

	this->m_FEAttackSuccessRateConstC = GetPrivateProfileInt(section,"FEAttackSuccessRateConstC",0,path);

	this->m_FEAttackSuccessRateConstD = GetPrivateProfileInt(section,"FEAttackSuccessRateConstD",0,path);

	this->m_MGAttackSuccessRateConstA = GetPrivateProfileInt(section,"MGAttackSuccessRateConstA",0,path);

	this->m_MGAttackSuccessRateConstB = GetPrivateProfileInt(section,"MGAttackSuccessRateConstB",0,path);

	this->m_MGAttackSuccessRateConstC = GetPrivateProfileInt(section,"MGAttackSuccessRateConstC",0,path);

	this->m_MGAttackSuccessRateConstD = GetPrivateProfileInt(section,"MGAttackSuccessRateConstD",0,path);

	this->m_DLAttackSuccessRateConstA = GetPrivateProfileInt(section,"DLAttackSuccessRateConstA",0,path);

	this->m_DLAttackSuccessRateConstB = GetPrivateProfileInt(section,"DLAttackSuccessRateConstB",0,path);

	this->m_DLAttackSuccessRateConstC = GetPrivateProfileInt(section,"DLAttackSuccessRateConstC",0,path);

	this->m_DLAttackSuccessRateConstD = GetPrivateProfileInt(section,"DLAttackSuccessRateConstD",0,path);

	this->m_DLAttackSuccessRateConstE = GetPrivateProfileInt(section,"DLAttackSuccessRateConstE",0,path);

	this->m_SUAttackSuccessRateConstA = GetPrivateProfileInt(section,"SUAttackSuccessRateConstA",0,path);

	this->m_SUAttackSuccessRateConstB = GetPrivateProfileInt(section,"SUAttackSuccessRateConstB",0,path);

	this->m_SUAttackSuccessRateConstC = GetPrivateProfileInt(section,"SUAttackSuccessRateConstC",0,path);

	this->m_SUAttackSuccessRateConstD = GetPrivateProfileInt(section,"SUAttackSuccessRateConstD",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFAttackSuccessRateConstA = GetPrivateProfileInt(section,"RFAttackSuccessRateConstA",0,path);

	this->m_RFAttackSuccessRateConstB = GetPrivateProfileInt(section,"RFAttackSuccessRateConstB",0,path);

	this->m_RFAttackSuccessRateConstC = GetPrivateProfileInt(section,"RFAttackSuccessRateConstC",0,path);

	this->m_RFAttackSuccessRateConstD = GetPrivateProfileInt(section,"RFAttackSuccessRateConstD",0,path);

	#endif

	this->m_DWAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"DWAttackSuccessRatePvPConstA",0,path);

	this->m_DWAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"DWAttackSuccessRatePvPConstB",0,path);

	this->m_DWAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"DWAttackSuccessRatePvPConstC",0,path);

	this->m_DWAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"DWAttackSuccessRatePvPConstD",0,path);

	this->m_DKAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"DKAttackSuccessRatePvPConstA",0,path);

	this->m_DKAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"DKAttackSuccessRatePvPConstB",0,path);

	this->m_DKAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"DKAttackSuccessRatePvPConstC",0,path);

	this->m_DKAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"DKAttackSuccessRatePvPConstD",0,path);

	this->m_FEAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"FEAttackSuccessRatePvPConstA",0,path);

	this->m_FEAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"FEAttackSuccessRatePvPConstB",0,path);

	this->m_FEAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"FEAttackSuccessRatePvPConstC",0,path);

	this->m_FEAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"FEAttackSuccessRatePvPConstD",0,path);

	this->m_MGAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"MGAttackSuccessRatePvPConstA",0,path);

	this->m_MGAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"MGAttackSuccessRatePvPConstB",0,path);

	this->m_MGAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"MGAttackSuccessRatePvPConstC",0,path);

	this->m_MGAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"MGAttackSuccessRatePvPConstD",0,path);

	this->m_DLAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"DLAttackSuccessRatePvPConstA",0,path);

	this->m_DLAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"DLAttackSuccessRatePvPConstB",0,path);

	this->m_DLAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"DLAttackSuccessRatePvPConstC",0,path);

	this->m_DLAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"DLAttackSuccessRatePvPConstD",0,path);

	this->m_SUAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"SUAttackSuccessRatePvPConstA",0,path);

	this->m_SUAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"SUAttackSuccessRatePvPConstB",0,path);

	this->m_SUAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"SUAttackSuccessRatePvPConstC",0,path);

	this->m_SUAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"SUAttackSuccessRatePvPConstD",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFAttackSuccessRatePvPConstA = GetPrivateProfileInt(section,"RFAttackSuccessRatePvPConstA",0,path);

	this->m_RFAttackSuccessRatePvPConstB = GetPrivateProfileInt(section,"RFAttackSuccessRatePvPConstB",0,path);

	this->m_RFAttackSuccessRatePvPConstC = GetPrivateProfileInt(section,"RFAttackSuccessRatePvPConstC",0,path);

	this->m_RFAttackSuccessRatePvPConstD = GetPrivateProfileInt(section,"RFAttackSuccessRatePvPConstD",0,path);

	#endif

	this->m_DWPhysiSpeedConstA = GetPrivateProfileInt(section,"DWPhysiSpeedConstA",0,path);

	this->m_DWMagicSpeedConstA = GetPrivateProfileInt(section,"DWMagicSpeedConstA",0,path);

	this->m_DKPhysiSpeedConstA = GetPrivateProfileInt(section,"DKPhysiSpeedConstA",0,path);

	this->m_DKMagicSpeedConstA = GetPrivateProfileInt(section,"DKMagicSpeedConstA",0,path);

	this->m_FEPhysiSpeedConstA = GetPrivateProfileInt(section,"FEPhysiSpeedConstA",0,path);

	this->m_FEMagicSpeedConstA = GetPrivateProfileInt(section,"FEMagicSpeedConstA",0,path);

	this->m_MGPhysiSpeedConstA = GetPrivateProfileInt(section,"MGPhysiSpeedConstA",0,path);

	this->m_MGMagicSpeedConstA = GetPrivateProfileInt(section,"MGMagicSpeedConstA",0,path);

	this->m_DLPhysiSpeedConstA = GetPrivateProfileInt(section,"DLPhysiSpeedConstA",0,path);

	this->m_DLMagicSpeedConstA = GetPrivateProfileInt(section,"DLMagicSpeedConstA",0,path);

	this->m_SUPhysiSpeedConstA = GetPrivateProfileInt(section,"SUPhysiSpeedConstA",0,path);

	this->m_SUMagicSpeedConstA = GetPrivateProfileInt(section,"SUMagicSpeedConstA",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFPhysiSpeedConstA = GetPrivateProfileInt(section,"RFPhysiSpeedConstA",0,path);

	this->m_RFMagicSpeedConstA = GetPrivateProfileInt(section,"RFMagicSpeedConstA",0,path);

	#endif

	this->m_DWDefenseSuccessRateConstA = GetPrivateProfileInt(section,"DWDefenseSuccessRateConstA",0,path);

	this->m_DKDefenseSuccessRateConstA = GetPrivateProfileInt(section,"DKDefenseSuccessRateConstA",0,path);

	this->m_FEDefenseSuccessRateConstA = GetPrivateProfileInt(section,"FEDefenseSuccessRateConstA",0,path);

	this->m_MGDefenseSuccessRateConstA = GetPrivateProfileInt(section,"MGDefenseSuccessRateConstA",0,path);

	this->m_DLDefenseSuccessRateConstA = GetPrivateProfileInt(section,"DLDefenseSuccessRateConstA",0,path);

	this->m_SUDefenseSuccessRateConstA = GetPrivateProfileInt(section,"SUDefenseSuccessRateConstA",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFDefenseSuccessRateConstA = GetPrivateProfileInt(section,"RFDefenseSuccessRateConstA",0,path);

	#endif

	this->m_DWDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"DWDefenseSuccessRatePvPConstA",0,path);

	this->m_DWDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"DWDefenseSuccessRatePvPConstB",0,path);

	this->m_DWDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"DWDefenseSuccessRatePvPConstC",0,path);

	this->m_DKDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"DKDefenseSuccessRatePvPConstA",0,path);

	this->m_DKDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"DKDefenseSuccessRatePvPConstB",0,path);

	this->m_DKDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"DKDefenseSuccessRatePvPConstC",0,path);

	this->m_FEDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"FEDefenseSuccessRatePvPConstA",0,path);

	this->m_FEDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"FEDefenseSuccessRatePvPConstB",0,path);

	this->m_FEDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"FEDefenseSuccessRatePvPConstC",0,path);

	this->m_MGDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"MGDefenseSuccessRatePvPConstA",0,path);

	this->m_MGDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"MGDefenseSuccessRatePvPConstB",0,path);

	this->m_MGDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"MGDefenseSuccessRatePvPConstC",0,path);

	this->m_DLDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"DLDefenseSuccessRatePvPConstA",0,path);

	this->m_DLDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"DLDefenseSuccessRatePvPConstB",0,path);

	this->m_DLDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"DLDefenseSuccessRatePvPConstC",0,path);

	this->m_SUDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"SUDefenseSuccessRatePvPConstA",0,path);

	this->m_SUDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"SUDefenseSuccessRatePvPConstB",0,path);

	this->m_SUDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"SUDefenseSuccessRatePvPConstC",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFDefenseSuccessRatePvPConstA = GetPrivateProfileInt(section,"RFDefenseSuccessRatePvPConstA",0,path);

	this->m_RFDefenseSuccessRatePvPConstB = GetPrivateProfileInt(section,"RFDefenseSuccessRatePvPConstB",0,path);

	this->m_RFDefenseSuccessRatePvPConstC = GetPrivateProfileInt(section,"RFDefenseSuccessRatePvPConstC",0,path);

	#endif

	this->m_DWDefenseConstA = GetPrivateProfileInt(section,"DWDefenseConstA",0,path);

	this->m_DKDefenseConstA = GetPrivateProfileInt(section,"DKDefenseConstA",0,path);

	this->m_FEDefenseConstA = GetPrivateProfileInt(section,"FEDefenseConstA",0,path);

	this->m_MGDefenseConstA = GetPrivateProfileInt(section,"MGDefenseConstA",0,path);

	this->m_DLDefenseConstA = GetPrivateProfileInt(section,"DLDefenseConstA",0,path);

	this->m_SUDefenseConstA = GetPrivateProfileInt(section,"SUDefenseConstA",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFDefenseConstA = GetPrivateProfileInt(section,"RFDefenseConstA",0,path);

	#endif

	
	this->m_nReflectDamageRatePvP[0] = GetPrivateProfileInt(section,"DWReflectDamageRatePvP",0,path);

	this->m_nReflectDamageRatePvP[1] = GetPrivateProfileInt(section,"DKReflectDamageRatePvP",0,path);

	this->m_nReflectDamageRatePvP[2] = GetPrivateProfileInt(section,"FEReflectDamageRatePvP",0,path);

	this->m_nReflectDamageRatePvP[3] = GetPrivateProfileInt(section,"MGReflectDamageRatePvP",0,path);

	this->m_nReflectDamageRatePvP[4] = GetPrivateProfileInt(section,"DLReflectDamageRatePvP",0,path);

	this->m_nReflectDamageRatePvP[5] = GetPrivateProfileInt(section,"SUReflectDamageRatePvP",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_nReflectDamageRatePvP[6] = GetPrivateProfileInt(section,"RFReflectDamageRatePvP",0,path);

	#endif

	this->m_UnlimitedBoltArrowEnable = GetPrivateProfileInt(section,"UnlimitedBoltArrowEnable",0,path);

	this->m_UnlimitedBoltArrowLevel = GetPrivateProfileInt(section,"UnlimitedBoltArrowLevel",0,path);

	this->m_PoisonDamageDWRate = GetPrivateProfileInt(section,"PoisonDamageDWRate",0,path);

	this->m_PoisonDamageDWTime = GetPrivateProfileInt(section,"PoisonDamageDWTime ",0,path);

	//--

	this->m_nReflectDamageRatePvM[0] = GetPrivateProfileInt(section,"DWReflectDamageRatePvM",0,path);

	this->m_nReflectDamageRatePvM[1] = GetPrivateProfileInt(section,"DKReflectDamageRatePvM",0,path);

	this->m_nReflectDamageRatePvM[2] = GetPrivateProfileInt(section,"FEReflectDamageRatePvM",0,path);

	this->m_nReflectDamageRatePvM[3] = GetPrivateProfileInt(section,"MGReflectDamageRatePvM",0,path);

	this->m_nReflectDamageRatePvM[4] = GetPrivateProfileInt(section,"DLReflectDamageRatePvM",0,path);

	this->m_nReflectDamageRatePvM[5] = GetPrivateProfileInt(section,"SUReflectDamageRatePvM",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_nReflectDamageRatePvM[6] = GetPrivateProfileInt(section,"RFReflectDamageRatePvM",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=701)

	this->m_DuelElementalDamageRate = GetPrivateProfileInt(section,"DuelElementalDamageRate",0,path);

	this->m_GensElementalDamageRate = GetPrivateProfileInt(section,"GensElementalDamageRate",0,path);

	this->m_CustomArenaElementalDamageRate = GetPrivateProfileInt(section,"CustomArenaElementalDamageRate",0,path);

	this->m_ChaosCastleElementalDamageRate = GetPrivateProfileInt(section,"ChaosCastleElementalDamageRate",0,path);

	this->m_IllusionTempleElementalDamageRate = GetPrivateProfileInt(section,"IllusionTempleElementalDamageRate",0,path);

	this->m_CastleSiegeElementalDamageRate1 = GetPrivateProfileInt(section,"CastleSiegeElementalDamageRate1",0,path);

	this->m_CastleSiegeElementalDamageRate2 = GetPrivateProfileInt(section,"CastleSiegeElementalDamageRate2",0,path);

	this->m_GeneralElementalDamageRatePvP = GetPrivateProfileInt(section,"GeneralElementalDamageRatePvP",0,path);

	this->m_GeneralElementalDamageRatePvM = GetPrivateProfileInt(section,"GeneralElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvP[0] = GetPrivateProfileInt(section,"DWElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvP[1] = GetPrivateProfileInt(section,"DKElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvP[2] = GetPrivateProfileInt(section,"FEElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvP[3] = GetPrivateProfileInt(section,"MGElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvP[4] = GetPrivateProfileInt(section,"DLElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvP[5] = GetPrivateProfileInt(section,"SUElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvP[6] = GetPrivateProfileInt(section,"RFElementalDamageRatePvP",0,path);

	this->m_ElementalDamageRatePvM[0] = GetPrivateProfileInt(section,"DWElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvM[1] = GetPrivateProfileInt(section,"DKElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvM[2] = GetPrivateProfileInt(section,"FEElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvM[3] = GetPrivateProfileInt(section,"MGElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvM[4] = GetPrivateProfileInt(section,"DLElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvM[5] = GetPrivateProfileInt(section,"SUElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRatePvM[6] = GetPrivateProfileInt(section,"RFElementalDamageRatePvM",0,path);

	this->m_ElementalDamageRateTo[0][0] = GetPrivateProfileInt(section,"DWElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[0][1] = GetPrivateProfileInt(section,"DWElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[0][2] = GetPrivateProfileInt(section,"DWElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[0][3] = GetPrivateProfileInt(section,"DWElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[0][4] = GetPrivateProfileInt(section,"DWElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[0][5] = GetPrivateProfileInt(section,"DWElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[0][6] = GetPrivateProfileInt(section,"DWElementalDamageRateToRF",0,path);

	this->m_ElementalDamageRateTo[1][0] = GetPrivateProfileInt(section,"DKElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[1][1] = GetPrivateProfileInt(section,"DKElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[1][2] = GetPrivateProfileInt(section,"DKElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[1][3] = GetPrivateProfileInt(section,"DKElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[1][4] = GetPrivateProfileInt(section,"DKElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[1][5] = GetPrivateProfileInt(section,"DKElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[1][6] = GetPrivateProfileInt(section,"DKElementalDamageRateToRF",0,path);

	this->m_ElementalDamageRateTo[2][0] = GetPrivateProfileInt(section,"FEElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[2][1] = GetPrivateProfileInt(section,"FEElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[2][2] = GetPrivateProfileInt(section,"FEElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[2][3] = GetPrivateProfileInt(section,"FEElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[2][4] = GetPrivateProfileInt(section,"FEElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[2][5] = GetPrivateProfileInt(section,"FEElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[2][6] = GetPrivateProfileInt(section,"FEElementalDamageRateToRF",0,path);

	this->m_ElementalDamageRateTo[3][0] = GetPrivateProfileInt(section,"MGElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[3][1] = GetPrivateProfileInt(section,"MGElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[3][2] = GetPrivateProfileInt(section,"MGElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[3][3] = GetPrivateProfileInt(section,"MGElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[3][4] = GetPrivateProfileInt(section,"MGElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[3][5] = GetPrivateProfileInt(section,"MGElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[3][6] = GetPrivateProfileInt(section,"MGElementalDamageRateToRF",0,path);

	this->m_ElementalDamageRateTo[4][0] = GetPrivateProfileInt(section,"DLElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[4][1] = GetPrivateProfileInt(section,"DLElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[4][2] = GetPrivateProfileInt(section,"DLElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[4][3] = GetPrivateProfileInt(section,"DLElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[4][4] = GetPrivateProfileInt(section,"DLElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[4][5] = GetPrivateProfileInt(section,"DLElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[4][6] = GetPrivateProfileInt(section,"DLElementalDamageRateToRF",0,path);

	this->m_ElementalDamageRateTo[5][0] = GetPrivateProfileInt(section,"SUElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[5][1] = GetPrivateProfileInt(section,"SUElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[5][2] = GetPrivateProfileInt(section,"SUElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[5][3] = GetPrivateProfileInt(section,"SUElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[5][4] = GetPrivateProfileInt(section,"SUElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[5][5] = GetPrivateProfileInt(section,"SUElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[5][6] = GetPrivateProfileInt(section,"SUElementalDamageRateToRF",0,path);

	this->m_ElementalDamageRateTo[6][0] = GetPrivateProfileInt(section,"RFElementalDamageRateToDW",0,path);

	this->m_ElementalDamageRateTo[6][1] = GetPrivateProfileInt(section,"RFElementalDamageRateToDK",0,path);

	this->m_ElementalDamageRateTo[6][2] = GetPrivateProfileInt(section,"RFElementalDamageRateToFE",0,path);

	this->m_ElementalDamageRateTo[6][3] = GetPrivateProfileInt(section,"RFElementalDamageRateToMG",0,path);

	this->m_ElementalDamageRateTo[6][4] = GetPrivateProfileInt(section,"RFElementalDamageRateToDL",0,path);

	this->m_ElementalDamageRateTo[6][5] = GetPrivateProfileInt(section,"RFElementalDamageRateToSU",0,path);

	this->m_ElementalDamageRateTo[6][6] = GetPrivateProfileInt(section,"RFElementalDamageRateToRF",0,path);

	this->m_DWElementalDefenseConstA = GetPrivateProfileInt(section,"DWElementalDefenseConstA",0,path);

	this->m_DKElementalDefenseConstA = GetPrivateProfileInt(section,"DKElementalDefenseConstA",0,path);

	this->m_FEElementalDefenseConstA = GetPrivateProfileInt(section,"FEElementalDefenseConstA",0,path);

	this->m_MGElementalDefenseConstA = GetPrivateProfileInt(section,"MGElementalDefenseConstA",0,path);

	this->m_DLElementalDefenseConstA = GetPrivateProfileInt(section,"DLElementalDefenseConstA",0,path);

	this->m_SUElementalDefenseConstA = GetPrivateProfileInt(section,"SUElementalDefenseConstA",0,path);

	this->m_RFElementalDefenseConstA = GetPrivateProfileInt(section,"RFElementalDefenseConstA",0,path);

	this->m_DWElementalDamageMinConstA = GetPrivateProfileInt(section,"DWElementalDamageMinConstA",0,path);

	this->m_DWElementalDamageMaxConstA = GetPrivateProfileInt(section,"DWElementalDamageMaxConstA",0,path);

	this->m_DKElementalDamageMinConstA = GetPrivateProfileInt(section,"DKElementalDamageMinConstA",0,path);

	this->m_DKElementalDamageMaxConstA = GetPrivateProfileInt(section,"DKElementalDamageMaxConstA",0,path);

	this->m_FEElementalDamageMinConstA = GetPrivateProfileInt(section,"FEElementalDamageMinConstA",0,path);

	this->m_FEElementalDamageMinConstB = GetPrivateProfileInt(section,"FEElementalDamageMinConstB",0,path);

	this->m_FEElementalDamageMaxConstA = GetPrivateProfileInt(section,"FEElementalDamageMaxConstA",0,path);

	this->m_FEElementalDamageMaxConstB = GetPrivateProfileInt(section,"FEElementalDamageMaxConstB",0,path);

	this->m_MGElementalDamageMinConstA = GetPrivateProfileInt(section,"MGElementalDamageMinConstA",0,path);

	this->m_MGElementalDamageMinConstB = GetPrivateProfileInt(section,"MGElementalDamageMinConstB",0,path);

	this->m_MGElementalDamageMaxConstA = GetPrivateProfileInt(section,"MGElementalDamageMaxConstA",0,path);

	this->m_MGElementalDamageMaxConstB = GetPrivateProfileInt(section,"MGElementalDamageMaxConstB",0,path);

	this->m_DLElementalDamageMinConstA = GetPrivateProfileInt(section,"DLElementalDamageMinConstA",0,path);

	this->m_DLElementalDamageMinConstB = GetPrivateProfileInt(section,"DLElementalDamageMinConstB",0,path);

	this->m_DLElementalDamageMaxConstA = GetPrivateProfileInt(section,"DLElementalDamageMaxConstA",0,path);

	this->m_DLElementalDamageMaxConstB = GetPrivateProfileInt(section,"DLElementalDamageMaxConstB",0,path);

	this->m_SUElementalDamageMinConstA = GetPrivateProfileInt(section,"SUElementalDamageMinConstA",0,path);

	this->m_SUElementalDamageMaxConstA = GetPrivateProfileInt(section,"SUElementalDamageMaxConstA",0,path);

	this->m_RFElementalDamageMinConstA = GetPrivateProfileInt(section,"RFElementalDamageMinConstA",0,path);

	this->m_RFElementalDamageMinConstB = GetPrivateProfileInt(section,"RFElementalDamageMinConstB",0,path);

	this->m_RFElementalDamageMaxConstA = GetPrivateProfileInt(section,"RFElementalDamageMaxConstA",0,path);

	this->m_RFElementalDamageMaxConstB = GetPrivateProfileInt(section,"RFElementalDamageMaxConstB",0,path);

	this->m_DWElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"DWElementalAttackSuccessRateConstA",0,path);

	this->m_DWElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"DWElementalAttackSuccessRateConstB",0,path);

	this->m_DWElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"DWElementalAttackSuccessRateConstC",0,path);

	this->m_DWElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"DWElementalAttackSuccessRateConstD",0,path);
	
	this->m_DKElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"DKElementalAttackSuccessRateConstA",0,path);

	this->m_DKElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"DKElementalAttackSuccessRateConstB",0,path);

	this->m_DKElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"DKElementalAttackSuccessRateConstC",0,path);

	this->m_DKElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"DKElementalAttackSuccessRateConstD",0,path);
	
	this->m_FEElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"FEElementalAttackSuccessRateConstA",0,path);

	this->m_FEElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"FEElementalAttackSuccessRateConstB",0,path);

	this->m_FEElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"FEElementalAttackSuccessRateConstC",0,path);

	this->m_FEElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"FEElementalAttackSuccessRateConstD",0,path);
	
	this->m_MGElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"MGElementalAttackSuccessRateConstA",0,path);

	this->m_MGElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"MGElementalAttackSuccessRateConstB",0,path);

	this->m_MGElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"MGElementalAttackSuccessRateConstC",0,path);

	this->m_MGElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"MGElementalAttackSuccessRateConstD",0,path);
	
	this->m_DLElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"DLElementalAttackSuccessRateConstA",0,path);

	this->m_DLElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"DLElementalAttackSuccessRateConstB",0,path);

	this->m_DLElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"DLElementalAttackSuccessRateConstC",0,path);

	this->m_DLElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"DLElementalAttackSuccessRateConstD",0,path);
	
	this->m_SUElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"SUElementalAttackSuccessRateConstA",0,path);

	this->m_SUElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"SUElementalAttackSuccessRateConstB",0,path);

	this->m_SUElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"SUElementalAttackSuccessRateConstC",0,path);

	this->m_SUElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"SUElementalAttackSuccessRateConstD",0,path);
	
	this->m_RFElementalAttackSuccessRateConstA = GetPrivateProfileInt(section,"RFElementalAttackSuccessRateConstA",0,path);

	this->m_RFElementalAttackSuccessRateConstB = GetPrivateProfileInt(section,"RFElementalAttackSuccessRateConstB",0,path);

	this->m_RFElementalAttackSuccessRateConstC = GetPrivateProfileInt(section,"RFElementalAttackSuccessRateConstC",0,path);

	this->m_RFElementalAttackSuccessRateConstD = GetPrivateProfileInt(section,"RFElementalAttackSuccessRateConstD",0,path);

	this->m_DWElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"DWElementalDefenseSuccessRateConstA",0,path);

	this->m_DKElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"DKElementalDefenseSuccessRateConstA",0,path);

	this->m_FEElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"FEElementalDefenseSuccessRateConstA",0,path);

	this->m_MGElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"MGElementalDefenseSuccessRateConstA",0,path);

	this->m_DLElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"DLElementalDefenseSuccessRateConstA",0,path);

	this->m_SUElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"SUElementalDefenseSuccessRateConstA",0,path);

	this->m_RFElementalDefenseSuccessRateConstA = GetPrivateProfileInt(section,"RFElementalDefenseSuccessRateConstA",0,path);

	#endif
}

void CServerInfo::ReadCommandInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	this->m_CommandPostType = GetPrivateProfileInt(section,"CommandPostType",0,path);

	this->m_CommandAddPointAutoEnable[0] = GetPrivateProfileInt(section,"CommandAddPointAutoEnable_AL0",0,path);

	this->m_CommandAddPointAutoEnable[1] = GetPrivateProfileInt(section,"CommandAddPointAutoEnable_AL1",0,path);

	this->m_CommandAddPointAutoEnable[2] = GetPrivateProfileInt(section,"CommandAddPointAutoEnable_AL2",0,path);

	this->m_CommandAddPointAutoEnable[3] = GetPrivateProfileInt(section,"CommandAddPointAutoEnable_AL3",0,path);

	this->m_CommandChangeLimit[0] = GetPrivateProfileInt(section,"CommandChangeLimit_AL0",0,path);

	this->m_CommandChangeLimit[1] = GetPrivateProfileInt(section,"CommandChangeLimit_AL1",0,path);

	this->m_CommandChangeLimit[2] = GetPrivateProfileInt(section,"CommandChangeLimit_AL2",0,path);

	this->m_CommandChangeLimit[3] = GetPrivateProfileInt(section,"CommandChangeLimit_AL3",0,path);
	
	this->m_CommandWareNumber[0] = GetPrivateProfileInt(section,"CommandWareNumber_AL0",0,path);

	this->m_CommandWareNumber[1] = GetPrivateProfileInt(section,"CommandWareNumber_AL1",0,path);

	this->m_CommandWareNumber[2] = GetPrivateProfileInt(section,"CommandWareNumber_AL2",0,path);

	this->m_CommandWareNumber[3] = GetPrivateProfileInt(section,"CommandWareNumber_AL3",0,path);

	this->m_CommandResetType = GetPrivateProfileInt(section,"CommandResetType",0,path);

	this->m_CommandResetAutoEnable[0] = GetPrivateProfileInt(section,"CommandResetAutoEnable_AL0",0,path);

	this->m_CommandResetAutoEnable[1] = GetPrivateProfileInt(section,"CommandResetAutoEnable_AL1",0,path);

	this->m_CommandResetAutoEnable[2] = GetPrivateProfileInt(section,"CommandResetAutoEnable_AL2",0,path);

	this->m_CommandResetAutoEnable[3] = GetPrivateProfileInt(section,"CommandResetAutoEnable_AL3",0,path);

	this->m_CommandResetCheckItem[0] = GetPrivateProfileInt(section,"CommandResetCheckItem_AL0",0,path);

	this->m_CommandResetCheckItem[1] = GetPrivateProfileInt(section,"CommandResetCheckItem_AL1",0,path);

	this->m_CommandResetCheckItem[2] = GetPrivateProfileInt(section,"CommandResetCheckItem_AL2",0,path);

	this->m_CommandResetCheckItem[3] = GetPrivateProfileInt(section,"CommandResetCheckItem_AL3",0,path);

	this->m_CommandResetMove[0] = GetPrivateProfileInt(section,"CommandResetMove_AL0",0,path);

	this->m_CommandResetMove[1] = GetPrivateProfileInt(section,"CommandResetMove_AL1",0,path);

	this->m_CommandResetMove[2] = GetPrivateProfileInt(section,"CommandResetMove_AL2",0,path);

	this->m_CommandResetMove[3] = GetPrivateProfileInt(section,"CommandResetMove_AL3",0,path);

	this->m_CommandResetQuest[0] = GetPrivateProfileInt(section,"CommandResetQuest_AL0",0,path);

	this->m_CommandResetQuest[1] = GetPrivateProfileInt(section,"CommandResetQuest_AL1",0,path);

	this->m_CommandResetQuest[2] = GetPrivateProfileInt(section,"CommandResetQuest_AL2",0,path);

	this->m_CommandResetQuest[3] = GetPrivateProfileInt(section,"CommandResetQuest_AL3",0,path);

	this->m_CommandResetSkill[0] = GetPrivateProfileInt(section,"CommandResetSkill_AL0",0,path);

	this->m_CommandResetSkill[1] = GetPrivateProfileInt(section,"CommandResetSkill_AL1",0,path);

	this->m_CommandResetSkill[2] = GetPrivateProfileInt(section,"CommandResetSkill_AL2",0,path);

	this->m_CommandResetSkill[3] = GetPrivateProfileInt(section,"CommandResetSkill_AL3",0,path);

	this->m_CommandResetLevel[0] = GetPrivateProfileInt(section,"CommandResetLevel_AL0",0,path);

	this->m_CommandResetLevel[1] = GetPrivateProfileInt(section,"CommandResetLevel_AL1",0,path);

	this->m_CommandResetLevel[2] = GetPrivateProfileInt(section,"CommandResetLevel_AL2",0,path);

	this->m_CommandResetLevel[3] = GetPrivateProfileInt(section,"CommandResetLevel_AL3",0,path);

	this->m_CommandResetMoney[0] = GetPrivateProfileInt(section,"CommandResetMoney_AL0",0,path);

	this->m_CommandResetMoney[1] = GetPrivateProfileInt(section,"CommandResetMoney_AL1",0,path);

	this->m_CommandResetMoney[2] = GetPrivateProfileInt(section,"CommandResetMoney_AL2",0,path);

	this->m_CommandResetMoney[3] = GetPrivateProfileInt(section,"CommandResetMoney_AL3",0,path);

	this->m_CommandResetCount[0] = GetPrivateProfileInt(section,"CommandResetCount_AL0",0,path);

	this->m_CommandResetCount[1] = GetPrivateProfileInt(section,"CommandResetCount_AL1",0,path);

	this->m_CommandResetCount[2] = GetPrivateProfileInt(section,"CommandResetCount_AL2",0,path);

	this->m_CommandResetCount[3] = GetPrivateProfileInt(section,"CommandResetCount_AL3",0,path);

	this->m_CommandResetLimit[0] = GetPrivateProfileInt(section,"CommandResetLimit_AL0",0,path);

	this->m_CommandResetLimit[1] = GetPrivateProfileInt(section,"CommandResetLimit_AL1",0,path);

	this->m_CommandResetLimit[2] = GetPrivateProfileInt(section,"CommandResetLimit_AL2",0,path);

	this->m_CommandResetLimit[3] = GetPrivateProfileInt(section,"CommandResetLimit_AL3",0,path);

	this->m_CommandResetLimitDay[0] = GetPrivateProfileInt(section,"CommandResetLimitDay_AL0",0,path);

	this->m_CommandResetLimitDay[1] = GetPrivateProfileInt(section,"CommandResetLimitDay_AL1",0,path);

	this->m_CommandResetLimitDay[2] = GetPrivateProfileInt(section,"CommandResetLimitDay_AL2",0,path);

	this->m_CommandResetLimitDay[3] = GetPrivateProfileInt(section,"CommandResetLimitDay_AL3",0,path);

	this->m_CommandResetLimitWek[0] = GetPrivateProfileInt(section,"CommandResetLimitWek_AL0",0,path);

	this->m_CommandResetLimitWek[1] = GetPrivateProfileInt(section,"CommandResetLimitWek_AL1",0,path);

	this->m_CommandResetLimitWek[2] = GetPrivateProfileInt(section,"CommandResetLimitWek_AL2",0,path);

	this->m_CommandResetLimitWek[3] = GetPrivateProfileInt(section,"CommandResetLimitWek_AL3",0,path);

	this->m_CommandResetLimitMon[0] = GetPrivateProfileInt(section,"CommandResetLimitMon_AL0",0,path);

	this->m_CommandResetLimitMon[1] = GetPrivateProfileInt(section,"CommandResetLimitMon_AL1",0,path);

	this->m_CommandResetLimitMon[2] = GetPrivateProfileInt(section,"CommandResetLimitMon_AL2",0,path);

	this->m_CommandResetLimitMon[3] = GetPrivateProfileInt(section,"CommandResetLimitMon_AL3",0,path);

	this->m_CommandResetStartLevel[0] = GetPrivateProfileInt(section,"CommandResetStartLevel_AL0",0,path);

	this->m_CommandResetStartLevel[1] = GetPrivateProfileInt(section,"CommandResetStartLevel_AL1",0,path);

	this->m_CommandResetStartLevel[2] = GetPrivateProfileInt(section,"CommandResetStartLevel_AL2",0,path);

	this->m_CommandResetStartLevel[3] = GetPrivateProfileInt(section,"CommandResetStartLevel_AL3",0,path);

	this->m_CommandResetPoint[0] = GetPrivateProfileInt(section,"CommandResetPoint_AL0",0,path);

	this->m_CommandResetPoint[1] = GetPrivateProfileInt(section,"CommandResetPoint_AL1",0,path);

	this->m_CommandResetPoint[2] = GetPrivateProfileInt(section,"CommandResetPoint_AL2",0,path);

	this->m_CommandResetPoint[3] = GetPrivateProfileInt(section,"CommandResetPoint_AL3",0,path);

	this->m_CommandResetPointRate[0] = GetPrivateProfileInt(section,"CommandResetPointRateDW",0,path);

	this->m_CommandResetPointRate[1] = GetPrivateProfileInt(section,"CommandResetPointRateDK",0,path);

	this->m_CommandResetPointRate[2] = GetPrivateProfileInt(section,"CommandResetPointRateFE",0,path);

	this->m_CommandResetPointRate[3] = GetPrivateProfileInt(section,"CommandResetPointRateMG",0,path);

	this->m_CommandResetPointRate[4] = GetPrivateProfileInt(section,"CommandResetPointRateDL",0,path);

	this->m_CommandResetPointRate[5] = GetPrivateProfileInt(section,"CommandResetPointRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_CommandResetPointRate[6] = GetPrivateProfileInt(section,"CommandResetPointRateRF",0,path);

	#endif
	
	this->m_CommandMasterResetType = GetPrivateProfileInt(section,"CommandMasterResetType",0,path);

	this->m_CommandMasterResetCheckItem[0] = GetPrivateProfileInt(section,"CommandMasterResetCheckItem_AL0",0,path);

	this->m_CommandMasterResetCheckItem[1] = GetPrivateProfileInt(section,"CommandMasterResetCheckItem_AL1",0,path);

	this->m_CommandMasterResetCheckItem[2] = GetPrivateProfileInt(section,"CommandMasterResetCheckItem_AL2",0,path);

	this->m_CommandMasterResetCheckItem[3] = GetPrivateProfileInt(section,"CommandMasterResetCheckItem_AL3",0,path);

	this->m_CommandMasterResetMove[0] = GetPrivateProfileInt(section,"CommandMasterResetMove_AL0",0,path);

	this->m_CommandMasterResetMove[1] = GetPrivateProfileInt(section,"CommandMasterResetMove_AL1",0,path);

	this->m_CommandMasterResetMove[2] = GetPrivateProfileInt(section,"CommandMasterResetMove_AL2",0,path);

	this->m_CommandMasterResetMove[3] = GetPrivateProfileInt(section,"CommandMasterResetMove_AL3",0,path);

	this->m_CommandMasterResetQuest[0] = GetPrivateProfileInt(section,"CommandMasterResetQuest_AL0",0,path);

	this->m_CommandMasterResetQuest[1] = GetPrivateProfileInt(section,"CommandMasterResetQuest_AL1",0,path);

	this->m_CommandMasterResetQuest[2] = GetPrivateProfileInt(section,"CommandMasterResetQuest_AL2",0,path);

	this->m_CommandMasterResetQuest[3] = GetPrivateProfileInt(section,"CommandMasterResetQuest_AL3",0,path);

	this->m_CommandMasterResetSkill[0] = GetPrivateProfileInt(section,"CommandMasterResetSkill_AL0",0,path);

	this->m_CommandMasterResetSkill[1] = GetPrivateProfileInt(section,"CommandMasterResetSkill_AL1",0,path);

	this->m_CommandMasterResetSkill[2] = GetPrivateProfileInt(section,"CommandMasterResetSkill_AL2",0,path);

	this->m_CommandMasterResetSkill[3] = GetPrivateProfileInt(section,"CommandMasterResetSkill_AL3",0,path);

	this->m_CommandMasterResetLevel[0] = GetPrivateProfileInt(section,"CommandMasterResetLevel_AL0",0,path);

	this->m_CommandMasterResetLevel[1] = GetPrivateProfileInt(section,"CommandMasterResetLevel_AL1",0,path);

	this->m_CommandMasterResetLevel[2] = GetPrivateProfileInt(section,"CommandMasterResetLevel_AL2",0,path);

	this->m_CommandMasterResetLevel[3] = GetPrivateProfileInt(section,"CommandMasterResetLevel_AL3",0,path);

	this->m_CommandMasterResetReset[0] = GetPrivateProfileInt(section,"CommandMasterResetReset_AL0",0,path);

	this->m_CommandMasterResetReset[1] = GetPrivateProfileInt(section,"CommandMasterResetReset_AL1",0,path);

	this->m_CommandMasterResetReset[2] = GetPrivateProfileInt(section,"CommandMasterResetReset_AL2",0,path);

	this->m_CommandMasterResetReset[3] = GetPrivateProfileInt(section,"CommandMasterResetReset_AL3",0,path);

	this->m_CommandMasterResetMoney[0] = GetPrivateProfileInt(section,"CommandMasterResetMoney_AL0",0,path);

	this->m_CommandMasterResetMoney[1] = GetPrivateProfileInt(section,"CommandMasterResetMoney_AL1",0,path);

	this->m_CommandMasterResetMoney[2] = GetPrivateProfileInt(section,"CommandMasterResetMoney_AL2",0,path);

	this->m_CommandMasterResetMoney[3] = GetPrivateProfileInt(section,"CommandMasterResetMoney_AL3",0,path);

	this->m_CommandMasterResetCount[0] = GetPrivateProfileInt(section,"CommandMasterResetCount_AL0",0,path);

	this->m_CommandMasterResetCount[1] = GetPrivateProfileInt(section,"CommandMasterResetCount_AL1",0,path);

	this->m_CommandMasterResetCount[2] = GetPrivateProfileInt(section,"CommandMasterResetCount_AL2",0,path);

	this->m_CommandMasterResetCount[3] = GetPrivateProfileInt(section,"CommandMasterResetCount_AL3",0,path);

	this->m_CommandMasterResetLimit[0] = GetPrivateProfileInt(section,"CommandMasterResetLimit_AL0",0,path);

	this->m_CommandMasterResetLimit[1] = GetPrivateProfileInt(section,"CommandMasterResetLimit_AL1",0,path);

	this->m_CommandMasterResetLimit[2] = GetPrivateProfileInt(section,"CommandMasterResetLimit_AL2",0,path);

	this->m_CommandMasterResetLimit[3] = GetPrivateProfileInt(section,"CommandMasterResetLimit_AL3",0,path);

	this->m_CommandMasterResetLimitDay[0] = GetPrivateProfileInt(section,"CommandMasterResetLimitDay_AL0",0,path);

	this->m_CommandMasterResetLimitDay[1] = GetPrivateProfileInt(section,"CommandMasterResetLimitDay_AL1",0,path);

	this->m_CommandMasterResetLimitDay[2] = GetPrivateProfileInt(section,"CommandMasterResetLimitDay_AL2",0,path);

	this->m_CommandMasterResetLimitDay[3] = GetPrivateProfileInt(section,"CommandMasterResetLimitDay_AL3",0,path);

	this->m_CommandMasterResetLimitWek[0] = GetPrivateProfileInt(section,"CommandMasterResetLimitWek_AL0",0,path);

	this->m_CommandMasterResetLimitWek[1] = GetPrivateProfileInt(section,"CommandMasterResetLimitWek_AL1",0,path);

	this->m_CommandMasterResetLimitWek[2] = GetPrivateProfileInt(section,"CommandMasterResetLimitWek_AL2",0,path);

	this->m_CommandMasterResetLimitWek[3] = GetPrivateProfileInt(section,"CommandMasterResetLimitWek_AL3",0,path);

	this->m_CommandMasterResetLimitMon[0] = GetPrivateProfileInt(section,"CommandMasterResetLimitMon_AL0",0,path);

	this->m_CommandMasterResetLimitMon[1] = GetPrivateProfileInt(section,"CommandMasterResetLimitMon_AL1",0,path);

	this->m_CommandMasterResetLimitMon[2] = GetPrivateProfileInt(section,"CommandMasterResetLimitMon_AL2",0,path);

	this->m_CommandMasterResetLimitMon[3] = GetPrivateProfileInt(section,"CommandMasterResetLimitMon_AL3",0,path);

	this->m_CommandMasterResetStartLevel[0] = GetPrivateProfileInt(section,"CommandMasterResetStartLevel_AL0",0,path);

	this->m_CommandMasterResetStartLevel[1] = GetPrivateProfileInt(section,"CommandMasterResetStartLevel_AL1",0,path);

	this->m_CommandMasterResetStartLevel[2] = GetPrivateProfileInt(section,"CommandMasterResetStartLevel_AL2",0,path);

	this->m_CommandMasterResetStartLevel[3] = GetPrivateProfileInt(section,"CommandMasterResetStartLevel_AL3",0,path);

	this->m_CommandMasterResetStartReset[0] = GetPrivateProfileInt(section,"CommandMasterResetStartReset_AL0",0,path);

	this->m_CommandMasterResetStartReset[1] = GetPrivateProfileInt(section,"CommandMasterResetStartReset_AL1",0,path);

	this->m_CommandMasterResetStartReset[2] = GetPrivateProfileInt(section,"CommandMasterResetStartReset_AL2",0,path);

	this->m_CommandMasterResetStartReset[3] = GetPrivateProfileInt(section,"CommandMasterResetStartReset_AL3",0,path);

	this->m_CommandMasterResetRemoveReset[0] = GetPrivateProfileInt(section,"CommandMasterResetRemoveReset_AL0",0,path);

	this->m_CommandMasterResetRemoveReset[1] = GetPrivateProfileInt(section,"CommandMasterResetRemoveReset_AL1",0,path);

	this->m_CommandMasterResetRemoveReset[2] = GetPrivateProfileInt(section,"CommandMasterResetRemoveReset_AL2",0,path);

	this->m_CommandMasterResetRemoveReset[3] = GetPrivateProfileInt(section,"CommandMasterResetRemoveReset_AL3",0,path);

	this->m_CommandMasterResetPoint[0] = GetPrivateProfileInt(section,"CommandMasterResetPoint_AL0",0,path);

	this->m_CommandMasterResetPoint[1] = GetPrivateProfileInt(section,"CommandMasterResetPoint_AL1",0,path);

	this->m_CommandMasterResetPoint[2] = GetPrivateProfileInt(section,"CommandMasterResetPoint_AL2",0,path);

	this->m_CommandMasterResetPoint[3] = GetPrivateProfileInt(section,"CommandMasterResetPoint_AL3",0,path);

	this->m_CommandMasterResetPointRate[0] = GetPrivateProfileInt(section,"CommandMasterResetPointRateDW",0,path);

	this->m_CommandMasterResetPointRate[1] = GetPrivateProfileInt(section,"CommandMasterResetPointRateDK",0,path);

	this->m_CommandMasterResetPointRate[2] = GetPrivateProfileInt(section,"CommandMasterResetPointRateFE",0,path);

	this->m_CommandMasterResetPointRate[3] = GetPrivateProfileInt(section,"CommandMasterResetPointRateMG",0,path);

	this->m_CommandMasterResetPointRate[4] = GetPrivateProfileInt(section,"CommandMasterResetPointRateDL",0,path);

	this->m_CommandMasterResetPointRate[5] = GetPrivateProfileInt(section,"CommandMasterResetPointRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_CommandMasterResetPointRate[6] = GetPrivateProfileInt(section,"CommandMasterResetPointRateRF",0,path);

	#endif

	this->m_CommandMarryLevel = GetPrivateProfileInt(section,"CommandMarryLevel",0,path);
	
    this->m_CommandMarryCost = GetPrivateProfileInt(section,"CommandMarryCost",0,path);
	
    this->m_CommandMarryMinTime = GetPrivateProfileInt(section,"CommandMarryMinTime",0,path);
	
    this->m_CommandMarryNoticeDelay = GetPrivateProfileInt(section,"CommandMarryNoticeDelay",0,path);

	this->m_CommandMarryOnlyGM = GetPrivateProfileInt(section,"CommandMarryOnlyGM",0,path);


	this->m_CommandOpenWareOnlySafeZone = GetPrivateProfileInt(section,"CommandOpenWareOnlySafeZone",0,path);

	this->m_CommandChangeClassToDW = GetPrivateProfileInt(section,"CommandChangeClassToDW",0,path);

	this->m_CommandChangeClassToDK = GetPrivateProfileInt(section,"CommandChangeClassToDK",0,path);

	this->m_CommandChangeClassToELF = GetPrivateProfileInt(section,"CommandChangeClassToELF",0,path);

	this->m_CommandChangeClassToMG = GetPrivateProfileInt(section,"CommandChangeClassToMG",0,path);

	this->m_CommandChangeClassToDL = GetPrivateProfileInt(section,"CommandChangeClassToDL",0,path);

	this->m_CommandChangeClassToSU = GetPrivateProfileInt(section,"CommandChangeClassToSU",0,path);

	this->m_CommandChangeClassToRF = GetPrivateProfileInt(section,"CommandChangeClassToRF",0,path);

	this->m_CommandRewardMaxType			= GetPrivateProfileInt(section,"CommandRewardMaxType",0,path);

	this->m_CommandRewardMaxValue			= GetPrivateProfileInt(section,"CommandRewardMaxValue",0,path);

	GetPrivateProfileString(section,"CommandRewardType1Text","",this->m_CommandRewardType1Text,sizeof(this->m_CommandRewardType1Text),path);
	GetPrivateProfileString(section,"CommandRewardType2Text","",this->m_CommandRewardType2Text,sizeof(this->m_CommandRewardType2Text),path);
	GetPrivateProfileString(section,"CommandRewardType3Text","",this->m_CommandRewardType3Text,sizeof(this->m_CommandRewardType3Text),path);
	GetPrivateProfileString(section,"CommandRewardType4Text","",this->m_CommandRewardType4Text,sizeof(this->m_CommandRewardType4Text),path);
	GetPrivateProfileString(section,"CommandRewardType5Text","",this->m_CommandRewardType5Text,sizeof(this->m_CommandRewardType5Text),path);
	GetPrivateProfileString(section,"CommandRewardType6Text","",this->m_CommandRewardType6Text,sizeof(this->m_CommandRewardType6Text),path);
	GetPrivateProfileString(section,"CommandRewardType7Text","",this->m_CommandRewardType7Text,sizeof(this->m_CommandRewardType7Text),path);
	GetPrivateProfileString(section,"CommandRewardType8Text","",this->m_CommandRewardType8Text,sizeof(this->m_CommandRewardType8Text),path);
	GetPrivateProfileString(section,"CommandRewardType9Text","",this->m_CommandRewardType9Text,sizeof(this->m_CommandRewardType9Text),path);
	GetPrivateProfileString(section,"CommandRewardType10Text","",this->m_CommandRewardType10Text,sizeof(this->m_CommandRewardType10Text),path);

	this->m_CommandRewardAllSwitch			= GetPrivateProfileInt(section,"CommandRewardAllSwitch",0,path);

	this->m_CommandRewardAllGameMasterLevel	= GetPrivateProfileInt(section,"CommandRewardAllGameMasterLevel",0,path);

	this->m_CommandRewardAllMaxType			= GetPrivateProfileInt(section,"CommandRewardAllMaxType",0,path);

	this->m_CommandRewardAllMaxValue		= GetPrivateProfileInt(section,"CommandRewardAllMaxValue",0,path);

	GetPrivateProfileString(section,"CommandRewardAllType1Text","",this->m_CommandRewardAllType1Text,sizeof(this->m_CommandRewardAllType1Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType2Text","",this->m_CommandRewardAllType2Text,sizeof(this->m_CommandRewardAllType2Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType3Text","",this->m_CommandRewardAllType3Text,sizeof(this->m_CommandRewardAllType3Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType4Text","",this->m_CommandRewardAllType4Text,sizeof(this->m_CommandRewardAllType4Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType5Text","",this->m_CommandRewardAllType5Text,sizeof(this->m_CommandRewardAllType5Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType6Text","",this->m_CommandRewardAllType6Text,sizeof(this->m_CommandRewardAllType6Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType7Text","",this->m_CommandRewardAllType7Text,sizeof(this->m_CommandRewardAllType7Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType8Text","",this->m_CommandRewardAllType8Text,sizeof(this->m_CommandRewardAllType8Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType9Text","",this->m_CommandRewardAllType9Text,sizeof(this->m_CommandRewardAllType9Text),path);
	GetPrivateProfileString(section,"CommandRewardAllType10Text","",this->m_CommandRewardAllType10Text,sizeof(this->m_CommandRewardAllType10Text),path);

	this->m_CommandRenameDelay[0]			= GetPrivateProfileInt(section,"CommandRenameDelay_AL0",0,path);

	this->m_CommandRenameDelay[1]			= GetPrivateProfileInt(section,"CommandRenameDelay_AL1",0,path);

	this->m_CommandRenameDelay[2]			= GetPrivateProfileInt(section,"CommandRenameDelay_AL2",0,path);

	this->m_CommandRenameDelay[3]			= GetPrivateProfileInt(section,"CommandRenameDelay_AL3",0,path);

	this->m_CommandRenameTicket				= GetPrivateProfileInt(section,"CommandRenameNeedTicket",0,path);

	this->m_CommandGiftLimit				= GetPrivateProfileInt(section,"CommandGiftLimit",0,path);

	this->m_CommandHelpMonsterIndex			= GetPrivateProfileInt(section,"CommandHelpMonsterIndex",0,path);

	this->m_CommandHelpMonsterAmount		= GetPrivateProfileInt(section,"CommandHelpMonsterAmount",0,path);

	this->m_CommandBlocAccShowMessage	=  GetPrivateProfileInt(section,"CommandBlocAccShowMessage",0,path);

	this->m_CommandBlocCharShowMessage	=  GetPrivateProfileInt(section,"CommandBlocCharShowMessage",0,path);
}

void CServerInfo::ReadCommonInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	this->m_ServerMinLevel = GetPrivateProfileInt(section,"ServerMinLevel",0,path);

	this->m_ServerMaxLevel = GetPrivateProfileInt(section,"ServerMaxLevel",0,path);

	this->m_ServerMinReset = GetPrivateProfileInt(section,"ServerMinReset",0,path);

	this->m_ServerMaxReset = GetPrivateProfileInt(section,"ServerMaxReset",0,path);

	this->m_ServerMinMasterReset = GetPrivateProfileInt(section,"ServerMinMasterReset",0,path);

	this->m_ServerMaxMasterReset = GetPrivateProfileInt(section,"ServerMaxMasterReset",0,path);

	this->m_ServerLock = GetPrivateProfileInt(section,"ServerLock",0,path);

	this->m_ServerMaxUserNumber = GetPrivateProfileInt(section, "ServerMaxUserNumber", 0, path);

	this->m_MainChecksum = GetPrivateProfileInt(section,"MainChecksum",0,path);

	this->m_MaxItemOption = GetPrivateProfileInt(section,"MaxItemOption",0,path);

	this->m_MaxIpConnection = GetPrivateProfileInt(section,"MaxIpConnection",0,path);

	this->m_MaxHwidConnection = GetPrivateProfileInt(section, "MaxHwidConnection", 0, path);
	
	this->m_BannedDuration = GetPrivateProfileInt(section,"BannedDuration",0,path);
	
	this->m_PersonalCodeCheck = GetPrivateProfileInt(section,"PersonalCodeCheck",0,path);

	this->m_SetItemAcceptHarmonySwitch = GetPrivateProfileInt(section,"SetItemAcceptHarmonySwitch",0,path);

	this->m_CharacterCloseCount = GetPrivateProfileInt(section,"CharacterCloseCount",0,path);

	this->m_MonsterLifeRate = GetPrivateProfileInt(section,"MonsterLifeRate",100,path);

	this->m_MonsterDamageRate = GetPrivateProfileInt(section,"MonsterDamageRate",100,path);

	this->m_MonsterDefenseRate = GetPrivateProfileInt(section,"MonsterDefenseRate",100,path);

	#if(GAMESERVER_UPDATE<=603)

	this->m_MonsterHealthBarSwitch = GetPrivateProfileInt(section,"MonsterHealthBarSwitch",0,path);

	#endif

	this->m_UserHealthBarSwitch = GetPrivateProfileInt(section,"UserHealthBarSwitch",0,path);

	this->m_NonPK = GetPrivateProfileInt(section,"NonPK",0,path);
	
	this->m_PKLimitCount = GetPrivateProfileInt(section,"PKLimitCount",100,path);

	this->m_PKLimitFree = GetPrivateProfileInt(section,"PKLimitFree",0,path);

	this->m_PKDownTime1 = GetPrivateProfileInt(section,"PKDownTime1",0,path);

	this->m_PKDownTime2 = GetPrivateProfileInt(section,"PKDownTime2",0,path);

	this->m_SelfDefenseTime = GetPrivateProfileInt(section, "SelfDefenseTime", 0, path);

	this->m_TradeSwitch = GetPrivateProfileInt(section,"TradeSwitch",0,path);

	this->m_PersonalShopSwitch = GetPrivateProfileInt(section,"PersonalShopSwitch",0,path);

	#if(GAMESERVER_UPDATE>=802)

	this->m_PersonalShopMoneyCommisionRate = GetPrivateProfileInt(section,"PersonalShopMoneyCommisionRate",0,path);

	this->m_PersonalShopJewelCommisionRate = GetPrivateProfileInt(section,"PersonalShopJewelCommisionRate",0,path);

	#endif

	this->m_DuelSwitch = GetPrivateProfileInt(section,"DuelSwitch",0,path);

	this->m_DuelScore = GetPrivateProfileInt(section, "DuelScore", 10, path);

	this->m_DuelArenaAnnounceSwitch = GetPrivateProfileInt(section,"DuelArenaAnnounceSwitch",0,path);

	this->m_DuelArenaDisableRestoreHP = GetPrivateProfileInt(section,"DuelArenaDisableRestoreHP",0,path);

	this->m_DuelArenaDisableRestoreSD = GetPrivateProfileInt(section,"DuelArenaDisableRestoreSD",0,path);

	this->m_GuildCreateSwitch = GetPrivateProfileInt(section,"GuildCreateSwitch",0,path);

	this->m_GuildDeleteSwitch = GetPrivateProfileInt(section,"GuildDeleteSwitch",0,path);

	this->m_GuildCreateMinLevel = GetPrivateProfileInt(section,"GuildCreateMinLevel",0,path);

	this->m_GuildInsertMaxUser1 = GetPrivateProfileInt(section,"GuildInsertMaxUser1",0,path);

	this->m_GuildInsertMaxUser2 = GetPrivateProfileInt(section,"GuildInsertMaxUser2",0,path);

	this->m_GuildAllianceMinUser = GetPrivateProfileInt(section,"GuildAllianceMinUser",0,path);

	this->m_GuildAllianceMaxCount = GetPrivateProfileInt(section,"GuildAllianceMaxCount",0,path);

	this->m_GuildOwnerDestroyLimit = GetPrivateProfileInt(section,"GuildOwnerDestroyLimit",0,path);

	this->m_ElfBufferMaxLevel[0] = GetPrivateProfileInt(section,"ElfBufferMaxLevel_AL0",0,path);

	this->m_ElfBufferMaxLevel[1] = GetPrivateProfileInt(section,"ElfBufferMaxLevel_AL1",0,path);

	this->m_ElfBufferMaxLevel[2] = GetPrivateProfileInt(section,"ElfBufferMaxLevel_AL2",0,path);

	this->m_ElfBufferMaxLevel[3] = GetPrivateProfileInt(section,"ElfBufferMaxLevel_AL3",0,path);

	this->m_ElfBufferMaxReset[0] = GetPrivateProfileInt(section,"ElfBufferMaxReset_AL0",0,path);

	this->m_ElfBufferMaxReset[1] = GetPrivateProfileInt(section,"ElfBufferMaxReset_AL1",0,path);

	this->m_ElfBufferMaxReset[2] = GetPrivateProfileInt(section,"ElfBufferMaxReset_AL2",0,path);

	this->m_ElfBufferMaxReset[3] = GetPrivateProfileInt(section,"ElfBufferMaxReset_AL3",0,path);

	this->m_ElfBufferDamageConstA = GetPrivateProfileInt(section,"ElfBufferDamageConstA",0,path);

	this->m_ElfBufferDamageConstB = GetPrivateProfileInt(section,"ElfBufferDamageConstB",0,path);

	this->m_ElfBufferDefenseConstA = GetPrivateProfileInt(section,"ElfBufferDefenseConstA",0,path);

	this->m_ElfBufferDefenseConstB = GetPrivateProfileInt(section,"ElfBufferDefenseConstB",0,path);

	this->m_AddExperienceRate[0] = GetPrivateProfileInt(section,"AddExperienceRate_AL0",0,path);

	this->m_AddExperienceRate[1] = GetPrivateProfileInt(section,"AddExperienceRate_AL1",0,path);

	this->m_AddExperienceRate[2] = GetPrivateProfileInt(section,"AddExperienceRate_AL2",0,path);

	this->m_AddExperienceRate[3] = GetPrivateProfileInt(section,"AddExperienceRate_AL3",0,path);

	this->m_AutoResetExperienceRate[0] = GetPrivateProfileInt(section,"AutoResetExperienceRate_AL0",0,path);

	this->m_AutoResetExperienceRate[1] = GetPrivateProfileInt(section,"AutoResetExperienceRate_AL1",0,path);

	this->m_AutoResetExperienceRate[2] = GetPrivateProfileInt(section,"AutoResetExperienceRate_AL2",0,path);

	this->m_AutoResetExperienceRate[3] = GetPrivateProfileInt(section,"AutoResetExperienceRate_AL3",0,path);

	this->m_OffAttackExperienceRate[0] = GetPrivateProfileInt(section,"OffAttackExperienceRate_AL0",0,path);

	this->m_OffAttackExperienceRate[1] = GetPrivateProfileInt(section,"OffAttackExperienceRate_AL1",0,path);

	this->m_OffAttackExperienceRate[2] = GetPrivateProfileInt(section,"OffAttackExperienceRate_AL2",0,path);

	this->m_OffAttackExperienceRate[3] = GetPrivateProfileInt(section,"OffAttackExperienceRate_AL3",0,path);

	#if(GAMESERVER_UPDATE>=401)

	this->m_AddMasterExperienceRate[0] = GetPrivateProfileInt(section,"AddMasterExperienceRate_AL0",0,path);

	this->m_AddMasterExperienceRate[1] = GetPrivateProfileInt(section,"AddMasterExperienceRate_AL1",0,path);

	this->m_AddMasterExperienceRate[2] = GetPrivateProfileInt(section,"AddMasterExperienceRate_AL2",0,path);

	this->m_AddMasterExperienceRate[3] = GetPrivateProfileInt(section,"AddMasterExperienceRate_AL3",0,path);

	this->m_MinMasterExperienceMonsterLevel[0] = GetPrivateProfileInt(section,"MinMasterExperienceMonsterLevel_AL0",0,path);

	this->m_MinMasterExperienceMonsterLevel[1] = GetPrivateProfileInt(section,"MinMasterExperienceMonsterLevel_AL1",0,path);

	this->m_MinMasterExperienceMonsterLevel[2] = GetPrivateProfileInt(section,"MinMasterExperienceMonsterLevel_AL2",0,path);

	this->m_MinMasterExperienceMonsterLevel[3] = GetPrivateProfileInt(section,"MinMasterExperienceMonsterLevel_AL3",0,path);

	#endif

	this->m_AddEventExperienceRate[0] = GetPrivateProfileInt(section,"AddEventExperienceRate_AL0",0,path);

	this->m_AddEventExperienceRate[1] = GetPrivateProfileInt(section,"AddEventExperienceRate_AL1",0,path);

	this->m_AddEventExperienceRate[2] = GetPrivateProfileInt(section,"AddEventExperienceRate_AL2",0,path);

	this->m_AddEventExperienceRate[3] = GetPrivateProfileInt(section,"AddEventExperienceRate_AL3",0,path);

	#if(GAMESERVER_UPDATE>=501)

	this->m_AddQuestExperienceRate[0] = GetPrivateProfileInt(section,"AddQuestExperienceRate_AL0",0,path);

	this->m_AddQuestExperienceRate[1] = GetPrivateProfileInt(section,"AddQuestExperienceRate_AL1",0,path);

	this->m_AddQuestExperienceRate[2] = GetPrivateProfileInt(section,"AddQuestExperienceRate_AL2",0,path);

	this->m_AddQuestExperienceRate[3] = GetPrivateProfileInt(section,"AddQuestExperienceRate_AL3",0,path);

	#endif

	this->m_ItemDropTime = GetPrivateProfileInt(section,"ItemDropTime",0,path);

	this->m_ItemDropPickUpTime = GetPrivateProfileInt(section, "ItemDropPickUpTime", 0, path);

	this->m_ItemDropRate[0] = GetPrivateProfileInt(section,"ItemDropRate_AL0",0,path);

	this->m_ItemDropRate[1] = GetPrivateProfileInt(section,"ItemDropRate_AL1",0,path);

	this->m_ItemDropRate[2] = GetPrivateProfileInt(section,"ItemDropRate_AL2",0,path);

	this->m_ItemDropRate[3] = GetPrivateProfileInt(section,"ItemDropRate_AL3",0,path);

	this->m_MoneyDropTime = GetPrivateProfileInt(section,"MoneyDropTime",0,path);

	this->m_MoneyAmountDropRate[0] = GetPrivateProfileInt(section,"MoneyAmountDropRate_AL0",0,path);

	this->m_MoneyAmountDropRate[1] = GetPrivateProfileInt(section,"MoneyAmountDropRate_AL1",0,path);

	this->m_MoneyAmountDropRate[2] = GetPrivateProfileInt(section,"MoneyAmountDropRate_AL2",0,path);

	this->m_MoneyAmountDropRate[3] = GetPrivateProfileInt(section,"MoneyAmountDropRate_AL3",0,path);

	this->m_WeaponDurabilityRate = GetPrivateProfileInt(section,"WeaponDurabilityRate",0,path);

	this->m_ArmorDurabilityRate = GetPrivateProfileInt(section,"ArmorDurabilityRate",0,path);

	this->m_WingDurabilityRate = GetPrivateProfileInt(section,"WingDurabilityRate",0,path);

	this->m_GuardianDurabilityRate = GetPrivateProfileInt(section,"GuardianDurabilityRate",0,path);

	this->m_PendantDurabilityRate = GetPrivateProfileInt(section,"PendantDurabilityRate",0,path);

	this->m_RingDurabilityRate = GetPrivateProfileInt(section,"RingDurabilityRate",0,path);

	this->m_PetDurabilityRate = GetPrivateProfileInt(section,"PetDurabilityRate",0,path);

	//#if(GAMESERVER_UPDATE>=803)

	this->m_MuunDurabilityRate = GetPrivateProfileInt(section,"MuunDurabilityRate",0,path);

	//#endif

	this->m_TradeItemBlock = GetPrivateProfileInt(section,"TradeItemBlock",0,path);

	this->m_TradeItemBlockExc = GetPrivateProfileInt(section,"TradeItemBlockExc",0,path);

	this->m_TradeItemBlockSet = GetPrivateProfileInt(section,"TradeItemBlockSet",0,path);

	this->m_TradeItemBlockHarmony = GetPrivateProfileInt(section,"TradeItemBlockHarmony",0,path);

	this->m_TradeItemBlockSell = GetPrivateProfileInt(section,"TradeItemBlockSell",0,path);

	this->m_TradeItemBlockLucky = GetPrivateProfileInt(section,"TradeItemBlockLucky",1,path);

	this->m_MaxLevelUp = GetPrivateProfileInt(section,"MaxLevelUp",0,path);

	this->m_MaxLevelUpEvent = GetPrivateProfileInt(section,"MaxLevelUpEvent",0,path);

	#if(GAMESERVER_UPDATE>=501)

	this->m_MaxLevelUpQuest = GetPrivateProfileInt(section,"MaxLevelUpQuest",0,path);

	#endif

	// max stat for class
	this->STR_MaxStatPoint[0] = GetPrivateProfileInt(section, "DW_MaxStatPoint_STR", 0, path);
	this->STR_MaxStatPoint[1] = GetPrivateProfileInt(section, "DK_MaxStatPoint_STR", 0, path);
	this->STR_MaxStatPoint[2] = GetPrivateProfileInt(section, "ELF_MaxStatPoint_STR", 0, path);
	this->STR_MaxStatPoint[3] = GetPrivateProfileInt(section, "MG_MaxStatPoint_STR", 0, path);
	this->STR_MaxStatPoint[4] = GetPrivateProfileInt(section, "DL_MaxStatPoint_STR", 0, path);
	this->STR_MaxStatPoint[5] = GetPrivateProfileInt(section, "SU_MaxStatPoint_STR", 0, path);
	this->STR_MaxStatPoint[6] = GetPrivateProfileInt(section, "RF_MaxStatPoint_STR", 0, path);
	//----------------------
	this->AGI_MaxStatPoint[0] = GetPrivateProfileInt(section, "DW_MaxStatPoint_AGI", 0, path);
	this->AGI_MaxStatPoint[1] = GetPrivateProfileInt(section, "DK_MaxStatPoint_AGI", 0, path);
	this->AGI_MaxStatPoint[2] = GetPrivateProfileInt(section, "ELF_MaxStatPoint_AGI", 0, path);
	this->AGI_MaxStatPoint[3] = GetPrivateProfileInt(section, "MG_MaxStatPoint_AGI", 0, path);
	this->AGI_MaxStatPoint[4] = GetPrivateProfileInt(section, "DL_MaxStatPoint_AGI", 0, path);
	this->AGI_MaxStatPoint[5] = GetPrivateProfileInt(section, "SU_MaxStatPoint_AGI", 0, path);
	this->AGI_MaxStatPoint[6] = GetPrivateProfileInt(section, "RF_MaxStatPoint_AGI", 0, path);
	//----------------------
	this->VIT_MaxStatPoint[0] = GetPrivateProfileInt(section, "DW_MaxStatPoint_VIT", 0, path);
	this->VIT_MaxStatPoint[1] = GetPrivateProfileInt(section, "DK_MaxStatPoint_VIT", 0, path);
	this->VIT_MaxStatPoint[2] = GetPrivateProfileInt(section, "ELF_MaxStatPoint_VIT", 0, path);
	this->VIT_MaxStatPoint[3] = GetPrivateProfileInt(section, "MG_MaxStatPoint_VIT", 0, path);
	this->VIT_MaxStatPoint[4] = GetPrivateProfileInt(section, "DL_MaxStatPoint_VIT", 0, path);
	this->VIT_MaxStatPoint[5] = GetPrivateProfileInt(section, "SU_MaxStatPoint_VIT", 0, path);
	this->VIT_MaxStatPoint[6] = GetPrivateProfileInt(section, "RF_MaxStatPoint_VIT", 0, path);
	//----------------------
	this->ENE_MaxStatPoint[0] = GetPrivateProfileInt(section, "DW_MaxStatPoint_ENE", 0, path);
	this->ENE_MaxStatPoint[1] = GetPrivateProfileInt(section, "DK_MaxStatPoint_ENE", 0, path);
	this->ENE_MaxStatPoint[2] = GetPrivateProfileInt(section, "ELF_MaxStatPoint_ENE", 0, path);
	this->ENE_MaxStatPoint[3] = GetPrivateProfileInt(section, "MG_MaxStatPoint_ENE", 0, path);
	this->ENE_MaxStatPoint[4] = GetPrivateProfileInt(section, "DL_MaxStatPoint_ENE", 0, path);
	this->ENE_MaxStatPoint[5] = GetPrivateProfileInt(section, "SU_MaxStatPoint_ENE", 0, path);
	this->ENE_MaxStatPoint[6] = GetPrivateProfileInt(section, "RF_MaxStatPoint_ENE", 0, path);
	//----------------------

	this->m_MaxStatPoint[0] = GetPrivateProfileInt(section,"MaxStatPoint_AL0",0,path);

	this->m_MaxStatPoint[1] = GetPrivateProfileInt(section,"MaxStatPoint_AL1",0,path);

	this->m_MaxStatPoint[2] = GetPrivateProfileInt(section,"MaxStatPoint_AL2",0,path);

	this->m_MaxStatPoint[3] = GetPrivateProfileInt(section,"MaxStatPoint_AL3",0,path);
	//---
	this->m_MaxStatPointCMD[0] = GetPrivateProfileInt(section,"MaxStatPointCMD_AL0",0,path);

	this->m_MaxStatPointCMD[1] = GetPrivateProfileInt(section,"MaxStatPointCMD_AL1",0,path);

	this->m_MaxStatPointCMD[2] = GetPrivateProfileInt(section,"MaxStatPointCMD_AL2",0,path);

	this->m_MaxStatPointCMD[3] = GetPrivateProfileInt(section,"MaxStatPointCMD_AL3",0,path);
	//---
	this->m_LevelUpPoint[0] = GetPrivateProfileInt(section,"DWLevelUpPoint",0,path);

	this->m_LevelUpPoint[1] = GetPrivateProfileInt(section,"DKLevelUpPoint",0,path);

	this->m_LevelUpPoint[2] = GetPrivateProfileInt(section,"FELevelUpPoint",0,path);

	this->m_LevelUpPoint[3] = GetPrivateProfileInt(section,"MGLevelUpPoint",0,path);

	this->m_LevelUpPoint[4] = GetPrivateProfileInt(section,"DLLevelUpPoint",0,path);

	#if(GAMESERVER_UPDATE>=301)

	this->m_LevelUpPoint[5] = GetPrivateProfileInt(section,"SULevelUpPoint",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=601)

	this->m_LevelUpPoint[6] = GetPrivateProfileInt(section,"RFLevelUpPoint",0,path);

	#endif

	this->m_PlusStatPoint = GetPrivateProfileInt(section,"PlusStatPoint",0,path);

	this->m_CharacterCreateSwitch = GetPrivateProfileInt(section,"CharacterCreateSwitch",0,path);

	this->m_MGCreateType = GetPrivateProfileInt(section,"MGCreateType",0,path);

	this->m_DLCreateType = GetPrivateProfileInt(section,"DLCreateType",0,path);

	#if(GAMESERVER_UPDATE>=301)

	this->m_SUCreateType = GetPrivateProfileInt(section,"SUCreateType",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFCreateType = GetPrivateProfileInt(section,"RFCreateType",0,path);

	#endif

	this->m_MGCreateLevel[0] = GetPrivateProfileInt(section,"MGCreateLevel_AL0",0,path);

	this->m_MGCreateLevel[1] = GetPrivateProfileInt(section,"MGCreateLevel_AL1",0,path);

	this->m_MGCreateLevel[2] = GetPrivateProfileInt(section,"MGCreateLevel_AL2",0,path);

	this->m_MGCreateLevel[3] = GetPrivateProfileInt(section,"MGCreateLevel_AL3",0,path);

	this->m_MGCreateReset[0] = GetPrivateProfileInt(section,"MGCreateReset_AL0",0,path);

	this->m_MGCreateReset[1] = GetPrivateProfileInt(section,"MGCreateReset_AL1",0,path);

	this->m_MGCreateReset[2] = GetPrivateProfileInt(section,"MGCreateReset_AL2",0,path);

	this->m_MGCreateReset[3] = GetPrivateProfileInt(section,"MGCreateReset_AL3",0,path);

	this->m_MGCreateMasterReset[0] = GetPrivateProfileInt(section,"MGCreateMasterReset_AL0",0,path);

	this->m_MGCreateMasterReset[1] = GetPrivateProfileInt(section,"MGCreateMasterReset_AL1",0,path);

	this->m_MGCreateMasterReset[2] = GetPrivateProfileInt(section,"MGCreateMasterReset_AL2",0,path);

	this->m_MGCreateMasterReset[3] = GetPrivateProfileInt(section,"MGCreateMasterReset_AL3",0,path);

	this->m_DLCreateLevel[0] = GetPrivateProfileInt(section,"DLCreateLevel_AL0",0,path);

	this->m_DLCreateLevel[1] = GetPrivateProfileInt(section,"DLCreateLevel_AL1",0,path);

	this->m_DLCreateLevel[2] = GetPrivateProfileInt(section,"DLCreateLevel_AL2",0,path);

	this->m_DLCreateLevel[3] = GetPrivateProfileInt(section,"DLCreateLevel_AL3",0,path);

	this->m_DLCreateReset[0] = GetPrivateProfileInt(section,"DLCreateReset_AL0",0,path);

	this->m_DLCreateReset[1] = GetPrivateProfileInt(section,"DLCreateReset_AL1",0,path);

	this->m_DLCreateReset[2] = GetPrivateProfileInt(section,"DLCreateReset_AL2",0,path);

	this->m_DLCreateReset[3] = GetPrivateProfileInt(section,"DLCreateReset_AL3",0,path);

	this->m_DLCreateMasterReset[0] = GetPrivateProfileInt(section,"DLCreateMasterReset_AL0",0,path);

	this->m_DLCreateMasterReset[1] = GetPrivateProfileInt(section,"DLCreateMasterReset_AL1",0,path);

	this->m_DLCreateMasterReset[2] = GetPrivateProfileInt(section,"DLCreateMasterReset_AL2",0,path);

	this->m_DLCreateMasterReset[3] = GetPrivateProfileInt(section,"DLCreateMasterReset_AL3",0,path);

	#if(GAMESERVER_UPDATE>=301)

	this->m_SUCreateLevel[0] = GetPrivateProfileInt(section,"SUCreateLevel_AL0",0,path);

	this->m_SUCreateLevel[1] = GetPrivateProfileInt(section,"SUCreateLevel_AL1",0,path);

	this->m_SUCreateLevel[2] = GetPrivateProfileInt(section,"SUCreateLevel_AL2",0,path);

	this->m_SUCreateLevel[3] = GetPrivateProfileInt(section,"SUCreateLevel_AL3",0,path);

	this->m_SUCreateReset[0] = GetPrivateProfileInt(section,"SUCreateReset_AL0",0,path);

	this->m_SUCreateReset[1] = GetPrivateProfileInt(section,"SUCreateReset_AL1",0,path);

	this->m_SUCreateReset[2] = GetPrivateProfileInt(section,"SUCreateReset_AL2",0,path);

	this->m_SUCreateReset[3] = GetPrivateProfileInt(section,"SUCreateReset_AL3",0,path);

	this->m_SUCreateMasterReset[0] = GetPrivateProfileInt(section,"SUCreateMasterReset_AL0",0,path);

	this->m_SUCreateMasterReset[1] = GetPrivateProfileInt(section,"SUCreateMasterReset_AL1",0,path);

	this->m_SUCreateMasterReset[2] = GetPrivateProfileInt(section,"SUCreateMasterReset_AL2",0,path);

	this->m_SUCreateMasterReset[3] = GetPrivateProfileInt(section,"SUCreateMasterReset_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=601)

	this->m_RFCreateLevel[0] = GetPrivateProfileInt(section,"RFCreateLevel_AL0",0,path);

	this->m_RFCreateLevel[1] = GetPrivateProfileInt(section,"RFCreateLevel_AL1",0,path);

	this->m_RFCreateLevel[2] = GetPrivateProfileInt(section,"RFCreateLevel_AL2",0,path);

	this->m_RFCreateLevel[3] = GetPrivateProfileInt(section,"RFCreateLevel_AL3",0,path);

	this->m_RFCreateReset[0] = GetPrivateProfileInt(section,"RFCreateReset_AL0",0,path);

	this->m_RFCreateReset[1] = GetPrivateProfileInt(section,"RFCreateReset_AL1",0,path);

	this->m_RFCreateReset[2] = GetPrivateProfileInt(section,"RFCreateReset_AL2",0,path);

	this->m_RFCreateReset[3] = GetPrivateProfileInt(section,"RFCreateReset_AL3",0,path);

	this->m_RFCreateMasterReset[0] = GetPrivateProfileInt(section,"RFCreateMasterReset_AL0",0,path);

	this->m_RFCreateMasterReset[1] = GetPrivateProfileInt(section,"RFCreateMasterReset_AL1",0,path);

	this->m_RFCreateMasterReset[2] = GetPrivateProfileInt(section,"RFCreateMasterReset_AL2",0,path);

	this->m_RFCreateMasterReset[3] = GetPrivateProfileInt(section,"RFCreateMasterReset_AL3",0,path);

	#endif

	this->m_ShieldGaugeRate = GetPrivateProfileInt(section,"ShieldGaugeRate",0,path);

	this->m_ShieldGaugeConstA = GetPrivateProfileInt(section,"ShieldGaugeConstA",0,path);

	this->m_ShieldGaugeConstB = GetPrivateProfileInt(section,"ShieldGaugeConstB",0,path);

	this->m_ShieldGaugeAttackRate = GetPrivateProfileInt(section,"ShieldGaugeAttackRate",0,path);

	this->m_ShieldGaugeAttackComboMiss = GetPrivateProfileInt(section,"ShieldGaugeAttackComboMiss",0,path);

	#if(GAMESERVER_UPDATE>=401)

	this->m_MasterSkillTree = GetPrivateProfileInt(section,"MasterSkillTree",0,path);

	this->m_MasterSkillTreePoint = GetPrivateProfileInt(section,"MasterSkillTreePoint",0,path);

	this->m_MasterSkillTreeMaxLevel = GetPrivateProfileInt(section,"MasterSkillTreeMaxLevel",0,path);

	#endif

	this->Max_LevelPlus = GetPrivateProfileInt(section,"Max_LevelPlus",0,path);

	this->DownGrade = GetPrivateProfileInt(section,"DownGrade",0,path);

	#if(GAMESERVER_UPDATE<=402)

	this->m_PcPointSwitch = GetPrivateProfileInt(section,"PcPointSwitch",0,path);

	this->m_PcPointMaxPoint = GetPrivateProfileInt(section,"PcPointMaxPoint",0,path);

	this->m_PcPointPointDelay = GetPrivateProfileInt(section,"PcPointPointDelay",0,path);

	this->m_PcPointPointValue[0] = GetPrivateProfileInt(section,"PcPointPointValue_AL0",0,path);

	this->m_PcPointPointValue[1] = GetPrivateProfileInt(section,"PcPointPointValue_AL1",0,path);

	this->m_PcPointPointValue[2] = GetPrivateProfileInt(section,"PcPointPointValue_AL2",0,path);

	this->m_PcPointPointValue[3] = GetPrivateProfileInt(section,"PcPointPointValue_AL3",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=501)

	this->m_GensSystemSwitch = GetPrivateProfileInt(section,"GensSystemSwitch",0,path);

	this->m_GensSystemGuildLock = GetPrivateProfileInt(section,"GensSystemGuildLock",0,path);

	this->m_GensSystemPartyLock = GetPrivateProfileInt(section,"GensSystemPartyLock",0,path);

	this->m_GensSystemInsertMinLevel = GetPrivateProfileInt(section,"GensSystemInsertMinLevel",0,path);

	this->m_GensSystemContributionFloodTime = GetPrivateProfileInt(section,"GensSystemContributionFloodTime",0,path);

	this->m_GensSystemVictimContributionDecrease = GetPrivateProfileInt(section,"GensSystemVictimContributionDecrease",0,path);

	this->m_GensSystemKillerContributionIncrease = GetPrivateProfileInt(section,"GensSystemKillerContributionIncrease",0,path);

	this->m_GensSystemVictimMinContributionDecrease = GetPrivateProfileInt(section,"GensSystemVictimMinContributionDecrease",0,path);

	this->m_GensSystemVictimMaxContributionDecrease = GetPrivateProfileInt(section,"GensSystemVictimMaxContributionDecrease",0,path);

	this->m_GensSystemKillerMinContributionIncrease = GetPrivateProfileInt(section,"GensSystemKillerMinContributionIncrease",0,path);

	this->m_GensSystemKillerMaxContributionIncrease = GetPrivateProfileInt(section,"GensSystemKillerMaxContributionIncrease",0,path);

	this->m_GensSystemStartRewardDay = GetPrivateProfileInt(section,"GensSystemStartRewardDay",0,path);

	this->m_GensSystemFinalRewardDay = GetPrivateProfileInt(section,"GensSystemFinalRewardDay",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=603)

	this->m_HelperSwitch = GetPrivateProfileInt(section,"HelperSwitch",0,path);

	this->m_HelperActiveLevel = GetPrivateProfileInt(section,"HelperActiveLevel",0,path);

	this->m_HelperActiveDelay = GetPrivateProfileInt(section,"HelperActiveDelay",0,path);

	this->m_HelperActiveMoney[0] = GetPrivateProfileInt(section,"HelperActiveMoney1",0,path);

	this->m_HelperActiveMoney[1] = GetPrivateProfileInt(section,"HelperActiveMoney2",0,path);

	this->m_HelperActiveMoney[2] = GetPrivateProfileInt(section,"HelperActiveMoney3",0,path);

	this->m_HelperActiveMoney[3] = GetPrivateProfileInt(section,"HelperActiveMoney4",0,path);

	this->m_HelperActiveMoney[4] = GetPrivateProfileInt(section,"HelperActiveMoney5",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=802)

	this->m_EventInventorySwitch = GetPrivateProfileInt(section,"EventInventorySwitch",0,path);

	this->m_EventInventoryExpireYear = GetPrivateProfileInt(section,"EventInventoryExpireYear",0,path);

	this->m_EventInventoryExpireMonth = GetPrivateProfileInt(section,"EventInventoryExpireMonth",0,path);

	this->m_EventInventoryExpireDay = GetPrivateProfileInt(section,"EventInventoryExpireDay",0,path);

	this->m_MuRummySwitch = GetPrivateProfileInt(section,"MuRummySwitch",0,path);

	this->m_MuRummyRewardScore1 = GetPrivateProfileInt(section,"MuRummyRewardScore1",0,path);

	this->m_MuRummyRewardScore2 = GetPrivateProfileInt(section,"MuRummyRewardScore2",0,path);

	this->m_MuRummyRewardMoneyAmount = GetPrivateProfileInt(section,"MuRummyRewardMoneyAmount",0,path);

	#endif

	this->m_PartyReconnectTime = GetPrivateProfileInt(section,"PartyReconnectTime",0,path);

	this->m_PartyGeneralExperience[0] = GetPrivateProfileInt(section,"PartyGeneralExperience1",0,path);

	this->m_PartyGeneralExperience[1] = GetPrivateProfileInt(section,"PartyGeneralExperience2",0,path);

	this->m_PartyGeneralExperience[2] = GetPrivateProfileInt(section,"PartyGeneralExperience3",0,path);

	this->m_PartyGeneralExperience[3] = GetPrivateProfileInt(section,"PartyGeneralExperience4",0,path);

	this->m_PartyGeneralExperience[4] = GetPrivateProfileInt(section,"PartyGeneralExperience5",0,path);

	this->m_PartyGeneralExperience[5] = GetPrivateProfileInt(section,"PartyGeneralExperience6",0,path);

	this->m_PartyGeneralExperience[6] = GetPrivateProfileInt(section,"PartyGeneralExperience7",0,path);

	this->m_PartyGeneralExperience[7] = GetPrivateProfileInt(section,"PartyGeneralExperience8",0,path);

	this->m_PartyGeneralExperience[8] = GetPrivateProfileInt(section,"PartyGeneralExperience9",0,path);

	this->m_PartyGeneralExperience[9] = GetPrivateProfileInt(section,"PartyGeneralExperience10",0,path);

	this->m_PartySpecialExperience[0] = GetPrivateProfileInt(section,"PartySpecialExperience1",0,path);

	this->m_PartySpecialExperience[1] = GetPrivateProfileInt(section,"PartySpecialExperience2",0,path);

	this->m_PartySpecialExperience[2] = GetPrivateProfileInt(section,"PartySpecialExperience3",0,path);

	this->m_PartySpecialExperience[3] = GetPrivateProfileInt(section,"PartySpecialExperience4",0,path);

	this->m_PartySpecialExperience[4] = GetPrivateProfileInt(section,"PartySpecialExperience5",0,path);

	this->m_PartySpecialExperience[5] = GetPrivateProfileInt(section,"PartySpecialExperience6",0,path);

	this->m_PartySpecialExperience[6] = GetPrivateProfileInt(section,"PartySpecialExperience7",0,path);

	this->m_PartySpecialExperience[7] = GetPrivateProfileInt(section,"PartySpecialExperience8",0,path);

	this->m_PartySpecialExperience[8] = GetPrivateProfileInt(section,"PartySpecialExperience9",0,path);

	this->m_PartySpecialExperience[9] = GetPrivateProfileInt(section,"PartySpecialExperience10",0,path);

	this->m_PartyMaxMembers = GetPrivateProfileInt(section,"PartyMaxMembers",5,path);
	
	this->m_PartyRestrict = GetPrivateProfileInt(section,"RestrictRequest", 0, path);

	this->m_DifferenceMaxLevelParty = GetPrivateProfileInt(section,"DifferenceMaxLevel", 0, path);

	this->m_ApplePotionRate = GetPrivateProfileInt(section,"ApplePotionRate",0,path);

	this->m_SmallLifePotionRate = GetPrivateProfileInt(section,"SmallLifePotionRate",0,path);

	this->m_MidleLifePotionRate = GetPrivateProfileInt(section,"MidleLifePotionRate",0,path);

	this->m_LargeLifePotionRate = GetPrivateProfileInt(section,"LargeLifePotionRate",0,path);

	this->m_SmallManaPotionRate = GetPrivateProfileInt(section,"SmallManaPotionRate",0,path);

	this->m_MidleManaPotionRate = GetPrivateProfileInt(section,"MidleManaPotionRate",0,path);

	this->m_LargeManaPotionRate = GetPrivateProfileInt(section,"LargeManaPotionRate",0,path);

	this->m_SmallShieldPotionRate = GetPrivateProfileInt(section,"SmallShieldPotionRate",0,path);

	this->m_MidleShieldPotionRate = GetPrivateProfileInt(section,"MidleShieldPotionRate",0,path);

	this->m_LargeShieldPotionRate = GetPrivateProfileInt(section,"LargeShieldPotionRate",0,path);

	this->m_SmallCompoundPotionRate1 = GetPrivateProfileInt(section,"SmallCompoundPotionRate1",0,path);

	this->m_SmallCompoundPotionRate2 = GetPrivateProfileInt(section,"SmallCompoundPotionRate2",0,path);

	this->m_MidleCompoundPotionRate1 = GetPrivateProfileInt(section,"MidleCompoundPotionRate1",0,path);

	this->m_MidleCompoundPotionRate2 = GetPrivateProfileInt(section,"MidleCompoundPotionRate2",0,path);

	this->m_LargeCompoundPotionRate1 = GetPrivateProfileInt(section,"LargeCompoundPotionRate1",0,path);

	this->m_LargeCompoundPotionRate2 = GetPrivateProfileInt(section,"LargeCompoundPotionRate2",0,path);

	this->m_EliteLifePotionRate = GetPrivateProfileInt(section,"EliteLifePotionRate",0,path);

	this->m_EliteManaPotionRate = GetPrivateProfileInt(section,"EliteManaPotionRate",0,path);

	this->m_EliteShieldPotionRate = GetPrivateProfileInt(section,"EliteShieldPotionRate",0,path);

	this->m_TransformationRing1 = GetPrivateProfileInt(section,"TransformationRing1",0,path);

	this->m_TransformationRing2 = GetPrivateProfileInt(section,"TransformationRing2",0,path);

	this->m_TransformationRing3 = GetPrivateProfileInt(section,"TransformationRing3",0,path);

	this->m_TransformationRing4 = GetPrivateProfileInt(section,"TransformationRing4",0,path);

	this->m_TransformationRing5 = GetPrivateProfileInt(section,"TransformationRing5",0,path);

	this->m_TransformationRing6 = GetPrivateProfileInt(section,"TransformationRing6",0,path);

	this->m_SoulSuccessRate[0] = GetPrivateProfileInt(section,"SoulSuccessRate_AL0",0,path);

	this->m_SoulSuccessRate[1] = GetPrivateProfileInt(section,"SoulSuccessRate_AL1",0,path);

	this->m_SoulSuccessRate[2] = GetPrivateProfileInt(section,"SoulSuccessRate_AL2",0,path);

	this->m_SoulSuccessRate[3] = GetPrivateProfileInt(section,"SoulSuccessRate_AL3",0,path);

	this->m_LifeSuccessRate[0] = GetPrivateProfileInt(section,"LifeSuccessRate_AL0",0,path);

	this->m_LifeSuccessRate[1] = GetPrivateProfileInt(section,"LifeSuccessRate_AL1",0,path);

	this->m_LifeSuccessRate[2] = GetPrivateProfileInt(section,"LifeSuccessRate_AL2",0,path);

	this->m_LifeSuccessRate[3] = GetPrivateProfileInt(section,"LifeSuccessRate_AL3",0,path);

	this->m_HarmonySuccessRate[0] = GetPrivateProfileInt(section,"HarmonySuccessRate_AL0",0,path);

	this->m_HarmonySuccessRate[1] = GetPrivateProfileInt(section,"HarmonySuccessRate_AL1",0,path);

	this->m_HarmonySuccessRate[2] = GetPrivateProfileInt(section,"HarmonySuccessRate_AL2",0,path);

	this->m_HarmonySuccessRate[3] = GetPrivateProfileInt(section,"HarmonySuccessRate_AL3",0,path);

	this->m_SmeltStoneSuccessRate1[0] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate1_AL0",0,path);

	this->m_SmeltStoneSuccessRate1[1] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate1_AL1",0,path);

	this->m_SmeltStoneSuccessRate1[2] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate1_AL2",0,path);

	this->m_SmeltStoneSuccessRate1[3] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate1_AL3",0,path);

	this->m_SmeltStoneSuccessRate2[0] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate2_AL0",0,path);

	this->m_SmeltStoneSuccessRate2[1] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate2_AL1",0,path);

	this->m_SmeltStoneSuccessRate2[2] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate2_AL2",0,path);

	this->m_SmeltStoneSuccessRate2[3] = GetPrivateProfileInt(section,"SmeltStoneSuccessRate2_AL3",0,path);

	this->m_AddLuckSuccessRate1[0] = GetPrivateProfileInt(section,"AddLuckSuccessRate1_AL0",0,path);

	this->m_AddLuckSuccessRate1[1] = GetPrivateProfileInt(section,"AddLuckSuccessRate1_AL1",0,path);

	this->m_AddLuckSuccessRate1[2] = GetPrivateProfileInt(section,"AddLuckSuccessRate1_AL2",0,path);

	this->m_AddLuckSuccessRate1[3] = GetPrivateProfileInt(section,"AddLuckSuccessRate1_AL3",0,path);

	this->m_AddLuckSuccessRate2[0] = GetPrivateProfileInt(section,"AddLuckSuccessRate2_AL0",0,path);

	this->m_AddLuckSuccessRate2[1] = GetPrivateProfileInt(section,"AddLuckSuccessRate2_AL1",0,path);

	this->m_AddLuckSuccessRate2[2] = GetPrivateProfileInt(section,"AddLuckSuccessRate2_AL2",0,path);

	this->m_AddLuckSuccessRate2[3] = GetPrivateProfileInt(section,"AddLuckSuccessRate2_AL3",0,path);

	this->m_FruitAddPointMin = GetPrivateProfileInt(section,"FruitAddPointMin",0,path);

	this->m_FruitAddPointMax = GetPrivateProfileInt(section,"FruitAddPointMax",0,path);

	this->m_FruitAddPointSuccessRate[0] = GetPrivateProfileInt(section,"FruitAddPointSuccessRate_AL0",0,path);

	this->m_FruitAddPointSuccessRate[1] = GetPrivateProfileInt(section,"FruitAddPointSuccessRate_AL1",0,path);

	this->m_FruitAddPointSuccessRate[2] = GetPrivateProfileInt(section,"FruitAddPointSuccessRate_AL2",0,path);

	this->m_FruitAddPointSuccessRate[3] = GetPrivateProfileInt(section,"FruitAddPointSuccessRate_AL3",0,path);

	this->m_FruitMaxPointValue = GetPrivateProfileInt(section, "FruitMaxPointValue", 0, path);

	this->m_FruitSubPointMin = GetPrivateProfileInt(section,"FruitSubPointMin",0,path);

	this->m_FruitSubPointMax = GetPrivateProfileInt(section,"FruitSubPointMax",0,path);

	this->m_FruitSubPointSuccessRate[0] = GetPrivateProfileInt(section,"FruitSubPointSuccessRate_AL0",0,path);

	this->m_FruitSubPointSuccessRate[1] = GetPrivateProfileInt(section,"FruitSubPointSuccessRate_AL1",0,path);

	this->m_FruitSubPointSuccessRate[2] = GetPrivateProfileInt(section,"FruitSubPointSuccessRate_AL2",0,path);

	this->m_FruitSubPointSuccessRate[3] = GetPrivateProfileInt(section,"FruitSubPointSuccessRate_AL3",0,path);

	//HpBonus system
	this->m_HpBonus[0] = GetPrivateProfileInt(section,"HpBonus_AL0",0,path);

	this->m_HpBonus[1] = GetPrivateProfileInt(section,"HpBonus_AL1",0,path);

	this->m_HpBonus[2] = GetPrivateProfileInt(section,"HpBonus_AL2",0,path);

	this->m_HpBonus[3] = GetPrivateProfileInt(section,"HpBonus_AL3",0,path);

	this->m_HpBonusMax = GetPrivateProfileInt(section,"HpBonus_MAX",0,path);

	//Die system
	this->m_DieUserSwitch			= GetPrivateProfileInt(section,"DieUserSwitch",0,path);

	this->m_DieMonsterSwitch		= GetPrivateProfileInt(section,"DieMonsterSwitch",0,path);

	//Online user
	this->m_OnlineGmSwitch			= GetPrivateProfileInt(section,"OnlineGmSwitch",0,path);

	this->m_OnlineUserSwitch		= GetPrivateProfileInt(section,"OnlineUserSwitch",0,path);

	//Disable exp messsage
	this->m_DisableExpMessage		= GetPrivateProfileInt(section,"DisableExpMessage",0,path);

	//Disable Skill Effect
	this->m_DisableLightningEffect	= GetPrivateProfileInt(section,"DisableLightningEffect",0,path);
	this->m_DisableFallingEffect	= GetPrivateProfileInt(section,"DisableFallingEffect",0,path);
	this->m_DisableLungEffect		= GetPrivateProfileInt(section,"DisableLungEffect",0,path);
	this->m_DisableUpperCutEffect	= GetPrivateProfileInt(section,"DisableUpperCutEffect",0,path);
	this->m_DisableCycloneEffect	= GetPrivateProfileInt(section,"DisableCycloneEffect",0,path);
	this->m_DisableTwistEffect		= GetPrivateProfileInt(section,"DisableTwistEffect",0,path);
	
	//jewel of socket in pentragram
	this->m_JewelSocketPentagram	= GetPrivateProfileInt(section,"JewelSocketPentagram",0,path);

	//Disable wing mix
	this->m_DisableWingMixDL	= GetPrivateProfileInt(section,"DisableWingMixDL",0,path);
	this->m_DisableWingMixSU	= GetPrivateProfileInt(section,"DisableWingMixSU",0,path);
	this->m_DisableWingMixRF	= GetPrivateProfileInt(section,"DisableWingMixRF",0,path);

	this->m_DisableWing4MixSU	= GetPrivateProfileInt(section,"DisableWing4MixSU",0,path);
	this->m_DisableWing4MixRF	= GetPrivateProfileInt(section,"DisableWing4MixRF",0,path);

	//Pk enter in events
	this->m_PkCanEnterBC	= GetPrivateProfileInt(section,"PkCanEnterBC",0,path);
	this->m_PkCanEnterCC	= GetPrivateProfileInt(section,"PkCanEnterCC",0,path);
	this->m_PkCanEnterDS	= GetPrivateProfileInt(section,"PkCanEnterDS",0,path);

	//Pk Item Drop
	this->m_PkItemDropSwitch	=  GetPrivateProfileInt(section,"PkItemDropSwitch",0,path);
	this->m_PkItemDropRate		=  GetPrivateProfileInt(section,"PkItemDropRate",0,path);
	this->m_PkItemDropMinLevel	=  GetPrivateProfileInt(section,"PkItemDropMinLevel",0,path);
	this->m_PkItemDropMaxLevel	=  GetPrivateProfileInt(section,"PkItemDropMaxLevel",0,path);
	this->m_PkItemDropExecellent=  GetPrivateProfileInt(section,"PkItemDropExecellent",0,path);
	this->m_PkItemDropSocketItem=  GetPrivateProfileInt(section,"PkItemDropSocketItem",0,path);
	this->m_PkItemDropSetItem	=  GetPrivateProfileInt(section,"PkItemDropSetItem",0,path);
	this->m_PkItemDropHarmony	=  GetPrivateProfileInt(section,"PkItemDropHarmony",0,path);

	this->m_PkItemDropEnable[0] =  GetPrivateProfileInt(section,"PkItemDropEnable_AL0",0,path);

	this->m_PkItemDropEnable[1] =  GetPrivateProfileInt(section,"PkItemDropEnable_AL1",0,path);

	this->m_PkItemDropEnable[2] =  GetPrivateProfileInt(section,"PkItemDropEnable_AL2",0,path);

	this->m_PkItemDropEnable[3] =  GetPrivateProfileInt(section,"PkItemDropEnable_AL3",0,path);

	this->m_DisconnectOnlineAccount	=  GetPrivateProfileInt(section,"DisconnectOnlineAccount",0,path);

	//Disable wing mix
	this->m_EnableCsSkillsAllMaps	= GetPrivateProfileInt(section,"EnableCsSkillsAllMaps",0,path);

	//Combo to all Classes
	this->m_EnableComboToAllSwitch	= GetPrivateProfileInt(section,"EnableComboToAllSwitch",0,path);

	//idioma
	this->m_Idioma = GetPrivateProfileInt(section, "Message_Language", 1, path);

	this->m_SocketHarmony = GetPrivateProfileInt(section, "SocketItemAcceptHarmonySwitch", 0, path);

	//Advanced Zen Drop Value
	this->m_MoneyValue[0]	= GetPrivateProfileInt(section,"MoneyValue_AL0",0,path);
	this->m_MoneyValue[1]	= GetPrivateProfileInt(section,"MoneyValue_AL1",0,path);
	this->m_MoneyValue[2]	= GetPrivateProfileInt(section,"MoneyValue_AL2",0,path);
	this->m_MoneyValue[3]	= GetPrivateProfileInt(section,"MoneyValue_AL3",0,path);

	this->m_PartyDisablePK	=  GetPrivateProfileInt(section,"PartyDisablePK",0,path);

}

void CServerInfo::ReadCustomInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};
	//---
	this->m_DissableSD = GetPrivateProfileInt(section,"DisabledSD", 0, path);

	this->m_AnnounceChaosMix	= GetPrivateProfileInt(section,"AnnounceChaosMix",0,path);

	this->m_CustomQuestSwitch	= GetPrivateProfileInt(section,"CustomQuestSwitch",0,path);

	GetPrivateProfileString(section,"AnnounceChaosMixText","",this->m_AnnounceChaosMixText,sizeof(this->m_AnnounceChaosMixText),path);

	this->m_CustomRankUserSwitch		= GetPrivateProfileInt(section,"CustomRankUserSwitch",0,path);
	this->m_CustomRankUserType		= GetPrivateProfileInt(section,"CustomRankUserType",0,path);
	this->m_CustomRankUserRewardSwitch	= GetPrivateProfileInt(section,"CustomRankUserRewardSwitch",0,path);
	this->m_CustomRankUserNoticeToAll	= GetPrivateProfileInt(section,"CustomRankUserNoticeToAll",0,path);
	this->m_CustomRankUserNoticeToUser	= GetPrivateProfileInt(section,"CustomRankUserNoticeToUser",0,path);

	this->m_CustomNpcCollectorSwitch    =  GetPrivateProfileInt(section,"CustomNpcCollectorSwitch",0,path);

	this->m_CustomDeathMessageSwitch	= GetPrivateProfileInt(section,"CustomDeathMessageSwitch",0,path);

	//-- CUSTOMNPCTALK
	this->m_CustomNpcTalkBaul	= GetPrivateProfileInt(section,"CustomNpcTalkBaul",0,path);

	this->m_CustomNpcTalkQuest	= GetPrivateProfileInt(section,"CustomNpcTalkQuest",0,path);

	this->m_CustomNpcTalkGoblin	= GetPrivateProfileInt(section,"CustomNpcTalkGoblin",0,path);

	this->m_CustomNpcTalkTrainer	= GetPrivateProfileInt(section,"CustomNpcTalkTrainer",0,path);

	this->m_CustomNpcTalkGuard	= GetPrivateProfileInt(section,"CustomNpcTalkGuard",0,path);

	this->m_CustomNpcTalkNixie	= GetPrivateProfileInt(section,"CustomNpcTalkNixie",0,path);

	this->m_CustomNpcTalkPriestJames = GetPrivateProfileInt(section, "CustomNpcTalkPriestJames", 0, path);

	this->m_CustomQuizSwitch			=  GetPrivateProfileInt(section,"CustomQuizSwitch",0,path);

	//CUSTOM RANKING
	this->m_CustomRankingSwitch			=  GetPrivateProfileInt(section,"CustomRankingSwitch",0,path);
	//CUSTOM EVENTTIME
	this->m_CustomEventTimeSwitch		=  GetPrivateProfileInt(section,"CustomEventTimeSwitch",0,path);
	//CUSTOM GUILD WAREHOUSE
	this->m_GuildWarehouseEnable		=  GetPrivateProfileInt(section,"GuildWarehouseEnable",0,path);
	this->m_GuildWarehouseStatus		=  GetPrivateProfileInt(section,"GuildWarehouseStatus",0,path);

	this->m_CustomShopMessageBox		=  GetPrivateProfileInt(section,"CustomShopMessageBox",0,path);

	this->m_CustomNpcQuestSwitch	= GetPrivateProfileInt(section,"CustomNpcQuestSwitch",0,path);

	//warecustom
	this->m_CustomWarehouseSwitch = GetPrivateProfileInt(section, "CustomWarehouseSwitch", 0, path);

	this->m_CustomWarehouseEnable[0] = GetPrivateProfileInt(section, "CustomWarehouseEnable_AL0", 0, path);

	this->m_CustomWarehouseEnable[1] = GetPrivateProfileInt(section, "CustomWarehouseEnable_AL1", 0, path);

	this->m_CustomWarehouseEnable[2] = GetPrivateProfileInt(section, "CustomWarehouseEnable_AL2", 0, path);

	this->m_CustomWarehouseEnable[3] = GetPrivateProfileInt(section, "CustomWarehouseEnable_AL3", 0, path);

	this->m_CustomWarehouseMaxNumber[0] = GetPrivateProfileInt(section, "CustomWarehouseMaxNumber_AL0", 0, path);

	this->m_CustomWarehouseMaxNumber[1] = GetPrivateProfileInt(section, "CustomWarehouseMaxNumber_AL1", 0, path);

	this->m_CustomWarehouseMaxNumber[2] = GetPrivateProfileInt(section, "CustomWarehouseMaxNumber_AL2", 0, path);

	this->m_CustomWarehouseMaxNumber[3] = GetPrivateProfileInt(section, "CustomWarehouseMaxNumber_AL3", 0, path);

}

void CServerInfo::ReadEventInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	//--

	this->m_TimeTeleportMarlon = GetPrivateProfileInt(section,"TimerMarlonTeleport",0,path);
	//--

	this->m_BloodCastleEvent = GetPrivateProfileInt(section,"BloodCastleEvent",0,path);

	this->m_BloodCastleMaxUser = GetPrivateProfileInt(section,"BloodCastleMaxUser",0,path);

	this->m_BloodCastlePvp[0] = GetPrivateProfileInt(section, "BloodCastlePvp_AL0", 0, path);

	this->m_BloodCastlePvp[1] = GetPrivateProfileInt(section, "BloodCastlePvp_AL1", 0, path);

	this->m_BloodCastlePvp[2] = GetPrivateProfileInt(section, "BloodCastlePvp_AL2", 0, path);

	this->m_BloodCastlePvp[3] = GetPrivateProfileInt(section, "BloodCastlePvp_AL3", 0, path);

	this->m_BonusManagerSwitch = GetPrivateProfileInt(section,"BonusManagerSwitch",0,path);

	this->m_CastleDeepEvent = GetPrivateProfileInt(section,"CastleDeepEvent",0,path);

	this->m_CastleDeepEventTime = GetPrivateProfileInt(section,"CastleDeepEventTime",0,path);

	this->m_CastleSiegeEvent = GetPrivateProfileInt(section,"CastleSiegeEvent",0,path);

	this->m_CastleSiegeCycleStartYear = GetPrivateProfileInt(section,"CastleSiegeCycleStartYear",0,path);

	this->m_CastleSiegeCycleStartMonth = GetPrivateProfileInt(section,"CastleSiegeCycleStartMonth",0,path);

	this->m_CastleSiegeCycleStartDay = GetPrivateProfileInt(section,"CastleSiegeCycleStartDay",0,path);

	this->m_CastleSiegeSpecificState = GetPrivateProfileInt(section,"CastleSiegeSpecificState",0,path);

	this->m_CastleSiegeStateStartYear = GetPrivateProfileInt(section,"CastleSiegeStateStartYear",0,path);

	this->m_CastleSiegeStateStartMonth = GetPrivateProfileInt(section,"CastleSiegeStateStartMonth",0,path);

	this->m_CastleSiegeStateStartDay = GetPrivateProfileInt(section,"CastleSiegeStateStartDay",0,path);

	this->m_CastleSiegeStateStartHour = GetPrivateProfileInt(section,"CastleSiegeStateStartHour",0,path);

	this->m_CastleSiegeStateStartMinute = GetPrivateProfileInt(section,"CastleSiegeStateStartMinute",0,path);

	this->m_CastleSiegeOffensiveWeaponDamage = GetPrivateProfileInt(section,"CastleSiegeOffensiveWeaponDamage",0,path);

	this->m_CastleSiegeDefensiveWeaponDamage = GetPrivateProfileInt(section,"CastleSiegeDefensiveWeaponDamage",0,path);

	this->m_CastleSiegeDecayAccumulatedTimeValue = GetPrivateProfileInt(section,"CastleSiegeDecayAccumulatedTimeValue",0,path);

	this->m_CastleSiegeLowerAccumulatedTimeValue = GetPrivateProfileInt(section,"CastleSiegeLowerAccumulatedTimeValue",0,path);

	this->m_ChaosCastleEvent = GetPrivateProfileInt(section,"ChaosCastleEvent",0,path);

	this->m_ChaosCastleMinUser = GetPrivateProfileInt(section,"ChaosCastleMinUser",0,path);

	this->m_ChaosCastleBlowUserRate = GetPrivateProfileInt(section,"ChaosCastleBlowUserRate",0,path);

	gCrywolfSync.SetEnableCrywolf((this->m_CrywolfEvent=GetPrivateProfileInt(section,"CrywolfEvent",0,path)));

	gCrywolfSync.SetApplyBenefit((this->m_CrywolfBenefitSwitch=GetPrivateProfileInt(section,"CrywolfBenefitSwitch",0,path)));

	gCrywolfSync.SetPlusChaosRate((this->m_CrywolfBenefitChaosRate=GetPrivateProfileInt(section,"CrywolfBenefitChaosRate",0,path)));

	gCrywolfSync.SetMonHPBenefitRate((this->m_CrywolfBenefitMonsterLife=GetPrivateProfileInt(section,"CrywolfBenefitMonsterLife",0,path)));

	gCrywolfSync.SetApplyPenalty((this->m_CrywolfPenaltySwitch=GetPrivateProfileInt(section,"CrywolfPenaltySwitch",0,path)));

	gCrywolfSync.SetGemDropPenaltiyRate((this->m_CrywolfPenaltyJewelDrop=GetPrivateProfileInt(section,"CrywolfPenaltyJewelDrop",0,path)));

	gCrywolfSync.SetGettingExpPenaltyRate((this->m_CrywolfPenaltyExperience=GetPrivateProfileInt(section,"CrywolfPenaltyExperience",0,path)));

	this->m_DevilSquareEvent = GetPrivateProfileInt(section,"DevilSquareEvent",0,path);

	this->m_DevilSquareMaxUser = GetPrivateProfileInt(section,"DevilSquareMaxUser",0,path);

	#if(GAMESERVER_UPDATE>=501)

	this->m_DoubleGoerEvent = GetPrivateProfileInt(section,"DoubleGoerEvent",0,path);

	this->m_DoubleGoerDifficultRate = GetPrivateProfileInt(section,"DoubleGoerDifficultRate",0,path);

	#endif

	this->m_IllusionTempleEvent = GetPrivateProfileInt(section,"IllusionTempleEvent",0,path);

	this->m_IllusionTempleMinUser = GetPrivateProfileInt(section,"IllusionTempleMinUser",0,path);

	this->m_IllusionTempleRewardFenrirRate = GetPrivateProfileInt(section,"IllusionTempleRewardFenrirRate",0,path);

	#if(GAMESERVER_UPDATE>=501)

	this->m_ImperialGuardianEvent = GetPrivateProfileInt(section,"ImperialGuardianEvent",0,path);

	this->m_ImperialGuardianDifficultRate = GetPrivateProfileInt(section,"ImperialGuardianDifficultRate",0,path);

	#endif

	this->m_InvasionManagerSwitch = GetPrivateProfileInt(section,"InvasionManagerSwitch",0,path);
	//---
	this->m_FlyingDragonsSwitch = GetPrivateProfileInt(section,"FlyingDragonsSwitch",0,path); //Dragones Server Switch

	this->m_FlyingDragonsKillBossSwitch = GetPrivateProfileInt(section,"FlyingDragonsKillBossSwitch",0,path); //Dragones Kill Boss Server Switch
	//---
	this->m_KanturuEvent = GetPrivateProfileInt(section,"KanturuEvent",0,path);

	#if(GAMESERVER_UPDATE>=402)

	this->m_MossMerchantEvent = GetPrivateProfileInt(section,"MossMerchantEvent",0,path);

	this->m_MossMerchantEventTime = GetPrivateProfileInt(section,"MossMerchantEventTime",0,path);

	#endif

	#if(GAMESERVER_UPDATE>=401)

	this->m_QuicklyEvent					= GetPrivateProfileInt(section,"QuicklyEvent",0,path);
	this->m_QuicklyEventAutoReward1			= GetPrivateProfileInt(section,"QuicklyEventAutoReward1",0,path);
	this->m_QuicklyEventAutoReward2			= GetPrivateProfileInt(section,"QuicklyEventAutoReward2",0,path);
	this->m_QuicklyEventAutoReward3			= GetPrivateProfileInt(section,"QuicklyEventAutoReward3",0,path);

	this->m_ReiDoMUEvent					= GetPrivateProfileInt(section,"ReiDoMUEvent",0,path);
	this->m_ReiDoMUMap						= GetPrivateProfileInt(section,"ReiDoMUMap",0,path);
	this->m_ReiDoMUCordX					= GetPrivateProfileInt(section,"ReiDoMUCordX",0,path);
	this->m_ReiDoMUCordY					= GetPrivateProfileInt(section,"ReiDoMUCordY",0,path);
	this->m_ReiDoMUGuildMinMembers			= GetPrivateProfileInt(section,"ReiDoMUGuildMinMembers",0,path);
	
	this->m_RaklionEvent					= GetPrivateProfileInt(section,"RaklionEvent",0,path);

	this->m_EventStartSwitch				= GetPrivateProfileInt(section,"EventStartSwitch",0,path);
	this->m_EventStartTime					= GetPrivateProfileInt(section,"EventStartTime",0,path);

	this->m_EventRunAndCatchSwitch			= GetPrivateProfileInt(section,"EventRunAndCatchSwitch",0,path);
	this->m_EventRunAndCatchTimeToEnter		= GetPrivateProfileInt(section,"EventRunAndCatchTimeToEnter",30,path);
	this->m_EventRunAndCatchMaxTime			= GetPrivateProfileInt(section,"EventRunAndCatchMaxTime",0,path);
	this->m_EventRunAndCatchAutoReward1		= GetPrivateProfileInt(section,"EventRunAndCatchAutoReward1",0,path);
	this->m_EventRunAndCatchAutoReward2		= GetPrivateProfileInt(section,"EventRunAndCatchAutoReward2",0,path);
	this->m_EventRunAndCatchAutoReward3		= GetPrivateProfileInt(section,"EventRunAndCatchAutoReward3",0,path);

	this->m_EventHideAndSeekSwitch			= GetPrivateProfileInt(section,"EventHideAndSeekSwitch",0,path);
	this->m_EventHideAndSeekMaxTime			= GetPrivateProfileInt(section,"EventHideAndSeekMaxTime",0,path);
	this->m_EventHideAndSeekAutoReward1		= GetPrivateProfileInt(section,"EventHideAndSeekAutoReward1",0,path);
	this->m_EventHideAndSeekAutoReward2		= GetPrivateProfileInt(section,"EventHideAndSeekAutoReward2",0,path);
	this->m_EventHideAndSeekAutoReward3		= GetPrivateProfileInt(section,"EventHideAndSeekAutoReward3",0,path);

	this->m_EventRussianRouletteSwitch		= GetPrivateProfileInt(section,"EventRussianRouletteSwitch",0,path);
	this->m_EventRussianRouletteTimeToEnter	= GetPrivateProfileInt(section,"EventRussianRouletteTimeToEnter",30,path);
	this->m_EventRussianRouletteMaxTime		= GetPrivateProfileInt(section,"EventRussianRouletteMaxTime",0,path);
	this->m_EventRussianRouletteMaxPlayer	= GetPrivateProfileInt(section,"EventRussianRouletteMaxPlayer",0,path);
	this->m_EventRussianRouletteAutoReward1	= GetPrivateProfileInt(section,"EventRussianRouletteAutoReward1",0,path);
	this->m_EventRussianRouletteAutoReward2	= GetPrivateProfileInt(section,"EventRussianRouletteAutoReward2",0,path);
	this->m_EventRussianRouletteAutoReward3	= GetPrivateProfileInt(section,"EventRussianRouletteAutoReward3",0,path);

	this->m_EventPvPSwitch					=  GetPrivateProfileInt(section,"EventPvPSwitch",0,path);
	this->m_EventPvPMaxScore				=  GetPrivateProfileInt(section,"EventPvPMaxScore",3,path);
	this->m_EventPvPMaxTime					=  GetPrivateProfileInt(section,"EventPvPMaxTime",0,path);
	this->m_EventPvPAutoReward1				=  GetPrivateProfileInt(section,"EventPvPAutoReward1",0,path);
	this->m_EventPvPAutoReward2				=  GetPrivateProfileInt(section,"EventPvPAutoReward2",0,path);
	this->m_EventPvPAutoReward3				=  GetPrivateProfileInt(section,"EventPvPAutoReward3",0,path);

	this->m_EventKillAllSwitch				=  GetPrivateProfileInt(section,"EventKillAllSwitch",0,path);
	this->m_EventKillAllTimeToEnter			=  GetPrivateProfileInt(section,"EventKillAllTimeToEnter",0,path);
	this->m_EventKillAllDeadDecrease		=  GetPrivateProfileInt(section,"EventKillAllDeadDecrease",0,path);
	this->m_EventKillAllKillIncrease		=  GetPrivateProfileInt(section,"EventKillAllKillIncrease",0,path);
	this->m_EventKillAllMaxScore			=  GetPrivateProfileInt(section,"EventKillAllMaxScore",0,path);
	this->m_EventKillAllMinPlayers			=  GetPrivateProfileInt(section,"EventKillAllMinPlayers",0,path);
	this->m_EventKillAllMaxPlayers			=  GetPrivateProfileInt(section,"EventKillAllMaxPlayers",0,path);
	this->m_EventKillAllMaxTime				=  GetPrivateProfileInt(section,"EventKillAllMaxTime",0,path);
	this->m_EventKillAllAutoReward1[0]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward1Rank1",0,path);
	this->m_EventKillAllAutoReward1[1]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward1Rank2",0,path);
	this->m_EventKillAllAutoReward1[2]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward1Rank3",0,path);
	this->m_EventKillAllAutoReward2[0]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward2Rank1",0,path);
	this->m_EventKillAllAutoReward2[1]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward2Rank2",0,path);
	this->m_EventKillAllAutoReward2[2]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward2Rank3",0,path);
	this->m_EventKillAllAutoReward3[0]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward3Rank1",0,path);
	this->m_EventKillAllAutoReward3[1]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward3Rank2",0,path);
	this->m_EventKillAllAutoReward3[2]		=  GetPrivateProfileInt(section,"EventKillAllAutoReward3Rank3",0,path);

	this->m_TvTEventSwitch					= GetPrivateProfileInt(section,"EventTvTSwitch",0,path);
	this->m_TvTEventNPC						= GetPrivateProfileInt(section,"EventTvTNpc",0,path);
	this->m_TvTEventNPCMap					= GetPrivateProfileInt(section,"EventTvTNpcMap",0,path);
	this->m_TvTEventNPCX					= GetPrivateProfileInt(section,"EventTvTNpcX",0,path);
	this->m_TvTEventNPCY					= GetPrivateProfileInt(section,"EventTvTNpcY",0,path);
	this->m_TvTEventMinUsers				= GetPrivateProfileInt(section,"EventTvtMinUsers",2,path);
	this->m_TvTEventMaxUsers				= GetPrivateProfileInt(section,"EventTvtMaxUsers",20,path);

	#endif
}

void CServerInfo::ReadHackInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	this->m_CheckSpeedHack = GetPrivateProfileInt(section,"CheckSpeedHack",0,path);

	this->m_CheckSpeedHackTolerance = GetPrivateProfileInt(section,"CheckSpeedHackTolerance",0,path);

	this->m_CheckLatencyHack = GetPrivateProfileInt(section,"CheckLatencyHack",0,path);

	this->m_CheckLatencyHackTolerance = GetPrivateProfileInt(section,"CheckLatencyHackTolerance",0,path);

	this->m_CheckAutoPotionHack = GetPrivateProfileInt(section,"CheckAutoPotionHack",0,path);

	this->m_CheckAutoPotionHackTolerance = GetPrivateProfileInt(section,"CheckAutoPotionHackTolerance",0,path);

	this->m_CheckAutoComboHack = GetPrivateProfileInt(section,"CheckAutoComboHack",0,path);

	this->m_CheckAutoComboHackTolerance = GetPrivateProfileInt(section,"CheckAutoComboHackTolerance",0,path);

	//Speed skill hack

	this->m_SpeedHackSkillEnable = GetPrivateProfileInt(section,"SpeedHackSkillEnable",0,path);

	this->m_SpeedHackSkillType = GetPrivateProfileInt(section,"SpeedHackSkillType",0,path);

	this->m_SpeedHackSkillPenalty = GetPrivateProfileInt(section,"SpeedHackSkillPenalty",0,path);

	this->m_SpeedHackSkillDialog = GetPrivateProfileInt(section,"SpeedHackSkillDialog",0,path);

	this->m_SpeedHackSkillDebug = GetPrivateProfileInt(section,"SpeedHackSkillDebug",0,path);
}

void CServerInfo::ReadSkillInfo(char* section,char* path) // OK
{
	char GameServerInfo[100] = {0};

	this->m_ManaShieldConstA = GetPrivateProfileInt(section,"ManaShieldConstA",0,path);

	this->m_ManaShieldConstB = GetPrivateProfileInt(section,"ManaShieldConstB",0,path);

	this->m_ManaShieldConstC = GetPrivateProfileInt(section,"ManaShieldConstC",0,path);

	this->m_ManaShieldRate[0] = GetPrivateProfileInt(section,"ManaShieldRateDW",0,path);

	this->m_ManaShieldRate[1] = GetPrivateProfileInt(section,"ManaShieldRateDK",0,path);

	this->m_ManaShieldRate[2] = GetPrivateProfileInt(section,"ManaShieldRateFE",0,path);

	this->m_ManaShieldRate[3] = GetPrivateProfileInt(section,"ManaShieldRateMG",0,path);

	this->m_ManaShieldRate[4] = GetPrivateProfileInt(section,"ManaShieldRateDL",0,path);

	this->m_ManaShieldRate[5] = GetPrivateProfileInt(section,"ManaShieldRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_ManaShieldRate[6] = GetPrivateProfileInt(section,"ManaShieldRateRF",0,path);

	#endif

	this->m_ManaShieldTimeConstA = GetPrivateProfileInt(section,"ManaShieldTimeConstA",0,path);

	this->m_ManaShieldTimeConstB = GetPrivateProfileInt(section,"ManaShieldTimeConstB",0,path);

	this->m_ManaShieldMaxRate = GetPrivateProfileInt(section,"ManaShieldMaxRate",0,path);

	this->m_DefenseConstA = GetPrivateProfileInt(section,"DefenseConstA",0,path);

	this->m_DefenseTimeConstA = GetPrivateProfileInt(section,"DefenseTimeConstA",0,path);

	this->m_HealConstA = GetPrivateProfileInt(section,"HealConstA",0,path);

	this->m_HealConstB = GetPrivateProfileInt(section,"HealConstB",0,path);

	this->m_GreaterDefenseConstA = GetPrivateProfileInt(section,"GreaterDefenseConstA",0,path);

	this->m_GreaterDefenseConstB = GetPrivateProfileInt(section,"GreaterDefenseConstB",0,path);

	this->m_GreaterDefenseRate[0] = GetPrivateProfileInt(section,"GreaterDefenseRateDW",0,path);

	this->m_GreaterDefenseRate[1] = GetPrivateProfileInt(section,"GreaterDefenseRateDK",0,path);

	this->m_GreaterDefenseRate[2] = GetPrivateProfileInt(section,"GreaterDefenseRateFE",0,path);

	this->m_GreaterDefenseRate[3] = GetPrivateProfileInt(section,"GreaterDefenseRateMG",0,path);

	this->m_GreaterDefenseRate[4] = GetPrivateProfileInt(section,"GreaterDefenseRateDL",0,path);

	this->m_GreaterDefenseRate[5] = GetPrivateProfileInt(section,"GreaterDefenseRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_GreaterDefenseRate[6] = GetPrivateProfileInt(section,"GreaterDefenseRateRF",0,path);

	#endif

	this->m_GreaterDefenseTimeConstA = GetPrivateProfileInt(section,"GreaterDefenseTimeConstA",0,path);

	this->m_GreaterDamageConstA = GetPrivateProfileInt(section,"GreaterDamageConstA",0,path);

	this->m_GreaterDamageConstB = GetPrivateProfileInt(section,"GreaterDamageConstB",0,path);

	this->m_GreaterDamageRate[0] = GetPrivateProfileInt(section,"GreaterDamageRateDW",0,path);

	this->m_GreaterDamageRate[1] = GetPrivateProfileInt(section,"GreaterDamageRateDK",0,path);

	this->m_GreaterDamageRate[2] = GetPrivateProfileInt(section,"GreaterDamageRateFE",0,path);

	this->m_GreaterDamageRate[3] = GetPrivateProfileInt(section,"GreaterDamageRateMG",0,path);

	this->m_GreaterDamageRate[4] = GetPrivateProfileInt(section,"GreaterDamageRateDL",0,path);

	this->m_GreaterDamageRate[5] = GetPrivateProfileInt(section,"GreaterDamageRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_GreaterDamageRate[6] = GetPrivateProfileInt(section,"GreaterDamageRateRF",0,path);

	#endif

	this->m_GreaterDamageTimeConstA = GetPrivateProfileInt(section,"GreaterDamageTimeConstA",0,path);

	this->m_SummonMonster1 = GetPrivateProfileInt(section,"SummonMonster1",0,path);

	this->m_SummonMonster2 = GetPrivateProfileInt(section,"SummonMonster2",0,path);

	this->m_SummonMonster3 = GetPrivateProfileInt(section,"SummonMonster3",0,path);

	this->m_SummonMonster4 = GetPrivateProfileInt(section,"SummonMonster4",0,path);

	this->m_SummonMonster5 = GetPrivateProfileInt(section,"SummonMonster5",0,path);

	this->m_SummonMonster6 = GetPrivateProfileInt(section,"SummonMonster6",0,path);

	this->m_SummonMonster7 = GetPrivateProfileInt(section,"SummonMonster7",0,path);

	this->m_SummonMonster8 = GetPrivateProfileInt(section,"SummonMonster8",0,path);

	this->m_GreaterLifeConstA = GetPrivateProfileInt(section,"GreaterLifeConstA",0,path);

	this->m_GreaterLifeConstB = GetPrivateProfileInt(section,"GreaterLifeConstB",0,path);

	this->m_GreaterLifeConstC = GetPrivateProfileInt(section,"GreaterLifeConstC",0,path);

	this->m_GreaterLifeRate[0] = GetPrivateProfileInt(section,"GreaterLifeRateDW",0,path);

	this->m_GreaterLifeRate[1] = GetPrivateProfileInt(section,"GreaterLifeRateDK",0,path);

	this->m_GreaterLifeRate[2] = GetPrivateProfileInt(section,"GreaterLifeRateFE",0,path);

	this->m_GreaterLifeRate[3] = GetPrivateProfileInt(section,"GreaterLifeRateMG",0,path);

	this->m_GreaterLifeRate[4] = GetPrivateProfileInt(section,"GreaterLifeRateDL",0,path);

	this->m_GreaterLifeRate[5] = GetPrivateProfileInt(section,"GreaterLifeRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_GreaterLifeRate[6] = GetPrivateProfileInt(section,"GreaterLifeRateRF",0,path);

	#endif

	this->m_GreaterLifeTimeConstA = GetPrivateProfileInt(section,"GreaterLifeTimeConstA",0,path);

	this->m_GreaterLifeTimeConstB = GetPrivateProfileInt(section,"GreaterLifeTimeConstB",0,path);

	this->m_GreaterLifeMaxRate = GetPrivateProfileInt(section,"GreaterLifeMaxRate",0,path);

	this->m_FireSlashConstA = GetPrivateProfileInt(section,"FireSlashConstA",0,path);

	this->m_FireSlashConstB = GetPrivateProfileInt(section,"FireSlashConstB",0,path);

	this->m_FireSlashTimeConstA = GetPrivateProfileInt(section,"FireSlashTimeConstA",0,path);

	this->m_FireSlashMaxRate = GetPrivateProfileInt(section,"FireSlashMaxRate",0,path);

	this->m_GreaterCriticalDamageConstA = GetPrivateProfileInt(section,"GreaterCriticalDamageConstA",0,path);

	this->m_GreaterCriticalDamageConstB = GetPrivateProfileInt(section,"GreaterCriticalDamageConstB",0,path);

	this->m_GreaterCriticalDamageTimeConstA = GetPrivateProfileInt(section,"GreaterCriticalDamageTimeConstA",0,path);

	this->m_GreaterCriticalDamageTimeConstB = GetPrivateProfileInt(section,"GreaterCriticalDamageTimeConstB",0,path);

	this->m_SternTimeConstA = GetPrivateProfileInt(section,"SternTimeConstA",0,path);

	this->m_GreaterManaConstA = GetPrivateProfileInt(section,"GreaterManaConstA",0,path);

	this->m_GreaterManaTimeConstA = GetPrivateProfileInt(section,"GreaterManaTimeConstA",0,path);

	this->m_InvisibilityTimeConstA = GetPrivateProfileInt(section,"InvisibilityTimeConstA",0,path);

	this->m_BrandTimeConstA = GetPrivateProfileInt(section,"BrandTimeConstA",0,path);

	this->m_InfinityArrowTimeConstA = GetPrivateProfileInt(section,"InfinityArrowTimeConstA",0,path);

	this->m_MagicDamageImmunityTimeConstA = GetPrivateProfileInt(section,"MagicDamageImmunityTimeConstA",0,path);

	this->m_PhysiDamageImmunityTimeConstA = GetPrivateProfileInt(section,"PhysiDamageImmunityTimeConstA",0,path);

	this->m_DrainLifeConstA = GetPrivateProfileInt(section,"DrainLifeConstA",0,path);

	this->m_DrainLifeConstB = GetPrivateProfileInt(section,"DrainLifeConstB",0,path);

	this->m_ReflectDamageConstA = GetPrivateProfileInt(section,"ReflectDamageConstA",0,path);

	this->m_ReflectDamageConstB = GetPrivateProfileInt(section,"ReflectDamageConstB",0,path);

	this->m_ReflectDamageRate[0] = GetPrivateProfileInt(section,"ReflectDamageRateDW",0,path);

	this->m_ReflectDamageRate[1] = GetPrivateProfileInt(section,"ReflectDamageRateDK",0,path);

	this->m_ReflectDamageRate[2] = GetPrivateProfileInt(section,"ReflectDamageRateFE",0,path);

	this->m_ReflectDamageRate[3] = GetPrivateProfileInt(section,"ReflectDamageRateMG",0,path);

	this->m_ReflectDamageRate[4] = GetPrivateProfileInt(section,"ReflectDamageRateDL",0,path);

	this->m_ReflectDamageRate[5] = GetPrivateProfileInt(section,"ReflectDamageRateSU",0,path);

	#if(GAMESERVER_UPDATE>=601)

	this->m_ReflectDamageRate[6] = GetPrivateProfileInt(section,"ReflectDamageRateRF",0,path);

	#endif

	this->m_ReflectDamageTimeConstA = GetPrivateProfileInt(section,"ReflectDamageTimeConstA",0,path);

	this->m_ReflectDamageTimeConstB = GetPrivateProfileInt(section,"ReflectDamageTimeConstB",0,path);

	this->m_ReflectDamageMaxRate = GetPrivateProfileInt(section,"ReflectDamageMaxRate",0,path);

	this->m_SwordPowerConstA = GetPrivateProfileInt(section,"SwordPowerConstA",0,path);

	this->m_SwordPowerConstB = GetPrivateProfileInt(section,"SwordPowerConstB",0,path);

	this->m_SwordPowerTimeConstA = GetPrivateProfileInt(section,"SwordPowerTimeConstA",0,path);

	this->m_SwordPowerTimeConstB = GetPrivateProfileInt(section,"SwordPowerTimeConstB",0,path);

	this->m_SwordPowerMaxRate = GetPrivateProfileInt(section,"SwordPowerMaxRate",0,path);

	this->m_SleepConstA = GetPrivateProfileInt(section,"SleepConstA",0,path);

	this->m_SleepConstB = GetPrivateProfileInt(section,"SleepConstB",0,path);

	this->m_SleepTimeConstA = GetPrivateProfileInt(section,"SleepTimeConstA",0,path);

	this->m_SleepTimeConstB = GetPrivateProfileInt(section,"SleepTimeConstB",0,path);

	this->m_SleepMaxTime = GetPrivateProfileInt(section,"SleepMaxTime",0,path);

	this->m_LesserDefenseConstA = GetPrivateProfileInt(section,"LesserDefenseConstA",0,path);

	this->m_LesserDefenseConstB = GetPrivateProfileInt(section,"LesserDefenseConstB",0,path);

	this->m_LesserDefenseConstC = GetPrivateProfileInt(section,"LesserDefenseConstC",0,path);

	this->m_LesserDefenseConstD = GetPrivateProfileInt(section,"LesserDefenseConstD",0,path);

	this->m_LesserDefenseTimeConstA = GetPrivateProfileInt(section,"LesserDefenseTimeConstA",0,path);

	this->m_LesserDefenseTimeConstB = GetPrivateProfileInt(section,"LesserDefenseTimeConstB",0,path);

	this->m_LesserDefenseMaxRate = GetPrivateProfileInt(section,"LesserDefenseMaxRate",0,path);

	this->m_LesserDamageConstA = GetPrivateProfileInt(section,"LesserDamageConstA",0,path);

	this->m_LesserDamageConstB = GetPrivateProfileInt(section,"LesserDamageConstB",0,path);

	this->m_LesserDamageConstC = GetPrivateProfileInt(section,"LesserDamageConstC",0,path);

	this->m_LesserDamageConstD = GetPrivateProfileInt(section,"LesserDamageConstD",0,path);

	this->m_LesserDamageTimeConstA = GetPrivateProfileInt(section,"LesserDamageTimeConstA",0,path);

	this->m_LesserDamageTimeConstB = GetPrivateProfileInt(section,"LesserDamageTimeConstB",0,path);

	this->m_LesserDamageMaxRate = GetPrivateProfileInt(section,"LesserDamageMaxRate",0,path);

	this->m_SahamuttConstA = GetPrivateProfileInt(section,"SahamuttConstA",0,path);

	this->m_NeilConstA = GetPrivateProfileInt(section,"NeilConstA",0,path);

	this->m_MagicCircleConstA = GetPrivateProfileInt(section,"MagicCircleConstA",0,path);

	this->m_MagicCircleTimeConstA = GetPrivateProfileInt(section,"MagicCircleTimeConstA",0,path);

	this->m_ShieldRecoverConstA = GetPrivateProfileInt(section,"ShieldRecoverConstA",0,path);

	this->m_ShieldRecoverConstB = GetPrivateProfileInt(section,"ShieldRecoverConstB",0,path);

	this->m_DragonSlayerConstA = GetPrivateProfileInt(section,"DragonSlayerConstA",0,path);

	this->m_DragonSlayerConstB = GetPrivateProfileInt(section,"DragonSlayerConstB",0,path);

	this->m_DragonSlayerConstC = GetPrivateProfileInt(section,"DragonSlayerConstC",0,path);

	this->m_DragonSlayerConstD = GetPrivateProfileInt(section,"DragonSlayerConstD",0,path);

	this->m_DragonSlayerMaxRate = GetPrivateProfileInt(section,"DragonSlayerMaxRate",0,path);

	this->m_GreaterIgnoreDefenseRateConstA = GetPrivateProfileInt(section,"GreaterIgnoreDefenseRateConstA",0,path);

	this->m_GreaterIgnoreDefenseRateConstB = GetPrivateProfileInt(section,"GreaterIgnoreDefenseRateConstB",0,path);

	this->m_GreaterIgnoreDefenseRateTimeConstA = GetPrivateProfileInt(section,"GreaterIgnoreDefenseRateTimeConstA",0,path);

	this->m_GreaterIgnoreDefenseRateTimeConstB = GetPrivateProfileInt(section,"GreaterIgnoreDefenseRateTimeConstB",0,path);

	this->m_FitnessConstA = GetPrivateProfileInt(section,"FitnessConstA",0,path);

	this->m_FitnessConstB = GetPrivateProfileInt(section,"FitnessConstB",0,path);

	this->m_FitnessTimeConstA = GetPrivateProfileInt(section,"FitnessTimeConstA",0,path);

	this->m_FitnessTimeConstB = GetPrivateProfileInt(section,"FitnessTimeConstB",0,path);

	this->m_GreaterDefenseSuccessRateConstA = GetPrivateProfileInt(section,"GreaterDefenseSuccessRateConstA",0,path);

	this->m_GreaterDefenseSuccessRateConstB = GetPrivateProfileInt(section,"GreaterDefenseSuccessRateConstB",0,path);

	this->m_GreaterDefenseSuccessRateTimeConstA = GetPrivateProfileInt(section,"GreaterDefenseSuccessRateTimeConstA",0,path);

	this->m_GreaterDefenseSuccessRateTimeConstB = GetPrivateProfileInt(section,"GreaterDefenseSuccessRateTimeConstB",0,path);

	#if(GAMESERVER_UPDATE>=701)

	this->m_PartyHealConstA = GetPrivateProfileInt(section,"PartyHealConstA",0,path);

	this->m_PartyHealConstB = GetPrivateProfileInt(section,"PartyHealConstB",0,path);

	this->m_BlessConstA = GetPrivateProfileInt(section,"BlessConstA",0,path);

	this->m_BlessTimeConstA = GetPrivateProfileInt(section,"BlessTimeConstA",0,path);

	this->m_BlindConstA = GetPrivateProfileInt(section,"BlindConstA",0,path);

	this->m_BlindConstB = GetPrivateProfileInt(section,"BlindConstB",0,path);

	this->m_BlindConstC = GetPrivateProfileInt(section,"BlindConstC",0,path);

	this->m_BlindTimeConstA = GetPrivateProfileInt(section,"BlindTimeConstA",0,path);

	this->m_EarthPrisonConstA = GetPrivateProfileInt(section,"EarthPrisonConstA",0,path);

	this->m_IronDefenseConstA = GetPrivateProfileInt(section,"IronDefenseConstA",0,path);

	this->m_IronDefenseConstB = GetPrivateProfileInt(section,"IronDefenseConstB",0,path);

	this->m_IronDefenseTimeConstA = GetPrivateProfileInt(section,"IronDefenseTimeConstA",0,path);

	this->m_BloodHowlingConstA = GetPrivateProfileInt(section,"BloodHowlingConstA",0,path);

	this->m_BloodHowlingConstB = GetPrivateProfileInt(section,"BloodHowlingConstB",0,path);

	this->m_BloodHowlingTimeConstA = GetPrivateProfileInt(section,"BloodHowlingTimeConstA",0,path);

	#endif
}

bool CServerInfo::InSafeZone(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return false;
	}

	LPOBJ lpUser = &gObj[aIndex];

	if (lpUser->Connected < OBJECT_ONLINE)
	{
		return false;
	}

	int map = lpUser->Map;

	if (MAP_RANGE(map) == FALSE)
	{
		return false;
	}

	BYTE attr = gMap[map].GetAttr(lpUser->X, lpUser->Y);

	if ((attr & 1) == 1)
	{
		return true;
	}

	return false;
}

char g_szMapName[85][32] =
{
	"Lorencia", "Dungeon", "Devias",
	"Noria", "LostTower", "Exile",
	"Arena", "Atlans", "Tarkan", "Devil Square 1",
	"Icarus", "BloodCastle 1", "BloodCastle 2",
	"BloodCastle 3", "BloodCastle 4", "BloodCastle 5",
	"BloodCastle 6", "BloodCastle 7", "ChaosCastle 1",
	"ChaosCastle 2", "ChaosCastle 3", "ChaosCastle 4",
	"ChaosCastle 5", "ChaosCastle 6", "Kalima 1",
	"Kalima 2", "Kalima 3", "Kalima 4",
	"Kalima 5", "Kalima 6", "Valley Of Loren",
	"Land Of Trial", "Devil Square 2", "Aida",
	"Crywolf", "None", "Kalima 7",
	"Kanturu 1", "Kanturu 2", "Kanturu 3",
	"GM Map", "Balgass Baracks", "Balgass Refuge",
	"None", "None", "Illusion Temple 1",
	"Illusion Temple 2", "Illusion Temple 3", "Illusion Temple 4",
	"Illusion Temple 5", "Illusion Temple 6", "Elbeland",
	"BloodCastle 8", "Chaos Castle 7", "None",
	"None", "Swamp of Calmness", "Raklion",
	"Raklion Boss", "None", "None",
	"None", "Santa Town", "Vulcanus",
	"Duel Arena"
};