#pragma once
#include <iostream>
#include "../Global.h"
#include "../File.h"

using namespace std;

class Map : public Stage
{
public:
	Map(string, string);
	int width;
	int height;
	int* operator[](int);
	void update();
	~Map();
private:
	File* fMap;
	int **iMap;
	void resolveMap();
};

Map::Map(string mapName,string mapBGM) : Stage(mapBGM)
{
	//the map file
	this->fMap = new File(mapName + EXTENSION);
	//create map
	int i;
	this->iMap = new int*[this->height];
	for (i = 0; i < this->height; i++)
		this->iMap[i] = new int[this->width];
	this->resolveMap();
}

int* Map::operator[](int index) {
	return this->iMap[index];
}

void Map::resolveMap() {
	int index, unitCount = 0;
	string fileText = this->fMap->output();
	string fileTextUnit[3] = { "" };
	for (index = 0;
	index < fileText.length() && unitCount < 3;
		index++)
	{
		if (fileText[index] == SEPARATE) {
			unitCount++;
			continue;
		}
		fileTextUnit[unitCount] += fileText[index];
	}
	this->width = stoi(fileTextUnit[0], NULL);
	this->height = stoi(fileTextUnit[1], NULL);
	LOG(fileTextUnit[2]);
}

void Map::update() {

}

Map::~Map()
{
	delete[] this->iMap;
}