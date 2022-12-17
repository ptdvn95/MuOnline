#pragma once

#define Offset_CreateFontA1 0x004060D0
#define Offset_CreateFontA2 0x004D2882
#define Offset_CreateFontA3    0x004D28EB
#define Offset_CreateFontA4 0x004D2957
#define Offset_CreateFontA5 0x004D29C1

void InitCommon();
BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
char FixHelperMouseClick(int a1);
void CRenderBoolean(int a1, int a2, char *a3);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight );


extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableShadow;
extern int DisableShadowPet;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int DisableObject;
extern int DisableWings;
extern int DisableWeapons;
extern int DisableCloack;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int SeparateChat;
extern int TimerBar;
extern int HpMonsterBar;
extern int HPMonsterName;
extern char Main_Font_Name[100];
extern int Main_Font_Bold;
extern int Main_Font_Height;
extern int Main_Font_Italic;
extern int Main_Font_Unicode;
extern int Main_Font_Width;
extern int Main_Font_Underline;
extern int Main_Font_Quality;
extern int Main_Font_StrikeOut;
extern int SellPostColor;
extern int offhelper;
extern int zenoff;
extern int OpenSwicthSkill;
extern int SkillPage;

extern int Encoger;
extern int MinimizarRadar;
extern int MinimizarParty;
extern int isHiddenPlayer;