#pragma once
#include "../Stage.h"
#include "../Base.h"
#include "../Image.h"

class Title :public Stage{
public:
	Title();
	void update();
private:
	Image *background;
};

Title::Title() :Stage(TITLE_IMAGE,TITLE_BGM) {
	string options[3] = { NEW_GAME, LOAD_GAME, EXIT_GAME };
	this->setMenu(options);
	this->background = new Image(TITLE_IMAGE);
}

void Title::update(){
	switch (control.key)
	{
	case VK_UP: 
		this->selection->previousIndex();
		break;
	case VK_DOWN:
		this->selection->nextIndex();
		break;
	case VK_ENTER:
		
		break;
	}
}

