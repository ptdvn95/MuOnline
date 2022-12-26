#pragma once
//--/TAP FULLMAP
//----- (00790DF0) --------------------------------------------------------
//----- (00638130) --------------------------------------------------------
#define pDrawMapFull ((void(__cdecl*)(int ModelID, float x, float y, float Width, float Heigth, float Rotacion))0x00638130)
#define sub_82B7A0 ((char(__thiscall*)(signed int a4, signed int a5))0x0082B7A0)
#define sub_8875E0 ((char(__cdecl*)(DWORD a1))0x008875E0)
#define sub_635CF0 ((void (__stdcall*)(signed int a4))0X00635CF0)
#define rFileOpen ((int(__cdecl*)(char* FileName, char* Mode)) 0x9D0040) //1.04E
#define rFileClose ((signed int(__cdecl*)(int a1))0x9CFC26) //1.04E 

#include "Object.h"

//Mover MiniMapa
#define MAX_WIN_WIDTH		    640
#define MAX_WIN_HEIGHT		    480

#define pCursorX				*(int*)0x879340C//(1.04e) -- (1.05g)->*(int*)0x08B156EC
#define pCursorY				*(int*)0x8793410//(1.04e) -- (1.05g)->*(int*)0x08B156F0

#define MAX_MINI_MAP 100

class CMinimap
{
public:
	CMinimap();
	virtual ~CMinimap();
	void MiniMapLoadNew();
	char MapRender(int a1);
public:
	LoadTypeMap DataMap;
	//MoverMiniMapa
	DWORD DelayMove;
	bool Moving;
	short maxX;
	short maxY;
	DWORD ultimoX;
	DWORD ultimoY;
}; extern CMinimap gRenderMap;