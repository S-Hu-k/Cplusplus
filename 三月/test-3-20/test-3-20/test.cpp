//第五十一题  iNOC产品部-杨辉三角的变形
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		vector<vector<int>>vvI(num);
		vvI[0].push_back(1);
		for (int i = 1; i < num; i++)
		{
			int jMax = (i + 1) * 2 - 1;
			vvI[i].push_back(1);
			for (int j = 1; j < jMax; j++)
			{
				int iMedian = j - 1;
				int iMedian1 = iMedian - 1;
				int iMedian2 = iMedian + 1;
				int iNum1 = iMedian1 < 0 ? 0 : vvI[i - 1][iMedian1];
				int iNum2 = iMedian >= vvI[i - 1].size() ? 0 : vvI[i - 1][iMedian];
				int iNum3 = iMedian2 >= vvI[i - 1].size() ? 0 : vvI[i - 1][iMedian2];
				int iTemp = iNum1 + iNum2 + iNum3;
				vvI[i].push_back(iTemp);
			}
		}
		int k = 0;
		int iNum = num - 1;
		int kMax = 2 * num - 1;
		for (; k < kMax; k++)
		{
			if (vvI[iNum][k] & 1)
				continue;
			else
				break;
		}
		if (k != kMax)
			cout << k + 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}




/*请设计一个算法完成两个超长正整数的加法。
接口说明：
/*
请设计一个算法完成两个超长正整数的加法。
输入参数：
String addend：加数
String augend：被加数
返回值：加法结果
*/
/*
public String AddLongInteger(String addend, String augend)
{
	/*在这里实现功能*/
/*
	return null;
}
输入描述:
输入两个字符串数字

输出描述 :
输出相加后的结果，string型

示例1
输入

99999999999999999999999999999999999999999999999999
1
输出

100000000000000000000000000000000000000000000000000
*/


/*
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string AddLongInteger(string addend, string augend) {
	//最终返回的结果
	string result = "";
	//从低位开始加
	int i = addend.size() - 1;
	int j = augend.size() - 1;
	//当前位的相加结果
	int carry = 0;
	while (i >= 0 || j >= 0) {
		if (i >= 0)
			carry += (addend[i] - '0');
		if (j >= 0)
			carry += (augend[j] - '0');
		//carry的范围是0-19，取余赋给当前位
		result += (char)(carry % 10 + '0');
		//若大于9，则carry==1，不大于carry==0
		carry /= 10;
		--i;
		--j;
	}
	//若相加完毕进位仍然为1，说明还有进位
	if (carry == 1)
		result += '1';
	//最终只需要将result逆置一下即可
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	string addend;
	string augend;
	while (cin >> addend >> augend) {
		cout << AddLongInteger(addend, augend) << endl;
	}
	return 0;
}



/*
#include<iostream>
using namespace std;
class A
{
public:
	~A()
	{
		cout << "~A()";
	}
};
class B {
public:
	virtual ~B() 
	{
		cout << "~B()";
	}
};
class C :public A, public B
{
public:
	~C()
	{
		cout << "~C()" << endl;
	}
};
int main()
{
	C* c = new C;
	B* b1 = dynamic_cast<B*>(c);
	A* a2 = dynamic_cast<A*>(b1);
	delete a2;
}
/*
int main()
{
	char* p = "abc";
	char* q = "abc123";
	while (*q = *p)
	{
		printf("%c %c", *p, *q);
	}
}
/*
int main()
{
	int a[] = { 1,2,3,4,5 };
	int* p[] = { a,a + 1,a + 2,a + 3 };
	int** q = p;
	cout << *(p[0] + 1) + **(q + 2) << endl;
}
/*
#define M 5
#define N 20
int fun(char(*ss)[N], int* n)
{
	int i, k = 0, len = N;
	for (i = 0; i <M ; i++)
	{
		len = strlen(ss[i]);
			if (i == 0)
				*n = len;
			if (len > * n)
			{
				*n = len;
				k = i;
			}
	}
	return k;
}
int main()
{
	char ss[M][N] = { "shanghai","guangzhou","beijing","chongqing" };
	int n, k, i;
	printf("\nThe originalb stringsare:\n");
	for (i = 0; i < M; i++)
		puts(ss[i]);
	k = fun(ss, &n);
	printf("\nThe length of shortest string is:%d\n", n);
	printf("\nTHe shortest string is:%s\n", ss[k]);
}
/*
int main()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	return 0;
}
/*
int main()
{
	char* ptr;
	char mystring[] = "abcdefg";
	ptr = mystring;
	ptr += 5;
	cout << ptr << endl;

}
/*

class A
{
public:
	A()
	{
		p();
	}
	virtual void p()
	{
		printf("A");
	}
	virtual ~A()
	{
		p();
	}
};
class B :public A
{
public:
	B()
	{
		p();
	}
	void p()
	{
		printf("B");
	}
	~B()
	{
		p();
	}
};
int main(int,char**)
{
	A* a = new B();
	delete a;
}*/