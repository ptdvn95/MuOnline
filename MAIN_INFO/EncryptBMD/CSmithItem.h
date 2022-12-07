#pragma once

#define MAX_SMITH_ITEM 200

struct CUSTOM_SMITH_INFO
{
	int ItemIndex;
	int Price1Days;
	int Price7Days;
	int Price30Days;
	char ItemName[50];
};

class CCustomSmith
{
public:
	CCustomSmith();
	virtual ~CCustomSmith();
	void Init();
	void Load(char* path);
	void SetInfoSword(CUSTOM_SMITH_INFO info);
	void SetInfoAxe(CUSTOM_SMITH_INFO info);
	void SetInfoMace(CUSTOM_SMITH_INFO info);
	void SetInfoSpear(CUSTOM_SMITH_INFO info);
	void SetInfoBow(CUSTOM_SMITH_INFO info);
	void SetInfoStaff(CUSTOM_SMITH_INFO info);
	void SetInfoShield(CUSTOM_SMITH_INFO info);
	void SetInfoHelm(CUSTOM_SMITH_INFO info);
	void SetInfoArmor(CUSTOM_SMITH_INFO info);
	void SetInfoPant(CUSTOM_SMITH_INFO info);
	void SetInfoGlove(CUSTOM_SMITH_INFO info);
	void SetInfoBoot(CUSTOM_SMITH_INFO info);
public:
	CUSTOM_SMITH_INFO m_SmithSwordInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithAxeInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithMaceInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithSpearInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithBowInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithStaffInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithShieldInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithHelmInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithArmorInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithPantInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithGloveInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO m_SmithBootInfo[MAX_SMITH_ITEM];

};

extern CCustomSmith gCustomSmith;
