
/*现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1, 1), 
B在(n, m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i, j + 1)或(i + 1, j)这样的路线，
在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格), 问：A如果每一步随机选择的话(若她在边界上，
	则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？

输入描述 :
第一行N，M，K(2 ≤ N, M ≤ 20, k ≤ 100), N, M为草地大小，接下来K行，每行两个整数x，y，代表(x, y)处有一个蘑菇。
输出描述 :
输出一行，代表所求概率(保留到2位小数)
输入例子 :
    2 2 1
    2 1
    输出例子 :
    0.50
    分析：看了题目直接就写了一段代码，用不遇到蘑菇的总路径数除以到达终点的总路径数，输出答案一直不对，看了讨论区发现很多人和我犯了同样的错误。错在哪里呢？因为在网格中间时向下和向右的概率是一样的，都是0.5，而到了边缘，比如在m[i][M - 1]时，就只能向下走了！向下的概率为1，向右的概率为0，不能用简单的数路径方法。
    
#include <iostream>
#include <vector>
#include <iomanip>
	using namespace std;
int main() {
	int N, M, K;
	while (cin >> N >> M >> K) {
		vector<vector<float> > p(N + 1, vector<float>(M + 1, 1.0));
		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			p[x][y] = 0;
		}


		for (int i = 2; i < N + 1; i++) {
			if (p[i - 1][1] && p[i][1] && M > 1) {  //之前的路径没有蘑菇，且本身不为蘑菇
				p[i][1] = 0.5 * p[i - 1][1];
			}
			else if (p[i - 1][1] && p[i][1] && M <= 1) continue; //如果只有一行或者一列，也只有一条路径，概率也为1
			else {
				p[i][1] = 0;
			}
		}
		for (int i = 2; i < M + 1; i++) {
			if (p[1][i - 1] && p[1][i] && N > 1) {
				p[1][i] = 0.5 * p[1][i - 1];
			}
			else if (p[1][i - 1] && p[1][i] && N <= 1) continue;
			else {
				p[1][i] = 0;
			}
		}
		for (int i = 2; i < N + 1; i++) {
			for (int j = 2; j < M + 1; j++) {
				if (!p[i][j]) continue;

				else p[i][j] = (i == N ? 1 : 0.5) * p[i][j - 1] + (j == M ? 1 : 0.5) * p[i - 1][j];  //关键计算公式
			}
		}
		cout << setiosflags(ios::fixed);
		cout << setprecision(2) << p[N][M] << endl;

	}
	return 0;
}


/*


题目描述
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，
只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

输入描述:
输入包含多组数据。

每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：

1. “.”：黑色的瓷砖；
2. “#”：白色的瓷砖；
3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
输出描述:
对应每组数据，输出总共能够到达多少块黑色的瓷砖。
示例1

输入
9 6
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
输出
45









#include<iostream>
#include<map>
#include<iterator>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char mapp[22][22];
int res;
vector<vector<bool> > vis(30, vector<bool>(30, false));
int nextt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<int> write(int H, int W) {
	vector<int> tt;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> mapp[i][j];
			if (mapp[i][j] == '@')
			{
				tt.push_back(i);
				tt.push_back(j);
			}
		}
		cin.ignore();
	}
	return tt;
}
void dfs(int x, int y, int W, int H) {

	if (mapp[x][y] == '#')
		return;
	if (mapp[x][y] == '.')
		res++;
	for (int k = 0; k < 4; k++) {
		int tx = x + nextt[k][0];
		int ty = y + nextt[k][1];
		if (tx < 0 || ty < 0 || tx >= H || ty >= W)
			continue;
		if (!vis[tx][ty] && mapp[tx][ty] == '.')
		{
			vis[tx][ty] = true;
			dfs(tx, ty, W, H);
		}
	}
}
int main()
{
	int W, H;
	int x, y;
	while (cin >> W >> H && W != 0 && H != 0)
	{
		vector<int> t = write(W, H);
		x = t[0];
		y = t[1];
		vis[x][y] = true;
		dfs(x, y, W, H);
		cout << res + 1 << endl;
		res = 0;
		for (int i = 0; i < vis.size(); i++)
			fill(vis[i].begin(), vis[i].end(), false);
	}
	return 0;
}*/
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
