#include "Data\System\Image.h"

Image::Image(string location) {
	this->setImage(location);
}

void Image::setImage(string location) {
	this->x = 0;
	this->y = 0;
	this->name = location;
	wchar_t fileName[256];
	wsprintfW(fileName, L"%hs", this->name.c_str());
	this->hBitmap = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
	if (this->hBitmap == NULL)
		LOG("load " + location + " ERROR!");
	else 
		{
			SelectObject(this->hDC, &this->bitmap);
			GetObject(this->hBitmap, sizeof(BITMAP), &this->bitmap);
			this->width = this->bitmap.bmWidth;
			this->height = this->bitmap.bmHeight;
		}
}