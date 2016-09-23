#pragma once
#include <windows.h>
#include <iostream>
#include "Base.h"
#include "Selection.h"

using namespace std;

class Stage {
	public:
		Stage(string);
		string bgm;
		virtual void update() = NULL;
};