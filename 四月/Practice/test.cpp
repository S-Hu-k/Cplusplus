
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long score = 0;
    string str;
    getline(cin , str);

    if (str.size() <= 4)
        score += 5;
    else if (str.size() > 5 && str.size() < 7)
        score += 10;
    else if (str.size() >= 8)
        score += 25;
    int c1=0, c2=0, c3=0, c4=0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            c1++;
        if (str[i] >= 'A' && str[i] <= 'Z')
            c2++;
        if (str[i] >= '0' && str[i] <= '9')
            c3++;
        if ((str[i] >= 0x21 && str[i] <= 0x2F) ||
            (str[i] >= 0x3A && str[i] <= 0x40) ||
            (str[i] >= 0x5B && str[i] <= 0x60) ||
            (str[i] >= 0x7B && str[i] <= 0x7E))
            c4++;
    }
    if (c1 == 0 && c2 == 0)
        score += 0;
    else if ((c1 != 0 && c2 == 0) || (c1 == 0 && c2 != 0))
        score += 10;
    else if (c1 != 0 && c2 != 0)
        score += 25;
    
    if (c3 == 0)
        score += 0;
    else if (c3 == 1)
        score += 10;
    else if (c3 > 1)
        score += 20;

    if (c4 == 0)
        score += 0;
    else if (c4 == 1)
        score += 10;
    else if (c4 > 1)
        score += 25;

    if ((c1 != 0 && c2 != 0) && c3 != 0 && c4 != 0)
        score += 5;
    else if (((c1 != 0 && c2 == 0) || (c1 == 0 && c2 != 0)) && c3 != 0 && c4 != 0)
        score += 3;
    else if (c4 == 0 && c3 != 0 &&
        ((c1 != 0 && c2 == 0) || (c1 == 0 && c2 != 0)))
        score += 2;



    if (score >= 90)
        cout << "VERY_SECURE" << endl;
    else if (score >= 80)
        cout << "SECURE" << endl;
    else if (score >= 70)
        cout << "VERY_STRONG" << endl;
    else if (score >= 60)
        cout << "STRONG" << endl;
    else if (score >= 50)
        cout << "AVERAGE" << endl;
    else if (score >= 25)
        cout << "WEAK" << endl;
    else
        cout << "VERY_WEAK" << endl;

    return 0;


}




























