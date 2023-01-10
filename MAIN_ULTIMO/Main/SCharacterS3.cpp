#include "stdafx.h"
#include "SCharacterS3.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "Util.h"

__declspec(naked) void SelectCharacterMap()
{
	static DWORD SelectCharacterMap_buff = 0x004D6C35;
	_asm
	{
	MOV DWORD PTR DS:[0xE61E18],0x36 //0x4A
	MOV EAX,DWORD PTR DS:[0xE61E18]
	jmp [SelectCharacterMap_buff]
	}
}

__declspec(naked) void SelectCharacterCord()
{
	static float D27B98 = -84.50000f;
	static float D25708 = -45.00000f;
	static float D27B94 = 8898.929687f;
	static float D27B90 = 18513.10938f;
	static float D27B8C = 550.5000f;
	static float D27B88 = -48.50000;
	static DWORD SelectCharacterCord_buff = 0x004D8B57;
	static DWORD SCCordJMP    = 0x004D8B42;
	_asm
	{
	//CMP DWORD PTR DS:[0xE609E8],0x4
	//JNZ SCCordJNZ
	FLD DWORD PTR DS:[D27B98]
	FSTP DWORD PTR DS:[0x87933D0]
	FLDZ
	FSTP DWORD PTR DS:[0x87933D4]
	FLD DWORD PTR DS:[D25708]
	FSTP DWORD PTR DS:[0x87933D8]
	FLD DWORD PTR DS:[D27B94]
	FSTP DWORD PTR DS:[0x87933DC]
	FLD DWORD PTR DS:[D27B90]
	FSTP DWORD PTR DS:[0x87933E0]
	FLD DWORD PTR DS:[D27B8C]
	FSTP DWORD PTR DS:[0x87933E4]
	JMP SCCordJMP
	FLD DWORD PTR DS:[D27B88]
	FSTP DWORD PTR DS:[0x87933D0]
	FLD DWORD PTR DS:[0x87933D0]
	FADD DWORD PTR DS:[0x8787D48]
	FSTP DWORD PTR DS:[0x87933D0]
	MOV EDX,DWORD PTR SS:[EBP-0x68]
	jmp [SelectCharacterCord_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ1()
{
	static float D41DCC = 7900.000f; //8008.000
	static float D41DC8 = 19100.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ21()
{
	static float D41DCC = 7900.000f; //8008.000
	static float D41DC8 = 19100.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ2()
{
	static float D41DC4 = 7900.000f; //7986.000
	static float D41DC0 = 19300.00f; //19145.00
	static float D254C0 = 75.00000f; //90.00000
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D206;
	_asm
	{
	FLD DWORD PTR DS:[D41DC4]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC0]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D254C0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ22()
{
	static float D41DC4 = 7900.000f; //7986.000
	static float D41DC0 = 19300.00f; //19145.00
	static float D254C0 = 75.00000f; //90.00000
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D447;
	_asm
	{
	FLD DWORD PTR DS:[D41DC4]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC0]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D254C0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ3()
{
	static float D41DBC = 8000.000f; //8046.000
	static float D41DB8 = 19450.00f; //19400.00
	static float D2B954 = 45.00000f; //75.00000
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D223;
	_asm
	{
	FLD DWORD PTR DS:[D41DBC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DB8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D2B954]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ23()
{
	static float D41DBC = 8000.000f; //8046.000
	static float D41DB8 = 19450.00f; //19400.00
	static float D2B954 = 45.00000f; //75.00000
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D464;
	_asm
	{
	FLD DWORD PTR DS:[D41DBC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DB8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D2B954]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ4()
{
	static float D41DB4 = 8150.00f; //8133.000
	static float D41DB0 = 19550.00f; //19645.00
	static float D2577C = 25.00000f; //60.00000
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D240;
	_asm
	{
	FLD DWORD PTR DS:[D41DB4]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DB0]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D2577C]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ24()
{
	static float D41DB4 = 8150.00f; //8133.000
	static float D41DB0 = 19550.00f; //19645.00
	static float D2577C = 25.00000f; //60.00000
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D481;
	_asm
	{
	FLD DWORD PTR DS:[D41DB4]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DB0]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D2577C]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ5()
{
	static float D41DAC = 8300.000f; //8282.000
	static float D41DA8 = 19600.00f; //19845.00
	static float D27BFC = 0.00000f; //35.00000
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D25D;
	_asm
	{
	FLD DWORD PTR DS:[D41DAC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DA8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27BFC]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ5_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ25()
{
	static float D41DAC = 8300.000f; //8282.000
	static float D41DA8 = 19600.00f; //19845.00
	static float D27BFC = 0.00000f; //35.00000
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D49E;
	_asm
	{
	FLD DWORD PTR DS:[D41DAC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DA8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27BFC]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ5_buff]
	}
}

// CAOTHU.VN add here to fix mount size
__declspec(naked) void ThuNhoThuCuoi()
{
	static float CAOTHU_VN = 1.00000f;
	static DWORD BACK = 0x50383F;
	_asm
	{
		FLD DWORD PTR DS : [CAOTHU_VN]
		jmp[BACK]
	}
}

// remove black bar ver 1
void sub_6363D0(GLint x, int y, GLsizei Width, GLsizei Height)
{
	*(DWORD*)0x87933F4 = x;
	*(DWORD*)0x87933F0 = y;
	*(DWORD*)0x87933EC = Width;
	*(DWORD*)0x87933E8 = Height;

	if(SceneFlag == 2)
	{
		glViewport(x, y, Width, Height);
	}
	else if(SceneFlag == 4)
	{
		glViewport(x, y - y, Width, Height);
	}
	else if(SceneFlag == 5)
	{
		glViewport(x, pWinHeight - (Height + y), Width, Height);
	}
}

void SCharacterS3()
{
	SetRange((LPVOID)0x004D6C26, 5, ASM::NOP);
    SetOp((LPVOID)0x004D6C26, (LPVOID)SelectCharacterMap, ASM::JMP);
	
	SetRange((LPVOID)0x004D8AF0, 5, ASM::NOP);//0x004D8AE7
    SetOp((LPVOID)0x004D8AF0, (LPVOID)SelectCharacterCord, ASM::JMP);

//Posicion Personajes

	SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1, ASM::JMP);
	SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21, ASM::JMP);
	
	SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ2, ASM::JMP);
	SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ22, ASM::JMP);
	
	SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ3, ASM::JMP);
	SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ23, ASM::JMP);
	
	SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ4, ASM::JMP);
	SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ24, ASM::JMP);
	
	SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ5, ASM::JMP);
	SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
    SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ25, ASM::JMP);
	SetByte((LPVOID)0x0057F0FC, 0xE9);
    SetByte((LPVOID)0x0057F0FD, 0x4A);
    SetByte((LPVOID)0x0057F0FE, 0x01);
    SetByte((LPVOID)0x0057F0FF, 0x00);
    SetByte((LPVOID)0x0057F100, 0x00);
    SetByte((LPVOID)0x0057F101, 0x90);

	// SetDword((PVOID)(0x004D7A0E), 450);
	// SetByte((PVOID)(0x004D7A18), 0);
	// SetDword((PVOID)(0x004D7179), 450);
	// SetByte((PVOID)(0x004D7183), 0);

	// fix mount size ver 1
	// SetRange((LPVOID)0x503839, 6, ASM::NOP);
	// SetOp((LPVOID)0x503839, (LPVOID)ThuNhoThuCuoi, ASM::JMP);	

	// fix mount size ver 2
	SetByte((LPVOID)0x00503834, 0xEB);

	// SetCompleteHook(0xE8, 0x00636505, &sub_6363D0);
}
