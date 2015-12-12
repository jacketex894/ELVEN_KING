#pragma once
#include <iostream>
#include "File.h"

#define SEPARATE	'#'
#define EXTENSION	".map"

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