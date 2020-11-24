#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());//翻转整个句子
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);

		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}



/*
#include<string>
#include<iostream>

using namespace std;



struct A
{
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};
int main()
{
	cout << sizeof(A) << endl;
}
/*
int main()
{
	string str1;
	string str2;
	string str3;

	int hashtable[256] = { 0 };
	getline(cin, str1);
	getline(cin, str2);
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
		{
			str3 += str1[i];
		}
		
	}
	cout << str3;
	return 0;



}
/*
#include<string>
#include<iostream>

using namespace std;

int main()
{
	//vector<string> v;
	string s;
	string m;
	string tmp;
	getline(cin, s);//字符串一般用getline//they are students
	getline(cin, m);                  //aeiou

	for (int i = 0; i < s.size(); i++)
	{
		if (m.find(s[i]) == string::npos)//npos就是-1
		{
			tmp += s[i];
		}
	}
	cout << tmp;
	return 0;
}*/
//#include<iostream>
////#include<vector>
//using namespace std;
//int main()
//{
//	printf("%s,%5.3", "computer", "computer");
//	return 0;
//}
////
//int main()
//{
//    bool Min(int a, int b)
//    {
//        int min = 0;
//        if (a > b)
//            return min = b;
//        if (a < b)
//            return min = a;
//    }
//    int minNumberInRotateArray(vector<int> rotateArray) {
//        if (rotateArray.size() == 0)
//            return false;
//        for (int i = 0; i < rotateArray.size(); ++i)
//        {
//            return Min(rotateArray[i], rotateArray[i + 1]);
//        }
//
//    }
//
//}
//
//int main()
//{
//	cin >> n;
//	while (n != 0)
//	{
//		int count = 0;
//		count++;
//		n=n& (n - 1);
//
//	}
//	return count;
//}

//class Solution {
//public:
//    int minNumberInRotateArray(vector<int> rotateArray) {
//        if (rotateArray.size() == 0)
//            return false;
//        for (int i = 0; i < rotateArray.size(); ++i)
//        {
//            int x = 0;
//            int y = x + 1;
//            if ((rotateArray[x] > rotateArray[y]) || (rotateArray[x] < rotateArray[y]))
//            {
//                x = y;
//                y = y + 1;
//                return rotateArray[y];
//            }
//        }
//
//    }
//};
//#include<string>
//using namespace std;
//int main()
//{
//	string str = { 1,2,3,4,5,6 };
//	int n = 3;
//	for (int i = 0; i < n; ++i)
//		str.push_back(i);
//}
//#include <iostream>
//#include <vector>

//int main()
//{
//    std::vector<int> myvector;
//    int sum(0);
//    myvector.push_back(100);
//    myvector.push_back(200);
//    myvector.push_back(300);
//
//    while (!myvector.empty())
//    {
//        sum += myvector.back();
//        myvector.pop_back();
//    }
//
//    std::cout << "The elements of myvector add up to " << sum << '\n';
//
//    return 0;
//}