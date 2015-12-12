#include "Data\Map.h"
Map::Map(int widht, int height)
{
	//setting
	this->iWidth = widht;
	this->iHeight = height;
	//create map
	int i,j;
	this->iMap = new int*[this->iHeight];
	for (i = 0; i < this->iHeight; i++)
		this->iMap[i] = new int[this->iWidth];
}

int* Map::operator[](int index) {
	return this->iMap[index];
}

Map::~Map()
{
	int i;
	for (i = 0; i < this->iHeight; i++)
		delete this->iMap[i];
	delete this->iMap;
}