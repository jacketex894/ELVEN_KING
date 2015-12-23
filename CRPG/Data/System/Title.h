#pragma once
#include "Stage.h"
#include "Selection.h"

#define NEW_GAME	"新的冒險"
#define LOAD_GAME	"讀取紀錄"
#define EXIT_GAME	"離開遊戲"

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