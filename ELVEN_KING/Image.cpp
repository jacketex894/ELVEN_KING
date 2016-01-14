#include "Data\System\Image.h"

Image::Image(string location) {
	this->setImage(location);
}

void Image::setImage(string location) {
	this->name = this->location + location;
	wchar_t fileName[256];
	wsprintfW(fileName, L"%hs", (this->name).c_str());
    this->hBitmap = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (this->hBitmap == NULL){
		LOG("load " + this->name + " ERROR!");
	}
	else {
        this->hDc = CreateCompatibleDC(NULL);
        SelectObject(this->hDc, this->hBitmap);
		GetObject(this->hBitmap, sizeof(BITMAP), &this->bitmap);
		this->width = this->bitmap.bmWidth;
		this->height = this->bitmap.bmHeight;
	}
}

void Image::createImage(int width,int height) {
	this->hDc = CreateCompatibleDC(NULL);
	this->hBitmap = CreateCompatibleBitmap(this->hDc, width, height);
	SelectObject(this->hDc, this->hBitmap);
	GetObject(this->hBitmap, sizeof(BITMAP), &this->bitmap);
	this->width = width;
	this->height = height;
}

string Image::getName() { return this->name; }
int Image::getX() { return this->x; }
int Image::getY() { return this->y; }
int Image::getWidth() { return this->width; }
int Image::getHeight() { return this->height; }
HDC Image::getHdc() { return this->hDc; }

void Image::setVisiable(bool visiable) {
	this->visiable = visiable;
}

bool Image::getVisiable() {
	return this->visiable;
}

void Image::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Image::setPositionTransition(int x, int y,int time) {
	this->targetX = x;
	this->targetY = y;
	this->time = time;
}

void Image::setName(string name) {
	this->name = name;
}

void Image::update() {
	if (this->time > 0) {
		if(this->time == 1){
			this->x = this->targetX;
			this->y = this->targetY;
		}
		else {
			this->x += ((this->targetX - this->x) / 2);
			this->y += ((this->targetY - this->y) / 2);
		}
		this->time -= 1;
	}
}

void Image::cpoyImage(HWND hwnd,Image *origin, RECT rect, int ox, int oy) {
	int x = rect.left;
	int y = rect.top;
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	Image image = *origin;

	int size = height * image.bitmap.bmWidthBytes;
	BYTE *bBits = new BYTE[size];

	BITMAPINFO bInfo;
	GetObject(image.hBitmap, sizeof(BITMAPINFO), &bInfo);
	image.bitmap.bmBits;
	//GetBitmapBits(image.hBitmap, size, bBits);
	//SetBitmapBits(this->hBitmap, size, bBits);
}