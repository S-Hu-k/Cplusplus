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
    multiset<string> db_set;
    m_db.GetDocs(path, db_set);

     
    //�Աȱ����ļ������ݿ��ļ�

    auto local_it = local_set.begin();
    auto db_it = db_set.begin();

    while (local_it != local_set.end() && db_it != db_set.end())
    {
        if (*local_it < *db_it)
        {
            //������ ���ݿ�û��   ���ݿ�Ҫ����
            m_db.InsertDoc(path, *local_it);
            local_it++;
        }
        else if (*local_it < *db_it)
        {
            //����û�� ���ݿ���   ���ݿ�Ҫɾ��
            m_db.DeleteDoc(path, *db_it);
            db_it++;


        }
        else
        {
            //���ش��� ���ݿ���ڣ����ݿⲻ��Ҫ�ı�
            local_it++;
            db_it++;
        }
    }
    while (local_it!=local_set.end())   
    {
        //������ ���ݿ�û��   ���ݿ�Ҫ����
        m_db.InsertDoc(path, *local_it);
        local_it++;
    }
    while (db_it != db_set.end())
    {
        //����û�� ���ݿ���   ���ݿ�Ҫɾ��
        m_db.DeleteDoc(path, *db_it);
        db_it++;

    }

    //�ݹ������Ŀ¼

 }
