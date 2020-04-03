#include<iostream>
#include<string>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& out, const String& s);
	friend istream& operator>>(istream& in, String& s);
public:
	String(const char* str = "")
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	String(const String& s)
	{
		m_str = new char[strlen(s.m_str) + 1];
		strcpy(m_str, s.m_str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[]m_str;
			m_str = new char[strlen(s.m_str) + 1];
		strcpy(m_str, s.m_str);
	}

		return *this;
	}
	~String()
	{
		if (m_str)
		{
			delete[]m_str;
			m_str = nullptr;
		}
	}
private:
	char* m_str;
};

ostream& operator<<(ostream& out, const String& s)
{
	out << s.m_str;
	return out;
}
istream& operator>>(istream& in, String& s)
{
	char buf[500] = { 0 };  //
	//自动增长
	//in>>buf; //101
	//赋值 s.m_str
	return in;
}
void main()
{
	String s;
	//cin>>s;
	cout << "s = " << s << endl;
	string s1;
	cin >> s1;
}
//字符串最后一个单词的长度
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	size_t pos = str.rfind(' ');
//	if (pos == string::npos)
//		printf("%d", str.size());
//	else
//		printf("%d", str.size() - pos - 1);
//	return 0;
//}


//字符串中唯一一个字符
//1.
//class Solution {
//public:
//	int firstUniqChar(string s)
//	{
//		for (int i = 0; i < s.size(); ++i)
//		{
//			int index_1 = s.find(s[i]);
//			int index_2 = s.rfind(s[i]);
//			if (index_1 == index_2)
//				return i;
//		}
//		return -1;
//
//	}
//}
//2.class Solution {
//public:
//	int firstUniqChar(string s)
//	{
//		int count[256] = { 0 };
//		for (int i = 0; i < s.size(); ++i)
//		{
//			count[s[i]] += 1;
//		}
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (1 == count[s[i]])
//				return i;
//		}
//		return -1;
//	}
//};



//反转字符串

//#include<iostream>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		reverse(s.begin(), s.end());
//	}
//};

/*
int main()
{
	//find_first_not_of 在str中找出第一个不是size_t中的字母
	std::string str("look for non-alphabetic characters...");

	std::size_t found = str.find_first_not_of("lk");

	if (found != std::string::npos)
	{
		std::cout << "The first non-alphabetic character is " << str[found];
		std::cout << " at position " << found << '\n';
	}

	return 0;
}

void main()
{
	             //string (1)
                //          size_t find_first_of (const string& str, size_t pos = 0) const;
                //    c-string (2)
                //          size_t find_first_of (const char* s, size_t pos = 0) const;
                //    buffer (3)
                //          size_t find_first_of (const char* s, size_t pos, size_t n) const;
                //    character (4)
                //          size_t find_first_of (char c, size_t pos = 0) const;
 
	string str = "hello bit";

	size_t pos1 = str.find_first_of("pf");
	if (pos1 == string::npos)
	{
		cout << "not find" << endl;
	}
	else
		cout << "pos1=" << pos1 << endl;

	size_t pos2 = str.find_first_of("lksdjsjf");
	if (pos2 == string::npos)
	{
		cout << "not find" << endl;
	}
	else
		cout << "pos2=" << pos2 << endl;

	size_t pos3 = str.find_first_of("pf",2);
	if (pos3 == string::npos)
	{
		cout << "not find" << endl;
	}
	else
		cout << "pos3=" << pos3 << endl;
}

void main()
{
	string str = "hello bit";

	//iterator  正向迭代器
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	//反向迭代器 
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
}*/