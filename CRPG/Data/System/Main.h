#pragma once
#include <windows.h>
#include "../resource.h"
#include "Base.h"
#include "Global.h"

Stage *tempStage = stage;

int WINAPI WinMain(HINSTANCE ,HINSTANCE ,LPSTR ,int);
LRESULT CALLBACK MainProc(HWND, UINT, WPARAM, LPARAM);
TIMERPROC update(HWND,UINT,UINT_PTR,DWORD);