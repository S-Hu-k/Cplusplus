#include"ScanManager.h"
#include"Sysutil.cpp"

void ScanManager::ScanDirectory(const string& path)
{
    //1 扫描本地文件系统
    vector<string> local_files;
    vector<string> local_dirs;
    DirectionList(path, local_files,local_dirs);
    set<string> local_set;
    local_set.insert(local_files.begin(), local_files.end());
    local_set.insert(local_dirs.begin(), local_dirs.end());



    //2 扫描数据库文件系统
    set<string> db_set;



    //对比本地文件和数据库文件

    auto local_it = local_set.begin();
    auto db_it = db_set.begin();
 }
