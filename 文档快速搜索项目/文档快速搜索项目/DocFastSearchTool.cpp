#include"common.h"
#include"sysutil.h"
#include"sqlite3.h"
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
		char* zErrMsg = 0;
		int rc;

		rc = sqlite3_open("test.db", &db);

		if (rc) {
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
}