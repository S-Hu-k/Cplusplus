#include<iostream>
#include<string>

using namespace std;


/*
//字符串中第一个唯一字符【https://leetcode-cn.com/problems/first-unique-character-in-a-string/submissions/】
解法一
   int firstUniqChar(string s)
	{
		int count[256]={0};
		for(int i=0;i<s.size();++i)
		{
			count[s[i]]+=1;
		}
		for(int i=0;i<s.size();++i)
		{
			if(count[s[i]]==1)
			return i;
		}
		return -1;
	}
	//解法二
	int firstUniqChar(string s)
	{
		for(int i=0;i<s.size();++i)
		{
			int index1=s.find(s[i]);
			int index2=s.rfind(s[i]);
			if(index1==index2)
			return i;
		}
		return -1;

	}
//仅仅反转字母【https://leetcode-cn.com/problems/reverse-only-letters/】
string reverseOnlyLetters(string S)
{
	int start = 0;
	int end = S.size() - 1;
	while (start < end)
	{
		//查找左边第一个字母
		while (start < end)
		{
			if ((S[start] >= 'a' && S[start] <= 'z')
				|| (S[start] >= 'A' && S[start] <= 'Z'))
				break;
			start++;
		}
		//查找右边第一个字母
		while (start < end)
		{
			if ((S[end] >= 'a' && S[end] <= 'z')
				|| (S[end] >= 'A' && S[end] <= 'Z'))
				break;
			end--;
		}
		if (start < end)
		{
			char tmp = S[start];
			S[start] = S[end];
			S[end] = tmp;
			start++;
			end--;
		}
	}
	return S;
}*/
/*
int main()
{
	string str = "Hello Bit.";
	//直接输出
	cout << str << endl;

	//C++11
	for (auto& e : str)
		cout << e;
	cout << endl;

	//operator[]
	for (int i = 0; i < str.size(); ++i)
		cout << str[i] ;
	cout << endl;

	//string.at()
	for (int i = 0; i < str.size(); ++i)
		cout << str.at(i);
	cout << endl;

	//正向迭代器
	string::iterator  it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	//反向迭代器
	string::reverse_iterator  rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
	//正向迭代器反向输出
	string::iterator it1 = str.end() - 1;
	while (it1 != str.begin())
	{
		cout << *it1;
		--it1;
	}
	cout << *it1;
	cout << endl;
}
/*int main()
{
	string str = "Hello Bit.";

	//直接输出
	cout << str << endl;
	//operator[]
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i];
	}
	cout << endl;
	//C++11
	for (auto& e : str)
	{
		//if(e == 'H')
		//	e = 'h';
		cout << e;
	}
	cout << endl;
	//at()
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i);
	}
	cout << endl;
	//iterator ++ --
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
	//
	string::iterator it1 = str.end() - 1;
	while (it1 != str.begin())
	{
		cout << *it1;
		--it1;
	}
	cout << *it1;
	cout << endl;
}
/*int main()
{
	/*size_t find(const string & str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;*/


	/*string email = "32@c5690203@qq.com";
	string substr("60.c");
	size_t pos = email.find_first_of(substr);
	cout << pos << endl;
}*/
/*
void main()
{
	string email = "36@5690203@qq.com";
	size_t pos = email.find('@', 3);
	cout<<"pos = "<<pos<<endl;
	pos = email.find("569", 4);
	if(pos == string::npos)
		cout<<"find not."<<endl;
	else
		cout<<"pos = "<<pos<<endl;
	string str = "qq";
	pos = email.find(str);
	cout<<"pos = "<<pos<<endl;
}
}*/