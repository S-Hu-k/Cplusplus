
/*
输入描述：

输入有多组数据，每组数据为一张20x20的棋盘。
其中黑子用“*”表示，白子用“+”表示，空白位置用“.”表示。

输出描述：

如果棋盘上存在五子连珠（无论哪种颜色的棋子），输入“Yes”，否则输出“No”


该题是对五子棋赢的检测，五子棋赢的规则：如果当前位置有连在一起的五颗棋子为同一种，则为赢，每取一个位置，检测该位置上、下、左、右以及对角线为是否为统一中棋子，是输出YES，否则获取下一个位置继续检测，如果棋盘中没有连在一起的五颗棋子则输出NO。

结构设计：dir代表当前位置的8个方向，其中上下、左右、左上右下、右上左下为必须放在一起检测。获取一个棋盘，按照行列检测棋盘中的每个位置，当拿到一个位置后，按照以下步骤进行操作：

以该位置为中心，依次检测该位置的上下、左右、左上右下、右上左下，比如左上
从该位置开始向上检测，找出连在一起的同种棋子个数，再向下检测同种棋子的个数并累计，注意在检测时，中心位置统计了两次，上下统计完时，需要给结果减去1
按照2统计完上下、左右、左上右下、右上左下各个方向，找出最大的同种棋子个数
检测3中统计出的最大同种棋子个数，如果大于等于5，输出YSE，否则取下一个位置继续1
如果所有的位置检测完，没有超过5个的相同棋子，则输出NO

#include <bits/stdc++.h>

using namespace std;

int count(string table[], char ch, int x, int y) {
    int maxc = 0;
    int dir[4][2][2] = { {{-1, 0},{1, 0}}, {{0, -1}, {0, 1}}, {{-1, -1}, {1, 1}}, {{-1, 1}, {1, -1}} };
    for (int i = 0; i < 4; ++i) {  // 四种方向
        int c = 0;
        for (int j = 0; j < 2; ++j) {  // 两个小方向
            int nx = x, ny = y;
            while (nx >= 0 && nx < 20 && ny >= 0 && ny <20 && table[nx][ny] == ch) {
                nx += dir[i][j][0];
                ny += dir[i][j][1];
                ++c;
            }
        }
        maxc = (maxc > c ? maxc : c);
    }
    return maxc - 1;  // 统计两个方向（如横向的左右两个方向的时候，当前棋子被计算了两次）
}

int solve  (string table[]) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (table[i][j] == '*' || table[i][j] == '+')
                if (count(table, table[i][j], i, j) >= 5)
                    return true;
        }
    }
    return false;
}

int main() {
    string table[20];
    while (cin >> table[0]) {
        for (int i = 1; i < 20; ++i)
            cin >> table[i];
        cout << (solve(table) ? "Yes" : "No") << endl;
    }
    return 0;
}



*/
/*
Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。

输入描述：
输入包含多组数据。
每组数据包括两行：第一行是一个正整数n (3 ≤ n ≤ 50)；
紧接着第二行包含n个由数值和运算符组成的列表。
“+-*/”分别为加减乘除四则运算，其中除法为整除，即“5/3=1”。

输出描述：
对应每一组数据，输出它们的运算结果。

示例1：

输入：
3
2 3 +
5
2 2 + 3 *
5
2 2 3 + *
输出：
5
12
10
解题思路
循环输入，获取逆波兰表达式（后缀表达式），然后进行以下步骤，直到测试完所有的测试用例：

遇到数字字符串，将该数字字符串转化为数字然后入栈。
遇到操作符时，从栈顶取两个数字，然后进行该运算符所对应运算，完成好将结果入栈。
【注意】：根据逆波兰表达式定义：先取到的数字为运算符的右操作数。
继续1和2，直到处理完所有的字符串，最终栈顶元素即为所要结果。

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            continue;
        vector<string> s(n);
        stack<int> st;
        for(int i = 0;i < n;++i){
            cin >> s[i];
        }
        
        for(int i = 0;i < n;++i){
            if(s[i][0] >= '0' && s[i][0] <= '9'){
                st.push(atoi(s[i].data()));
                //string().data():
                //返回指向数组的指针，该数组包含与构成字符串对象值的字符相同的字符序列。
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                switch(s[i][0]){
                    case '+':st.push(b + a);break;
                    case '-':st.push(b - a);break;
                    case '*':st.push(a * b);break;
                    case '/':{
                        //if(a == 0)  TODO
                        st.push(b / a);break;
                    }
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}













*/
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
