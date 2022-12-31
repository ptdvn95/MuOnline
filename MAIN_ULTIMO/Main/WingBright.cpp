#include "stdafx.h"
#include "WingBright.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "ToolKit.h"
#include "Import.h"
#include "Defines.h"
// ---------------------------------------------------------------------------------------------
Wings gWings;
// ---------------------------------------------------------------------------------------------
float magicianwing4da_render;
float dknightwing4db_render;
float elfwing4da;
float elfwing4da_render01;
float elfwing4da_render02;
float alicewing4db_render;
// ----
DWORD dwItemId;
DWORD dwWingThis;
DWORD dwWingStyle;
DWORD dwWingEff;
// ----
DWORD mdTmpEax;
DWORD mdTmpEsi;
DWORD mdTmpEdi;
DWORD mdTmpEcx;
DWORD mdTmpEdx;
DWORD mdTmpEbx;
DWORD mdTmpEbp;
DWORD mdTmpEsp;
// ----
DWORD dwCustomItemGlowJmp00		= 0x005FAA3F;
DWORD dwCustomItemGlowJmp01		= 0x005FAA33;
// ---------------------------------------------------------------------------------------------
float Render(float a1, float a2) //Main S13; Not here
{
float v5;
float v2 = a2 * 0.01745f;
float v6 = (float)((int)(v2 * 1000.0f / a1 + timeGetTime()) % (int)(6283.185546875f / a1))* 0.001f * a1;

if (v6 >= 3.14f)
v5 = cosf(v6);
else
v5 = -cosf(v6);
return (float)((v5 + 1.0f) * 0.5f);
}
// ---------------------------------------------------------------------------------------------


