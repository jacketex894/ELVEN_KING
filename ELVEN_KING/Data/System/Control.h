#pragma once
#include <Windows.h>
#define VK_ENTER VK_RETURN

class Control {
    public:
		WPARAM key;
		short int playerCount = 1;
		int money = 0;
};