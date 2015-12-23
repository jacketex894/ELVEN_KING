#include "Data\System\Graphics.h"

void Graphics::initialize(HWND hwnd)
{
    
    //get windows handle varible
    this->hwnd = hwnd;
    //setting game screen
    this->setScreen();
    //create  memory HDC
    this->hMemoryDC = CreateCompatibleDC(this->hdc);
    //create buffer bitmap
    hBitmapWidth = this->gameScreen.right - this->gameScreen.left;
    hBitmapHeight = this->gameScreen.bottom - this->gameScreen.top;
    this->hBitmap = CreateCompatibleBitmap(this->hdc,hBitmapWidth,hBitmapHeight);
    SelectObject(this->hMemoryDC,this->hBitmap);
}

void Graphics::setScreen()
{
    this->gameScreen.left = (GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2;
    this->gameScreen.top = (GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2;
    this->gameScreen.right = gameScreen.left + SCREEN_WIDTH;
    this->gameScreen.bottom = gameScreen.top + SCREEN_HEIGHT;
}

void Graphics::update() {
    //to begin draw 
    this->hMemoryDC = BeginPaint(this->hwnd, &this->paintStruct);
	//clear screen
	FillRect(this->hMemoryDC, &this->gameScreen, this->hBrush);
    this->draw();
    EndPaint(this->hwnd, &this->paintStruct);
    //copy memory hdc to real hdc
    BitBlt(this->hdc,0,0,this->hBitmapWidth,this->hBitmapHeight,this->hMemoryDC,0,0,SRCCOPY);
}

void Graphics::draw() {
    if (gdx < dx) gdx += (dx - gdx) / 2;
    if (gdx > dx) gdx -= (gdx - dx) / 2;
    if (gdy < dy) gdy += (dy - gdy) / 2;
    if (gdy > dy) gdy -= (gdy - dy) / 2;

    int speed = 4;
   // LOG("DRAW");
    if (gdx < dx) gdx += speed; //(dx - gdx) / 2;
    if (gdx > dx) gdx -= speed; //(gdx - dx) / 2;
    if (gdy < dy) gdy += speed; //(dy - gdy) / 2;
    if (gdy > dy) gdy -= speed; //(gdy - dy) / 2;

    Ellipse(this->hMemoryDC,this->gameScreen.left + gdx,
                            this->gameScreen.top  + gdy,
                            this->gameScreen.left + gdx + 32,
                            this->gameScreen.top  + gdy + 32);
}