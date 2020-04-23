#include"ScanManager.h"
#include"Sysutil.cpp"

void ScanManager::ScanDirectory(const string& path)
{
    //1 ɨ�豾���ļ�ϵͳ
    vector<string> local_files;
    vector<string> local_dirs;
    DirectionList(path, local_files,local_dirs);
    set<string> local_set;
    local_set.insert(local_files.begin(), local_files.end());
    local_set.insert(local_dirs.begin(), local_dirs.end());



    //2 ɨ�����ݿ��ļ�ϵͳ
    set<string> db_set;
    m_db.GetDocs(path, db_set);


    //�Աȱ����ļ������ݿ��ļ�

    auto local_it = local_set.begin();
    auto db_it = db_set.begin();

    while (local_it != local_set.end() && db_it != db_set.end())
    {
        if (*local_it < *db_it)
        {
            //������ ���ݿ�û��   ���ݿ�Ҫ����
        }
        else if (*local_it < *db_it)
        {
            //����û�� ���ݿ���   ���ݿ�Ҫɾ��

        }
        else
        {
            //���ش��� ���ݿ���ڣ����ݿⲻ��Ҫ�ı�
        }
    }
    while (local_it!=local_set.end())   
    {
        //������ ���ݿ�û��   ���ݿ�Ҫ����
    }
    while (db_it != db_set.end())
    {
        //����û�� ���ݿ���   ���ݿ�Ҫɾ��

    }

    //�ݹ������Ŀ¼

 }
