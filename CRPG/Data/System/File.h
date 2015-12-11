#pragma once
#include "Base.h"
#include <fstream>
#include <string>
#define FILE_DEFAULT ios::in | ios::out | ios::app

using namespace std;

class File
{
public:
	File(string strLocation, string fFileName);
	void input(string strMessage);
	string output();
	~File();
protected:
	void open();
	fstream file;
	string fFileName;
	string strLocation;
	int iFileSize;
	bool bBinary = false;
};

File::File(string strLocation,string fFileName)
{
	strLocation += fFileName;
	this->strLocation	= strLocation;
	this->iFileSize		= file.tellg();
	this->fFileName		= fFileName;
}

void File::open() {
	if (this->bBinary)
		file.open(strLocation, ios::binary | FILE_DEFAULT);
	else
		file.open(strLocation, FILE_DEFAULT);
	if (!this->file.is_open()) LOG(L"File Open Failed!");
}

void File::input(string strMessage) {
	this->open();
	if (this->file.is_open())
		this->file << strMessage.c_str();
	file.close();
}

string File::output() {
	this->open();
	char *cpText = new char[this->iFileSize];
	if (this->file.is_open()){
		file.seekg(0,ios::beg);
		file.read(cpText, this->iFileSize);
	}
	file.close();
	return cpText;
}

File::~File()
{
	file.close();
}