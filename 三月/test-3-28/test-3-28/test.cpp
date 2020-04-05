#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
int N, M;//�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ��Ѿ��߹�����������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����ȥ

	if (i == N - 1 && j == M - 1)//�ж��Ƿ񵽴��յ�
	{

		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//����̽���Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//����̽���Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//����̽���Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//����̽���Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0;//�ָ��ֳ�����Ϊδ��
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
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	}
	system("pause");
	return 0;
}

/* ���ս�����
//���ڶ�̬�滮��˼�룬������������6*6�������������е�N*M�����Լ����еķ���
public int getMost(int[][] board) {
	//����forѭ������������ά���鲻�ö�˵��
	for (int i = 0; i < board.length; i++) {
		for (int j = 0; j < board[0].length; j++) {
			if (i == 0 && j == 0) {
				//�����������꣬�����κδ���
			}
			else if (i == 0) {
				//��������е��ٽ�ߣ�Ҳ���ǵ�һ�У���ô��ֻ��������
				//�����ߵ�ʱ��õ��Ҫ�������ֵ��������
				board[i][j] += board[i][j - 1];
			}
			else if (j == 0) {
				//��������е��ٽ�ߣ�Ҳ���ǵ�һ�У���ô��ֻ��������
				//�����ߵ�ʱ��õ��Ҫ�������ֵ��������
				board[i][j] += board[i - 1][j];
			}
			else {
				//���ĵ����⣬��ȥ�����ٽ�ߣ�ʣ�µľ��Ǽ��������ߣ�Ҳ�������ߣ�
				//��ô��ʱ���Ҫ�����ߵ���ǰ������п��ܵ������Ҳ�����ߵ���ǰ��
				//����·���ĺ��ǲ�����Щ���е���õ�·�����������ˡ�
				//temup�����洢�Ӹõ����������������·���͡�
				//templeft�����洢�Ӹõ�����߹��������·���ĺͣ�
				int temup = board[i - 1][j];
				int templeft = board[i][j - 1];
				//�����߿϶�ֻ��ѡ��һ�����бȽϣ��Ǹ��󣬾Ͱ����ֵ�Ӹ���ǰ�㣬
				//��Ϊ��һ��ʼ���Ǿͽ����˴�С�ıȽϣ�ÿһ����洢�Ķ��ǵ��ﵱǰ��
				//�����ֵ������ֱ�����һ����Ϊֹ������ֵ���ǵ�ǰ���ֵ�ĺ͡�ֻҪ����
				//���һ��������ݾͿ����ˡ�
				if (temup > templeft) {
					board[i][j] += temup;
				}
				else {
					board[i][j] += templeft;
				}
			}
		}
	}
	/*  ��ʼ����������
	564 448 654 186 490 699
	487 444 563 228 365 261
	429 505 612 564 715 726
	464 617 234 647 702 263
	245 249 231 462 453 646
	669 510 492 512 622 135
	*/
	/*�����󷵻ص����顣
	564     1012    1666    1852    2342    3041
	1051    1495    2229    2457    2822    3302
	1480    2000    2841    3405    4120    4846
	1944    2617    3075    4052    4822    5109
	2189    2866    3306    4514    5275    5921
	2858    3376    3868    5026    5897    6056
	���Կ��������һ��������ֵ6056�������ǵ�ǰ���ŵ�·�����ó�����ֵ
	
	return  board[board.length - 1][board[0].length - 1];
}
*/