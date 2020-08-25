#include<iostream>
using namespace std;
int main()
{
	string str = "Hello Bit.";

	//Ö±½ÓÊä³ö
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