
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


//////////////////////////////////////////////////////////////////
class DataManager
{

public:
	DataManager();
	~DataManager();
public:
	void InsertDoc(const string& path, const string& doc);
	void GetDocs(const string& path, const set<string>& docs);
	void DeleteDoc(const string& path, const string& doc);

private:
	SqliteManager m_dbmgr;
};