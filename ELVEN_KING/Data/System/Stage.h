#pragma once
#include <windows.h>
#include <iostream>
#include "Base.h"
#include "Image.h"
#include "Selection.h"

using namespace std;

class Stage {
	public:
		Stage(string);
		string bgm;
        Image *image = NULL;
        int imageCount = 0;
		virtual void update() = NULL;
};