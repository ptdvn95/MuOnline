#pragma once

#define MUEMOJI    1
#include "stdafx.h"
#ifdef MUEMOJI

#ifndef _LIB
#define EMOJI_LIB 1
#else
#define EMOJI_LIB 1
#endif

#if(EMOJI_LIB==1)
namespace myheart
{
	namespace MUEmoji
	{
		struct EMOJI_TOKEN
		{
			std::string syntax;
			WORD index;
		};

		void Init(int t1, int t2, int t3, float cs, float hs, int sc, int sh);
		void SetTokenInfo(void* lpInfo, int Count);
		void AddTexture(int Index, int Max);
		BOOL GetMouseFocus();
	}
}

#ifndef _LIB
#pragma comment(lib, "MUEmoji.lib")
#endif
#endif
#endif