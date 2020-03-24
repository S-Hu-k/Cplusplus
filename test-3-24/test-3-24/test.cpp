#include<iostream>
#include <string>
using namespace std;
int Maxsubstr(string a, string b)
{
	unsigned int start1, start2;
	int count = 0, Max = 0;
	for (unsigned int i = 0; a[i] != '\0'; i++)
	{
		for (unsigned int j = 0; b[j] != '\0'; j++)
		{
			start1 = i;
			start2 = j;
			while (a[start1] == b[start2] && start1 < a.length() && start2 < b.length())
			{
				start1++;
				start2++;
				count++;
			}
			if (count > Max)
			{
				Max = count;
			}
			count = 0;
		}
	}
	return Max;
}

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	//不区分大小写
	for (unsigned int i = 0; i < str1.length(); i++)
	{
		str1[i] = tolower(str1[i]);
	}
	for (unsigned int i = 0; i < str2.length(); i++)
	{
		str2[i] = tolower(str2[i]);
	}
	cout << Maxsubstr(str1, str2) << endl;
}

/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int min = str1.size() > str2.size() ? str2.size():str1.size();
	int count = 0;
	if (str1.size() == 0 || str2.size() == 0)
		return 0;
	else
	{
		if (str1.size() < str2.size())
		{
			for (int i = 0; i < min; ++i)
			{
				for (int j = 0; j < str2.size(); ++j)
				{
					if (str1[i] == str2[j])
						break;
				}
		    }
		}
		if (str1.size() > str2.size())
		{
			for (int i = 0; i < min; ++i)
			{
				for (int j = 0; j < str1.size(); ++j)
				{
					if (str2[i] == str1[j])
						break;
				}
			}
		}
		else
			for (int i = 0; i < str1.size(); ++i)
			{
				for (int j = 0; j < str2.size(); ++j)
				{
					if (str1[i] == str2[j])
						break;
				}
			}

	}

}
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int l = 0;
	int r = str.size() - 1;
	while (l <= r)
	{
		char tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
	cout << str << endl;
}
/*int l = 0;
int r = s.length - 1;
while (l <= r)
{
	char tmp = s[l];
	s[l] = s[r];
	s[r] = tmp;
	l++;
	r--;
}
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	cin >> str;
	vector<string> v1;
	vector<string> v2;
	for (int i = 0; i < v1.size(); ++i)
	{
		v2[i] = v1[v1.size() - i];
	}
	cout << v2 << endl;
}

/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	cin >> str;
	for (int i = str.size(); i > 0; i--)
	{
		cout << str[i] << endl;
	}
}

/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	vector<string> v;
	cin >> str;
	vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it<<endl ;
		++it;
	}
}

/*
int main()
{
	// 使用push_back插入4个数据
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// 使用迭代器进行遍历打印
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
}
/*
两个字符串寻找最长公共子串

#include <iostream>
#include<vector>
#include<string>
using namespace std;
char* commonstr(char* str1, char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
	{
		return nullptr;
	}
	char* shortstr, * longstr;
	char* substr;
	if (strlen(str1) <= strlen(str2))
	{
		shortstr = str1;
		longstr = str2;
	}
	else
	{
		shortstr = str2;
		longstr = str1;
	}
	if (strstr(longstr, shortstr) != nullptr)//使用库函数查找子串
	{
		return shortstr;
	}
	substr = new char[strlen(shortstr) + 1];
	for (int i = strlen(shortstr) - 1; i > 0; i--)
	{
		for (int j = 0; j <= strlen(shortstr) - i; j++)
		{
			memcpy(substr, &shortstr[j], i);
			substr[i] = '\0';
			if (strstr(longstr, substr) != nullptr)
			{
				return substr;
			}
		}
	}
	delete[] substr;
	return nullptr;
}

int main()
{
	char str1[] = "hello thank you,thank you very much";
	char str2[] = "thank you very much";
	cout << commonstr(str1, str2) << endl;
}

/*
#include <iostream>
#include<vector>
#include<string>
using namespace std;

string MaxSubStr(string s1, string s2)

{

    vector<vector<int> >record(s1.size(), vector<int>(s2.size()));

    int maxNum = -1, indexEnd = -1;

    for (int i = 0; i < static_cast<int>(s1.size()); ++i)

        for (int j = 0; j < static_cast<int>(s2.size()); ++j)

        {

            if (s1[i] == s2[j])

            {

                if (i == 0 || j == 0)

                    record[i][j] = 1;

                else {

                    record[i][j] = record[i - 1][j - 1] + 1;

                }

            }

            else

                record[i][j] = 0;

            if (record[i][j] > maxNum)

            {

                maxNum = record[i][j];

                indexEnd = i;

            }

        }

    return s1.substr(indexEnd - maxNum + 1, maxNum);

}

int main()

{

    string str1, str2;

    cin >> str1 >> str2;

    cout << MaxSubStr(str1, str2) << endl;

    return 0;

}

/*
#include<iostream>
using namespace std;
int Bottle(int n)
{
    if (n < 2) return 0;
    if (n == 2) return 1;
    else
        return (n / 3 + Bottle(n / 3 + n % 3));
}
int main()
{
    int n;
    cin >> n;
    cout << Bottle(n) << endl;

}

/*
#include<iostream>
using namespace std;
bool fun(int n)
{
	int sum = 0;
	for (int i = 1; n > sum; i += 2)
		sum += i;
	return (n == sum);
}
int main()
{
	cout << fun(484) << endl;
}*/