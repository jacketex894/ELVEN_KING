#pragma once
#include <fstream>
#include <string>
#include "Debug.h"

#define FILE_DEFAULT ios::in | ios::out | ios::app

using namespace std;

class File
{
public:
	File(string, string);
	void input(string);
	string output();
	~File();
protected:
	void open();
	fstream file;
	string fFileName;
	string strLocation;
	int iFileSize;
	bool bBinary;
};
