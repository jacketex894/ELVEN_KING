#pragma once
#include <windows.h>
#include "Base.h"

class Graphics
{
public:
    void initialize(HWND);
    void update();
private:
    HWND hwnd;
    PAINTSTRUCT paintStruct;
    HDC hdc;
    RECT gameScreen;
    void setScreen();
};