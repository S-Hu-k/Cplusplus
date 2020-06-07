//输入有多组数据，每组数据有两行。
//第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。
//第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
//
//如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string namelist;
	string name;
	while (getline(cin, namelist))
	{
		getline(cin, name);
		vector<string> str;
		for (size_t i = 0; i < namelist.size(); ++i)
		{
			if (namelist[i] == '\"')//名字中有""的情况
			{
				str.push_back(namelist.substr(i + 1, namelist.find('\"', i + 1) - i - 1));//给vector中尾插去除""的名字
				i = namelist.find('\"', i + 1) + 1;
			}
			else//名字中无""的情况
			{
				if (namelist.find(',', i) == namelist.npos)//最后一个末尾名字 其后没有,字符
				{
					str.push_back(namelist.substr(i, namelist.size() - i));
					i = namelist.size();
				}
				else//中间都有,隔开的名字
				{
					str.push_back(namelist.substr(i, namelist.find(',', i) - i));//需要把,一起尾插进去隔开 防止前后名字重复
					i = namelist.find(',', i);
				}
			}
		}
		if (find(str.begin(), str.end(), name) != str.end())
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}








/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string ss, s;
	while (getline(cin, ss))
	{
		getline(cin, s);
		bool flag = false;
		for (int i = 0; i < ss.length(); i++)
		{
			string str;
			if (ss[i] == '"')
			{
				i++;
				while (i < ss.length() && ss[i] != '"')
				{
					str += ss[i];
					i++;
				}
				if (str == s)
				{
					flag = true;
					break;
				}
			}
			else if (ss[i] != ',')
			{
				while (i < ss.length() && ss[i] != ',')
				{
					str += ss[i];
					i++;
				}
				if (str == s)
				{
					flag = true;
					break;
				}
			}
			else
			{
				;
			}
		}
		if (flag == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}
 
/*今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？



输入描述:
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。

输出描述:
对应每一组数据，以“xx.xx % ”的格式输出发生无人获奖的概率。
示例1

输入
2
输出
50.00 %
n个有序的元素应有n!个不同的排列，如若一个排列使得所有的元素不在原来的位置上，则称这个排列为错排；有的叫重排。
如，1 2的错排是唯一的，即2 1。1 2 3的错排有31 2，2 3 1。这二者可以看作是1 2错排，3分别与1、2换位而得的。

百度错排算法
针对错排算法， 为什么要(n - 1)[D(n - 2) + D(n - 1)]
首先n - 1是第一个选择的数据的错位可能，这个数据可以是任意一个数
在排序完第一个选择的数据后，我们面临两种选择，因为第一个选择的数据占据了一个不属于他的位置，
那该位置原本的数据就肯定是一个错排数据，但该数据有两种选择
1.占据第一个数据的空位--n - 2个数据
2.不占第一个数据的空位，将自己当做是以第一个数据空位为位置的数据进行排序-- - n - 1个数据


#include<iostream>
using namespace std;

int main() {
	int n;
	long long a[21] = { 0,0,1 }, b[21] = { 1,1,2 };
	while (cin >> n) {
		for (int i = 3; i <= n; i++) {
			b[i] = i * b[i - 1];
			a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
			//		cout << "a[i]=" << a[i] << endl;
			//		cout << "b[i]=" << b[i] << endl;

		}
		//	cout << 1.0 * a[n] / b[n]*100 << endl;
		printf("%.2f%c\n", 1.0 * a[n] / b[n] * 100, '%');

	}
	return 0;
}*/
