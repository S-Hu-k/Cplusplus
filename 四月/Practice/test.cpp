/*
#include<iostream>
#include<vector>
using namespace std;
int fun(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fun(n - 1) + fun(n - 2);
    
    for (unsigned i = 2; i < 1000000; ++i)
    {
        v.push_back(fun(i));
    }
}
int main()
{
    vector<unsigned> v;
    size_t n = 0;
    size_t step = 0;
    cin >> n;
    for (unsigned i = 0; i < 1000000; ++i)
    {
        if (n > v[i] && n < v[i + 1])
            return i;
        int x=
    }

}

/*
#include <iostream>
#include <vector>
#include<string>
using namespace std;
class A
{
    friend long fun(A s)
    {
        if(s.x<3)
        {
            return 1;
        }
        return s.x + fun(A(s.x - 1));
    }
public:
    A(long a)
    {
        x = a--;
    }
private:
    long x;
};
int main()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += fun(A(i));
    }
    cout << sum;
}



/*
#include <iostream>
#include <vector>
using namespace std;
void main()
{
    int a = 1, b = 0, c = -1, d = 0;
    d = ++a || ++b && ++c;
    cout << d << endl;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int W, H, ret = 0;
    // ����vector�Ķ�ά���������
    vector<vector<int>> v;
    cin >> W >> H;
    // ���ٺ��ſռ�
    v.resize(W);
    // �������ſռ�
    // �Ƚ����е�����ȫ��Ϊ1����󽫲����ϵ���Ϊ0
    for (auto& e : v)
    {

        e.resize(H, 1);
    }

    // ѭ���������е�����
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (v[i][j] == 1)
            {
                ret++;
                // ������Ż����ѿ�֮�����2���Ϳ���ֱ����Ϊ0
                // ret��������ж��ٸ�����
                if ((i + 2) < W)
                    v[i + 2][j] = 0;
                if ((j + 2) < H)
                    v[i][j + 2] = 0;
            }
        }
    }
    // ��ӡ
    cout << ret << endl;
    return 0;
}
/*���ַ���ת��������
class Solution {
public:
    int StrToInt(string str) {
        int tmp = 0;
        int f = 1;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                if (str[i] == '+')
                    ;
                else if (str[i] == '-')
                    f = -1;
                else
                    return 0;
            }
            else
            {
                tmp = tmp * 10 + (str[i] - '0');
            }
        }
        return tmp * f;
    }

};




/*
#include<iostream>
using namespace std;
int f(int n)
{
    if (n == 1)
        return 1;
    else
        return (f(n - 1) + n * n * n);
}
int main()
{
    int s = f(3);
    cout << s << endl;
}
/*
#include<iostream>
using namespace std;
struct A
{
    long a1;
    short a2;
    int a3;
    int* a4;
};
int main()
{
    cout << sizeof(A);
    return 0;
}
/*
#include<iostream>
using namespace std;
char fun(char x, char y)
{
    if (x < y)
        return x;
    return y;
}
int main()
{
    int a = '1', b = '1', c = '2';
    cout << fun(fun(a, b), fun(b, c));
    return 0;
}
/*
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int m = 0123, n = 123;
    printf("%o %o", m, n);
}
/*
#include<iostream>
using namespace std;
int main()
{
    char a = 0, ch = 0;
    scanf("%c", ch);
    while ((ch = getchar()) != '\n')
    {
        if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
            ch = ch - 'a' + 'A';
        a++;
        putchar(ch);
    }
}



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
	D* p = new D("class A"��"class B"��"class C"��"class D");
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