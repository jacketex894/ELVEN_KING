#pragma once
#include <windows.h>
#include <iostream>
#include "../Global.h"
#include "../File.h"

using namespace std;

struct BLOCK {
	string name;
	int index;
	bool pass;
	short int layer;
	int count;
	int materialId;
};

class Map : public Stage
{
public:
	Map(string, string);
	int getWidth();
	int getHeight();
	bool getPass(int,int);
	
	void longUpdate();
	void update();
private:
	//========================
	Enemy *enemys;
	//========================
	//base data
	File* fMap;
	int width;
	int height;
	bool **passage;

	//used for text
	void resolveBase(string);
	void resolveMap(string);
	void createPassage();
	void settingPassage();

	//used for block
	int blockSize;
	BLOCK *blockList;
	string *materialList;
	void resolveBlock(BLOCK*, string);

	//create map image
	void drawMap();
};

Map::Map(string mapName,string mapBGM) : Stage(mapBGM)
{	
	//the map file
	this->fMap = new File(mapName + EXTENSION);
	//this->resolveBase(this->fMap->output());
	
	this->imageCount = 3;						//map image (all 3 layers)
	this->imageCount += control.playerCount;	//check player count
	//this->imageCount += this->blockSize;		//check material count
	this->imageCount += 0;						//check event image count
	this->image = new Image[this->imageCount];	//create all image image

	//load image for material
	int offset = 3 + control.playerCount;
	/*
	for (int index = 0; index < this->blockSize;index++) {
		string &material = this->materialList[index];
		this->image[offset + index].setImage(material);
		this->image[offset + index].setVisiable(false);
		//this->image[offset + index].setPosition(SCREEN_LEFT, SCREEN_TOP);
	}
	*/
	//==================================================
	// GAME DEMO
	//==================================================
	// create demo map
	this->image[0].setImage("map_A.bmp");
	this->image[0].setPosition(SCREEN_LEFT, SCREEN_TOP);
	// create actor
	this->image[1].setImage("actor/downA.bmp");
	this->image[1].setPosition(SCREEN_LEFT, SCREEN_TOP);
	// create enemy
	this->image[2].setImage("enemy/slmA.bmp");
	this->image[2].setPosition(SCREEN_LEFT + 32, SCREEN_TOP);
	//==================================================
	//draw map
	//this->drawMap();
}

int Map::getWidth() {
	return this->width;
}
int Map::getHeight() {
	return this->height;
}
bool Map::getPass(int x, int y) {
	return this->passage[y][x];
}

void Map::resolveBase(string fMapText) {
	string text[6];
	//resolve file text for every "#"
	int unit = 0;
	for (char &c : fMapText)
	{
		if (c == SEPARATE)
			unit++;
		else
			if (c != WINDOW_NEWLINE)
				text[unit] += c;
	}
	this->width		= stoi(text[0], NULL);
	this->height	= stoi(text[1], NULL);
	this->blockSize = stoi(text[2], NULL);
	this->resolveMap(text[3]);
}
void Map::resolveMap(string mapText) {
	//get array for every type of blocks
	this->blockList = new BLOCK[this->blockSize];
	this->materialList = new string[this->blockSize];
	//reset blockSize
	int &materialUnit = this->blockSize = 0;

	int unit = 0;
	string temp;
	for (char &c : mapText)
	{
		if (c == BLOCK_SEPARATE)
		{
			BLOCK &block = this->blockList[unit];
			this->resolveBlock(&block, temp);
			//create material list for used
			if (!this->blockList[unit].name.empty())
			{
				this->materialList[materialUnit] = block.name;
				block.materialId = materialUnit;
				materialUnit++;
			}
			temp.clear();
			unit++;
		}
		else
			if(c != WINDOW_NEWLINE)
				temp += c;
	}

	//create pass map
	this->createPassage();
	this->settingPassage();
}

void Map::createPassage() {
	//for Y coordinate
	this->passage = new bool*[this->height];
	for (int y = 0; y < this->height; y++)
	{
		//for X coordinate
		this->passage[y] = new bool[this->width];
		//initialize
		for (int x = 0; x < this->width; x++)
			this->passage[y][x] = true;
	}
}
void Map::settingPassage() {
	//setting passage
	int unit = 0;
	int saveCount = this->blockList[unit].count;
	for (int z = 0; z < 3; z++)
	for (int y = 0; y < this->height; y++)
	for (int x = 0; x < this->width; x++)
	{
		BLOCK &block = this->blockList[unit];
		if (block.count > 0)
		{
			this->passage[y][x] &= block.pass;
			block.count--;
		}
		else {
			this->blockList[unit].count = saveCount;
			unit++;
		}
	}
}

void Map::resolveBlock(BLOCK* block, string origin) {
	string temp;
	int size = origin.length();
	for (int index = 0; index < size; index++)
	{
		char c = origin[index];
		switch (c)
		{
		case COUNT_SIGN:
			(*block).count = stoi(temp, NULL);
			temp.clear();
			break;
		case BLOCK_SIGN:
			(*block).name = temp;
			temp.clear();
			break;
		case INDEX_SIGN:
			(*block).index = stoi(temp, NULL);
			temp.clear();
			break;
		case PASS_SIGN:
			(*block).pass = (stoi(temp, NULL) == 1 ? true : false);
			temp.clear();
			break;
		case LAYER_SIGN:
			(*block).layer = stoi(temp, NULL);
			temp.clear();
			break;
		default:
			temp += c;
			break;
		}
	}
}

void Map::drawMap() {
	int offset = control.playerCount + 3;
	RECT rect;
	for (int layer = 0; layer < 1; layer++)
	{
		Image &map = this->image[control.playerCount + layer];
		map.setName("map");
		map.createImage(this->width*BLOCK_SIZE, this->height*BLOCK_SIZE);
		map.setPosition(SCREEN_LEFT, SCREEN_TOP);

		//draw map
		int unit = 0;
		int saveCount = this->blockList[unit].count;
		for (int y = 0; y < this->height; y++)
		for (int x = 0; x < this->width; x++)
		{
			BLOCK &block = this->blockList[unit];
			if (block.count > 0)
			{
				if(!block.name.empty())
				{
					Image &material = this->image[block.materialId + offset];
					rect.left = (block.index % (material.getWidth() / BLOCK_SIZE)) * BLOCK_SIZE;
					rect.top = (block.index / (material.getWidth() / BLOCK_SIZE)) * BLOCK_SIZE;
					rect.right = rect.left + BLOCK_SIZE;
					rect.bottom = rect.top + BLOCK_SIZE;
					map.cpoyImage(graphics.hwnd, &material, rect, x*BLOCK_SIZE , y*BLOCK_SIZE);
					block.count--;
				}
			}
			else 
			{
				block.count = saveCount;
				unit++;
			}
		}
	}
}

void Map::update() {

}

void Map::longUpdate() {

}