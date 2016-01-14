#pragma once
#include <iostream>

using namespace std;

class Selection {
	public:
		Selection(int);
		short int getIndex();
		string getValue();
		void addOption(int,string);
		void nextIndex();
		void previousIndex();
		void setCycle(bool);
	private:
		int count;
		bool cycle;
		short int index;
		string *options;
};
