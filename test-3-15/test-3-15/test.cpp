

#include <iostream>
using namespace std;

/*从最中间的位置查找来满足距离最近
 *循环判断是否为素数*/
bool IsPrime(int a)
{
	for (int i = 2; i < a; ++i)
	{
		if (a % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int mid = n / 2;
		int i;
		for (i = mid; i > 0; --i)
		{
			if (IsPrime(i) && (IsPrime(n - i)))
				break;
		}
		cout << i << endl << n - i << endl;
	}
	return 0;
}










/*
#include<iostream>
using namespace std;
void func(const int& v1, const int& v2)
{
	std::cout << v1 << ' ';
	std::cout << v2 << ' ';
}
int main(int argc, char* argv[])
{
	int i = 0;
	func(++i, i++);
	return 0;

}
/*
#define sqr(a) a*a
void main()
{
	int x = 6, y = 3, z = 2;
	x /= sqr(y + z) / sqr(y + z);
	cout << x << endl;
}
/*
void main()
{
	int n[][3] = { 10,20 ,30,40,50,60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
}
/*
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived :public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x/2);
	}
};
int main(void)
{
	Derived obj;
	Base* pobj = &obj;
	printf("%d", pobj->Bar((char)(100)));
	printf("%d", pobj->Bar(100));
}*/