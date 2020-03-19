
#include <iostream>
#include<vector>
using namespace std;

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int s = 0, L = 0, R = 0, min_l = INT_MAX, min_r = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				s += (left[i] + right[i]);
			}
			else
			{
				L += left[i];
				R += right[i];

				min_l = min(min_l, left[i]);
				min_r = min(min_r, right[i]);
			}
		}
		return s + min(L - min_l + 1, R - min_r + 1) + 1;
	}
};

/*
int findNumberOf1(int num)
{
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = findNumberOf1(n);
		cout << count << endl;
	}
	return 0;
}
/*
int main()
{
	int a;
	int count = 0;
	cin >> a;
	while (a)
	{
		//n=n&(n-1)
			a = a & (a - 1);
			count++;
		
	}
	cout << count << endl;;
}
/*
int FindSubString(char* pch)
{
	int count = 0;
	char* p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count++;
		}
		else
		{
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count2--;
		}
		else
		{
			break;
		}
		if (count2 == 0)
			return (count);
		return 0;
	}
}
void ModifyString(char* pTest)
{
	char* p1 = pTest;
	char* p2 = p1;
	while(*p1!='\0')
		
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			printf(p2, "%i", count);
			while (*p2 != '\0')
			{
				p2++;
			}
			p1 += count + count + 1;
		}
		else
		{
			*p2++ = *p1++;
		}
	}
}
void main(void)
{
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf(text);
}
/*
class A
{
public:
	A()
	{
		printf("A");
	}
	~A()
	{
		printf("deA ");
	}
};
class B
{
public:
	B()
	{
		printf("B ");
	}
	~B()
	{
		printf("deB ");
	}
};
class C :public A, public B
{
public:
	C()
	{
		printf("C");
	}
	~C()
	{
		printf("deC ");
	}
};
int main()
{
	A* a = new C();
	delete a;
	return 0;
}


/*
class myclass
{
	myclass::foo() {
		delete this;
	}
	void func() {
		myclass* a = new myclass();
		a->foo();
	}
};

/*

static int a = 1;
void fun1(void) { a = 2; }
void fun2(void) { int a = 3; }
void fun3(void) { static int a = 4; }
int main(int argc, char* argv[])
{
	printf("%d", a);

	fun1();
	printf("%d", a);
	fun2();
	printf("%d", a);
	fun3();
	printf("%d", a);


}

/*
class A
{
public:
	void f()
	{
		printf("A\n");
	}
};
class B :public A
{
public:
	virtual void f()
	{
		printf("B\n");
	}
};
int main()
{

	A* a = new B;
	a->f();
	delete a;
	return 0;
}*/