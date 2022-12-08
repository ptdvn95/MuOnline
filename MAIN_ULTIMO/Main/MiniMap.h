#pragma once

//--/TAP FULLMAP
//----- (00790DF0) --------------------------------------------------------
#define sub_790DF0 ((void(__cdecl*)(int a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, int a13))0x00790DF0)
//----- (00638130) --------------------------------------------------------
#define pDrawMapFull ((void(__cdecl*)(int ModelID, float x, float y, float Width, float Heigth, float Rotacion))0x00638130)
#define sub_82B7A0 ((char(__thiscall*)(signed int a4, signed int a5))0x0082B7A0)
#define sub_8875E0 ((char(__cdecl*)(DWORD a1))0x008875E0)
#define sub_635CF0 ((void (__stdcall*)(signed int a4))0X00635CF0)
#define rFileOpen ((int(__cdecl*)(char* FileName, char* Mode)) 0x9D0040) //1.04E
#define rFileClose ((signed int(__cdecl*)(int a1))0x9CFC26) //1.04E 

#include "Object.h"

class CMinimap
{
public:
	CMinimap();
	virtual ~CMinimap();
	void initClassic();
	void initRadar();
	void MiniMapload();
	char MapRender(int a1);
public:
	LoadTypeMap DataMap;
}; extern CMinimap gRenderMap;