#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

// wstring¡÷string
string wStrToStr(wstring data)
{
	string str(data.begin(), data.end());
	return str;
}

// wstring¡÷int
int wStrToInt(wstring data)
{
	int iData = atoi(wStrToStr(data).c_str());
	return  iData;
}

// string¡÷wchar
wchar_t strToWChar(string data)
{
	wchar_t wstr[256];
	wsprintfW(wstr,L"%hs", data.c_str());
	return wstr[256];
}

// int¡÷wchar
wchar_t intToWChar(int data)
{
	wchar_t wstr[256];
	wsprintfW(wstr, L"%d", data);
	return wstr[256];
}

