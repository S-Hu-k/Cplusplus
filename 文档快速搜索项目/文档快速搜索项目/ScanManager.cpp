#include"ScanManager.h"
#include"Sysutil.cpp"

void ScanManager::ScanDirectory(const string& path)
{
    //1 扫描本地文件系统
    vector<string> local_files;
    vector<string> local_dirs;
    DirectionList(path, local_files,local_dirs);

    //2 扫描数据库文件系统

    //对比本地文件和数据库文件
 }
