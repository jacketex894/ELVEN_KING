#include "Data\System\Debug.h"

//Debug Log Function
void LOG(LPCWSTR msg) {
	MessageBox(NULL, msg, L"DEBUG", MB_OK);
}
void LOG(string msg) {
	wchar_t str[256];
	wsprintfW(str, L"%hs", msg.c_str());
	LOG(str);
}
void LOG(const char* msg) {
	wchar_t str[256];
	wsprintfW(str, L"%hs", msg);
	LOG(str);
}
void LOG(int msg) {
	wchar_t str[256];
	wsprintfW(str, L"%d", msg);
	LOG(str);
}