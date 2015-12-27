#pragma once
#include <iostream>
#include "Base.h"
#include "File.h"

using namespace std;

class Map
{
public:
	Map(string);
	int width;
	int height;
	int* operator[](int);
	~Map();
private:
	File* fMap;
	int **iMap;
	void resolveMap();
};