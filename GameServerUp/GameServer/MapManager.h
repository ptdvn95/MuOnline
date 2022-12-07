// MapManager.h: interface for the CMapManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#include "User.h"

struct MAP_MANAGER_INFO
{
	int Index;
	int NonPK;
	int ViewRange;
	int ExperienceRate;
	int ItemDropRate;
	int ExcItemDropRate;
	int SetItemDropRate;
	int SocketItemDrop;
	int HelperEnable;
	int GensBattle;
	int DisableCustomAttack;
	int ResetEnable;
	int GResetEnable;
	char Name[32];
};

class CMapManager
{
public:
	CMapManager();
	virtual ~CMapManager();
	void Load(char* path);
	int GetMapNonPK(int index,LPOBJ lpObj,LPOBJ lpTarget);
	int GetMapNonPK(int index);
	int GetMapNonOutlaw(int index);
	int GetMapViewRange(int index);
	int GetMapExperienceRate(int index);
	int GetMapMasterExperienceRate(int index);
	int GetMapItemDropRate(int index);
	int GetMapExcItemDropRate(int index);
	int GetMapSetItemDropRate(int index);
	int GetMapSocketItemDrop(int index);
	int GetMapHelperEnable(int index);
	int GetMapGensBattle(int index);
	int GetMapDisableCustomAttack(int index);
	char* GetMapName(int index);
	int GetMapResetEnable(int index);
	int GetMapGResetEnable(int index);
public:
	std::map<int,MAP_MANAGER_INFO> m_MapManagerInfo;
};

extern CMapManager gMapManager;
