#include "Data\Map.h"

Map::Map(string mapName)
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

void Map::resolveMap(){
	int index,unitCount = 0;
	string fileText = this->fMap->output();
	string fileTextUnit[3] = {""};
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
	//work break
	/*
	LOG(fileTextUnit[0]);
	LOG(fileTextUnit[1]);
	LOG(fileTextUnit[2]);
	*/
}

Map::~Map()
{
	delete[] this->iMap;
}