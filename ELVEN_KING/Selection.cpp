#include "Data\System\Selection.h"

Selection::Selection(int count) {
	this->index = 0;
	this->cycle = false;
	this->count = count;
	this->options = new string[count];
}

short int Selection::getIndex() {
	return this->index;
}

string Selection::getValue() {
	return this->options[this->index];
}

void Selection::addOption(int index, string option) {
	this->options[index] = option;
}

void Selection::nextIndex() {
	if (this->index >= (this->count - 1))
	{
		if (this->cycle)
			this->index = 0;
		else
			this->index = (this->count - 1);
	}
	else
	{
		this->index += 1;
	}
}

void Selection::previousIndex() {
	if (this->index <= 0)
	{
		if (this->cycle) 
			this->index = (this->count - 1);
		else 
			this->index = 0;
	}
	else
	{
		this->index -= 1;
	}
}

void Selection::setCycle(bool cycle) {
	this->cycle = cycle;
}