Naked(CustomItemGlow)
{
        _asm
        {
                MOV mdTmpEax,EAX
                MOV mdTmpEsi,ESI
                MOV mdTmpEdi,EDI
                MOV mdTmpEcx,ECX
                MOV mdTmpEdx,EDX
                MOV mdTmpEbx,EBX
                // ----
                MOV EAX, DWORD PTR SS:[EBP+0x10]
                MOV dwItemId, EAX
                // ----
                MOV EDX,DWORD PTR SS:[EBP+0x8]
                MOV dwWingThis, EDX
                // ----
                MOV EAX,DWORD PTR SS:[EBP+0xC]
                MOV dwWingStyle, EAX
                // ----
        }

//Wing401.bmd
				if(dwItemId == ITEM2(12,156))
        {		   			   
                glColor3fv((GLfloat*)(dwWingThis+72));
                // ----
				magicianwing4da_render = Render(-2.0, 0.0) * 0.699999988079071 + 0.2000000029802322;
				// ----
				sub_5468A0(dwWingThis,
				  0,
				  2,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);
				sub_5468A0(dwWingThis,
				  1,
				  2,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);
				sub_5468A0(dwWingThis,
				  1,
				  2,
				  *(float *)(dwWingStyle + 152),
				  1,
				  magicianwing4da_render,
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  32831);
				*(float*)(dwWingThis+72) = 0.70980392156;
                *(float*)(dwWingThis+76) = 0.51372549019;
                *(float*)(dwWingThis+80) = 0.27058823529;
				sub_5468A0(dwWingThis,
				  0,
				  70,
				  *(float*)(dwWingStyle+152),
				  *(DWORD*)(dwWingStyle+68),
				  *(float*)(dwWingStyle+100),
				  *(float*)(dwWingStyle+104),
				  *(float*)(dwWingStyle+108),
				  -1);
				*(float*)(dwWingThis+72) = 0.70980392156;
                *(float*)(dwWingThis+76) = 0.51372549019;
                *(float*)(dwWingThis+80) = 0.27058823529;
				sub_5468A0(dwWingThis,
				  0,
				  70,
				  *(float*)(dwWingStyle+152),
				  *(DWORD*)(dwWingStyle+68),
				  *(float*)(dwWingStyle+100),
				  *(float*)(dwWingStyle+104),
				  *(float*)(dwWingStyle+108),
				  -1);

                _asm
                {
                        MOV EAX,mdTmpEax
                        MOV ESI,mdTmpEsi
                        MOV EDI,mdTmpEdi
                        MOV ECX,mdTmpEcx
                        MOV EDX,mdTmpEdx
                        MOV EBX,mdTmpEbx
                        //---
                        JMP dwCustomItemGlowJmp01
                }
        }

//Wing402.bmd
				if(dwItemId == ITEM2(12,157))
        {		   			  
                glColor3fv((GLfloat*)(dwWingThis+72));
                // ----
                dknightwing4db_render = Render(-1.75, 0.0);
				// ----
                sub_5468A0(dwWingThis,
                  0,
                  2,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
                sub_5468A0(dwWingThis,
                  1,
                  2,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
                sub_5468A0(dwWingThis,
                  2,
                  2,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
                 sub_5468A0(dwWingThis,
                  3,
                  2,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
				int Avatar1 = (((int)(( *(float*)0x5EF5A1C) * 0.75f )) % 600 / 40);
				double Avatar2 = (double)(Avatar1 % 4) * 0.25;
				double Avatar3 = (double)(Avatar1 / 4) * 0.25;
				sub_5468A0(dwWingThis,4, 66, *(float *)(dwWingStyle + 152), 4, *(float *)(dwWingStyle + 100), Avatar2, Avatar3, *(DWORD *)(dwWingStyle + 60));				  
				sub_5468A0(dwWingThis,
                  2,
                  2,
                  *(float *)(dwWingStyle + 152),
                  2,
                  dknightwing4db_render,
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  32833);
				*(float*)(dwWingThis+72) = 0.83137254902;
                *(float*)(dwWingThis+76) = 0.78431372549;
                *(float*)(dwWingThis+80) = 0.66666666666;
                sub_5468A0(dwWingThis,
                  0,
                  70,
                  *(float*)(dwWingStyle+152),
                  *(DWORD*)(dwWingStyle+68),
                  *(float*)(dwWingStyle+100),
                  *(float*)(dwWingStyle+104),
                  *(float*)(dwWingStyle+108),
                  -1);
				*(float*)(dwWingThis+72) = 0.83137254902;
				*(float*)(dwWingThis+76) = 0.78431372549;
				*(float*)(dwWingThis+80) = 0.66666666666;
				sub_5468A0(dwWingThis,
                  0,
                  70,
                  *(float*)(dwWingStyle+152),
                  *(DWORD*)(dwWingStyle+68),
                  *(float*)(dwWingStyle+100),
                  *(float*)(dwWingStyle+104),
                  *(float*)(dwWingStyle+108),
                  -1);

                _asm
                {
                        MOV EAX,mdTmpEax
                        MOV ESI,mdTmpEsi
                        MOV EDI,mdTmpEdi
                        MOV ECX,mdTmpEcx
                        MOV EDX,mdTmpEdx
                        MOV EBX,mdTmpEbx
                        //---
                        JMP dwCustomItemGlowJmp01
                }
        }

//Wing403.bmd
				if(dwItemId == ITEM2(12,158))
        {
                glColor3fv((GLfloat*)(dwWingThis+72));
                // ----
				elfwing4da = Render(-4.0, 0.0) * 0.5 + 0.5;
				elfwing4da_render01 = Render(-4.0, 120.0);
				elfwing4da_render02 = Render(-4.0, 240.0);
				// ----
				sub_5468A0(dwWingThis,
				  2,
				  2,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);
				sub_5468A0(dwWingThis,
				  1,
				  66,
				  *(float *)(dwWingStyle + 152),
				  1,	
				  elfwing4da,	
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);
				sub_5468A0(dwWingThis,
				  1,
				  66,
				  *(float *)(dwWingStyle + 152),
				  1,	
				  elfwing4da_render01,	
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  32834);
				sub_5468A0(dwWingThis,
				  1,
				  66,
				  *(float *)(dwWingStyle + 152),
				  1,	
				  elfwing4da_render02,	
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  32835);
				sub_5468A0(dwWingThis,
				  0,
				  66,
				  *(float *)(dwWingStyle + 152),
				  0,
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);
				sub_5468A0(dwWingThis,
				  3,
				  66,
				  *(float *)(dwWingStyle + 152),
				  3,
				  elfwing4da,
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);
				*(float*)(dwWingThis+72) = 1.00;
                *(float*)(dwWingThis+76) = 0.65098039215;
                *(float*)(dwWingThis+80) = 0.4862745098;
                sub_5468A0(dwWingThis,
				  2,
				  70,
				  *(float*)(dwWingStyle+152),
                  *(DWORD*)(dwWingStyle+68),
                  *(float*)(dwWingStyle+100),
                  *(float*)(dwWingStyle+104),
                  *(float*)(dwWingStyle+108),
                  -1);
				*(float*)(dwWingThis+72) = 1.00;
                *(float*)(dwWingThis+76) = 0.65098039215;
                *(float*)(dwWingThis+80) = 0.4862745098;
                sub_5468A0(dwWingThis,
				  2,
				  70,
				  *(float*)(dwWingStyle+152),
                  *(DWORD*)(dwWingStyle+68),
                  *(float*)(dwWingStyle+100),
                  *(float*)(dwWingStyle+104),
                  *(float*)(dwWingStyle+108),
                  -1);

                _asm
                {
                        MOV EAX,mdTmpEax
                        MOV ESI,mdTmpEsi
                        MOV EDI,mdTmpEdi
                        MOV ECX,mdTmpEcx
                        MOV EDX,mdTmpEdx
                        MOV EBX,mdTmpEbx
                        //---
                        JMP dwCustomItemGlowJmp01
                }
        }

//Wing404.bmd
		        if(dwItemId == ITEM2(12,159))
        {
                glColor3fv((GLfloat*)(dwWingThis+72));
                // ----
                sub_5468A0(dwWingThis,
				  1,
				  2,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);	
                sub_5468A0(dwWingThis,
				  2,
				  2,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);	
                sub_5468A0(dwWingThis,
				  3,
				  2,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);	
                sub_5468A0(dwWingThis,
				  4,
				  66,
				  *(float *)(dwWingStyle + 152),
				  *(DWORD *)(dwWingStyle + 68),
				  *(float *)(dwWingStyle + 100),
				  *(float *)(dwWingStyle + 104),
				  *(float *)(dwWingStyle + 108),
				  -1);	
				int fall1 = (int) *(float*)0x5EF5A1C % 600 / 40;
				double fall2 = (double)(fall1 % 4) * 0.25;
				double fall3 = (double)(fall1 / 4) * 0.25;
				*(float*)(dwWingThis+72) = 0.50;
                *(float*)(dwWingThis+76) = 0.50;
                *(float*)(dwWingThis+80) = 0.50;  
				sub_5468A0(dwWingThis,0, 66, 1.0, 0, *(float *)(dwWingStyle + 100), fall2, fall3, *(DWORD *)(dwWingStyle + 60));
				*(float*)(dwWingThis+72) = 0.8;
                *(float*)(dwWingThis+76) = 0.74509803921;
                *(float*)(dwWingThis+80) = 0.59215686274;     
                sub_5468A0(dwWingThis,
				  1,
				  70,
				  *(float*)(dwWingStyle+152),
				  *(DWORD*)(dwWingStyle+68),
				  *(float*)(dwWingStyle+100),
				  *(float*)(dwWingStyle+104),
				  *(float*)(dwWingStyle+108),
				  -1);	
                sub_5468A0(dwWingThis,
				  2,
				  70,
				  *(float*)(dwWingStyle+152),
				  *(DWORD*)(dwWingStyle+68),
				  *(float*)(dwWingStyle+100),
				  *(float*)(dwWingStyle+104),
				  *(float*)(dwWingStyle+108),
				  -1);	
                sub_5468A0(dwWingThis,
				  3,
				  70,
				  *(float*)(dwWingStyle+152),
				  *(DWORD*)(dwWingStyle+68),
				  *(float*)(dwWingStyle+100),
				  *(float*)(dwWingStyle+104),
				  *(float*)(dwWingStyle+108),
				  -1);	

                _asm
                {
                        MOV EAX,mdTmpEax
                        MOV ESI,mdTmpEsi
                        MOV EDI,mdTmpEdi
                        MOV ECX,mdTmpEcx
                        MOV EDX,mdTmpEdx
                        MOV EBX,mdTmpEbx
                        //---
						JMP dwCustomItemGlowJmp01
                }
        }	

//Wing406.bmd
				if(dwItemId == ITEM2(12,161))
        {
                glColor3fv((GLfloat*)(dwWingThis+72));
                // ----
                alicewing4db_render = Render(-4.0, 0.0) * 0.1000000014901161 + 0.3;
				// ----
                sub_5468A0(dwWingThis,
                  0,
                  2,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
                sub_5468A0(dwWingThis,
                  1,
                  66,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
                sub_5468A0(dwWingThis,
                  2,
                  2,
                  *(float *)(dwWingStyle + 152),
                  *(DWORD *)(dwWingStyle + 68),
                  *(float *)(dwWingStyle + 100),
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  -1);
                sub_5468A0(dwWingThis,
                  2,
                  2,
                  *(float *)(dwWingStyle + 152),
                  2,
                  alicewing4db_render,
                  *(float *)(dwWingStyle + 104),
                  *(float *)(dwWingStyle + 108),
                  32836);
				*(float*)(dwWingThis+72) = 1.00;
                *(float*)(dwWingThis+76) = 0.07843137254;
                *(float*)(dwWingThis+80) = 0.07843137254;
                sub_5468A0(dwWingThis,
                  0,
                  70,
                  *(float*)(dwWingStyle+152),
                  *(DWORD*)(dwWingStyle+68),
                  *(float*)(dwWingStyle+100),
                  *(float*)(dwWingStyle+104),
                  *(float*)(dwWingStyle+108),
                  -1);	
				*(float*)(dwWingThis+72) = 1.00;
                *(float*)(dwWingThis+76) = 0.07843137254;
                *(float*)(dwWingThis+80) = 0.07843137254;
                sub_5468A0(dwWingThis,
                  0,
                  70,
                  *(float*)(dwWingStyle+152),
                  *(DWORD*)(dwWingStyle+68),
                  *(float*)(dwWingStyle+100),
                  *(float*)(dwWingStyle+104),
                  *(float*)(dwWingStyle+108),
                  -1);	

                _asm
                {
                        MOV EAX,mdTmpEax
                        MOV ESI,mdTmpEsi
                        MOV EDI,mdTmpEdi
                        MOV ECX,mdTmpEcx
                        MOV EDX,mdTmpEdx
                        MOV EBX,mdTmpEbx
                        //---
                        JMP dwCustomItemGlowJmp01
                }
        }
        // ----
        _asm
        {
                MOV EAX,mdTmpEax
                MOV ESI,mdTmpEsi
                MOV EDI,mdTmpEdi
                MOV ECX,mdTmpEcx
                MOV EDX,mdTmpEdx
                MOV EBX,mdTmpEbx
                //---
                CMP DWORD PTR SS:[EBP+0x10],0x1CB7
                JMP dwCustomItemGlowJmp00
        }
}

void Wings::Load()
{
	SetRange((LPVOID)0x005FAA38 , 7, ASM::NOP);
	SetOp((LPVOID)0x005FAA38, (LPVOID)CustomItemGlow, ASM::JMP);
}
// ---------------------------------------------------------------------------------------------
