#pragma once
#include "../Global.h"
#include "Map.h"

class Title :public Stage{
public:
	Title();
	void update();
private:
	Selection* selection = NULL;
};

Title::Title() :Stage(TITLE_BGM) {
	//set options
	this->selection = new Selection(3);
	this->selection->addOption(0, NEW_GAME);
	this->selection->addOption(1, LOAD_GAME);
	this->selection->addOption(2, EXIT_GAME);
	this->selection->setCycle(true);
	//set image
	this->imageCount = 4;
	this->image = new Image[this->imageCount];
	//background image
	this->image[0].setImage(TITLE_IMAGE);
	this->image[0].x = (GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2;
	this->image[0].y = (GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2;
	//set options image
	this->image[1].setImage(TITLE_OPTION_IMAGE_A);
	this->image[2].setImage(TITLE_OPTION_IMAGE_B);
	this->image[3].setImage(TITLE_OPTION_IMAGE_C);
	this->image[1].x = this->image[2].x = this->image[3].x = 1150;
	this->image[1].y = 650;
	this->image[2].y = this->image[1].y + 1 * 60;
	this->image[3].y = this->image[1].y + 2 * 60;
}

void Title::update() {
	if (changeWait == true) return;
	switch (control.key)
	{
	case VK_UP:
		this->selection->previousIndex();
		break;
	case VK_DOWN:
		this->selection->nextIndex();
		break;
	case VK_ENTER:
		switch (this->selection->getIndex())
		{
		case 0:
			changeWait = true;
			stage = new Map("ex1","helix.wav"); //To Map
			break;
		case 1:
			break;
		case 2:
			exit(0);
			break;
		}
		break;
	}
	//change options image's postion
	for (int index = 1; index < 4; index++) {
		if (index == (this->selection->getIndex() + 1))
			this->image[index].x = 1100;
		else
			this->image[index].x = 1150;
	}
}