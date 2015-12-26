#pragma once
#include "../Stage.h"

#define TITLE_BGM		"title.wav"
#define TITLE_IMAGE		"title.png"

class Title :public Stage{
public:
	Title();
	void update();
	static void updateGraphics();
private:
	
};

Title::Title() :Stage(TITLE_IMAGE,TITLE_BGM) {
	graphics.draw = updateGraphics;
}

void Title::update(){
}

void Title::updateGraphics() {
}