// MapManager.cpp: implementation of the CMapManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MapManager.h"
#include "MemScript.h"
#include "ServerInfo.h"
#include "Util.h"
#include "CustomPKFree.h"

CMapManager gMapManager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMapManager::CMapManager() // OK
{
	this->m_MapManagerInfo.clear();
}

CMapManager::~CMapManager() // OK
{

}

void CMapManager::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_MapManagerInfo.clear();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			MAP_MANAGER_INFO info;

			memset(&info,0,sizeof(info));

			info.Index = lpMemScript->GetNumber();

			info.NonPK = lpMemScript->GetAsNumber();

			info.ViewRange = lpMemScript->GetAsNumber();

			info.ExperienceRate = lpMemScript->GetAsNumber();

			info.ItemDropRate = lpMemScript->GetAsNumber();

			info.ExcItemDropRate = lpMemScript->GetAsNumber();

			info.SetItemDropRate = lpMemScript->GetAsNumber();

			info.SocketItemDrop = lpMemScript->GetAsNumber();

			#if(GAMESERVER_UPDATE>=603)

			info.HelperEnable = lpMemScript->GetAsNumber();

			#else

			info.HelperEnable = 0;

			#endif

			#if(GAMESERVER_UPDATE>=501)

			info.GensBattle = lpMemScript->GetAsNumber();

			#else

			info.GensBattle = 0;

			#endif

			info.DisableCustomAttack = lpMemScript->GetAsNumber();

			info.ResetEnable = lpMemScript->GetAsNumber();

			info.GResetEnable = lpMemScript->GetAsNumber();

			strcpy_s(info.Name,lpMemScript->GetAsString());

			this->m_MapManagerInfo.insert(std::pair<int,MAP_MANAGER_INFO>(info.Index,info));
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

int CMapManager::GetMapNonPK(int index,LPOBJ lpObj,LPOBJ lpTarget) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		//pkfree
		if(!gPKFree.CheckPKZona(index,lpObj->X,lpObj->Y) && !gPKFree.CheckPKZona(index,lpTarget->X,lpTarget->Y)){
			return gServerInfo.m_NonPK;
		}else {
			return 0;
		}
	}
	else
	{
		//pkfree
		if(!gPKFree.CheckPKZona(index,lpObj->X,lpObj->Y) && !gPKFree.CheckPKZona(index,lpTarget->X,lpTarget->Y)){
			return ((it->second.NonPK==-1)?gServerInfo.m_NonPK:((it->second.NonPK==1)?1:0));
		}else {
			return 0;
		}
		
	}
}

int CMapManager::GetMapNonPK(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return gServerInfo.m_NonPK;
	}
	else
	{
		return ((it->second.NonPK==-1)?gServerInfo.m_NonPK:((it->second.NonPK==1)?1:0));
	}
}

int CMapManager::GetMapNonOutlaw(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.NonPK==-1)?0:((it->second.NonPK==2)?1:0));
	}
}

int CMapManager::GetMapViewRange(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 15;
	}
	else
	{
		return ((it->second.ViewRange==-1)?15:it->second.ViewRange);
	}
}

int CMapManager::GetMapExperienceRate(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 100;
	}
	else
	{
		return ((it->second.ExperienceRate==-1)?100:it->second.ExperienceRate);
	}
}

int CMapManager::GetMapMasterExperienceRate(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 100;
	}
	else
	{
		return ((it->second.ExperienceRate==-1)?100:it->second.ExperienceRate);
	}
}

int CMapManager::GetMapItemDropRate(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 100;
	}
	else
	{
		return ((it->second.ItemDropRate==-1)?100:it->second.ItemDropRate);
	}
}

int CMapManager::GetMapExcItemDropRate(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.ExcItemDropRate==-1)?0:it->second.ExcItemDropRate);
	}
}

int CMapManager::GetMapSetItemDropRate(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.SetItemDropRate==-1)?0:it->second.SetItemDropRate);
	}
}

int CMapManager::GetMapSocketItemDrop(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.SocketItemDrop==-1)?0:it->second.SocketItemDrop);
	}
}

int CMapManager::GetMapHelperEnable(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.HelperEnable==-1)?0:it->second.HelperEnable);
	}
}

int CMapManager::GetMapGensBattle(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.GensBattle==-1)?0:it->second.GensBattle);
	}
}

int CMapManager::GetMapDisableCustomAttack(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.DisableCustomAttack==-1)?0:it->second.DisableCustomAttack);
	}
}


char* CMapManager::GetMapName(int index) // OK
{
	std::map<int,MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if(it == this->m_MapManagerInfo.end())
	{
		return "NoName";
	}
	else
	{
		return it->second.Name;
	}
}


int CMapManager::GetMapResetEnable(int index)
{
	std::map<int, MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if (it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.ResetEnable == -1) ? 0 : it->second.ResetEnable);
	}
}

int CMapManager::GetMapGResetEnable(int index)
{
	std::map<int, MAP_MANAGER_INFO>::iterator it = this->m_MapManagerInfo.find(index);

	if (it == this->m_MapManagerInfo.end())
	{
		return 0;
	}
	else
	{
		return ((it->second.GResetEnable == -1) ? 0 : it->second.GResetEnable);
	}
}