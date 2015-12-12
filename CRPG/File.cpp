#include "Data\File.h"

File::File(string fFileName)
{
	this->strLocation = FILE_MAP + fFileName;
	this->fFileName = fFileName;
	this->bBinary = false;
	setFileLenght();
}

File::File(string strLocation, string fFileName)
{
	this->strLocation = strLocation + fFileName;
	this->fFileName = fFileName;
	this->bBinary = false;
	setFileLenght();
}

void File::open() {
	if (this->bBinary)
		file.open(strLocation, ios::binary | FILE_DEFAULT);
	else
		file.open(strLocation, FILE_DEFAULT);
	if (!this->file.is_open()) LOG(L"File Open Failed!");
}

void File::setFileLenght() {
	file.open(strLocation, ios::binary | FILE_DEFAULT);
	file.seekg(0, ios::end);
	this->iFileSize = file.tellg();
	file.close();
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
	if (this->file.is_open()) {
		file.seekg(0, ios::beg);
		file.read(cpText, this->iFileSize);
	}
	file.close();
	return cpText;
}

File::~File()
{
	file.close();
}