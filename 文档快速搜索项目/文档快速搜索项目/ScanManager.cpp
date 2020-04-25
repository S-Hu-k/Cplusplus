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
    multiset<string> db_set;
    m_db.GetDocs(path, db_set);

     
    //对比本地文件和数据库文件

    auto local_it = local_set.begin();
    auto db_it = db_set.begin();

    while (local_it != local_set.end() && db_it != db_set.end())
    {
        if (*local_it < *db_it)
        {
            //本地有 数据库没有   数据库要增加
            m_db.InsertDoc(path, *local_it);
            local_it++;
        }
        else if (*local_it < *db_it)
        {
            //本地没有 数据库有   数据库要删除
            m_db.DeleteDoc(path, *db_it);
            db_it++;


        }
        else
        {
            //本地存在 数据库存在，数据库不需要改变
            local_it++;
            db_it++;
        }
    }
    while (local_it!=local_set.end())   
    {
        //本地有 数据库没有   数据库要增加
        m_db.InsertDoc(path, *local_it);
        local_it++;
    }
    while (db_it != db_set.end())
    {
        //本地没有 数据库有   数据库要删除
        m_db.DeleteDoc(path, *db_it);
        db_it++;

    }

    //递归遍历子目录

 }
