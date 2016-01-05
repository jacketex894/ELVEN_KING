#pragma once
#include <iostream>
#include <windows.h>
#include "Base.h"
#include "Debug.h"

using namespace std;

class Image {
public:
	Image() {};
	Image(string);
	void setImage(string);
	string name;
	int x;
	int y;
	int width;
	int height;
    HDC hDc;
private:
    const string location = GRAPHICS_ADDRESS;
	RECT rect;
    BITMAP bitmap;
    HBITMAP hBitmap;
};