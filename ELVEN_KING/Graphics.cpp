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
    this->drawImage();
	//clear screen
	if (clear) this->clearScreen();
    //copy memory hdc to real hdc
    BitBlt(this->hdc,0,0,this->hBitmapWidth,this->hBitmapHeight,this->hMemoryDC,0,0,SRCCOPY);
	EndPaint(this->hwnd, &this->paintStruct);
}

void Graphics::setClear(bool setting) {
	this->clear = setting;
}

void Graphics::clearScreen() {
	RECT rect;
	rect.left = SCREEN_LEFT;
	rect.top = SCREEN_TOP;
	rect.right = rect.left + SCREEN_WIDTH;
	rect.bottom = rect.top + SCREEN_HEIGHT;
	FillRect(this->hMemoryDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
	this->clear = false;
}

void Graphics::drawImage() {
	static int index;
	for (index = 0; index < this->imageCount; index++) {
		Image img = this->image[index];
		if (!img.getVisiable()) continue;
        BitBlt(	this->hMemoryDC,
				img.getX(),
				img.getY(),
				img.getWidth(),
				img.getHeight(),
				img.getHdc(), 0, 0, SRCCOPY);
		this->image[index].update();
	}
}