#pragma once
#include <iostream>
#include "Selection.h"

using namespace std;

class Stage {
	public:
		Stage(string,string);
		void setMenu(string*);
		string bgm;
		virtual void update() = NULL;
	protected:
		string background;
		Selection* selection = NULL;
};