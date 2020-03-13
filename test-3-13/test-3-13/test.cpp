#include<iostream>
#include<vector>
using namespace std;
int getLCA(int a, int b)
{
	while (a != b)
	{
		int  num1=a ;
		int  num2=b ;
		int count1 = 0;
		int count2 = 0;
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; num1 != 0; ++i)
		{
			num1 /= 2;
			count1++;
			v1[i] = num1;
		}
		for (int j = 0; num2!=0; ++j)
		{
			num2 /= 2;
			count2++;
			v2[j] = num2;
		}
		for (int k = 0; k <count1 ; ++k)
		{
			for (int l = 0; l < count2; ++l)
			{
				if (v1[k] == v2[l])
					return v1[k];
			}

		}
		
	}
};
int main()
{
	int a, b;
	cin >> a >> b;
	cout << getLCA(a, b) << endl;
}
/*
int main()
{
	int a;
	int num=0;
	cin >> a;
		while (a)
		{
			a = a & (a << 1);
			num++;
		}
	cout<< num<<endl;

}
/*
class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}
	virtual void test()
	{
		func();
	}
};
class B :public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc,char* argv[])
{
	B* p = new B;
	p->test();
	return 0;
}
/*
class A
{
public:
	void foo()
	{
		printf("1");
	}
	virtual void fun()
	{
		printf("2");
	}
};
class B :public A
{
public:
	void foo()
	{
		printf("3");
	}
	void fun()
	{
		printf("4");
	}
};
int main(void)
{
	A a;
	B b;
	A* p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A* ptr = (A*)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}
/*
int main()
{
	int x = 3, y = 3;
	switch (x % 2) {
	case 1:
		switch (y) {
		case 0:cout << "first";
		case 1:cout << "second"; break;
		default:cout << "hello";
		}
	case 2:cout << "third";
	}
}*/