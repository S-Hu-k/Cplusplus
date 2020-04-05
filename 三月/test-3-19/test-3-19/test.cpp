#include<iostream>
using namespace std;
int main()
{
	
	int j;
	int count = 0;
	int sum = 0;
	cin >> j;
	for (; j > 0; j--)
	{
		for (int i = 1; i < j; ++i)
		{
			if (j % i == 0)
		    {
				sum += i;
		     }
	    }
		if (sum == j)
		{
			count++;
		}
		else
			return -1;
	}
	
}
/*
#include<iostream>
using namespace std;
int main()
{
	int a;
	int sum = 0;
	cin >> a;
	for (int i = 1; i < a; ++i)
	{
		if (a % i == 0)
		{
			sum += i;
		}	
	}
	if (sum == a)
	{
		cout << sum << endl;
	}
}
/*
#include<iostream>
using namespace std;
class Base
{
public:
	virtual int foo(int x)
	{
		return x * 10;
	}
	int foo(char x[14])
	{
		return sizeof(x) + 10;
	}
};
class Derived :public Base
{
	int foo(int x)
	{
		return x * 20;
	}
	virtual int foo(char x[10])
	{
		return sizeof(x) + 20;

	}
};
int main()
{
	Derived strdervied;
	Base* pstBase = &strdervied;
	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
	return 0;
}


/*
int main(void)
{
	const int a = 10;
	int* p = (int*)(&a);
	*p = 20;
	cout << "a=" << a << ", *p=" << *p << endl;
	return 0;
}
/*
class A
{
public:
	void funcA()
	{
		printf("FuncA called\n");
	}
	virtual void FuncB()
	{
		printf("FuncB called\n");
	}
};
class B :public A
{
public:
	void FuncA()
	{
		A::funcA();
		printf("FuncAB called\n");
	}
	virtual void FuncB()
	{
		printf("FuncBB called\n");
	}
};
void main(void)
{
	B b;
	A* pa;
	pa = &b;
	A* pa2 = new A;
	pa->funcA();
	pa->FuncB();
	pa2->funcA();
	pa2->FuncB();
	delete pa2;
}
/*
void swap_int(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	swap_int((int*)a,(int*)b);
	cout << a << endl;
	cout << b << endl;

}*/