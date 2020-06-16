
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	printf("%5.2f\n", 12.0 * 3 / 4);
	return 0;
}


/*��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1, 1), 
B��(n, m)������A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i, j + 1)��(i + 1, j)������·�ߣ�
�ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����), �ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ�
	��ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�

�������� :
��һ��N��M��K(2 �� N, M �� 20, k �� 100), N, MΪ�ݵش�С��������K�У�ÿ����������x��y������(x, y)����һ��Ģ����
������� :
���һ�У������������(������2λС��)
�������� :
    2 2 1
    2 1
    ������� :
    0.50
    ������������Ŀֱ�Ӿ�д��һ�δ��룬�ò�����Ģ������·�������Ե����յ����·�����������һֱ���ԣ��������������ֺܶ��˺��ҷ���ͬ���Ĵ��󡣴��������أ���Ϊ�������м�ʱ���º����ҵĸ�����һ���ģ�����0.5�������˱�Ե��������m[i][M - 1]ʱ����ֻ���������ˣ����µĸ���Ϊ1�����ҵĸ���Ϊ0�������ü򵥵���·��������
    
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
			if (p[i - 1][1] && p[i][1] && M > 1) {  //֮ǰ��·��û��Ģ�����ұ���ΪĢ��
				p[i][1] = 0.5 * p[i - 1][1];
			}
			else if (p[i - 1][1] && p[i][1] && M <= 1) continue; //���ֻ��һ�л���һ�У�Ҳֻ��һ��·��������ҲΪ1
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

				else p[i][j] = (i == N ? 1 : 0.5) * p[i][j - 1] + (j == M ? 1 : 0.5) * p[i - 1][j];  //�ؼ����㹫ʽ
			}
		}
		cout << setiosflags(ios::fixed);
		cout << setprecision(2) << p[N][M] << endl;

	}
	return 0;
}


/*


��Ŀ����
��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�
ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��

��������:
��������������ݡ�

ÿ�����ݵ�һ������������ m �� n��1��m, n��20���������� m �У�ÿ�а��� n ���ַ���ÿ���ַ���ʾһ���ש����ɫ���������£�

1. ��.������ɫ�Ĵ�ש��
2. ��#������ɫ�Ĵ�ש��
3. ��@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�
�������:
��Ӧÿ�����ݣ�����ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
ʾ��1

����
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
���
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