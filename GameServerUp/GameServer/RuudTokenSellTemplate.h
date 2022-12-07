#pragma once
#include "Item.h"
#include "ItemManager.h"
#include "Protocol.h"

#define MAX_RUUDTOKENSELL_INFO		25
#define MAX_CLASSTOKENSELL_INFO		7

struct PMSG_BUY_ITEMRUUD_RECV
{
	PBMSG_HEAD header; // EE:30
	BYTE PAGE;
	BYTE SLOT;
};

struct __tagRuudTokenSell
{
	BYTE byItemType;
	WORD wItemIndex;
	BYTE shPageShop;
	BYTE wSlotIndex;
	WORD dwRuudCount;
	//=====
	int ItemLevel;
	int ItemDurability;
	int ItemOption1;
	int ItemOption2;
	int ItemOption3;
	int ItemNewOption;
	int AncOption;
	int JOH;
	int OpEx;
	int Socket1;
	int Socket2;
	int Socket3;
	int Socket4;
	int Socket5;
	//=====
};


struct _RecvRuudTokenSell
{
	__tagRuudTokenSell JRShop[MAX_RUUDTOKENSELL_INFO];
	CItem m_Item[MAX_RUUDTOKENSELL_INFO];
};

//**********************************************//
//************ GameServer -> Client ************//
//**********************************************//

struct PMSG_RUUD_ITEM_LIST_SEND
{
	PWMSG_HEAD header; // C2:31
	BYTE type;
	BYTE count;
};

struct PMSG_RUUD_ITEM_LIST
{
	BYTE slot;
	DWORD dwRuudSell;
	BYTE ItemInfo[MAX_ITEM_INFO];
};

class RuudTokenSellTemplate
{
public:
	RuudTokenSellTemplate();
	virtual ~RuudTokenSellTemplate();
	void Load_RuudTokenSell(char *pchFileName);
	void GCShopItemListSend(LPOBJ lpObj);
	void _RecvRuudBUY(PMSG_BUY_ITEMRUUD_RECV * lpMsg, int aIndex);

public:
	_RecvRuudTokenSell RuudTokenSell[MAX_CLASSTOKENSELL_INFO];
};

extern RuudTokenSellTemplate g_RuudTokenSellTemplate;