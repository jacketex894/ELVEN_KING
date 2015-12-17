#pragma once
#include <windows.h>

#include "Base.h"
#include "Global.h"
#include "Debug.h"
#include "Map.h"

int WINAPI WinMain(HINSTANCE ,HINSTANCE ,LPSTR ,int);
LRESULT CALLBACK MainProc(HWND, UINT, WPARAM, LPARAM);
TIMERPROC update(HWND,UINT,UINT_PTR,DWORD);
TIMERPROC update(HWND hwnd, UINT sMsg, UINT_PTR idEvent, DWORD dwTime) {
    InvalidateRect(hwnd, &graphics.gameScreen, TRUE);
    return 0;
}