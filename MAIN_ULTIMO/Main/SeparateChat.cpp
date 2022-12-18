#include "stdafx.h"
#include "SeparateChat.h"
#include "Util.h"
#include "TMemory.h"

cSeparateChat SeparateChatN;

cSeparateChat::cSeparateChat()
{
	this->Init();
}

cSeparateChat::~cSeparateChat()
{
}

void cSeparateChat::Init()
{

	this->showingLines = 4; //total lines to shows
	this->chatType = MESSAGE_TYPE::TYPE_SYSTEM_MESSAGE; //chat type to separate
	// allowed to change other type to separate
	this->Enable = true;
	this->SetRect(0, 72, 280, 10 + 15 * this->showingLines);
	this->Dragging = false;
	this->Hook();
}

void cSeparateChat::Hook()
{
	SetCompleteHook(0xE8, 0x0078B0BC, cSeparateChat::RenderMessages);
	SetDword(0x00D43944, (DWORD)&cSeparateChat::UpdateMouseEvent);
}

void cSeparateChat::SetRect(float a1, float a2, float a3, float a4)
{
	this->m_Pos.x = a1;
	this->m_Pos.y = a2;
	this->w = a3;
	this->h = a4;
}

bool IsRelease(int iVirtKey)
{
	return ((bool(__cdecl*)(int)) 0x791050)(iVirtKey);
}

bool IsPress(int iVirtKey)
{
	return ((bool(__cdecl*)(int)) 0x791070)(iVirtKey);
}

bool IsRepeat(int iVirtKey)
{
	return ((bool(__cdecl*)(int)) 0x791090)(iVirtKey);
}

bool CheckMouseIn(int x, int y, int width, int height)
{
	if (MouseX >= x && MouseX < x + width && MouseY >= y && MouseY < y + height)
		return true;
	return false;
}

void cSeparateChat::EventDrag()
{
	if (this->Dragging) {
		if (IsRepeat(VK_LBUTTON)) { //moving
			//move it
			this->m_Pos.x = *(int*)0x879340C - this->m_Diff.x;
			this->m_Pos.y = *(int*)0x8793410 - this->m_Diff.y;
		}
		else { //rlease
			this->Dragging = false;
		}
	}
	else if (CheckMouseIn(this->m_Pos.x, this->m_Pos.y, this->w, this->h) && (IsPress(VK_LBUTTON) || IsRepeat(VK_LBUTTON))) { //start drag
		this->Dragging = true;
		this->m_Diff.x = *(int*)0x879340C - this->m_Pos.x;
		this->m_Diff.y = *(int*)0x8793410 - this->m_Pos.y;
	}
}

bool cSeparateChat::RenderMessages()
{
	int m_pNewUIMng = ((int(*)()) 0x00861110)();
	int m_pNewChatLogWindow = ((int(__thiscall*)(int This)) 0x00861180)(m_pNewUIMng);
	int m_pNewChatInputBox = ((int(__thiscall*)(int This)) 0x00861220)(m_pNewUIMng);

	SetByte(m_pNewChatLogWindow + 0x100 + SeparateChatN.chatType, 0x01);

	if (*(BYTE*)(m_pNewChatInputBox + 0x6D)) {
		int x = *(DWORD*)(m_pNewChatLogWindow + 292);
		int y = *(DWORD*)(m_pNewChatLogWindow + 296);
		int height = *(DWORD*)(m_pNewChatLogWindow + 312);
		int showingLines = *(DWORD*)(m_pNewChatLogWindow + 316);
		int type = *(DWORD*)(m_pNewChatLogWindow + 320);
		int scroll = *(DWORD*)(m_pNewChatLogWindow + 328);

		if (*(BYTE*)(m_pNewChatInputBox + 0x08)) {
			SeparateChatN.EventDrag();

			((void(__cdecl*)(BYTE Mode)) 0x00635FD0)(1);
			glColor4f(0.0, 0.0, 0.0, 0.5);
			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
				(SeparateChatN.m_Pos.x, SeparateChatN.m_Pos.y, SeparateChatN.w, SeparateChatN.h, 0.0, 0.0);
			
			//border
			glColor4f(0.0, 0.0, 0.0, 1.0);
			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
				(SeparateChatN.m_Pos.x, SeparateChatN.m_Pos.y, SeparateChatN.w, 1, 0.0, 0.0);
			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
				(SeparateChatN.m_Pos.x, SeparateChatN.m_Pos.y + SeparateChatN.h - 1, SeparateChatN.w, 1, 0.0, 0.0);
			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
				(SeparateChatN.m_Pos.x, SeparateChatN.m_Pos.y + 1, 1, SeparateChatN.h - 2, 0.0, 0.0);
			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
				(SeparateChatN.m_Pos.x + SeparateChatN.w - 1, SeparateChatN.m_Pos.y + 1, 1, SeparateChatN.h - 2, 0.0, 0.0);
			//end border

			glColor4f(1.0, 1.0, 1.0, 1.0);
		}

		SetDword(m_pNewChatLogWindow + 292, SeparateChatN.m_Pos.x);
		SetDword(m_pNewChatLogWindow + 296, SeparateChatN.m_Pos.y + SeparateChatN.h);
		((int(__thiscall*)(DWORD, int)) 0x0078B870)(m_pNewChatLogWindow, SeparateChatN.chatType);
		SetDword(m_pNewChatLogWindow + 312, SeparateChatN.h);
		SetDword(m_pNewChatLogWindow + 316, SeparateChatN.showingLines);

		((bool(__thiscall*)(DWORD)) 0x00788A80)(m_pNewChatLogWindow);

		SetDword(m_pNewChatLogWindow + 292, x);
		SetDword(m_pNewChatLogWindow + 296, y);
		((int(__thiscall*)(DWORD, int)) 0x0078B870)(m_pNewChatLogWindow, type);
		SetDword(m_pNewChatLogWindow + 312, height);
		SetDword(m_pNewChatLogWindow + 316, showingLines);
		SetDword(m_pNewChatLogWindow + 328, scroll);
		SetByte(m_pNewChatLogWindow + 0x100 + SeparateChatN.chatType, 0x00);
	}

	return ((bool(__thiscall*)(DWORD)) 0x00788A80)(m_pNewChatLogWindow);
}

bool cSeparateChat::MouseDrag()
{
	int m_pNewUIMng = ((int(*)()) 0x00861110)();
	int m_pNewChatInputBox = ((int(__thiscall*)(int This)) 0x00861220)(m_pNewUIMng);

	if (*(BYTE*)(m_pNewChatInputBox + 0x08) && *(BYTE*)(m_pNewChatInputBox + 0x6D)) {
		if (SeparateChatN.Dragging == true || ((IsPress(VK_LBUTTON) || IsRepeat(VK_LBUTTON)) && CheckMouseIn(SeparateChatN.m_Pos.x, SeparateChatN.m_Pos.y, SeparateChatN.w, SeparateChatN.h))) {
			return true;
		}
	}
	return false;
}

bool cSeparateChat::UpdateMouseEvent()
{
	int m_pNewUIMng = ((int(*)()) 0x00861110)();
	int m_pNewChatLogWindow = ((int(__thiscall*)(int This)) 0x00861180)(m_pNewUIMng);
	
	if (SeparateChatN.MouseDrag()) {
		return false;
	}

	return ((bool(__thiscall*)(DWORD)) 0x0078A740)(m_pNewChatLogWindow);
}