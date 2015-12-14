#pragma once
#include <fstream>
#include <string>
#include "Base.h"
#include "Debug.h"

#define FILE_DEFAULT ios::in | ios::out

using namespace std;

class File
{
public:
	File(string);
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
	void setFileLenght();
	bool bBinary;
};
