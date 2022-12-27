#include "stdafx.h"
#if (JEWEL_BANK == 1)
#include "Interface.h"
#include "postInterface.h"
#include "User.h"
#include "PrintPlayer.h"
#include "JewelryBank.h"
#include "Defines.h"
#include "Protocol.h"
#include "Item.h"
#include "Protect.h"
#include "Util.h"

JewelsBank gJewelsBank;

void SendByRightClick(int This)
{
	lpItemObj item = (lpItemObj) * (DWORD *)(This + 84);

	if (item)
	{
		if (GetKeyState(VK_RBUTTON) & 0x8000 && GetKeyState(VK_SHIFT) & 0x8000)
		{
			int start = 12;
			if (*(DWORD *)(This + 44) == 200)
			{
				start = 12;
			}
			else if (*(DWORD *)(This + 44) == 44)
			{
				start = 76;
			}
			else if (*(DWORD *)(This + 44) == 131)
			{
				start = 108;
			}

			int Slot = item->PosX + (item->PosY * 8) + start;

			gJewelsBank.JewelBankSend(Slot);
		}
	}

	((void(__thiscall *)(int))0x007DCF20)(This);
}

void JewelsBank::JewelBankSend(int slot)
{
	if ((GetTickCount() - this->StatusTick) < 250)
	{
		return;
	}

	if (slot < 0)
	{
		return;
	}

	this->StatusTick = GetTickCount();

	JEWELBANKSLOT_SEND pMsg;

	pMsg.slot = slot;

	pMsg.header.set(0xF3, 0xF9, sizeof(pMsg));

	DataSend((BYTE *)&pMsg, pMsg.header.size);
}

void JewelsBank::JewelsBankLoad()
{
	this->Active = false;
	SetCompleteHook(0xE8, 0x007DD0D9, &SendByRightClick);
	this->Bind();
}

void JewelsBank::Bind()
{
	gInterface.BindObject(eJEWELBANK_MAIN, 0x7A5A, 222, 320, -1, -1);
	gInterface.BindObject(eJEWELBANK_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eJEWELBANK_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eJEWELBANK_POINT, 0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(eJEWELBANK_LINE, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(eJEWELBANK_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eJEWELBANK_CLOSE, 0x7EC5, 36, 29, -1, -1);

	// Sumar
	gInterface.BindObject(eJEWELBANK_PAGEUP1, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP2, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP3, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP4, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP5, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP6, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP7, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP8, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP9, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP10, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP11, 0x7AA4, 15, 15, -1, -1);
	// Restar
	gInterface.BindObject(eJEWELBANK_PAGEDN1, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN2, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN3, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN4, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN5, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN6, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN7, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN8, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN9, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN10, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN11, 0x7C0D, 15, 15, -1, -1);
}

void JewelsBank::Draw()
{

	if (this->Active == false)
		return;

	gInterface.Data[eJEWELBANK_MAIN].OnShow = true;

	DWORD Color = eGray100;
	float MainWidth = 230.0;
	float MainHeight = 350.0;
	float StartY = 21;
	float StartX = 0;

	gInterface.DrawWindow(eJEWELBANK_MAIN, eJEWELBANK_TITLE, eJEWELBANK_FRAME, eJEWELBANK_FOOTER, 14, StartX, StartY, "Ngân Hàng Ngọc");
	// gInterface.DrawFormat(eYellow, StartX + 10, 110, 210, 3, "Jewel Bank System");

	gInterface.DrawGUI(eJEWELBANK_CLOSE, StartX + MainWidth - gInterface.Data[eJEWELBANK_CLOSE].Width, 18);
	// ----
	if (gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eJEWELBANK_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eJEWELBANK_CLOSE, gInterface.Data[eJEWELBANK_CLOSE].X, 18, Color);
		gInterface.DrawToolTip((int)gInterface.Data[eJEWELBANK_CLOSE].X + 5, 15, "Close");
	}

	float flDrawX = StartX + 20;
	float flDrawY = StartY + 30;

	this->DrawInfo(flDrawX, flDrawY, "Zen", true, Zen);

	flDrawY += 20;
	gInterface.DrawGUI(eJEWELBANK_DIV, StartX, flDrawY + 10);

	flDrawY += 20;
	this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Jewel Of Chaos", ChaosBank);

	flDrawY += 20;
	this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Jewel Of Bless", BlessBank);

	flDrawY += 20;
	this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Jewel Of Soul", SoulBank);

	flDrawY += 20;
	this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Jewel Of Life", LifeBank);

	flDrawY += 20;
	this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Jewel Of Creation", CreateonBank);
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType >= 2)
	{
		flDrawY += 20;
		this->DrawLine(14, 31, 6, flDrawX, flDrawY, "Jewel of Guardian", GuardianBank);

		flDrawY += 20;
		this->DrawLine(14, 42, 7, flDrawX, flDrawY, "Jewel of Harmony", HarmonyBank);

		flDrawY += 20;
		this->DrawLine(14, 43, 8, flDrawX, flDrawY, "Jewel Of LowStone", LowStoneBank);

		flDrawY += 20;
		this->DrawLine(14, 44, 9, flDrawX, flDrawY, "Jewel Of HighStone", HighStoneBank);

		flDrawY += 20;
		this->DrawLine(14, 41, 10, flDrawX, flDrawY, "Jewel Of GemStone", GemStoneBank);

		gInterface.DrawFormat(eYellow, flDrawX - 10, flDrawY + 52, 150, 1, "%s", "Nhấn nút [+] hoặc [shift + chuột phải] vào ngọc trong kho đồ để gửi.");
		gInterface.DrawFormat(eYellow, flDrawX - 10, flDrawY + 63, 150, 1, "%s", "Nhấn nút [-] để lấy ngọc x1 hoặc [shift + chuột trái] + [-] để lấy ngọc x3.");
	}
}

