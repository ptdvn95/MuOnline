// CustomPet.h: interface for the CLuckyWheel class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#if(GAMESERVER_PREMIUM==1)
#define MAX_ITEM 12

struct LUCKYWHEEL_INFO
{
	int Index;
	int ItemType;
	int ItemIndex;
	int Level;
	int Luck;
	int Skill;
	int Option;
	int Exc;
};

class CLuckyWheel
{
public:
	CLuckyWheel();
	virtual ~CLuckyWheel();
	void Init();
	void Load(char* path);
	void SetInfo(LUCKYWHEEL_INFO info);
public:
	LUCKYWHEEL_INFO m_LuckyWheelInfo[MAX_ITEM];
};

extern CLuckyWheel gLuckyWheel;
#endif