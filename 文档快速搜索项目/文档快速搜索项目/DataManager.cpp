#include"DataManager.h"
#include"sysutil.h"
#include"ScanManager.h"

SqliteManager::SqliteManager():m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	Close();
}
void SqliteManager::Open(const string &path)
{
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
void SqliteManager::Close()
{
	if (m_db)
	{
		int rc = sqlite3_close(m_db);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Close database failed:%s\n", sqlite3_errmsg(m_db));
		}
		else
		{
			fprintf(stderr, "Close  database successfully\n");
		}
	}
}
void SqliteManager::ExecuteSql(const string sql)
{
	char* zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		//fprintf(stderr, "SQL(%s) error: %s\n", sql.c_str(),zErrMsg);
		ERROR_LOG("SQL(%s) error: %s", sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "SQL(%s) Execute successfully.\n", sql.c_str());
		TRACE_LOG("SQL(%s) Execute successfully.", sql.c_str());
	}

}
void SqliteManager::GetResultTable(const string sql,int &row,int &col,char **&ppRet)
{
	char* zErrMsg = 0;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stdout, "GetResult failed:%s\n", zErrMsg);
	}
	else



	{
		//fprintf(stdout, "GetResult successfully.\n", zErrMsg);
		fprintf(stdout, "Get Result Table successfully.\n", zErrMsg);

	}

}
////////////////////////////////////////////////////////////////////////////
AutoGetResultTabes::AutoGetResultTabes(SqliteManager* db, const string& sql, int& row, int& col, char**& ppRet):m_db(db)
	{
	m_db->GetResultTable(sql,row,col,ppRet);
	m_ppRet = ppRet;

}
AutoGetResultTabes::~AutoGetResultTabes()
{
	if (m_ppRet)
		sqlite3_free_table(m_ppRet);

}




////////////////////////////////////////////////////////////////////////////
DataManager::DataManager()
{
	m_dbmgr.Open(DOC_DB);
}
DataManager::~DataManager()
{

}
void DataManager::InitSqlite()
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "create table if not exists %s(id integer primary key autoincrement, doc_name text, doc_path text, doc_pinyin text, doc_initials text)",
		DOC_TABLE);
	m_dbmgr.ExecuteSql(sql);
}
void DataManager::InsertDoc(const string& path, const string& doc)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "insert into % s values(null, '%s', '%s', '%s', '%s')",
		DOC_TABLE, doc.c_str(), path.c_str()); //, pinyin.c_str(), initials.c_str()
	m_dbmgr.ExecuteSql(sql);
}
void DataManager::GetDocs(const string& path,  set<string>& docs)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "select doc_name from %s where doc_path='%s'", DOC_TABLE, path.c_str());

	int row = 0, col = 0;
	char** ppRet = 0;
	//m_dbmgr.GetResultTable(sql, row, col, ppRet);
	AutoGetResultTable at(&m_dbmgr, sql, row, col, ppRet);

	for (int i = 1; i <= row; ++i)
		docs.insert(ppRet[i]);
		
	//释放结果表
	//sqlite3_free_table(ppRet); 
	//m_dbmgr.FreeResultTable(ppRet);
}
void DataManager::DeleteDoc(const string& path, const string& docs)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "delete from %s where doc_name='%s' and doc_path='%s'", DOC_TABLE, doc.c_str(), path.c_str());
	m_dbmgr.ExecuteSql(sql);

	/////////////////////////
	//级联删除目录下的子文件
	string doc_path = path;
	doc_path += "\\";
	doc_path += doc;
	memset(sql, 0, SQL_BUFFER_SIZE);
	sprintf(sql, "delete from %s where doc_path like '%s%%'", DOC_TABLE, doc_path.c_str());
	m_dbmgr.ExecuteSql(sql);
}




/////////////////////////////////////////////////////////////////
void DataManager::Search(const string& key, vector<pair<string, string>>&doc_path)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "select doc_name,doc_path from %s where doc_name like '%%%s%%'", DOC_TABLE, key.c_str());
	int row = 0, col = 0;
	char** ppRet = nullptr;
	//m_dbmgr.GetResultTable(sql,row,col,ppRet);
	AutoGetResultTabes at(&m_dbmgr,sql,row,col,ppRet);

	doc_path.clear();

	for (int i = 1; i < row; ++i)
		doc_path.push_back(ppRet[i * col], ppRet[i * col + 1]);

	//sqlite3_free_table(ppRet);

}