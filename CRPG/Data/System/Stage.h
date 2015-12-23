#pragma once
#include <iostream>
#include "Global.h"

using namespace std;

class Stage {
	public:
		Stage(string,string);
	private:
		string background;
		string bgm;
};

Stage::Stage(string background,string bgm){
	this->background = background;
	this->bgm = bgm;
	audio.setBGM(this->bgm);
}