#include "stdafx.h"
#include "AutoLogin.h"
#include "Util.h"
#include "Interface.h"
#include "CustomFont.h"

cAutoLogin AutoLogin;


cAutoLogin::cAutoLogin()
{
}

cAutoLogin::~cAutoLogin()
{
}

float getX(float x) {
	return x / g_fScreenRate_x;
}
float getY(float y) {
	return y / g_fScreenRate_x;
}

bool IsCursorInZone(short x, short y, short x2, short y2){
	return pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
}

bool WriteString(const std::string& name, const std::string& value) {
	HKEY	hKey = NULL;
	DWORD	dwDisp;
	DWORD	dwSize = value.size();

	if (ERROR_SUCCESS != RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
		return false;

	RegSetValueEx(hKey, name.c_str(), 0L, REG_SZ, (CONST BYTE*)value.c_str(), dwSize);
	RegCloseKey(hKey);
	return true;
}

bool WriteDword(const std::string& name, DWORD value) {
	HKEY	hKey = NULL;
	DWORD	dwDisp;
	DWORD	dwSize = sizeof(DWORD);

	if (ERROR_SUCCESS != RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
		return false;

	RegSetValueEx(hKey, name.c_str(), 0L, REG_DWORD, (BYTE*)&value, dwSize);
	RegCloseKey(hKey);
	return true;
}

void DoRequestLogin()
{
	int Struct = _Instance() + 16968;

	InputBox_GetText(*(DWORD *)(Struct + 848), AutoLogin.iUser, 11);
	InputBox_GetText(*(DWORD *)(Struct + 852), AutoLogin.iPassword, 11);
	if (AutoLogin.savePass) {
		WriteString("ID", AutoLogin.iUser);
		WriteString("PW", AutoLogin.iPassword);
		WriteDword("SavePass", 1);
	}
	else {
		WriteDword("SavePass", 0);
	}
	//do it
	RequestLogin(_Instance() + 16968);
}

void CButtonAutoLogin(int This, int a2)
{
	CUIRenderText_SetFont((int)pTextThis(), *(int*)0xE8C594);

	float startX = (530.0 - getX(329)) / 2,
		startY = (480.0 - getY(245)) * 2.0 / 3.0;

	int Struct = _Instance() + 16968;

	if (IsCursorInZone(startX + getX(246.0), startY + getY(156), 15, 15)) {
		if (pIsKeyRelease(VK_LBUTTON))
		{
			pDrawButton(0x7B69, startX + getX(246.0), startY + getY(156), 15, 15, 0, 0);
			AutoLogin.savePass = !AutoLogin.savePass;
			PlayBuffer(25, 0, 0);
		}
	}
	if (AutoLogin.savePass) {
		pDrawButton(0x7B69, startX + getX(246.0), startY + getY(156), 15, 15, 0, 0);
	}
	else {
		pDrawButton(0x7B69, startX + getX(246.0), startY + getY(156), 15, 15, 0, 15);
	}
	CustomFont.Draw((HFONT)pFontNormal, startX + getX(130), startY + getY(160), 0xffffffD1, 0x0, 92, 0, 4, "Save password");
}

void DoLoginWinCreate(int)
{
	int Struct = _Instance() + 16968;
	LoginWinCreate(Struct);
	if (AutoLogin.savePass) {
		InputBox_SetText(*(DWORD *)(Struct + 848), AutoLogin.iUser);
		InputBox_SetText(*(DWORD *)(Struct + 852), AutoLogin.iPassword);
	}
}

void cAutoLogin::Load()
{
	//read data
	HKEY hKey;
	DWORD dwDisp;
	DWORD dwSize;
	if (ERROR_SUCCESS == RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
	{
		dwSize = 11;
		if (RegQueryValueEx(hKey, "ID", 0, NULL, (LPBYTE)AutoLogin.iUser, &dwSize) != ERROR_SUCCESS)
		{
			ZeroMemory(AutoLogin.iUser, sizeof(AutoLogin.iUser));
		}
		dwSize = 11;
		if (RegQueryValueEx(hKey, "PW", 0, NULL, (LPBYTE)AutoLogin.iPassword, &dwSize) != ERROR_SUCCESS)
		{
			ZeroMemory(AutoLogin.iPassword, sizeof(AutoLogin.iPassword));
		}
		dwSize = sizeof (int);
		if (RegQueryValueEx(hKey, "SavePass", 0, NULL, (LPBYTE)&AutoLogin.savePass, &dwSize) != ERROR_SUCCESS)
		{
			AutoLogin.savePass = false;
		}
	}
	
	//end

	SetCompleteHook(0xE8, 0x0040B5A9, &CButtonAutoLogin);
	SetCompleteHook(0xE8, 0x0040B400, &DoRequestLogin);
	SetCompleteHook(0xE8, 0x0040B44F, &DoRequestLogin);
	SetCompleteHook(0xE8, 0x00483711, &DoLoginWinCreate);
}