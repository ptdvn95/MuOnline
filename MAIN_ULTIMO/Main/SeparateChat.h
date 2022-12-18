#pragma one

#define MouseX				*(int*)0x879340C
#define MouseY				*(int*)0x8793410

class cSeparateChat
{
	enum MESSAGE_TYPE
	{
		TYPE_ALL_MESSAGE = 0,
		TYPE_CHAT_MESSAGE,
		TYPE_WHISPER_MESSAGE,
		TYPE_SYSTEM_MESSAGE,
		TYPE_ERROR_MESSAGE,
		TYPE_PARTY_MESSAGE,
		TYPE_GUILD_MESSAGE,
		TYPE_UNION_MESSAGE,
		TYPE_GM_MESSAGE,
		TYPE_GEN_MESSAGE,

		NUMBER_OF_TYPES,
		TYPE_UNKNOWN = 0xFFFFFFFF
	};
public:
	cSeparateChat();
	~cSeparateChat();
	void Init();
	void Hook();
	void SetRect(float a1, float a2, float a3, float a4);
	void EventDrag();
	bool MouseDrag();
	static bool RenderMessages();
	static bool UpdateMouseEvent();

	bool Enable;
	POINT m_Pos;
	float w;
	float h;
	bool Dragging;
	POINT m_Diff;
	int showingLines;
	int chatType;
};

extern cSeparateChat SeparateChatN;