void JewelsBank::DrawLine(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char *ItemName, int Count)
{
	ItemBmdStruct *ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));

	const int WidthValue = 24;
	const int HeightValue = 26;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flY = ItemDrawY;
	int iLevel = 0;
	gPostInterface.DrawItemIMG(flX, flY - 20, barWidth, barHeight, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 1, 0, 0);

	flX += 30;
	flY += 10;
	gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s x %d", ItemName, Count);

	flX += 95;
	gInterface.DrawGUI(eJEWELBANK_PAGEDN1 + ItemLevel, flX, flY);

	if (gInterface.IsWorkZone(eJEWELBANK_PAGEDN1 + ItemLevel))
	{
		if (gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].OnClick)
		{
			gInterface.DrawColoredGUI(eJEWELBANK_PAGEDN1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].Y, eGray150);
		}
	}

	flX += 20;
	gInterface.DrawGUI(eJEWELBANK_PAGEUP1 + ItemLevel, flX, flY);

	if (gInterface.IsWorkZone(eJEWELBANK_PAGEUP1 + ItemLevel))
	{
		if (gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].OnClick)
		{
			gInterface.DrawColoredGUI(eJEWELBANK_PAGEUP1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].Y, eGray150);
		}
	}

	// gInterface.DrawGUI(eJEWELBANK_LINE, ItemDrawX + 15, flY + 15);
}

void JewelsBank::DrawInfo(float InfoDrawX, float InfoDrawY, char *Text, bool Type, int Count)
{
	float flX = InfoDrawX + 10;
	float flY = InfoDrawY;

	gInterface.DrawGUI(eJEWELBANK_POINT, flX + 8, flY + 10);

	flX += 30;
	flY += 10;

	if (Type)
	{
		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d 000 000", Text, Count);

		flX += 95;
		gInterface.DrawGUI(eJEWELBANK_PAGEDN1, flX, flY);

		if (gInterface.IsWorkZone(eJEWELBANK_PAGEDN1))
		{
			if (gInterface.Data[eJEWELBANK_PAGEDN1].OnClick)
			{
				gInterface.DrawColoredGUI(eJEWELBANK_PAGEDN1, gInterface.Data[eJEWELBANK_PAGEDN1].X, gInterface.Data[eJEWELBANK_PAGEDN1].Y, eGray150);
			}
		}

		flX += 20;
		gInterface.DrawGUI(eJEWELBANK_PAGEUP1, flX, flY);

		if (gInterface.IsWorkZone(eJEWELBANK_PAGEUP1))
		{
			if (gInterface.Data[eJEWELBANK_PAGEUP1].OnClick)
			{
				gInterface.DrawColoredGUI(eJEWELBANK_PAGEUP1, gInterface.Data[eJEWELBANK_PAGEUP1].X, gInterface.Data[eJEWELBANK_PAGEUP1].Y, eGray150);
			}
		}
	}
	else
	{
		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d", Text, Count);
	}

	// flX += 95;
	// gInterface.DrawGUI(eJEWELBANK_LINE, InfoDrawX + 15, flY + 15);
}

void JewelsBank::Button(DWORD key, bool triple)
{
	if (this->Active == false)
	{
		return;
	}

	for (int i = 0; i < 11; i++)
	{
		if (gInterface.ButtonEx(key, eJEWELBANK_PAGEUP1 + i, false))
		{
			this->Packet(i, false);
			return;
		}
		else if (gInterface.ButtonEx(key, eJEWELBANK_PAGEDN1 + i, false))
		{
			this->Packet(i + 11, triple);
			return;
		}
	}
}

bool JewelsBank::EventJewelBank_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();

	gJewelsBank.Active = false;
	gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void JewelsBank::Packet(int number, bool triple)
{
	PMSG_JEWELBANK pMsg;
	pMsg.Result = number;
	pMsg.h.set(0xF3, 0xDF, sizeof(pMsg));
	pMsg.Triple = triple;
	DataSend((LPBYTE)&pMsg, pMsg.h.size);
}

void JewelsBank::RecibirJewelsBank(PMSG_JEWELSBANK *aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}
	// ---
#if (JEWEL_BANK == 1)
	Zen = aRecv->Zen;
	ChaosBank = aRecv->Chaos;
	BlessBank = aRecv->Bless;
	SoulBank = aRecv->Soul;
	LifeBank = aRecv->Life;
	CreateonBank = aRecv->CreateonBank;
	GuardianBank = aRecv->GuardianBank;
	HarmonyBank = aRecv->HarmonyBank;
	LowStoneBank = aRecv->LowStoneBank;
	HighStoneBank = aRecv->HighStoneBank;
	GemStoneBank = aRecv->GemStoneBank;
#endif
}
#endif