#include "System\File.h"

File::File(string strLocation, string fFileName)
{
	this->strLocation = strLocation + fFileName;
	this->iFileSize = file.tellg();
	this->fFileName = fFileName;
	this->bBinary = false;
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