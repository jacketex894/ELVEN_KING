#pragma once
#include <iostream>
#include "Global.h"
#include "Selection.h"

using namespace std;

class Stage {
	public:
		Stage(string,string);
		void setMenu(string*);
		virtual void update() = NULL;
	private:
		string background;
		string bgm;
		Selection* selection = NULL;
};

Stage::Stage(string background,string bgm){
	this->background = background;
	this->bgm = bgm;
	audio.setBGM(this->bgm);
}

void Stage::setMenu(string* options){
	this->selection = new Selection(options);
}
