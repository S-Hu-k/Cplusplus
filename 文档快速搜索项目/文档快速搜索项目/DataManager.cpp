#include"DataManager.h"

SqliteManager::SqliteManager()
{
}
SqliteManager::~SqliteManager()
{
}
void Open(const string &path)
{
	sqlite3* m_db;
	char* zErrMsg = 0;
	int rc;
	rc = sqlite3_open(path.c_str(), &m_db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
		//ERROR_LOG("Can't open database: %s", sqlite3_errmsg(m_db));
		exit(0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
		//TRACE_LOG("Opened database successfully.");
	}
}
void Close()
{
	sqlite3* m_db;

	if (m_db)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
		//ERROR_LOG("Can't open database: %s", sqlite3_errmsg(m_db));
		exit(0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
		//TRACE_LOG("Opened database successfully.");
	}
}
void ExecuteSql(const string sql)
{

}
void GetResultTable(const string sql,int &row,int &col,int **&ppRet)
{

}