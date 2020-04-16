#pragma once

#include"common.h"

class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);
	void Close();
	void ExecuteSql(const string sql);
	void GetResultTable(const string sql, int& row, int& col, char **& ppRet);

private:
	sqlite3 *m_db;
};
