#include"ScanManager.h"
#include"Sysutil.cpp"

void ScanManager::ScanDirectory(const string& path)
{
    //1 ɨ�豾���ļ�ϵͳ
    vector<string> local_files;
    vector<string> local_dirs;
    DirectionList(path, local_files,local_dirs);

    //2 ɨ�����ݿ��ļ�ϵͳ

    //�Աȱ����ļ������ݿ��ļ�
 }
