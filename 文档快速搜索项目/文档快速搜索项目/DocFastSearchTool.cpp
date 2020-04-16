#include"common.h"
#include"sysutil.h"
#include"./sqlite/sqlite3.h"

#pragma comment(lib,"./sqlite/sqlite3.lib")
void Test_DirectionList()
{
	const string& path = "D:\\QQMusicCache";
	vector<string> subfile;
	vector<string> subdir;
	DirectionList(path, subfile, subdir);

	for (const auto& e : subfile)
		cout << e << endl;
	for (const auto& e : subdir)
		cout << e << endl;
}


static int callback(void* data, int argc, char** argv, char** azColName) 
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i < argc; i++) 
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}


void Test_Sqlite()
{
	//数据打开
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");

	//操作数据库
	string sql = "select * from my_tb";
	char** result;
	int row;
	int col;
	char* zErrMsg = 0;

	sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &zErrMsg);

	for (int i = 1; i <= row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			//cout<<*((result+(i*col)+j))<<"  ";
			printf("%-5s", *(result + (i * col) + j));

		}
		cout << endl;
	}
	//cout<<endl;

	sqlite3_free_table(result);
	//关闭数据库
	sqlite3_close(db);
}
int main(int argc, char* argv[])
{
	//Test_DirectionList();
	Test_Sqlite();
	//Test_SqliteManager();
	//Test_Log();
	//Test_Set();
	//Test_Map();
	//Test_Scan();
	return 0;
}
/*
void Test_Seqlite()
{
	sqlite3* db;
	int rc = sqlite3_open("test.db",& db);
	if (rc != SQLITE_OK)
	{
		printf("Opened database dafiled\n");
	}
	else
		printf("Opened database successfully\n");

	//操作数据库
	string sql = "select id, name, path from my_tb where id=2";
	//string sql = "create table you_tb(id int,name varchar(20),path varchar(100))";
	sqlite3_exec(db, sql.c_str(),0, 0, 0);
	char* zErrMsg = 0;
	const char* data = "Callback function called";
	//sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)；
	//string sql = "create table you_tb(id int, name varchar(20), path varchar(100))";
	//string sql = "insert into you_tb values(1, 'abc', 'c:\\')";
	
	//rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "Table created successfully\n");
		//fprintf(stdout, "Insert Data successfully\n");
		fprintf(stdout, "Select Data successfully\n");
	}
	sqlite3_close(db);
}
int main(int argc, char* argv[])
{
	//Test_DirectionList();
	return 0;
}
/*
void Test_Seqlite()
{
		sqlite3* db;
		char* zErrMsg = 0;
		int rc;

		rc = sqlite3_open("test.db", &db);

		if (rc)  {
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			exit(0);
		}
		else {
			fprintf(stderr, "Opened database successfully\n");
		}
		sqlite3_close(db);
}
int main(int argc, char* argv[])
{
	//Test_DirectionList();
	return 0;
}*/