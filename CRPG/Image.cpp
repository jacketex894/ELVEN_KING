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
        SelectObject(hDc, this->hBitmap);
		GetObject(this->hBitmap, sizeof(BITMAP), &this->bitmap);
		this->width = this->bitmap.bmWidth;
		this->height = this->bitmap.bmHeight;
	}
}

string Image::getName() { return this->name; }
int Image::getX() { return (int)this->x; }
int Image::getY() { return (int)this->y; }
int Image::getWidth() { return this->width; }
int Image::getHeight() { return this->height; }
HDC Image::getHdc() { return this->hDc; }

void Image::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Image::setPositionTransition(int x, int y,int time) {
	this->targetX = x;
	this->targetY = y;
	this->time = time + 1;
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