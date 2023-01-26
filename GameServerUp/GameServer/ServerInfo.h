// ServerInfo.h: interface for the CServerInfo class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "DefaultClassInfo.h"
#include "Helper.h"
#include "Party.h"
#include "User.h"

class CServerInfo
{
public:
	CServerInfo();
	virtual ~CServerInfo();
	void ReadInit();
	void ReadCashShopInfo();
	void ReadChaosMixInfo();
	void ReadCharacterInfo();
	void ReadCommandInfo();
	void ReadCommonInfo();
	void ReadCustomInfo();
	void ReadEventInfo();
	void ReadEventItemBagInfo();
	void ReadHackInfo();
	void ReadItemInfo();
	void ReadMapInfo();
	void ReadMonsterInfo();
	void ReadMoveInfo();
	void ReadQuestInfo();
	void ReadShopInfo();
	void ReadSkillInfo();
	void ReadUtilInfo();
	void ReloadBotInfo();//mc bot
	void ReloadMonsterInfo();
	void ReadStartupInfo(char* section,char* path);
	void ReadCashShopInfo(char* section,char* path);
	void ReadChaosMixInfo(char* section,char* path);
	void ReadCharacterInfo(char* section,char* path);
	void ReadCommandInfo(char* section,char* path);
	void ReadCommonInfo(char* section,char* path);
	void ReadCustomInfo(char* section,char* path);
	void ReadEventInfo(char* section,char* path);
	void ReadHackInfo(char* section,char* path);
	void ReadSkillInfo(char* section,char* path);
	void ReloadAll();
	bool InSafeZone(int aIndex);
public:
	char m_CustomerName[32];
	char m_CustomerHardwareId[36];
	char m_ServerName[32];
	long m_ServerCode;
	long m_ServerLock;
	int  m_ServerMinLevel;
	int  m_ServerMaxLevel;
	int  m_ServerMinReset;
	int  m_ServerMaxReset;
	int  m_ServerMinMasterReset;
	int  m_ServerMaxMasterReset;
	long m_ServerPort;
	char m_ServerMutex[32];
	char m_ServerVersion[6];
	char m_ServerSerial[17];
	long m_ServerMaxUserNumber;
	char m_JoinServerAddress[16];
	long m_JoinServerPort;
	char m_DataServerAddress[16];
	long m_DataServerPort;
	char m_ConnectServerAddress[16];
	long m_ConnectServerPort;
	int m_WriteChatLog;
	int m_WriteCommandLog;
	int m_WriteTradeLog;
	int m_WriteConnectLog;
	int m_WriteHackLog;
	int m_WriteCashShopLog;
	int m_WriteChaosMixLog;
	int m_WriteAntifloodLog;
	int m_CheckSpeedHack;
	int m_CheckSpeedHackTolerance;
	int m_CheckLatencyHack;
	int m_CheckLatencyHackTolerance;
	int m_CheckAutoPotionHack;
	int m_CheckAutoPotionHackTolerance;
	int m_CheckAutoComboHack;
	int m_CheckAutoComboHackTolerance;
	int m_MainChecksum;
	int m_MaxItemOption;
	int m_MaxIpConnection;
	int m_PersonalCodeCheck;
	int m_SetItemAcceptHarmonySwitch;
	int m_CharacterCloseCount;
	int m_MonsterLifeRate;
	int m_MonsterDamageRate;
	int m_MonsterDefenseRate;
	int m_MonsterHealthBarSwitch;
	int m_UserHealthBarSwitch;
	int m_NonPK;
	int m_PKLimitCount;
	int m_PKLimitFree;
	int m_PKDownTime1;
	int m_PKDownTime2;
	int m_SelfDefenseTime;
	int m_TradeSwitch;
	int m_PersonalShopSwitch;
	int m_PersonalShopMoneyCommisionRate;
	int m_PersonalShopJewelCommisionRate;
	int m_DuelSwitch;
	int m_DuelArenaAnnounceSwitch;
	int m_DuelArenaDisableRestoreHP;
	int m_DuelArenaDisableRestoreSD;
	int m_GuildCreateSwitch;
	int m_GuildDeleteSwitch;
	int m_GuildCreateMinLevel;
	int m_GuildInsertMaxUser1;
	int m_GuildInsertMaxUser2;
	int m_GuildAllianceMinUser;
	int m_GuildAllianceMaxCount;
	int m_GuildOwnerDestroyLimit;
	int m_ElfBufferMaxLevel[MAX_ACCOUNT_LEVEL];
	int m_ElfBufferMaxReset[MAX_ACCOUNT_LEVEL];
	int m_ElfBufferDamageConstA;
	int m_ElfBufferDamageConstB;
	int m_ElfBufferDefenseConstA;
	int m_ElfBufferDefenseConstB;
	int m_AddExperienceRate[MAX_ACCOUNT_LEVEL];
	int m_OffAttackExperienceRate[MAX_ACCOUNT_LEVEL];
	int m_AutoResetExperienceRate[MAX_ACCOUNT_LEVEL];
	int m_AddMasterExperienceRate[MAX_ACCOUNT_LEVEL];
	int m_MinMasterExperienceMonsterLevel[MAX_ACCOUNT_LEVEL];
	int m_AddEventExperienceRate[MAX_ACCOUNT_LEVEL];
	int m_AddQuestExperienceRate[MAX_ACCOUNT_LEVEL];
	int m_ItemDropTime;
	int m_ItemDropPickUpTime;
	int m_ItemDropRate[MAX_ACCOUNT_LEVEL];
	int m_MoneyDropTime;
	int m_MoneyAmountDropRate[MAX_ACCOUNT_LEVEL];
	int m_WeaponDurabilityRate;
	int m_ArmorDurabilityRate;
	int m_WingDurabilityRate;
	int m_GuardianDurabilityRate;
	int m_PendantDurabilityRate;
	int m_RingDurabilityRate;
	int m_PetDurabilityRate;
	int m_MuunDurabilityRate;
	int m_TradeItemBlock;
	int m_TradeItemBlockExc;
	int m_TradeItemBlockSet;
	int m_TradeItemBlockHarmony;
	int m_TradeItemBlockSell;
	int m_TradeItemBlockLucky;
	int m_MaxLevelUp;
	int m_MaxLevelUpEvent;
	int m_MaxLevelUpQuest;
	// max stat for class
	int STR_MaxStatPoint[MAX_CLASS];
	int AGI_MaxStatPoint[MAX_CLASS];
	int VIT_MaxStatPoint[MAX_CLASS];
	int ENE_MaxStatPoint[MAX_CLASS];
	//---------------
	int m_MaxStatPoint[MAX_ACCOUNT_LEVEL];
	int m_MaxStatPointCMD[MAX_ACCOUNT_LEVEL];
	int m_LevelUpPoint[MAX_CLASS];
	int m_PlusStatPoint;
	int m_CharacterCreateSwitch;
	int m_MGCreateType;
	int m_DLCreateType;
	int m_SUCreateType;
	int m_RFCreateType;
	int m_MGCreateLevel[MAX_ACCOUNT_LEVEL];
	int m_DLCreateLevel[MAX_ACCOUNT_LEVEL];
	int m_SUCreateLevel[MAX_ACCOUNT_LEVEL];
	int m_RFCreateLevel[MAX_ACCOUNT_LEVEL];
	int m_MGCreateReset[MAX_ACCOUNT_LEVEL];
	int m_DLCreateReset[MAX_ACCOUNT_LEVEL];
	int m_SUCreateReset[MAX_ACCOUNT_LEVEL];
	int m_RFCreateReset[MAX_ACCOUNT_LEVEL];
	int m_MGCreateMasterReset[MAX_ACCOUNT_LEVEL];
	int m_DLCreateMasterReset[MAX_ACCOUNT_LEVEL];
	int m_SUCreateMasterReset[MAX_ACCOUNT_LEVEL];
	int m_RFCreateMasterReset[MAX_ACCOUNT_LEVEL];
	int m_ShieldGaugeRate;
	int m_ShieldGaugeConstA;
	int m_ShieldGaugeConstB;
	int m_ShieldGaugeAttackRate;
	int m_ShieldGaugeAttackComboMiss;
	int m_MasterSkillTree;
	int m_MasterSkillTreePoint;
	int m_MasterSkillTreeMaxLevel;
	int m_PcPointSwitch;
	int m_PcPointMaxPoint;
	int m_PcPointPointDelay;
	int m_PcPointPointValue[MAX_ACCOUNT_LEVEL];
	int m_CashShopSwitch;
	int m_CashShopScriptVersion1;
	int m_CashShopScriptVersion2;
	int m_CashShopScriptVersion3;
	int m_CashShopBannerVersion1;
	int m_CashShopBannerVersion2;
	int m_CashShopBannerVersion3;
	int m_CashShopGoblinPointDelay;
	//--Reward Online Hours
	int m_CashShopCoinsDelay;
	int m_CashShopWCoinCValue[MAX_ACCOUNT_LEVEL];
	int m_CashShopWCoinPValue[MAX_ACCOUNT_LEVEL];
	int m_CashShopGoblinPointValue[MAX_ACCOUNT_LEVEL];
	int m_CashShopRuudValue[MAX_ACCOUNT_LEVEL];
	//--
	int m_GensSystemSwitch;
	int m_GensSystemGuildLock;
	int m_GensSystemPartyLock;
	int m_GensSystemInsertMinLevel;
	int m_GensSystemContributionFloodTime;
	int m_GensSystemVictimContributionDecrease;
	int m_GensSystemKillerContributionIncrease;
	int m_GensSystemVictimMinContributionDecrease;
	int m_GensSystemVictimMaxContributionDecrease;
	int m_GensSystemKillerMinContributionIncrease;
	int m_GensSystemKillerMaxContributionIncrease;
	int m_GensSystemStartRewardDay;
	int m_GensSystemFinalRewardDay;
	int m_HelperSwitch;
	int m_HelperActiveLevel;
	int m_HelperActiveDelay;
	int m_HelperActiveMoney[MAX_HELPER_STAGE];
	int m_EventInventorySwitch;
	int m_EventInventoryExpireYear;
	int m_EventInventoryExpireMonth;
	int m_EventInventoryExpireDay;
	int m_MuRummySwitch;
	int m_MuRummyRewardScore1;
	int m_MuRummyRewardScore2;
	int m_MuRummyRewardMoneyAmount;
	int m_PartyReconnectTime;
	int m_PartyGeneralExperience[MAX_PARTY_USER];
	int m_PartySpecialExperience[MAX_PARTY_USER];
	int m_PartyMaxMembers;
	int m_ApplePotionRate;
	int m_SmallLifePotionRate;
	int m_MidleLifePotionRate;
	int m_LargeLifePotionRate;
	int m_SmallManaPotionRate;
	int m_MidleManaPotionRate;
	int m_LargeManaPotionRate;
	int m_SmallShieldPotionRate;
	int m_MidleShieldPotionRate;
	int m_LargeShieldPotionRate;
	int m_SmallCompoundPotionRate1;
	int m_SmallCompoundPotionRate2;
	int m_MidleCompoundPotionRate1;
	int m_MidleCompoundPotionRate2;
	int m_LargeCompoundPotionRate1;
	int m_LargeCompoundPotionRate2;
	int m_EliteLifePotionRate;
	int m_EliteManaPotionRate;
	int m_EliteShieldPotionRate;
	int m_TransformationRing1;
	int m_TransformationRing2;
	int m_TransformationRing3;
	int m_TransformationRing4;
	int m_TransformationRing5;
	int m_TransformationRing6;
	int m_SoulSuccessRate[MAX_ACCOUNT_LEVEL];
	int m_LifeSuccessRate[MAX_ACCOUNT_LEVEL];
	int m_HarmonySuccessRate[MAX_ACCOUNT_LEVEL];
	int m_SmeltStoneSuccessRate1[MAX_ACCOUNT_LEVEL];
	int m_SmeltStoneSuccessRate2[MAX_ACCOUNT_LEVEL];
	int m_AddLuckSuccessRate1[MAX_ACCOUNT_LEVEL];
	int m_AddLuckSuccessRate2[MAX_ACCOUNT_LEVEL];
	int m_FruitAddPointMin;
	int m_FruitAddPointMax;
	int m_FruitAddPointSuccessRate[MAX_ACCOUNT_LEVEL];
	int m_FruitMaxPointValue;
	int m_FruitSubPointMin;
	int m_FruitSubPointMax;
	int m_FruitSubPointSuccessRate[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleEvent;
	int m_BloodCastleMaxUser;
	int m_BonusManagerSwitch;
	int m_CastleDeepEvent;
	int m_CastleDeepEventTime;
	int m_CastleSiegeEvent;
	int m_CastleSiegeCycleStartYear;
	int m_CastleSiegeCycleStartMonth;
	int m_CastleSiegeCycleStartDay;
	int m_CastleSiegeSpecificState;
	int m_CastleSiegeStateStartYear;
	int m_CastleSiegeStateStartMonth;
	int m_CastleSiegeStateStartDay;
	int m_CastleSiegeStateStartHour;
	int m_CastleSiegeStateStartMinute;
	int m_CastleSiegeOffensiveWeaponDamage;
	int m_CastleSiegeDefensiveWeaponDamage;
	int m_CastleSiegeDecayAccumulatedTimeValue;
	int m_CastleSiegeLowerAccumulatedTimeValue;
	int m_ChaosCastleEvent;
	int m_ChaosCastleMinUser;
	int m_ChaosCastleBlowUserRate;
	int m_CrywolfEvent;
	int m_CrywolfBenefitSwitch;
	int m_CrywolfBenefitChaosRate;
	int m_CrywolfBenefitMonsterLife;
	int m_CrywolfPenaltySwitch;
	int m_CrywolfPenaltyJewelDrop;
	int m_CrywolfPenaltyExperience;
	int m_DevilSquareEvent;
	int m_DevilSquareMaxUser;
	int m_DoubleGoerEvent;
	int m_DoubleGoerDifficultRate;
	int m_IllusionTempleEvent;
	int m_IllusionTempleMinUser;
	int m_IllusionTempleRewardFenrirRate;
	int m_ImperialGuardianEvent;
	int m_ImperialGuardianDifficultRate;
	int m_InvasionManagerSwitch;
	//--
	int m_FlyingDragonsSwitch; //Dragones Server Switch
	int m_FlyingDragonsKillBossSwitch; //Dragones Kill Boss Server Switch
	//--
	int m_KanturuEvent;
	int m_MossMerchantEvent;
	int m_MossMerchantEventTime;
	int m_RaklionEvent;
	int m_ChaosItemMixRate[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate1[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate2[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate3[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate4[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate5[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate6[MAX_ACCOUNT_LEVEL];
	int m_DevilSquareMixRate7[MAX_ACCOUNT_LEVEL];
	int m_PlusItemLevelMixRate1[MAX_ACCOUNT_LEVEL];
	int m_PlusItemLevelMixRate2[MAX_ACCOUNT_LEVEL];
	int m_PlusItemLevelMixRate3[MAX_ACCOUNT_LEVEL];
	int m_PlusItemLevelMixRate4[MAX_ACCOUNT_LEVEL];
	int m_PlusItemLevelMixRate5[MAX_ACCOUNT_LEVEL];
	int m_PlusItemLevelMixRate6[MAX_ACCOUNT_LEVEL];
	int m_DinorantMixRate[MAX_ACCOUNT_LEVEL];
	int m_FruitMixRate[MAX_ACCOUNT_LEVEL];
	int m_Wing2MixRate[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate1[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate2[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate3[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate4[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate5[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate6[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate7[MAX_ACCOUNT_LEVEL];
	int m_BloodCastleMixRate8[MAX_ACCOUNT_LEVEL];
	int m_Wing1MixRate[MAX_ACCOUNT_LEVEL];
	int m_PetMixRate[MAX_ACCOUNT_LEVEL];
	int m_PieceOfHornMixRate[MAX_ACCOUNT_LEVEL];
	int m_BrokenHornMixRate[MAX_ACCOUNT_LEVEL];
	int m_HornOfFenrirMixRate[MAX_ACCOUNT_LEVEL];
	int m_HornOfFenrirUpgradeMixRate[MAX_ACCOUNT_LEVEL];
	int m_ShieldPotionMixRate1[MAX_ACCOUNT_LEVEL];
	int m_ShieldPotionMixRate2[MAX_ACCOUNT_LEVEL];
	int m_ShieldPotionMixRate3[MAX_ACCOUNT_LEVEL];
	int m_JewelOfHarmonyItemPurityMixRate[MAX_ACCOUNT_LEVEL];
	int m_JewelOfHarmonyItemSmeltMixRate1[MAX_ACCOUNT_LEVEL];
	int m_JewelOfHarmonyItemSmeltMixRate2[MAX_ACCOUNT_LEVEL];
	int m_JewelOfHarmonyItemRestoreMixRate[MAX_ACCOUNT_LEVEL];
	int m_Item380MixRate1[MAX_ACCOUNT_LEVEL];
	int m_Item380MixRate2[MAX_ACCOUNT_LEVEL];
	int m_IllusionTempleMixRate1[MAX_ACCOUNT_LEVEL];
	int m_IllusionTempleMixRate2[MAX_ACCOUNT_LEVEL];
	int m_IllusionTempleMixRate3[MAX_ACCOUNT_LEVEL];
	int m_IllusionTempleMixRate4[MAX_ACCOUNT_LEVEL];
	int m_IllusionTempleMixRate5[MAX_ACCOUNT_LEVEL];
	int m_IllusionTempleMixRate6[MAX_ACCOUNT_LEVEL];
	int m_FeatherOfCondorMixRate[MAX_ACCOUNT_LEVEL];
	int m_Wing3MixRate[MAX_ACCOUNT_LEVEL];
	int m_Wing4MixRate[MAX_ACCOUNT_LEVEL];	//wings level 4
	int m_GarudaFeatherMixRate[MAX_ACCOUNT_LEVEL];
	int m_SocketItemCreateSeedMixRate[MAX_ACCOUNT_LEVEL];
	int m_SocketItemCreateSeedSphereMixRate[MAX_ACCOUNT_LEVEL];
	int m_SummonScrollMixRate1[MAX_ACCOUNT_LEVEL];
	int m_SummonScrollMixRate2[MAX_ACCOUNT_LEVEL];
	int m_SummonScrollMixRate3[MAX_ACCOUNT_LEVEL];
	int m_LuckyItemRefineMixRate1[MAX_ACCOUNT_LEVEL];
	int m_LuckyItemRefineMixRate2[MAX_ACCOUNT_LEVEL];
	int m_MonsterWingMixRate[MAX_ACCOUNT_LEVEL];
	int m_SocketWeaponMixRate[MAX_ACCOUNT_LEVEL];
	int m_PentagramMithrilMixRate[MAX_ACCOUNT_LEVEL];
	int m_PentagramElixirMixRate[MAX_ACCOUNT_LEVEL];
	int m_PentagramJewelMixRate[MAX_ACCOUNT_LEVEL];
	int m_PentagramDecompositeMixRate[MAX_ACCOUNT_LEVEL];
	int m_DuelDamageRate;
	int m_GensDamageRate;
	int m_CustomArenaDamageRate;
	int m_ChaosCastleDamageRate;
	int m_IllusionTempleDamageRate;
	int m_CastleSiegeDamageRate1;
	int m_CastleSiegeDamageRate2;
	int m_CastleSiegeDamageRate3;
	int m_GeneralDamageRatePvP;
	int m_GeneralDamageRatePvM;
	int m_ReflectDamageRatePvP;
	int m_ReflectDamageRatePvM;
	int m_DamageRatePvP[MAX_CLASS];
	int m_DamageRatePvM[MAX_CLASS];
	int m_DamageRateTo[MAX_CLASS][MAX_CLASS];
	int m_DamageStuckRate[MAX_CLASS];
	int m_DKDamageMultiplierConstA;
	int m_DLDamageMultiplierConstA;
	int m_RFDamageMultiplierConstA;
	int m_RFDamageMultiplierConstB;
	int m_RFDamageMultiplierConstC;
	int m_DKDamageMultiplierMaxRate;
	int m_DLDamageMultiplierMaxRate;
	int m_RFDamageMultiplierMaxRate;
	int m_DarkSpiritRangeAttackRate;
	int m_DarkSpiritCriticalDamageRate;
	int m_DarkSpiritExcellentDamageRate;
	int m_DarkSpiritAttackDamageMinConstA;
	int m_DarkSpiritAttackDamageMinConstB;
	int m_DarkSpiritAttackDamageMinConstC;
	int m_DarkSpiritAttackDamageMaxConstA;
	int m_DarkSpiritAttackDamageMaxConstB;
	int m_DarkSpiritAttackDamageMaxConstC;
	int m_DarkSpiritAttackSpeedConstA;
	int m_DarkSpiritAttackSpeedConstB;
	int m_DarkSpiritAttackSpeedConstC;
	int m_DarkSpiritAttackSpeedConstD;
	int m_DarkSpiritAttackSuccessRateConstA;
	int m_DarkSpiritAttackSuccessRateConstB;
	int m_DarkSpiritAttackSuccessRateConstC;
	int m_SatanIncDamageConstA;
	int m_DinorantIncDamageConstA;
	int m_BlackFenrirIncDamageConstA;
	int m_DemonIncDamageConstA;
	int m_SkeletonIncDamageConstA;
	int m_AngelDecDamageConstA;
	int m_DinorantDecDamageConstA;
	int m_DinorantDecDamageConstB;
	int m_DarkHorseDecDamageConstA;
	int m_DarkHorseDecDamageConstB;
	int m_BlueFenrirDecDamageConstA;
	int m_MariaDecDamageConstA;
	int m_ComboDamageConstA;
	int m_ComboDamageConstB;
	int m_EarthquakeDamageConstA;
	int m_EarthquakeDamageConstB;
	int m_EarthquakeDamageConstC;
	int m_ElectricSparkDamageConstA;
	int m_ElectricSparkDamageConstB;
	int m_DLSkillDamageConstA;
	int m_DLSkillDamageConstB;
	int m_NovaDamageConstA;
	int m_NovaDamageConstB;
	int m_NovaDamageConstC;
	int m_HPRecoveryRate[MAX_CLASS];
	int m_MPRecoveryRate[MAX_CLASS];
	int m_BPRecoveryRate[MAX_CLASS];
	int m_SDRecoveryRate[MAX_CLASS];
	int m_DWPlasmaStormDamageConstA;
	int m_DWPlasmaStormDamageConstB;
	int m_DWPlasmaStormDamageConstC;
	int m_DWPlasmaStormDamageConstD;
	int m_DKPlasmaStormDamageConstA;
	int m_DKPlasmaStormDamageConstB;
	int m_DKPlasmaStormDamageConstC;
	int m_DKPlasmaStormDamageConstD;
	int m_FEPlasmaStormDamageConstA;
	int m_FEPlasmaStormDamageConstB;
	int m_FEPlasmaStormDamageConstC;
	int m_FEPlasmaStormDamageConstD;
	int m_MGPlasmaStormDamageConstA;
	int m_MGPlasmaStormDamageConstB;
	int m_MGPlasmaStormDamageConstC;
	int m_MGPlasmaStormDamageConstD;
	int m_DLPlasmaStormDamageConstA;
	int m_DLPlasmaStormDamageConstB;
	int m_DLPlasmaStormDamageConstC;
	int m_DLPlasmaStormDamageConstD;
	int m_DLPlasmaStormDamageConstE;
	int m_SUPlasmaStormDamageConstA;
	int m_SUPlasmaStormDamageConstB;
	int m_SUPlasmaStormDamageConstC;
	int m_SUPlasmaStormDamageConstD;
	int m_RFPlasmaStormDamageConstA;
	int m_RFPlasmaStormDamageConstB;
	int m_RFPlasmaStormDamageConstC;
	int m_RFPlasmaStormDamageConstD;
	int m_DWPhysiDamageMinConstA;
	int m_DWPhysiDamageMaxConstA;
	int m_DWMagicDamageMinConstA;
	int m_DWMagicDamageMaxConstA;
	int m_DKPhysiDamageMinConstA;
	int m_DKPhysiDamageMaxConstA;
	int m_DKMagicDamageMinConstA;
	int m_DKMagicDamageMaxConstA;
	int m_FEPhysiDamageMinConstA;
	int m_FEPhysiDamageMaxConstA;
	int m_FEPhysiDamageMinBowConstA;
	int m_FEPhysiDamageMinBowConstB;
	int m_FEPhysiDamageMaxBowConstA;
	int m_FEPhysiDamageMaxBowConstB;
	int m_FEMagicDamageMinConstA;
	int m_FEMagicDamageMaxConstA;
	int m_MGPhysiDamageMinConstA;
	int m_MGPhysiDamageMinConstB;
	int m_MGPhysiDamageMaxConstA;
	int m_MGPhysiDamageMaxConstB;
	int m_MGMagicDamageMinConstA;
	int m_MGMagicDamageMaxConstA;
	int m_DLPhysiDamageMinConstA;
	int m_DLPhysiDamageMinConstB;
	int m_DLPhysiDamageMaxConstA;
	int m_DLPhysiDamageMaxConstB;
	int m_DLMagicDamageMinConstA;
	int m_DLMagicDamageMaxConstA;
	int m_SUPhysiDamageMinConstA;
	int m_SUPhysiDamageMaxConstA;
	int m_SUMagicDamageMinConstA;
	int m_SUMagicDamageMaxConstA;
	int m_RFPhysiDamageMinConstA;
	int m_RFPhysiDamageMinConstB;
	int m_RFPhysiDamageMaxConstA;
	int m_RFPhysiDamageMaxConstB;
	int m_RFMagicDamageMinConstA;
	int m_RFMagicDamageMaxConstA;
	int m_DWAttackSuccessRateConstA;
	int m_DWAttackSuccessRateConstB;
	int m_DWAttackSuccessRateConstC;
	int m_DWAttackSuccessRateConstD;
	int m_DKAttackSuccessRateConstA;
	int m_DKAttackSuccessRateConstB;
	int m_DKAttackSuccessRateConstC;
	int m_DKAttackSuccessRateConstD;
	int m_FEAttackSuccessRateConstA;
	int m_FEAttackSuccessRateConstB;
	int m_FEAttackSuccessRateConstC;
	int m_FEAttackSuccessRateConstD;
	int m_MGAttackSuccessRateConstA;
	int m_MGAttackSuccessRateConstB;
	int m_MGAttackSuccessRateConstC;
	int m_MGAttackSuccessRateConstD;
	int m_DLAttackSuccessRateConstA;
	int m_DLAttackSuccessRateConstB;
	int m_DLAttackSuccessRateConstC;
	int m_DLAttackSuccessRateConstD;
	int m_DLAttackSuccessRateConstE;
	int m_SUAttackSuccessRateConstA;
	int m_SUAttackSuccessRateConstB;
	int m_SUAttackSuccessRateConstC;
	int m_SUAttackSuccessRateConstD;
	int m_RFAttackSuccessRateConstA;
	int m_RFAttackSuccessRateConstB;
	int m_RFAttackSuccessRateConstC;
	int m_RFAttackSuccessRateConstD;
	int m_DWAttackSuccessRatePvPConstA;
	int m_DWAttackSuccessRatePvPConstB;
	int m_DWAttackSuccessRatePvPConstC;
	int m_DWAttackSuccessRatePvPConstD;
	int m_DKAttackSuccessRatePvPConstA;
	int m_DKAttackSuccessRatePvPConstB;
	int m_DKAttackSuccessRatePvPConstC;
	int m_DKAttackSuccessRatePvPConstD;
	int m_FEAttackSuccessRatePvPConstA;
	int m_FEAttackSuccessRatePvPConstB;
	int m_FEAttackSuccessRatePvPConstC;
	int m_FEAttackSuccessRatePvPConstD;
	int m_MGAttackSuccessRatePvPConstA;
	int m_MGAttackSuccessRatePvPConstB;
	int m_MGAttackSuccessRatePvPConstC;
	int m_MGAttackSuccessRatePvPConstD;
	int m_DLAttackSuccessRatePvPConstA;
	int m_DLAttackSuccessRatePvPConstB;
	int m_DLAttackSuccessRatePvPConstC;
	int m_DLAttackSuccessRatePvPConstD;
	int m_SUAttackSuccessRatePvPConstA;
	int m_SUAttackSuccessRatePvPConstB;
	int m_SUAttackSuccessRatePvPConstC;
	int m_SUAttackSuccessRatePvPConstD;
	int m_RFAttackSuccessRatePvPConstA;
	int m_RFAttackSuccessRatePvPConstB;
	int m_RFAttackSuccessRatePvPConstC;
	int m_RFAttackSuccessRatePvPConstD;
	int m_DWPhysiSpeedConstA;
	int m_DWMagicSpeedConstA;
	int m_DKPhysiSpeedConstA;
	int m_DKMagicSpeedConstA;
	int m_FEPhysiSpeedConstA;
	int m_FEMagicSpeedConstA;
	int m_MGPhysiSpeedConstA;
	int m_MGMagicSpeedConstA;
	int m_DLPhysiSpeedConstA;
	int m_DLMagicSpeedConstA;
	int m_SUPhysiSpeedConstA;
	int m_SUMagicSpeedConstA;
	int m_RFPhysiSpeedConstA;
	int m_RFMagicSpeedConstA;
	int m_DWDefenseSuccessRateConstA;
	int m_DKDefenseSuccessRateConstA;
	int m_FEDefenseSuccessRateConstA;
	int m_MGDefenseSuccessRateConstA;
	int m_DLDefenseSuccessRateConstA;
	int m_SUDefenseSuccessRateConstA;
	int m_RFDefenseSuccessRateConstA;
	int m_DWDefenseSuccessRatePvPConstA;
	int m_DWDefenseSuccessRatePvPConstB;
	int m_DWDefenseSuccessRatePvPConstC;
	int m_DKDefenseSuccessRatePvPConstA;
	int m_DKDefenseSuccessRatePvPConstB;
	int m_DKDefenseSuccessRatePvPConstC;
	int m_FEDefenseSuccessRatePvPConstA;
	int m_FEDefenseSuccessRatePvPConstB;
	int m_FEDefenseSuccessRatePvPConstC;
	int m_MGDefenseSuccessRatePvPConstA;
	int m_MGDefenseSuccessRatePvPConstB;
	int m_MGDefenseSuccessRatePvPConstC;
	int m_DLDefenseSuccessRatePvPConstA;
	int m_DLDefenseSuccessRatePvPConstB;
	int m_DLDefenseSuccessRatePvPConstC;
	int m_SUDefenseSuccessRatePvPConstA;
	int m_SUDefenseSuccessRatePvPConstB;
	int m_SUDefenseSuccessRatePvPConstC;
	int m_RFDefenseSuccessRatePvPConstA;
	int m_RFDefenseSuccessRatePvPConstB;
	int m_RFDefenseSuccessRatePvPConstC;
	int m_DWDefenseConstA;
	int m_DKDefenseConstA;
	int m_FEDefenseConstA;
	int m_MGDefenseConstA;
	int m_DLDefenseConstA;
	int m_SUDefenseConstA;
	int m_RFDefenseConstA;
	int m_DuelElementalDamageRate;
	int m_GensElementalDamageRate;
	int m_CustomArenaElementalDamageRate;
	int m_ChaosCastleElementalDamageRate;
	int m_IllusionTempleElementalDamageRate;
	int m_CastleSiegeElementalDamageRate1;
	int m_CastleSiegeElementalDamageRate2;
	int m_GeneralElementalDamageRatePvP;
	int m_GeneralElementalDamageRatePvM;
	int m_ElementalDamageRatePvP[MAX_CLASS];
	int m_ElementalDamageRatePvM[MAX_CLASS];
	int m_ElementalDamageRateTo[MAX_CLASS][MAX_CLASS];
	int m_DWElementalDefenseConstA;
	int m_DKElementalDefenseConstA;
	int m_FEElementalDefenseConstA;
	int m_MGElementalDefenseConstA;
	int m_DLElementalDefenseConstA;
	int m_SUElementalDefenseConstA;
	int m_RFElementalDefenseConstA;
	int m_DWElementalDamageMinConstA;
	int m_DWElementalDamageMaxConstA;
	int m_DKElementalDamageMinConstA;
	int m_DKElementalDamageMaxConstA;
	int m_FEElementalDamageMinConstA;
	int m_FEElementalDamageMinConstB;
	int m_FEElementalDamageMaxConstA;
	int m_FEElementalDamageMaxConstB;
	int m_MGElementalDamageMinConstA;
	int m_MGElementalDamageMinConstB;
	int m_MGElementalDamageMaxConstA;
	int m_MGElementalDamageMaxConstB;
	int m_DLElementalDamageMinConstA;
	int m_DLElementalDamageMinConstB;
	int m_DLElementalDamageMaxConstA;
	int m_DLElementalDamageMaxConstB;
	int m_SUElementalDamageMinConstA;
	int m_SUElementalDamageMaxConstA;
	int m_RFElementalDamageMinConstA;
	int m_RFElementalDamageMinConstB;
	int m_RFElementalDamageMaxConstA;
	int m_RFElementalDamageMaxConstB;
	int m_DWElementalAttackSuccessRateConstA;
	int m_DWElementalAttackSuccessRateConstB;
	int m_DWElementalAttackSuccessRateConstC;
	int m_DWElementalAttackSuccessRateConstD;
	int m_DKElementalAttackSuccessRateConstA;
	int m_DKElementalAttackSuccessRateConstB;
	int m_DKElementalAttackSuccessRateConstC;
	int m_DKElementalAttackSuccessRateConstD;
	int m_FEElementalAttackSuccessRateConstA;
	int m_FEElementalAttackSuccessRateConstB;
	int m_FEElementalAttackSuccessRateConstC;
	int m_FEElementalAttackSuccessRateConstD;
	int m_MGElementalAttackSuccessRateConstA;
	int m_MGElementalAttackSuccessRateConstB;
	int m_MGElementalAttackSuccessRateConstC;
	int m_MGElementalAttackSuccessRateConstD;
	int m_DLElementalAttackSuccessRateConstA;
	int m_DLElementalAttackSuccessRateConstB;
	int m_DLElementalAttackSuccessRateConstC;
	int m_DLElementalAttackSuccessRateConstD;
	int m_SUElementalAttackSuccessRateConstA;
	int m_SUElementalAttackSuccessRateConstB;
	int m_SUElementalAttackSuccessRateConstC;
	int m_SUElementalAttackSuccessRateConstD;
	int m_RFElementalAttackSuccessRateConstA;
	int m_RFElementalAttackSuccessRateConstB;
	int m_RFElementalAttackSuccessRateConstC;
	int m_RFElementalAttackSuccessRateConstD;
	int m_DWElementalDefenseSuccessRateConstA;
	int m_DKElementalDefenseSuccessRateConstA;
	int m_FEElementalDefenseSuccessRateConstA;
	int m_MGElementalDefenseSuccessRateConstA;
	int m_DLElementalDefenseSuccessRateConstA;
	int m_SUElementalDefenseSuccessRateConstA;
	int m_RFElementalDefenseSuccessRateConstA;
	int m_CommandPostType;
	int m_CommandAddPointAutoEnable[MAX_ACCOUNT_LEVEL];
	int m_CommandChangeLimit[MAX_ACCOUNT_LEVEL];
	int m_CommandWareNumber[MAX_ACCOUNT_LEVEL];
	int m_CommandResetType;
	int m_CommandResetAutoEnable[MAX_ACCOUNT_LEVEL];
	int m_CommandResetCheckItem[MAX_ACCOUNT_LEVEL];
	int m_CommandResetMove[MAX_ACCOUNT_LEVEL];
	int m_CommandResetQuest[MAX_ACCOUNT_LEVEL];
	int m_CommandResetSkill[MAX_ACCOUNT_LEVEL];
	int m_CommandResetLevel[MAX_ACCOUNT_LEVEL];
	int m_CommandResetMoney[MAX_ACCOUNT_LEVEL];
	int m_CommandResetCount[MAX_ACCOUNT_LEVEL];
	int m_CommandResetLimit[MAX_ACCOUNT_LEVEL];
	int m_CommandResetLimitDay[MAX_ACCOUNT_LEVEL];
	int m_CommandResetLimitWek[MAX_ACCOUNT_LEVEL];
	int m_CommandResetLimitMon[MAX_ACCOUNT_LEVEL];
	int m_CommandResetStartLevel[MAX_ACCOUNT_LEVEL];
	int m_CommandResetPoint[MAX_ACCOUNT_LEVEL];
	int m_CommandResetPointRate[MAX_CLASS];
	int m_CommandMasterResetType;
	int m_CommandMasterResetCheckItem[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetMove[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetQuest[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetSkill[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetLevel[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetReset[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetMoney[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetCount[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetLimit[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetLimitDay[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetLimitWek[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetLimitMon[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetStartLevel[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetStartReset[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetRemoveReset[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetPoint[MAX_ACCOUNT_LEVEL];
	int m_CommandMasterResetPointRate[MAX_CLASS];
	int m_ManaShieldConstA;
	int m_ManaShieldConstB;
	int m_ManaShieldConstC;
	int m_ManaShieldRate[MAX_CLASS];
	int m_ManaShieldTimeConstA;
	int m_ManaShieldTimeConstB;
	int m_ManaShieldMaxRate;
	int m_DefenseConstA;
	int m_DefenseTimeConstA;
	int m_HealConstA;
	int m_HealConstB;
	int m_GreaterDefenseConstA;
	int m_GreaterDefenseConstB;
	int m_GreaterDefenseRate[MAX_CLASS];
	int m_GreaterDefenseTimeConstA;
	int m_GreaterDamageConstA;
	int m_GreaterDamageConstB;
	int m_GreaterDamageRate[MAX_CLASS];
	int m_GreaterDamageTimeConstA;
	int m_SummonMonster1;
	int m_SummonMonster2;
	int m_SummonMonster3;
	int m_SummonMonster4;
	int m_SummonMonster5;
	int m_SummonMonster6;
	int m_SummonMonster7;
	int m_SummonMonster8;
	int m_GreaterLifeConstA;
	int m_GreaterLifeConstB;
	int m_GreaterLifeConstC;
	int m_GreaterLifeRate[MAX_CLASS];
	int m_GreaterLifeTimeConstA;
	int m_GreaterLifeTimeConstB;
	int m_GreaterLifeMaxRate;
	int m_FireSlashConstA;
	int m_FireSlashConstB;
	int m_FireSlashTimeConstA;
	int m_FireSlashMaxRate;
	int m_GreaterCriticalDamageConstA;
	int m_GreaterCriticalDamageConstB;
	int m_GreaterCriticalDamageTimeConstA;
	int m_GreaterCriticalDamageTimeConstB;
	int m_SternTimeConstA;
	int m_GreaterManaConstA;
	int m_GreaterManaTimeConstA;
	int m_InvisibilityTimeConstA;
	int m_BrandTimeConstA;
	int m_InfinityArrowTimeConstA;
	int m_MagicDamageImmunityTimeConstA;
	int m_PhysiDamageImmunityTimeConstA;
	int m_DrainLifeConstA;
	int m_DrainLifeConstB;
	int m_ReflectDamageConstA;
	int m_ReflectDamageConstB;
	int m_ReflectDamageRate[MAX_CLASS];
	int m_ReflectDamageTimeConstA;
	int m_ReflectDamageTimeConstB;
	int m_ReflectDamageMaxRate;
	int m_SwordPowerConstA;
	int m_SwordPowerConstB;
	int m_SwordPowerTimeConstA;
	int m_SwordPowerTimeConstB;
	int m_SwordPowerMaxRate;
	int m_SleepConstA;
	int m_SleepConstB;
	int m_SleepTimeConstA;
	int m_SleepTimeConstB;
	int m_SleepMaxTime;
	int m_LesserDefenseConstA;
	int m_LesserDefenseConstB;
	int m_LesserDefenseConstC;
	int m_LesserDefenseConstD;
	int m_LesserDefenseTimeConstA;
	int m_LesserDefenseTimeConstB;
	int m_LesserDefenseMaxRate;
	int m_LesserDamageConstA;
	int m_LesserDamageConstB;
	int m_LesserDamageConstC;
	int m_LesserDamageConstD;
	int m_LesserDamageTimeConstA;
	int m_LesserDamageTimeConstB;
	int m_LesserDamageMaxRate;
	int m_SahamuttConstA;
	int m_NeilConstA;
	int m_MagicCircleConstA;
	int m_MagicCircleTimeConstA;
	int m_ShieldRecoverConstA;
	int m_ShieldRecoverConstB;
	int m_DragonSlayerConstA;
	int m_DragonSlayerConstB;
	int m_DragonSlayerConstC;
	int m_DragonSlayerConstD;
	int m_DragonSlayerMaxRate;
	int m_GreaterIgnoreDefenseRateConstA;
	int m_GreaterIgnoreDefenseRateConstB;
	int m_GreaterIgnoreDefenseRateTimeConstA;
	int m_GreaterIgnoreDefenseRateTimeConstB;
	int m_FitnessConstA;
	int m_FitnessConstB;
	int m_FitnessTimeConstA;
	int m_FitnessTimeConstB;
	int m_GreaterDefenseSuccessRateConstA;
	int m_GreaterDefenseSuccessRateConstB;
	int m_GreaterDefenseSuccessRateTimeConstA;
	int m_GreaterDefenseSuccessRateTimeConstB;
	int m_PartyHealConstA;
	int m_PartyHealConstB;
	int m_BlessConstA;
	int m_BlessTimeConstA;
	int m_BlindConstA;
	int m_BlindConstB;
	int m_BlindConstC;
	int m_BlindTimeConstA;
	int m_EarthPrisonConstA;
	int m_IronDefenseConstA;
	int m_IronDefenseConstB;
	int m_IronDefenseTimeConstA;
	int m_BloodHowlingConstA;
	int m_BloodHowlingConstB;
	int m_BloodHowlingTimeConstA;
	long m_AnnounceChaosMix;
	char m_AnnounceChaosMixText[50];
	// REI DO MU
	int m_ReiDoMUEvent;
	int m_ReiDoMUMap;
	int m_ReiDoMUCordX;
	int m_ReiDoMUCordY;
	int m_ReiDoMUGuildMinMembers;
	// HpBonus por MR
	int m_HpBonus[MAX_ACCOUNT_LEVEL];
	int m_HpBonusMax;
	int m_DieUserSwitch;
	int m_DieMonsterSwitch;
    int m_CommandMarryLevel;
    int m_CommandMarryCost;
    int m_CommandMarryNoticeDelay;
    int m_CommandMarryMinTime;
	int m_CommandMarryOnlyGM;
	int m_CommandOpenWareOnlySafeZone;
	int m_CommandChangeClassToDW;
	int m_CommandChangeClassToDK;
	int m_CommandChangeClassToELF;
	int m_CommandChangeClassToMG;
	int m_CommandChangeClassToDL;
	int m_CommandChangeClassToSU;
	int m_CommandChangeClassToRF;
	int m_CommandRewardMaxType;
	int m_CommandRewardMaxValue;
	char m_CommandRewardType1Text[128];
	char m_CommandRewardType2Text[128];
	char m_CommandRewardType3Text[128];
	char m_CommandRewardType4Text[128];
	char m_CommandRewardType5Text[128];
	char m_CommandRewardType6Text[128];
	char m_CommandRewardType7Text[128];
	char m_CommandRewardType8Text[128];
	char m_CommandRewardType9Text[128];
	char m_CommandRewardType10Text[128];
	//RewardAll
	int m_CommandRewardAllSwitch;
	int m_CommandRewardAllGameMasterLevel;
	int m_CommandRewardAllMaxType;
	int m_CommandRewardAllMaxValue;
	char m_CommandRewardAllType1Text[128];
	char m_CommandRewardAllType2Text[128];
	char m_CommandRewardAllType3Text[128];
	char m_CommandRewardAllType4Text[128];
	char m_CommandRewardAllType5Text[128];
	char m_CommandRewardAllType6Text[128];
	char m_CommandRewardAllType7Text[128];
	char m_CommandRewardAllType8Text[128];
	char m_CommandRewardAllType9Text[128];
	char m_CommandRewardAllType10Text[128];
	// User Online
	int m_OnlineGmSwitch;
	int m_OnlineUserSwitch;
	//Change Name
	int m_CommandRenameDelay[MAX_ACCOUNT_LEVEL];
	int m_CommandRenameTicket;
	//Disabel exp message
	int m_DisableExpMessage;
	//Quickly Event
	int m_QuicklyEvent;
	int m_QuicklyEventAutoReward1;
	int m_QuicklyEventAutoReward2;
	int m_QuicklyEventAutoReward3;
	//Info
	//int m_CommandInfoSwitch;
	//Disable effect
	int m_DisableLightningEffect;
	int m_DisableFallingEffect;
	int m_DisableLungEffect;
	int m_DisableUpperCutEffect;
	int m_DisableCycloneEffect;
	int m_DisableTwistEffect;
	int m_JewelSocketPentagram;
	//Bloc Acc
	//Event Start
	int m_EventStartSwitch;
	int m_EventStartTime;
	//Event Run and Catch
	int m_EventRunAndCatchSwitch;
	int m_EventRunAndCatchTimeToEnter;
	int m_EventRunAndCatchMaxTime;
	int m_EventRunAndCatchAutoReward1;
	int m_EventRunAndCatchAutoReward2;
	int m_EventRunAndCatchAutoReward3;
	//Event Start
	int m_EventHideAndSeekSwitch;
	int m_EventHideAndSeekMaxTime;
	int m_EventHideAndSeekAutoReward1;
	int m_EventHideAndSeekAutoReward2;
	int m_EventHideAndSeekAutoReward3;
	//Custom Quest 
	int m_CustomQuestSwitch;
	//Gift
	//int m_CommandGiftSwitch;
	int m_CommandGiftLimit;
	//Event Russian Roulette
	int m_EventRussianRouletteSwitch;
	int m_EventRussianRouletteTimeToEnter;
	int m_EventRussianRouletteMaxTime;
	int m_EventRussianRouletteMaxPlayer;
	int m_EventRussianRouletteAutoReward1;
	int m_EventRussianRouletteAutoReward2;
	int m_EventRussianRouletteAutoReward3;
	//Disable Wing Mix Class
	int m_DisableWingMixDL;
	int m_DisableWingMixSU;
	int m_DisableWingMixRF;
	int m_DisableWing4MixSU;
	int m_DisableWing4MixRF;
	//Custom Rank User 
	int m_CustomRankUserSwitch;
	int m_CustomRankUserType;
	int m_CustomRankUserRewardSwitch;
	int m_CustomRankUserNoticeToAll;
	int m_CustomRankUserNoticeToUser;
	//Custom Npc Collector
	int m_CustomNpcCollectorSwitch;
	//Custom Death Message 
	int m_CustomDeathMessageSwitch;
	//Custom Quiz
	int m_CustomQuizSwitch;
	//PK Enter Events
	int m_PkCanEnterBC;
	int m_PkCanEnterCC;
	int m_PkCanEnterDS;
	//Custom Pick
	//Pk Item Drop
	int m_PkItemDropSwitch;
	int m_PkItemDropRate;
	int m_PkItemDropMinLevel;
	int m_PkItemDropMaxLevel;
	int m_PkItemDropExecellent;
	int m_PkItemDropSetItem;
	int m_PkItemDropHarmony;
	int m_PkItemDropSocketItem;
	int m_PkItemDropEnable[MAX_ACCOUNT_LEVEL];
	//Disconnect Account Connected
	int m_DisconnectOnlineAccount;
	//Custom Ranking
	int m_CustomRankingSwitch;
	//Enable Cs Skills in All Maps
	int m_EnableCsSkillsAllMaps;
	//Command Help
	//int m_CommandHelpSwitch;
	int m_CommandHelpMonsterIndex;
	int m_CommandHelpMonsterAmount;
	int m_EnableComboToAllSwitch;
	//Start Event
	//Custom EventTime
	int m_CustomEventTimeSwitch;
	//Event PvP
	int m_EventPvPSwitch;
	int m_EventPvPMaxScore;
	int m_EventPvPMaxTime;
	int m_EventPvPAutoReward1;
	int m_EventPvPAutoReward2;
	int m_EventPvPAutoReward3;
	//Event Skill All
	int m_EventKillAllSwitch;
	int m_EventKillAllTimeToEnter;
	int m_EventKillAllDeadDecrease;
	int m_EventKillAllKillIncrease;
	int m_EventKillAllMaxScore;
	int m_EventKillAllMinPlayers;
	int m_EventKillAllMaxPlayers;
	int m_EventKillAllMaxTime;
	int m_EventKillAllAutoReward1[3];
	int m_EventKillAllAutoReward2[3];
	int m_EventKillAllAutoReward3[3];
	//New Money System
	int m_MoneyValue[MAX_ACCOUNT_LEVEL];
	//Tvt Event
	int m_TvTEventSwitch;
	int m_TvTEventNPC;
	int m_TvTEventNPCMap;
	int m_TvTEventNPCX;
	int m_TvTEventNPCY;
	int m_TvTEventMinUsers;
	int m_TvTEventMaxUsers;
	//Guild Warehouse
	int m_GuildWarehouseEnable;
	int m_GuildWarehouseStatus;
	//Bloc Command
	int m_CommandBlocAccShowMessage;
	int m_CommandBlocCharShowMessage;
	//Speed skill hack
	int m_SpeedHackSkillEnable;
	int m_SpeedHackSkillType;
	int m_SpeedHackSkillPenalty;
	int m_SpeedHackSkillDialog;
	int m_SpeedHackSkillDebug;
	//Custom Shop MessageBox
	int m_CustomShopMessageBox;
	//party pk
	int m_PartyDisablePK;
	//trade pk
	int m_PKDisableTrade;
	//Custom Quest 
	int m_CustomNpcQuestSwitch;
	//--
	int m_TimeTeleportMarlon;
	//--
	int m_CustomNpcTalkBaul;
	int m_CustomNpcTalkQuest;
	int m_CustomNpcTalkGoblin;
	int m_CustomNpcTalkTrainer;
	int m_CustomNpcTalkGuard;
	int m_CustomNpcTalkNixie;
	int m_CustomNpcTalkPriestJames;
	int m_BannedDuration;
	//-- up13
	int m_TimeDisconectCount;
	int m_DissableSD;
	//Duel
	int m_DuelScore;
	//--
	int m_PartyRestrict; //Custom Activate Party Level Restrict
	int m_DifferenceMaxLevelParty; //Custom Max level party Diferencia Restric
	//custom ware
	int m_CustomWarehouseSwitch;
	int m_CustomWarehouseEnable[MAX_ACCOUNT_LEVEL];
	int m_CustomWarehouseMaxNumber[MAX_ACCOUNT_LEVEL];

	int m_BloodCastlePvp[MAX_ACCOUNT_LEVEL];

	int m_Idioma;

	int m_SocketHarmony;

	int Max_LevelPlus;
	int DownGrade;
	int m_MaxHwidConnection;

	int m_nReflectDamageRatePvP[MAX_CLASS];
	int m_nReflectDamageRatePvM[MAX_CLASS];

	int m_UnlimitedBoltArrowEnable;
	short m_UnlimitedBoltArrowLevel;

	int m_PoisonDamageDWRate;
	int m_PoisonDamageDWTime;
};

extern CServerInfo gServerInfo;

extern char g_szMapName[85][32];