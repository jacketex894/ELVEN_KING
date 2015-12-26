#pragma once
#include <windows.h>
#include "Base.h"
#include "Debug.h"

class Graphics
{
public:
    void initialize(HWND);
    void update();
	void (*draw)() = NULL;
    RECT gameScreen;
private:
    HWND hwnd;
    HDC hdc;
    HDC hMemoryDC;
    PAINTSTRUCT paintStruct;
    HBITMAP hBitmap;
    HBRUSH hBrush;
    int hBitmapWidth;
    int hBitmapHeight;
    void setScreen();
};

