#include<iostream>
#include<string>
using namespace std;
void main()
{
	string str1 = "sgggggggggg";
	string str2 = "sam,cm;asc';";
	bool ret = (str1 > str2);
	cout << "ret=" << ret << endl;

}
	/*
	string str3 = str1 + str2;
	cout << str3 << endl;
	string str4;
	cout << "请输入：>";
	getline(cin, str4);
	cout << "str4" << str4 << endl;
	
}*/
/*
void main()
{
	string email = "2096136603@qq.com4566256";
	size_t pos = email.find("q", 2);
	if (pos != string::npos)
		cout << "pos=" << pos << endl;
	else
		cout << "no find" << endl;
}





void main()
{
	string str = "shcjsalcksa";
	int len = strlen(str.c_str());
	cout << "len =" << len << endl;

}


void main()
{
	string path = "C:";
	path += "\\";
	path += "c++";
	path += "\\";
	path += "kugou";
	cout << path << endl;
}
}




/*
void main()
{
	char* s = "dsssa";
	string str;
	while (*s != "\0")
	{
		str.push_back(*s);
		s++;
	}
	cout << str << endl;

}


/*
void main()
{
	string str = "hello bit";
	cout << "str =" << str << endl;

	for (int i = 0; i < str.size(); ++i)
		cout  << str[i];
	cout << endl;

	//c++11
	for (auto& ele : str)
		cout << ele;
	cout << endl;

	//迭代器 iterator
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}


/*
int main()
{
	string s1 = "hello world";
	string s2 = "change world";
	string::iterator it = s1.begin();
	swap(s1, s2);
	while (it != s1.end())
		cout << *it;
	cout << endl;
}
	/*string str = "Hello Bit.";
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it != ' ')
			cout << *it;
		else
			str.erase(it);
		it++;
	}*/
/*

	/*string str("Hello Bit.");
	str.reserve(111);
	str.resize(5);
	str.reserve(50);
	cout << str.size() << ":" << str.capacity() << endl;
	return 0;*/
/*
int main(int argc, char* argv[])
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
	int size_prev_pos = 0;
	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
		size_prev_pos = ++size_pos;
	}
	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
	}
	cout << endl;
	return 0;
}

/*
int main(int argc, char* argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;
}


/*
int main()
{
	string str = "hello bit";

	cout << "str = "<<str.size() << endl;
	for (int i = 0; i < str.size(); ++i)
		cout << str[i];
	cout << endl;


	for (auto& ele : str)
		cout << ele;
	cout << endl;

	//迭代器 iterator

	//string str1 += "haha";
	//cout << "str1 = " << str1.size() << endl;
}*/