#pragma once
#include <windows.h>
#include "../Graphics/Icon/resource.h"

#include "Base.h"
#include "Global.h"
#include "Stage.h"

//Stage Class
#include "StageList\Title.h"

Stage *stage = NULL;

int WINAPI WinMain(HINSTANCE ,HINSTANCE ,LPSTR ,int);
LRESULT CALLBACK MainProc(HWND, UINT, WPARAM, LPARAM);
TIMERPROC update(HWND,UINT,UINT_PTR,DWORD);