/*

#include<iostream>
#include<vector>
using namespace std;
class Board
{
public:
    bool checkWon(vector<vector<int> > board)
    {
        int sum = 0;
        int a = board.size();
        for (int i = 0; i < a; ++i)
        {
            int sum = 0;
            for (int j = 0; j < a; ++j)
            {

                sum += board[i][j];
            }
            if (sum == a)
                return true;
        }
        /////////////////////////////////////////////////
        for (int i = 0; i < a; ++i)
        {
            int sum = 0;
            for (int j = 0; j < a; ++j)
            {
                sum += board[j][i];
            }
            if (sum == a)
                return true;
        }
        ///////////////////////////////////////////////////////////
        for (int i = 0; i < a; i++)
        {
            sum = 0;
            sum += board[i][i];
        }
        if (sum == a) 
        {
            return true;
        }
        ///////////////////////////////////////////////
        for (int i = 0; i < a; i++)
        {
            sum += board[i][a - i - 1];
        }
        if (sum == a)
        {
            return true;
        }
        return false;
    }
};
/*
class Board
{
public:
    bool checkWon(vector<vector<int> > board)
    {
        int a = board.size();
        for (int i = 0; i < a; ++i)
        {
            int sum = 0;
            for (int j = 0; j < a; ++j)
            {

                sum += board[i][j];
            }
            if (sum == a)
                return true;
        }
        /////////////////////////////////////////////////
        for (int i = 0; i < a; ++i)
        {
            int sum = 0;
            for (int j = 0; j < a; ++j)
            {
                sum += board[j][i];
            }
            if (sum == a)
                return true;
        }
        ///////////////////////////////////////////////////////////
        for (int i = 0; i < a; ++i)
        {
            int sum = 0;
            for (int j = 0; j < a; ++j)
            {

                sum += board[i][i];
            }
            if (sum == a)
                return true;
        }
        ///////////////////////////////////////////////
        for (int i = 0; i < a; ++i)
        {
            int sum = 0;
            for (int j = 0; j < a; ++j)
            {

                sum += board[j][j];
            }
            if (sum == a)
                return true;
        }
        return false;
    }
};










/*
#include<iostream>
using namespace std;
struct a
{
    void foo() { printf("foo"); }
    virtual void bar() { printf("bar"); }
    a() { bar(); }
};
struct b :a
{
    void foo() {
        printf("b_foo")
            ;
    }void bar() {
        printf("b_bar");
    }
};
int main()
{
    a* p = new b;
    p->foo();
    p->bar();
}
/*
int func(int x)
{
    int count = 0;
    while (x)
    {
        count++;
        x = x & (x - 1);
    }
    return count;
}
int main()
{
    cout << func(9999) << endl;
}
/*
#include<iostream>
using namespace std;
int main()
{
    int i = 1;
    if (i < 0)
    {
        printf("****\n");
    }
    else
        printf("%%%%\n");
}

/*
#include<iostream>
using namespace std;
int PathNum(int n, int m)
{
    if (n > 1 && m > 1)
        return PathNum(n - 1, m) + PathNum(n, m - 1);
    else if (((n == 1) && (m >= 1)) || ((n >= 1) && (m == 1)))
        return n + m;
    else //������Ϊ0��ֱ�ӷ���0
        return 0;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
        cout << PathNum(n, m) << endl;
    return 0;
}
/*
#include<iostream>
using namespace std;

int Go(int m, int n) {
    if (m < 0 || n < 0) {
        return 0;
    }
    else if (n == 0 || m == 0) {
        return 1;
    }
    else
        return Go(n - 1, m) + Go(n, m - 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    Go(m, n);
    cout << Go(m, n) << endl;
    system("pause");
    return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;
int go(int m, int n)
{
    if (m <= 0 || n <= 0)
        return 0;
    else if (m == 1 || n == 1)
        return 1;
    else
        return go(m, n - 1) + go(m - 1, n);

}
int main()
{
    int m, n;
    cin >> m >> n;
    go(m, n);
    cout << go(m, n) << endl;


}




/*
#include<iostream>
using namespace std;
class test
{
public:
    int a;
    int b;
    virtual void fun()
    {}
    test(int temp1 = 0, int temp2 = 0)
    {
        a = temp1;
        b = temp2;
    }int geta()
    {
        return a;
    }
    int getb()
    {
        return b;
    }
};
int main()
{
    test obj(5, 10);
    int* pint = (int*)&obj;
    *(pint + 0) = 100;
    *(pint + 1) = 200;
    cout << obj.geta() << endl;
    cout << obj.getb() << endl;
}

/*
#include<iostream>
using namespace std;
class myclass
{
public:
    myclass(int i = 0) { cout << 1; }
    myclass(const myclass& x) { cout << 2; }
    myclass& operator =(const myclass& x) { cout << 3; return *this; }
    ~myclass() { cout << 4; }
};
int main()
{
    myclass obj1(1), obj2(2), obj3(obj1);
    return 0;
}



/*
#include<iostream>
using namespace std;
void func(char** m)
{
    ++m;
    cout << *m << endl;
}
int main()
{
     char* a[] = { "morning","afternoon","evening" };
    char** p;
    p = a;
    func(p);
    return 0;
}
/*
#include<iostream>
using namespace std;
int fun(int n)
{
    int a = 0;
   a ^= (1 << 5) - 1;
    return a;
}
void func(int& nvall)
{

}
int main()
{
    int b = 0;
    func(b);
    cout << fun(21) << endl;
}
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//�����ֵ�����
bool dec_inorder(vector<string>& v, int n)
{
        for (unsigned int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
                return false;
        }
        return true;
}
//���ݳ�������
bool length_inorder(vector<string>& v, int n)
{
    for (unsigned int i = 0; i < v.size()-1; ++i)
    {
        if (v[i].size() > v[i + 1].size())
            return false;
    }
    return true;
    
}
int mian()
{
    int n = 0;
    string str;
    cin >> n;
    vector<string> v;
    v.resize(n);
    for (auto& str : v)
    {
        cin >> str;
    }
    if (length_inorder(v,n) && dec_inorder(v,n))
        cout << "both" << endl;
    else if (!length_inorder(v,n) && dec_inorder(v,n))
        cout << "lexicographically" << endl;
    else if (length_inorder(v,n) && !dec_inorder(v,n))
        cout << "lengths" << endl;
    else
        cout << "none" << endl;
    return 0;
}





/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n = 0;
    string str;
    cin >> n;
    vector<string> v;
    v.resize(n);
    for (auto& str : v)
    {
        cin >> str;
    }
    
}
/*
#include<iostream>
using namespace std;
class cla 
{
    static int n;
public:
    cla()
    {
        n++;
    }
    ~cla()
    {
        n--;
    }
    static int get_n() { return n; }
};
int cla::n = 0;//��̬����Ҫ�������ʼ��
int main()
{
    cla* p = new cla;
    delete p;
    cout << "n=" << cla::get_n() << endl;
    return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;
class A
{
public:
    A() :m_ival(0) { test(); }
    virtual void func() { std::cout << m_ival <<  ' '; }
    void test() { func(); }
public:
    int m_ival;
};
class B :public A
{
public:
    B() {
        test();
    }
    virtual void func() { ++m_ival;
    std::cout << m_ival << ' '; }

};
int main()
{
    A* p = new B;
    p->test();
    return 0;
}

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