#pragma once
#include <windows.h>
#include "Base.h"
#include "Debug.h"
#include "Image.h"

class Graphics
{
public:
    void initialize(HWND);
	HWND hwnd;
    void update();
	void setClear(bool);
    RECT gameScreen;
	Image *image = NULL;
    int imageCount = NULL;
private:
    HDC hdc;
    HDC hMemoryDC;
    PAINTSTRUCT paintStruct;
    HBITMAP hBitmap;
    int hBitmapWidth;
    int hBitmapHeight;
    void setScreen();
	void drawImage();
	bool clear = false;
	void clearScreen();
};

