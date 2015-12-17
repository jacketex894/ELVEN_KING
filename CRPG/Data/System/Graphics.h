#pragma once
#include <windows.h>
#include "Base.h"
#include "Debug.h"

class Graphics
{
public:
    void initialize(HWND);
    void draw();
    void update();
    RECT gameScreen;
    int dx = 0, dy = 0;
    int gdx = 0, gdy = 0;
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