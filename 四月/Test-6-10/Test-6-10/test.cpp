
/*
题目描述
工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“ / usr / local / bin”，就需要此次创建“ / usr”、“ / usr / local”以及“ / usr / local / bin”。好在，Linux下mkdir提供了强大的“ - p”选项，只要一条命令“mkdir - p / usr / local / bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir - p”命令。

输入描述 :
输入包含多组数据。
每组数据第一行为一个正整数n(1≤n≤1024)。
紧接着n行，每行包含一个待创建的目录名，目录名仅由数字和字母组成，长度不超过200个字符。

输出描述 :
对应每一组数据，输出相应的、按照字典顺序排序的“mkdir - p”命令。
每组数据之后输出一个空行作为分隔。

示例
输入
3
/ a
/ a / b
/ a / b / c
3
/ usr / local / bin
/ usr / bin
/ usr / local / share / bin
输出
mkdir - p / a / b / c

mkdir - p / usr / bin
mkdir - p / usr / local / bin
mkdir - p / usr / local / share / bin



将输入的字符串存在数组vector中，用sort对数组排序即实现按字典排序。
再判断若前一个数据是后一个数据的子串且后一个数据的下一个位置是 ‘ / ’ （这里很容易出错！！），
则删除前一个数据，如此判断数组的每个数据。最后在没有重复的vector中，在每个字符串前面加 “mkdir - p ”串再输出即可。


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsZi(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	string mk = "mkdir -p ";
	int i = 0;
	while (i < v.size() - 1)
	{
		//前一个是后一个的子串，且后一个子串的下一个位置为 /
		if (IsZi(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (auto& e : v)
		cout << mk << e << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string s1;
			cin >> s1;
			v.push_back(s1);
		}
		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}

/*
输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000），表示请求的数量。
紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。

输出描述 :
对应每一组数据，输出连接池最多需要创建多少个连接。

示例
输入
6
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
输出
2


将输入的Id 和 op 依次存在数组v中，然后判断数组中的op，因为是依次存入的，
所以op一定在数组的奇数位上，若op 是"connect" 则将op 前面的id 放入队列q中，
否则先记录q 的长度，再将op前的id出队列。取得最长的长度即可。下面是实现的部分函数：



#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int con = 0;
		queue<char> q;
		for (int i = 0; i < n; i++)
		{
			char ID;
			cin >> ID;
			string OP;
			cin >> OP;
			if (OP == "connect")
				q.push(ID);
			else
			{
				con = q.size() > con ? q.size() : con;
				q.pop();
			}
		}
		cout << con << endl;
	}
	return 0;
}*/
