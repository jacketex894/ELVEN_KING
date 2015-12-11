#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

//System Base Data
#define CLASSNAME		L"Main"
#define WINDOWNAME		L"TAIWAN NO.1"
#define LOG_TITLE		L"DEBUG"
#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

//Source Folder 
#define FILE_MAP		"./Data/Map/"

//Debug Log Function
void LOG(LPCWSTR msg) {
	MessageBox(NULL, msg, LOG_TITLE, MB_OK);
}
void LOG(string msg) {
	wchar_t str[256];
	wsprintfW(str, L"%hs", msg.c_str());
	MessageBox(NULL, str, LOG_TITLE, MB_OK);
}
void LOG(int msg) {
	wchar_t str[256];
	wsprintfW(str,L"%d",msg);
	MessageBox(NULL, str, LOG_TITLE, MB_OK);
}

