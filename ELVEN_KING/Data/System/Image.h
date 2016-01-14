#pragma once
#include <iostream>
#include <windows.h>
#include "Base.h"
#include "Debug.h"

using namespace std;

class Image {
private:
	const string location = GRAPHICS_ADDRESS;
	string name;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	bool visiable = true;
	BITMAP bitmap;
	HBITMAP hBitmap;
	HDC hDc;
	//animation used
	//times of transition(frame)
	int time = 0;
	//image target position
	int targetX = 0;
	int targetY = 0;
public:
	Image() {};
	Image(string);
	void setImage(string);
	void createImage(int,int);
	HDC getHdc();
	string getName();
	void setName(string);
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void setVisiable(bool);
	bool getVisiable();
	void setPosition(int, int);
	void setPositionTransition(int,int,int);
	void cpoyImage(HWND,Image*, RECT, int, int);
	void update();
};