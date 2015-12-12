#pragma once
class Map
{
public:
	Map(int,int);
	~Map();
private:
	int siWidth;
	int siHeight;
	int **sipMap;
};