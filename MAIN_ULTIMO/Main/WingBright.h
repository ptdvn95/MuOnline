#pragma once
// ---------------------------------------------------------------------------------------------
#define sub_5468A0                             ((int(__thiscall*)(int This, signed int a2, signed int a3, float a4, int a5, float a6, float a7, float a8, int a9)) 0x005468A0)
// ---------------------------------------------------------------------------------------------

class Wings
{
public:
	void Load();
	static bool		IsCustomWings(WORD ItemID, bool Preview);
	static bool		IsCustomItem(WORD ItemID, bool Preview);
	// ----
}; extern Wings gWings;
// ---------------------------------------------------------------------------------------------