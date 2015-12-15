#include "Data\System\Graphics.h"

void Graphics::initialize(HWND hwnd)
{
    this->hwnd = hwnd;
    this->setScreen();
}

void Graphics::setScreen()
{
    this->gameScreen.left = (GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2;
    this->gameScreen.top = (GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2;
    this->gameScreen.right = gameScreen.left + SCREEN_WIDTH;
    this->gameScreen.bottom = gameScreen.top + SCREEN_HEIGHT;
}

void Graphics::update() {
    this->hdc = BeginPaint(this->hwnd, &this->paintStruct);
    Rectangle(this->hdc,
        this->gameScreen.left,
        this->gameScreen.top,
        this->gameScreen.right,
        this->gameScreen.bottom);
    EndPaint(this->hwnd, &this->paintStruct);
}