#pragma once
#include <iostream>
#include "Base.h"
#include "Debug.h"
#include "Sqlite\sqlite3.h"

using namespace std;

int sqlCallback(void*, int, char**, char**);

class Database {
public:
	Database(string);
	void sql(string);
	wchar_t** message;
private:
	void openDatabase();
	inline void checkDatabase();
	sqlite3 *dbHandle;
	string dbLocation;
	int state;
};