#pragma once
#include "Stage.h"
#include "Selection.h"

#define NEW_GAME	"�s���_�I"
#define LOAD_GAME	"Ū������"
#define EXIT_GAME	"���}�C��"

#define TITLE_BGM	"title.wav"
#define TITLE_BACK	"title.png"

class Title :public Stage {
	public:
		Title();
	private:
		Selection* menu;
};

Title::Title() : Stage(TITLE_BACK,TITLE_BGM){
	string options[3] = {NEW_GAME,LOAD_GAME,EXIT_GAME};
	this->menu = new Selection(options);
}