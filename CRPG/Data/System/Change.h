#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


string WcS(wstring load ) // wchar→string  load為資料庫所讀出的資料
{
string Data;
wstring ws(load);   
string Data(ws.begin(), ws.end());
return  Data;
}

int WcI(wstring load) // wchar→int
{
int iData;
iData = atoi(WcS(load).c_str());
return  iData;
}

wchar_t ScW(string msg)//string→wchar
{
wchar_t str[256];
wsprintfW(str,L"%hs",msg.c_str());
return str[256];
}

wchar_t ScW(int msg)//int→wchar
{
wchar_t str[256];
wsprintfW(str, L"%d", msg);
return str[256];
}

