#pragma once
#include "../Global.h"
#include "Map.h"

class Title :public Stage{
public:
	Title();
	void update();
private:
	int tempIndex = 1;
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
	this->image[0].setPosition(SCREEN_LEFT, SCREEN_TOP);
	//set options image
	this->image[1].setImage(TITLE_OPTION_IMAGE_A);
	this->image[2].setImage(TITLE_OPTION_IMAGE_B);
	this->image[3].setImage(TITLE_OPTION_IMAGE_C);
	this->image[1].setPosition(800, 550);
	this->image[2].setPosition(850, 610);
	this->image[3].setPosition(850, 670);
}

void Title::update() {
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
			stage = new Map("ex1","map.wav"); //To Map
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
		if (index == (this->selection->getIndex() + 1) && tempIndex != index)
		{
		this->image[tempIndex].setPositionTransition(850, 550 + 60 * (tempIndex - 1), 60);
		this->image[index].setPositionTransition(800, 550 + 60 * (index - 1), 60);
		tempIndex = index;
		}
	}
}