#pragma once
#include <windows.h>
#include <gdiplus.h>

#include "Base.h"
#include "Debug.h"

int WINAPI WinMain(HINSTANCE ,HINSTANCE ,LPSTR ,int);
LRESULT CALLBACK MainProc(HWND, UINT, WPARAM, LPARAM);