
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
	void FreeResultTable(char** ppRet)
	{
		sqlite3_free_table(ppRet);
	}
private:
	sqlite3 *m_db;


};

/////////////////////////////////////////////////////////////////////

class AutoGetResultTabes
{
public:
	AutoGetResultTabes(SqliteManager *db,const string&sql,int &row,int &col, char**& ppRet);
	~AutoGetResultTabes();
public:
	//C++11
	AutoGetResultTabes(const AutoGetResultTabes&) = delete;
	AutoGetResultTabes& operator=(const AutoGetResultTabes&) = delete;


private:
	SqliteManager* m_db;
	char** m_ppRet;
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
public:
	void Search(const string& key, vector<pair<string, string>>&doc_path);
private:
	SqliteManager m_dbmgr;
};

























