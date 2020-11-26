#include<iostream>
using namespace std;
int main()
{
	unsigned a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a + c) / 2 << " " << (b + d) / 2 << " " << d - (b + d) / 2 << endl;

}
/*
class A
{
public:
	A(char* s)
	{
		cout << s << endl;
	}
	~A()
	{}
};
class B :virtual public A
{
public:
	B(char* s1, char* s2) :A(s1)
	{
		cout << s2 << endl;
	}
};
class C :virtual public A
{
public:
	C(char* s1, char* s2) :A(s1)
	{
		cout << s2 << endl;
	}
};
class D :public B, public C
{
public:
	D(char* s1, char* s2, char* s3, char* s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main()
{
	D* p = new D("class A"£¬"class B"£¬"class C"£¬"class D");
	delete p;
	return 0;
}
/*
int main()
{
	char a[10] = { '1','2','3','4','5','6','7','8','9',0 }, * p;
	int i;
	i = 8;
	p = a + i;
	printf("%s\n", p - 3);

}
/*int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	cout << (func());
}*/