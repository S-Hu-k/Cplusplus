#include"common.h"
#include"sysutil.h"
#include"./sqlite/sqlite3.h"

#pragma comment(lib,"./sqlite/sqlite3.lib")
void Test_DirectionList()
{
	const string& path = "D:\\QQMusicCache";
	vector<string> subfile;
	vector<string> subdir;
	DirectionList(path,subfile,subdir);

	for (const auto& e : subfile)
		cout << e << endl;
	for (const auto& e : subdir)
		cout << e << endl;


}
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

	//²Ù×÷Êý¾Ý¿â
	string sql = "create table you_tb(id int,name varchar(20),path varchar(100))";
	sqlite3_exec(db, sql.c_str(),0, 0, 0);
	char* zErrMsg = 0;
	const char* data = "Callback function called";
	//sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)£»
	//string sql = "create table you_tb(id int, name varchar(20), path varchar(100))";
	//string sql = "insert into you_tb values(1, 'abc', 'c:\\')";
	string sql = "select id, name, path from my_tb where id=2";
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