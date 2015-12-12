#pragma once
class Map
{
public:
	Map(int,int);
	int* operator[](int);
	~Map();
private:
	int iWidth;
	int iHeight;
	int **iMap;
};