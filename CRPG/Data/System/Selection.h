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
