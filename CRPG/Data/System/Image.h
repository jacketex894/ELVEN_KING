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
	float x = 0;
	float y = 0;
	int width = 0;
	int height = 0;
	RECT rect;
	BITMAP bitmap;
	HBITMAP hBitmap;
	HDC hDc;
	//animation used
	//times of transition(frame)
	int time = 0;
	//image target position
	float targetX = 0;
	float targetY = 0;
public:
	Image() {};
	Image(string);
	void setImage(string);
	string getName();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void setPosition(int, int);
	void setPositionTransition(int,int,int);
	void update();
	HDC getHdc();
};