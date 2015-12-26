#pragma once
#include <Windows.h>

class Control {
    public:
		WPARAM wParam;
		bool inputKey(int);
};

bool Control::inputKey(int input) {
	return (this->wParam == input);
};