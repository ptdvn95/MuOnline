#pragma once
// ---------------------------------------------------------------------------------------------
#define LoadBitmapA			((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define MUHELPER_STRUC		0x00E8CB7C
#define EnableAlphaTest				((void(__cdecl*)(char a1)) 0x00635FD0)
#define World								*(int*)0x00E61E18
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define RenderImage			((void(__cdecl*)(DWORD, float, float, float, float)) 0x00790B50)
#define RenderImage2		((int(__cdecl*)(int a1, float a2, float a3)) 0x00790C20)
#define HELPERBTN_POSITION_X 70.0f
#define HELPERBTN_POSITION_Y 0.0f
#define HELPERBTN_POSITION_Y2 0.6f
#define HELPERBTN_TOOLTIP_Y 30.0f
// ---------------------------------------------------------------------------------------------

class CMacroUIEx
{
public:
	void Load();
	//static void		LoadImages();
	static void		RenderFrame(int *This);
	static void		RenderHelperFrame(int *This);
	void			Button(DWORD Event);
	static void __thiscall RenderInterfaceLeft(int thisa);
	static BYTE __thiscall lpUI_ArrowCount(int thisa, int x, int y);
	static BOOL __thiscall lpUI_SummonMonster(int thisa, int x, int y);
	static BYTE __thiscall lpUI_HelperMonster(int thisa, int x, int y);
	// ----
private:
	
};
extern CMacroUIEx gCMacroUIEx;
// ---------------------------------------------------------------------------------------------

void MuHelperRemake_03();