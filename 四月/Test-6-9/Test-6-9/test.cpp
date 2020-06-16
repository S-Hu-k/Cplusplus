
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	printf("%5.2f\n", 12.0 * 3 / 4);
	return 0;
}


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