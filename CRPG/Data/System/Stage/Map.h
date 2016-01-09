#pragma once
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
};

class Map : public Stage
{
public:
	Map(string, string);
	int getWidth();
	int getHeight();
	BLOCK getBlock(int,int,int);
	void update();
private:
	File* fMap;
	BLOCK ***block;
	int width;
	int height;
	void resolveMap();
	void resolveBlock(BLOCK*,string);
};

Map::Map(string mapName,string mapBGM) : Stage(mapBGM)
{
	//the map file
	this->fMap = new File(mapName + EXTENSION);
	this->resolveMap();
}

void Map::resolveMap() {
	string fileText = this->fMap->output();
	string fileTextUnit[3] = { "" };
	int index;
	int size = fileText.length();
	int unitCount = 0;
	int blockSize = 0;

	//resolve map unit
	for (index = 0; index < size && unitCount < 3; index++)
	{
		if (fileText[index] == SEPARATE) {
			unitCount++;
			continue;
		}
		if (fileText[index] == BLOCK_SEPARATE)
			blockSize++;
		fileTextUnit[unitCount] += fileText[index];
	}
	this->width = stoi(fileTextUnit[0], NULL);
	this->height = stoi(fileTextUnit[1], NULL);

	//split block text
	blockSize += 1;
	BLOCK *block = new BLOCK[blockSize];
	size = fileTextUnit[2].length();
	unitCount = 0;
	string tempOrigin;
	for (index = 0; index < size; index++)
	{
		char temp = fileTextUnit[2][index];
		if (temp == BLOCK_SEPARATE)
		{
			//resolve block
			this->resolveBlock(&block[unitCount],tempOrigin);
			unitCount++;
		}
		else
		{
			if (temp == WINDOW_NEWLINE)
				continue;
			else
				tempOrigin += temp;
		}
	}
	
	//create map
	int x, y, z;

	this->block = new BLOCK**[3];
	for (index = 0; index < 3; index++)
		this->block[index] = new BLOCK*[this->height];
	for (index = 0; index < this->height; index++)
	{
		//set every layers
		this->block[0][index] = new BLOCK[this->width];
		this->block[1][index] = new BLOCK[this->width];
		this->block[2][index] = new BLOCK[this->width];
	}

	x = y = z = 0;
	unitCount = 0;
	for (z = 0; z < 3; z++)
		for (y = 0; y < this->height; y++)
			for (x = 0; x < this->width; x++)
			{
				if (block[unitCount].count > 0)
				{
					this->block[z][y][x] = block[unitCount];
					this->block[z][y][x].count = 1;
					block[unitCount].count--;
				}
				else {
					unitCount++;
				}
			}
}

void Map::resolveBlock(BLOCK* block,string origin) {
	int index;
	int size = origin.length();

	bool nameSaving = false;
	string temp;
	for (index = 0; index < size; index++)
	{
		char c = origin[index];
		if (nameSaving) {
			if (c == NAME_SIGN)
				nameSaving = false;
			else
				temp += c;
			continue;
		}
		switch (c)
		{
		case COUNT_SIGN:
			(*block).count = stoi(temp, NULL);
			temp = "";
			break;
		case BLOCK_SIGN:
			break;
		case NAME_SIGN:
			nameSaving = true;
			break;
		case INDEX_SIGN:
			(*block).name = temp;
			temp = "";
			break;
		case PASS_SIGN:
			(*block).index = stoi(temp, NULL);
			temp = "";
			break;
		case LAYER_SIGN:
			(*block).pass = (stoi(temp, NULL) == 1 ? true : false);
			temp = "";
			break;
		default:
			temp += c;
			break;
		}
	}
	(*block).layer = stoi(temp, NULL);
}

int Map::getWidth() {
	return this->width;
}

int Map::getHeight() {
	return this->height;
}

BLOCK Map::getBlock(int x, int y, int z) {
	return this->block[z][y][x];
}

void Map::update() {
	this->getBlock(0, 0, 0);
}