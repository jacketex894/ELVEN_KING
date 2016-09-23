#pragma once
#include "../Global.h"

class Title :public Stage{
public:
	Title();
	void update();
private:
	int tempIndex = 1;
	Selection* selection = NULL;
};

Title::Title() :Stage(TITLE_BGM)
{
    //set options
    this->selection = new Selection(3);
    this->selection->addOption(0, NEW_GAME);
    this->selection->addOption(1, LOAD_GAME);
    this->selection->addOption(2, EXIT_GAME);
    this->selection->setCycle(true);
}

void Title::update()
{
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
			break;
		case 1:
			break;
		case 2:
			exit(0);
			break;
		}
		break;
	}
	/*
	//change options image's postion
	for (int index = 1; index < 4; index++) {
		if (index == (this->selection->getIndex() + 1) && tempIndex != index)
		{
		this->image[tempIndex].setPositionTransition(850, 550 + 60 * (tempIndex - 1), 60);
		this->image[index].setPositionTransition(800, 550 + 60 * (index - 1), 60);
		tempIndex = index;
		}
	}
	*/
}