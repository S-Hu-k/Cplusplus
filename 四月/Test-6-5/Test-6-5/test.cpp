
/*一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，
计算一下能从花布条中尽可能剪出几块小饰条来呢？

Input

输入中含有一些数据，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，
可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。如果遇见#字符，则不再进行工作。

Output

输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就老老实实输出0，每个结果之间应换行。

Sample Input

abcde a3 aaaaaa aa 


Sample Output

0 3

//这里我用的是string里的substr的技巧，a.substr（1,5）从a的1号下标处获取长度为5的字符串，
//另外是strstr（字符串）是查找某一字符串在大字符串里首次出现的位置，返回值是指针，

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	string a;
	string b;
	while (cin >> a)
	{

		if (a == "#")
			break;
		cin >> b;

		int i = 0, j = 0;
		while (i != a.size())
		{
			if (a.substr(i, b.size()) == b)
			{
				i = i + b.size();
				j++;
			}
			else
				i++;
		}
		cout << j << endl;
		getchar();
	}
	return 0;
}*/







/*
NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；
并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。

于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……

现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。

测试数据包括多组。

每组数据包含两个整数from和to(1≤from≤to≤80)，分别代表开店的第from天和第to天。



输出描述:
对应每一组输入，输出从from到to这些天里（包含from和to两天），需要做多少份早餐

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int  i, x, y;
	long long sum=0;
	long long a[85];
	a[1] = 1; a[2] = 1;
	for (i = 3; i <= 80; i++)
		a[i] = a[i - 1] + a[i - 2];
	while (scanf_s("%d%d", &x, &y) != EOF)
	{
		sum = 0;
		for (i = x; i <= y; i++)
		{
			sum += a[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}**/
