#include"common.h"
#include"sysutil.h"

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

int main(int argc, char* argv[])
{
	Test_DirectionList();
	return 0;
}