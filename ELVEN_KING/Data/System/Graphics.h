#pragma once
#include "Base.h"
#include <Windows.h>
#include <d2d1.h>

#pragma comment(lib, "d2d1")

class Graphics {
private:
    ID2D1Factory *factory;
    ID2D1HwndRenderTarget *randerTarget;
    HDC hdC;
public:
    Graphics();
    ~Graphics();
    RECT screen = SCREEN;
    bool initialize(HWND);
    void clearScreen();
    void update();
};
