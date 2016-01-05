#pragma once
#include <iostream>
#include "Base.h"
#include "Image.h"
#include "Selection.h"

using namespace std;

class Stage {
	public:
		Stage(string,string);
		void setMenu(string*);
		string bgm;
		virtual void update() = NULL;
        Image *image = NULL;
        int imageCount = 0;
	protected:
		string background;
		Selection* selection = NULL;
};