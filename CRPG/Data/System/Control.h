#pragma once
#include <Windows.h>

class Control {
    private:
        bool bBusy;
        WPARAM wParam;
    public:
        void setControl(WPARAM);
};

void Control::setControl(WPARAM wParam) {
}