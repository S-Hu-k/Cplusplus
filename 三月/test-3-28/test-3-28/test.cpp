#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
int N, M;//分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
vector<vector<int>> path_best;//存储最佳路径

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已经走过，不可再走
	path_temp.push_back({ i, j });//将当前节点加入到路径中去

	if (i == N - 1 && j == M - 1)//判断是否到达终点
	{

		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//向上探索是否可行
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//向下探索是否可行
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//向右探索是否可行
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//向左探索是否可行
		MazeTrack(i, j + 1);
	maze[i][j] = 0;//恢复现场，设为未走
	path_temp.pop_back();
}

int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto& i : maze)
			for (auto& j : i)
				cin >> j;
		MazeTrack(0, 0);//回溯寻找迷宫最短通路
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
	}
	system("pause");
	return 0;
}

/* 年终奖问题
//基于动态规划的思想，不仅仅局限于6*6矩阵，适用于所有的N*M矩阵以及所有的方阵。
public int getMost(int[][] board) {
	//两个for循环用来遍历二维数组不用多说。
	for (int i = 0; i < board.length; i++) {
		for (int j = 0; j < board[0].length; j++) {
			if (i == 0 && j == 0) {
				//如果是起点坐标，不做任何处理。
			}
			else if (i == 0) {
				//如果走在行的临界边，也就是第一行，那么他只能向右走
				//向右走的时候该点就要将后面的值加起来。
				board[i][j] += board[i][j - 1];
			}
			else if (j == 0) {
				//如果走在列的临界边，也就是第一列，那么他只能向下走
				//向下走的时候该点就要将上面的值加起来。
				board[i][j] += board[i - 1][j];
			}
			else {
				//核心点在这，除去两个临界边，剩下的就是既能向右走，也能向下走，
				//那么这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点
				//各自路径的和是不是这些所有到达该点路径当中最大的了。
				//temup用来存储从该点上面走下来的最大路径和。
				//templeft用来存储从该点左边走过来的最大路径的和，
				int temup = board[i - 1][j];
				int templeft = board[i][j - 1];
				//这两者肯定只能选其一，进行比较，那个大，就把这个值加给当前点，
				//因为从一开始我们就进行了大小的比较，每一个点存储的都是到达当前点
				//的最大值。所以直到最后一个点为止，她的值就是当前最大值的和。只要返回
				//最后一个点的内容就可以了。
				if (temup > templeft) {
					board[i][j] += temup;
				}
				else {
					board[i][j] += templeft;
				}
			}
		}
	}
	/*  初始数组的情况。
	564 448 654 186 490 699
	487 444 563 228 365 261
	429 505 612 564 715 726
	464 617 234 647 702 263
	245 249 231 462 453 646
	669 510 492 512 622 135
	*/
	/*结束后返回的数组。
	564     1012    1666    1852    2342    3041
	1051    1495    2229    2457    2822    3302
	1480    2000    2841    3405    4120    4846
	1944    2617    3075    4052    4822    5109
	2189    2866    3306    4514    5275    5921
	2858    3376    3868    5026    5897    6056
	可以看到，最后一个坐标点的值6056，他就是当前最优的路径所得出来的值
	
	return  board[board.length - 1][board[0].length - 1];
}
*/