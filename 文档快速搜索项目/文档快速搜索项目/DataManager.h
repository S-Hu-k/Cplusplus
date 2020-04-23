
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
/////////////////////////////////////////////////////////////////////

#define DOC_DB "doc.db"
#define DOC_TABLE "doc_tb"
//////////////////////////////////////////////////////////////////
class DataManager
{

public:
	void InitSqlite();
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