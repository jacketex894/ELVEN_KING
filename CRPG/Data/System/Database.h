#pragma once
#include <iostream>
#include "Debug.h"
#include "Sqlite\sqlite3.h"

using namespace std;

#define DATABASE_NAME		"Database.db"
#define DATABASE_ADDRESS	"../CRPG/Data/System/"

int sqlCallback(void*, int, char**, char**);

class Database
{
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