#pragma once
#include <windows.h>
#include "Base.h"
#include "Debug.h"
#include "Image.h"

class Graphics
{
public:
    void initialize(HWND);
    void update();
    RECT gameScreen;
	Image *image = NULL;
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
	void drawImage();
};

