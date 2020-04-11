#include"sysutil.h"

void DirectionList(const string& path, vector<string>& subfile, vector<string>& subdir)
{
	string _path = path;
	_path += "\\*.*";

	_finddata_t file;
   long handel= _findfirst(_path.c_str(), &file);//搜索path路径下的第一个文件
   if (handel == -1)
   {
       perror("_findfirst");
       return;
   }

   do
   {
      // if (file.name[0] == '.')
       if(strcmp(file.name,".")==0|| strcmp(file.name, "..") == 0)
           continue;

       if (file.attrib & _A_SUBDIR)//说明是一个目录
       {
           //cout << file.name << endl;
          // string tmp_path = path;
          // tmp_path += "\\";
          // tmp_path += file.name;
          // DirectionList(tmp_path);
           subdir.push_back(file.name);

       }
       else
           //cout << file.name << endl;
           subfile.push_back(file.name);

   } while (_findnext(handel, &file) == 0);
   

   _findclose(handel);
}