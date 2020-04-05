/*小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3…
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述 :
输入为一行，有两个整数N，M，以空格隔开。(4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述 :
	输出小易最少需要跳跃的步数, 如果不能到达输出 - 1


	采用动态规划思想求解。创建一个vector容器steps，steps[i]表示到达i号石板所需的最小步数。
	初始化为steps容器为INT_MAX。从序号N的石板开始逐个遍历，若steps[i]为INT_MAX，表示该点不可到达，
	直接开始下次循环。若steps[i]不为INT_MAX，表示该点可以到达，
	下面求解编号i的约数，进行动态规划。动态规划的转移方程为：
steps[i+j] = min(steps[i]+1,steps[i+j])   //i为石板编号，j为i的约束
steps[N] = 0


#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	while (cin >> N >> M) {
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++) {
			if (steps[i] == INT_MAX) {
				continue;
			}
			for (int j = 2; (j * j) <= i; j++) {
				if (i % j == 0) {
					if (i + j <= M) {
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M) {
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}

				}

			}
		}
		if (steps[M] == INT_MAX) {
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}
	return 0;
}



/*在命令行输入如下命令：

xcopy / s c : \ d : \，

各个参数如下：

参数1：命令字xcopy

参数2：字符串 / s

参数3：字符串c : \

参数4 : 字符串d : \

请编写一个参数解析程序，实现将命令行各个参数解析出来。

解析规则：

1.参数分隔符为空格
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s “C : \program files” “d : \”时，
参数仍然是4个，第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长
4.输入由用例保证，不会出现不符合要求的输入

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		bool flag = false;
		vector<string> vec;
		string row;
		for (int i = 0; i < str.size(); i++)
		{
			if (flag)
			{//在括号内
				if (str[i] != '\"')
					row += str[i];
				else
					flag = false;
			}
			else
			{
				if (str[i] == ' ')
				{
					vec.push_back(row);
					row = "";
				}
				else if (str[i] == '\"') flag = true;
				else
					row += str[i];
			}
		}
		vec.push_back(row);
		cout << vec.size() << endl;
		for (auto i : vec)
			cout << i << endl;
	}
	return 0;
}

/*
#include <iostream>
using namespace std;
class A
{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B : public A
{
	public: virtual void print()
	{
		cout << "B::print()" << "\n";
	}
};
class C : public A
{
public: 
	virtual void print()
	{
        cout << "C: :print()" << "\n";
	}
		
};
void print(A a)
{
	a.print();
}
int main()
{
	A a, * aa, * ab, * ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
}





/*#include<iostream>
using namespace std;
class B
{
public:
	B()
	{
		cout << "default constructor" << " ";
	}
	~B()
	{
		cout << "destructed" << " ";
	}
	B(int i) :data(i)
	{
		cout << "constructed by parmeter" << data << " ";
	}
private:
	int data;
};
B play(B b)
{
	return b;
}
int main(int argc, char* argv[])
{
	
		B temp = play(5);
		return 0;
	
}*/