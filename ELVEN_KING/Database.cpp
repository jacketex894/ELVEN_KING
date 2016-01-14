#include "Data\System\Database.h"

Database::Database(string dbName)
{
	this->dbLocation = DATABASE_ADDRESS + dbName;
}

void Database::openDatabase() {
	this->state = sqlite3_open_v2(this->dbLocation.c_str(), &this->dbHandle, SQLITE_OPEN_READWRITE, NULL);
	this->checkDatabase();
}

inline void Database::checkDatabase() {
	if (this->state != SQLITE_OK) LOG(sqlite3_errmsg(this->dbHandle));
}

void Database::sql(string sql)
{
	//initialize
	char *errMsg = "";
	//open database and use SQL
	this->openDatabase();
	int(*callback)(void*, int, char**, char**) = &sqlCallback;
	this->state = sqlite3_exec(this->dbHandle, sql.c_str(), callback, this, &errMsg);
	this->checkDatabase();
	sqlite3_close(this->dbHandle);
}

int sqlCallback(void* exec, int columnCount, char** data, char** dataName) {
	int index;
	((Database*)exec)->message = new wchar_t*[columnCount];
	for (index = 0; index < columnCount; index++)
	{
		int size = MultiByteToWideChar(CP_UTF8, 0, ((string)data[index]).c_str(), -1, NULL, 0);
		((Database*)exec)->message[index] = new wchar_t[size + 1];
		MultiByteToWideChar(CP_UTF8, 0, ((string)data[index]).c_str(), -1, ((Database*)exec)->message[index], size);
	}
	return 0;
}