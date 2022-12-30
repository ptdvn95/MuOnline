#include "stdafx.h"
#include "FullViewMode.h"
#include "Util.h"
#include "TMemory.h"

cFullViewMode FullViewMode;

cFullViewMode::cFullViewMode()
{
	this->Init();
}

cFullViewMode::~cFullViewMode()
{
}

void cFullViewMode::Init()
{
	this->Hook();
	this->Hidden = false;
}

void cFullViewMode::Hook()
{
	SetCompleteHook(0xE8, 0x004D9344, &cFullViewMode::NewUISystemUpdate);
	SetCompleteHook(0xE8, 0x004D9CC2, &cFullViewMode::NewUISystemRender);
	SetCompleteHook(0xE8, 0x004D9CCC, &cFullViewMode::RenderInfomation);
	SetCompleteHook(0xE8, 0x004D9CDB, &cFullViewMode::RenderCursor); //remove it if you want to render the cursor
}

void cFullViewMode::NewUISystemUpdate()
{
	if (((bool(__cdecl*)(int)) 0x791050)(VK_F6)) {
		FullViewMode.Hidden = !FullViewMode.Hidden;
		if (FullViewMode.Hidden) {
			FullViewMode.BackupHeight = *(DWORD*)(0x004D9746 + 3);
			SetDword(0x004D9746 + 3, 480);
		}
		else {
			SetDword(0x004D9746 + 3, FullViewMode.BackupHeight);
		}
	}
	if (FullViewMode.Hidden == false)
		((void(__thiscall*)(DWORD)) 0x00860AC0)(((DWORD(*)()) 0x861110)());
}

void cFullViewMode::NewUISystemRender()
{
	if (FullViewMode.Hidden == false)
		((void(__thiscall*)(DWORD)) 0x00860B10)(((DWORD(*)()) 0x861110)());
}

void cFullViewMode::RenderInfomation()
{
	if (FullViewMode.Hidden == false)
		((void(*)()) 0x004D5EC0)();
}

void cFullViewMode::RenderCursor()
{
	if (FullViewMode.Hidden == false)
		((void(*)()) 0x005BB0B0)();
}