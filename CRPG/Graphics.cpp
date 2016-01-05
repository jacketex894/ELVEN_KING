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
    this->drawImage();
    //copy memory hdc to real hdc
    BitBlt(this->hdc,0,0,this->hBitmapWidth,this->hBitmapHeight,this->hMemoryDC,0,0,SRCCOPY);
    EndPaint(this->hwnd, &this->paintStruct);
}

void Graphics::drawImage() {
	static int index;
	for (index = 0; index < this->imageCount; index++) {
		Image img = this->image[index];
        BitBlt(this->hMemoryDC, img.x, img.y, img.width, img.height, img.hDc, 0, 0, SRCCOPY);
	}
}