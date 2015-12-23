#pragma once
#include <iostream>

using namespace std;

class Selection {
	public:
		Selection(string*,bool);
		short int getIndex();
		string getValue();
		void nextIndex();
		void previousIndex();
	private:
		bool cycle;
		short int index;
		string *options;
};

Selection::Selection(string* options, bool cycle = false) {
	this->index = 0;
	this->cycle = cycle;
	this->options = options;
}

short int Selection::getIndex() {
	return this->index;
}

string Selection::getValue() {
	return this->options[this->index];
}

void Selection::nextIndex() {
	if (this->index >= sizeof(this->options)-1)
		if (this->cycle) this->index = 0;
		else this->index = sizeof(this->options);
	else
		this->index += 1;
}

void Selection::previousIndex() {
	if (this->index <= 0)
		if (this->cycle) this->index = 0;
		else this->index = sizeof(this->options);
	else
		this->index += 1;
}

