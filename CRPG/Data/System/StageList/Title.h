#pragma once
#include "../Stage.h"

class Title :public Stage{
public:
	Title();
	void update();
};

Title::Title() :Stage(TITLE_IMAGE,TITLE_BGM) {
	string options[3] = { NEW_GAME, LOAD_GAME, EXIT_GAME };
	this->setMenu(options);
    //set image
    this->imageCount = 1;
	this->image = new Image[this->imageCount];
    //background image
    this->image->setImage(TITLE_IMAGE); 
    this->image[0].x = (GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2;
    this->image[0].y = (GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2;

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

