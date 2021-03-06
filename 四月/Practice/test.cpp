/*#include<iostream>
using namespace std;
int main()
{
    size_t n;
    int cnt;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cnt = 0;
        while (n >= 2)
        {
            if (n % 3)
                n = n / 3 + 1;
            else
                n /= 3;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;

}*/
class Solution {
public:
    /**
     *	正数数组中的最小不可组成和
     *	输入：正数数组arr
     *	返回：正数数组中的最小不可组成和
     */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        int i, j;
        for (int i = 0; i < len; ++i) {
            sum += arr[i];
            min = arr[i] < min ? arr[i] : min;
        }
        vector<int> dp(sum + 1, 0);
        for (i = 0; i < len; ++i) {
            // 有length个数据，有length个阶段
            // {2, 3, 5}
            //i=0--d[10]=2 d[9]=2 d[8]=2 d[7]=2...d[2]=2            
            //i=1--d[10]=5 d[9]=5...d[5]=5 d[4]=3 d[3]=3         
            //i=2--d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5
            for (j = sum; j >= arr[i]; --j) {
                //逆序判断背包承重中能够放入的数据                
               //当数组中只有2的时候，背包承重从2-10都可以放入2的数值              
               //当数组中放入2和3的时候，背包承重从5-10可以放入5，3-4放入3，2只能放入2
               //当数组中放入2，3，5时，背包承重10放入10，8-9放入8，7放入7，5-6放入5...                
               //dp[j-arr[i]]意思是背包承重为j时，如果已经放置了arr[i]的重量后还能放置的最大重量 
                if (dp[j] < dp[j - arr[i]] + arr[i]) // 对每个承重计算当前最大能放置重量
                    dp[j] = dp[j - arr[i]] + arr[i]; // 更新背包中能够放入的最大值
                else
                    dp[j] = dp[j];
            }
        }
        // 最后当承重为n时，放入的重量不为n则认为是最大不可求和
        for (i = min; i <= sum; ++i) {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
};
/*
#include<iostream>
using namespace std;
int main()
{
    unsigned int n = 0;
    unsigned int count = 0;
    while (cin >> n)
    {
        if (n == 0 && n==1)
            return 0;
        
        else
        {
            while (n != 1)
            {
                n /= 2;
                count++;
            }
            cout << count << endl;


        }
       
    }
}

/*
猴子分桃
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        long a = 0, b = 0;
        if (n == 0)
            break;
        else
        {
            a = pow(5.0, n) - 4; // 5的20次方数值超过int的大小
            b = pow(4.0, n) + n - 4;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}




class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
/*
    void oddInOddEvenInEven(vector<int>& arr, int len)
    {
        int i = 0, j = 1;
        while (i < len && j < len)
        {
            if ((arr[i] & 1) == 0) //偶数位上寻找非偶数，否则跳过
            {
                i += 2;
                continue;
            }
            if ((arr[j] & 1) == 1) //奇数位上寻找非奇数，否则跳过
            {
                j += 2;
                continue;
            }
            swap(arr[i], arr[j]);
            i += 2;
            j += 2;
        }


    }
};






#include<iostream>
using namespace std;
int shugen(int number)
{
    int sum = 0;
    if (number == 0)
        return 0;
    if (number)
    {
        sum += number % 10 + number / 10;
    }
    if (sum > 9)
        return shugen(sum);
    else
        return sum;

}
int main()
{
    string n;
    while (cin >> n)
    {
        int b = 0;
        for (int i = 0; i < n.size(); ++i)
        {
            b += n[i] - '0';
        }
        cout << shugen(b) << endl;
    }
    return 0;
}
/*#include<iostream>
using namespace std;
//删除字符串中出现次数最少的字符的函数接口
string Del_Str(string str)
{
    string Del_str; //删除字符串中出现次数最少的字符后的字符串
    int a[26] = { 0 }; //初始化一个数组，记录输入的字符串中每个小写字母出现的次数
    int len = str.size(); //获取字符串的长度
    int min = 1000; //出现次数最少的字符的出现次数，自然不能为 0
    //采用小写字母的 ASCII 码作为数组的下标，对应地记录字符串中每个小写字母字符出现的次数
    for (int i = 0; i < len; i++)
    {
        a[str[i] - 'a'] += 1;
    }
    //获取字符串中出现次数最少的字符的次数
    for (int i = 0; i < 26; i++)
    {
        if ((a[i] <= min) && (a[i] != 0))
        {
            min = a[i];
        }
    }
    //得到不包含字符串中出现次数最少的字符的字符串
    for (int i = 0; i < len; i++)
    {
        if (a[str[i] - 'a'] > min)
        {
            Del_str += str[i];
        }
    }
    return Del_str; //返回删除字符串中出现次数最少的字符后的字符串
}
//主函数
int main()
{
    string str;
    while (cin >> str)
    {
        cout << Del_Str(str) << endl;
    }
    return 0;
}
//#include<iostream>
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<sstream>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//    string s;
//    int count[26];
//    int i, j;
//    while (cin >> s)
//    {
//        memset(count, 0, sizeof(count));
//        //统计字母出现的次数
//        //a-z的ASCII码为97-122,通过s[i]-97转成对应的数组下标
//        for (i = 0; i < s.length(); i++)
//            count[s[i] - 97]++;
//
//        int min = count[s[0] - 97];
//
//        for (i = 0; i < s.length(); i++)
//            if (count[s[i] - 97] <= min)
//                min = count[s[i] - 97];
//        for (i = 0; i < s.length(); i++)
//            if (count[s[i] - 97] > min)
//            {
//                cout << s[i];
//            }
//        cout << endl;
//    }
//}
class Solution {
public:
    /**
     *
     * @param A int整型一维数组
     * @param n int A数组长度
     * @param target int整型
     * @return int整型
     */
/*
    int search(int* A, int n, int target) {
        // write code here
        int left = 0;
        int right = n - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[left] <= A[mid]) {
                if (target < A[mid] && target >= A[left])
                    right = mid - 1;
                else
                    left = mid + 1;

            }
            else {
                if (target > A[mid] && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

**************************************************************************
public class Solution {
    public ListNode FindKthToTail(ListNode head, int k) {

        if (k <= 0)
            return null;
        ListNode low = head;//倒数第k个节点
        ListNode fast = head;
        for (int i = 1; i < k; i++) {
            if (fast == null)
                return null;
            else
                fast = fast.next;
        }
        if (fast == null)
            return null;
        while (fast.next != null) {
            low = low.next;
            fast = fast.next;
        }
        return low;
    }
}
//https://www.nowcoder.com/practice/6c9d8d2e426c4c58bbadfdf67d591696?tpId=137&rp=1&ru=%2Fta%2Fexam-bytedance&qru=%2Fta%2Fexam-bytedance%2Fquestion-ranking
//将字典序视作一个树，寻找m次则循环m次来找寻结果
//如果在这个区间内则M在这个区间内查找，否则让梯度乘以10向上查找，知道找寻一个区间内，让i+1一个一个查找
//第一步while循环是判断是否查到这个位置，第二次则是写出num在这个区间内有多少个数
//本题不用构造一颗字典序树，却用到树的概念
//以十个十个数为区间计算
//此上均是自己的一点看法，本人不才，望指教
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long n, m;
    cin >> n >> m;
    long i = 1;
    m--;
    while (m != 0) {
        long start = i, end = i + 1;
        long num = 0;
        while (start <= n)
        {
            num += min(n + 1, end) - start;
            start *= 10;
            end *= 10;
        }
        if (num > m)
        {
            i *= 10;
            m--;
        }
        else
        {
            m -= num;
            i++;
        }
    }
    cout << i << endl;
    return 0;
}
//【把200个数按照字典输出】
//#include<iostream>*/
//#include<vector>
//using namespace std;
//int main()
//{
//    unsigned int n = 0;
//    while (cin >> n)
//    {
//
//    }
//}
//

/*
#include<iostream>
#include<string>
using namespace std;
class a
{
public:
    void print()
    {
        cout << "a ::print";
    }
};
class b :private a
{
public:
    void print()
    {
        cout << "b ::print";
    }
};
class c :public b
{
public:
    void print()
    {
        a::print()
            ;
    }
};
int main()
{
    c n;
    n.print();
}
/*int main()
{
    string addend;
    string augend;
    string sum;
    while (cin >> addend >> augend)
    {
        for (int i = addend.size() - 1; i != 0; --i)
        {
            for (int j = augend.size() - 1; j != 0; --j)
            {
                while (j == 0 || i == 0)
                {
                    sum = augend[j] + addend[i];
                }
            }
        }
        
    }
    cout << sum << endl;
}
/*#include<iostream>
using namespace std;
int main()
{
    char* ptr;
    char mystring[] = "abcdefg";
    ptr = mystring;
    ptr += 5;
    cout << *ptr << endl;
}
/*class a
{
public:
    ~a()
    {
        cout << "~a" << endl;
    }
}; class b
{
public:
   virtual ~b()
    {
        cout << "~b" << endl;
    }
};
class c:public a,public b
{
public:
    ~c()
    {
        cout << "~c" << endl;
    }
};
int main()
{
    c* C = new c;
    b* b1 = dynamic_cast<b*>(C);
    a* a2 = dynamic_cast<a*>(b1);
    delete a2;
}
/**
int main()
{
char* p = "abc";
char* q = "abc123";
while (*p = *q)
{
    printf("%c %c", *p, *q);
}
}

/*class a
{
public:
    a()
    {
        p();
    }
    virtual void p()
    {
        printf("a");
    }
    virtual ~a()
    {
        p();
    }
};
class b:public a
{
public:
   b()
    {
        p();
    }
    virtual void p()
    {
        printf("b");
    }
    virtual ~b()
    {
        p();
    }
};
int main()
{
    a* A = new b();
    delete A;
}
/*
int main()
{
    int a[] = { 1,2,3,4,5 };
    int* p[] = { a,a + 1,a + 2,a + 3 };
    int** q = p;
    cout << *(p[0] + 1) + **(q + 2) << endl;
    return 0;
}
/*template<class T>
struct sum
{
    static void foo(T op1, T op2)
        cout << op1 << op2;
};
int main()
{
    sum<int>::foo(1, 3);
}

/*
#include<iostream>
using namespace std;
bool judgeperfect(int x)
{
    if (x < 0 || x>500000)
        return -1;
    int sum = 0;
    for (int i = 1; i < x; ++i)
    {
        if (x % i == 0)
            sum += i;
    }
    if (sum == x)
        return true;
    else
        return false;
}
int main()
{
    int a = 0;
    cin >> a;
    int count = 0;
    for (int j = 1; j < a; ++j)
    {
        if (judgeperfect(j) == true)
            count++;
    }
    cout << count << endl;
    return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;
class base
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
class derived :public base
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
    derived stdervied;
    base* pstbase = &stdervied;

    char x[10];
    printf("%d", pstbase->foo(100) + pstbase->foo(x));
    return 0;
}
/*
class a
{
public:
    void funca()
    {
        printf("funca called");

    }
    virtual void funcb()
    {
        printf("funcb called");
    }
};
class b :public a
{
    void funca()
    {
        a::funca();
        printf("funcab called");
    }
    virtual void funcb()
    {
        printf("funcbb called");
    }
};
void main()
{
    b B;
    a* pa;
    pa = &B;
    a* pa2 = new a;
    pa->funca();
    pa->funcb();
    pa2->funca();
    pa2->funcb();
    delete pa2;
}
/*
int main()
{
    const int a = 10;
    int* p = (int*)(&a);
    *p = 20;
    cout << a << endl;
    cout << *p << endl;
    return 0;
}
/*
int findsubstring(char* pch)
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
    }int count2 = count;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] + 1)
        {
            p1++;
            count2--;
        }
        else
        {
            break;
        }

    }
    if (count2 == 0)
        return count;
    return 0;
}
void modifystring(char* ptext)
{
    char* p1 = ptext;
    char* p2 = p1;
    while (*p1 != '\0')
    {
        int count = findsubstring(p1);
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
int main()
{
    char test[32] = "XYBCDCBABABA";
    modifystring(test);
    printf(test);
}
/*
class A
{
public:
    A()
    {
        printf("A ");
    }
    ~A()
    {
        printf("dea");
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
        printf("deB");
    }
};
class C :public A,public B
{
public:
    C()
    {
        printf("C ");
    }
    ~C()
    {
        printf("deC");
    }
};
int main()
{
    A* a = new C();
    delete a;
    return 0;
 }
/*
class a
{
public:
    void f()
    {
        printf("a\n");
    }
};
class b :public a
{
public:
    virtual void f()
    {
        printf("b\n");
    }
};
int main()
{
    a* A = new b;
    A->f();
    delete A;
    return 0;
}
/*
bool isleepyear(int y)
{
    if ((y % 4 == 0 && y % 100 == 0) || (y % 400 == 0))
        return true;
    else
        return false;
}
int main()
{
    int sum = 0;
    int year = 0;
    int mouth = 0;
    int day = 0;
    
    while (cin >>year>>mouth>>day)
    {
        if (mouth > 2)
        {
            if (isleepyear(year))
            {
                int x2 = mouth / 2;
                sum = x2 * 31 * (x2 - 1) * 30 + 29 + day;

            }
            else
            {
                int x2 = mouth / 2;
                sum = x2 * 31 * (x2 - 1) * 30 + 28 + day;
            }
            return sum;
        }
        if (mouth == 1)
            sum=  day;
        return sum;
        if (mouth == 2)
        {
            if (isleepyear(year))
                 sum=31 + day;
            return sum;
        }
        
    }
   cout << sum << endl;
    return 0;
}

/*
#include<iostream>
using namespace std;
class a
{
public:
    int getvalue()const {
        vv = 1;
        return vv;
    }
private:
    mutable int  vv;
};
/*
class base
{
public:
    base(int j):i(j)
    {}
    virtual ~base()
    {}
    void func1()
    {
        i *= 10;
        func2();
    }
    int getvalue()
    {
        return i;
    }
protected:
    int i;
};
class child :public base
{
public:
    child(int j):base(j)
    {}
    void func1()
    {
        i *= 100;
        func2();
    }
protected:
    void func2()
    {
        i += 2;
    }
};
int main()
{
    base* pb = new child(1);
    pb->func1();
    cout << pb->getvalue() << endl;
    delete pb;
}

/*
#include<iostream>
using namespace std;
int main()
{
    char str[] = "glad to test something";
    char* p = str;
    p++;
    int* p1 = reinterpret_cast<int*>(p);
    p1++;
    p = reinterpret_cast<char*>(p1);
    cout << p << endl;
}
/*
#include<iostream>
using namespace std;

int function(unsigned int n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}
int main()
{
    cout << function(197) << endl;
}
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count = 0;
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
                count++;
            if(str[i]=='"')
                do
                {
                    i++;
                } while (str[i] != '"');
        }
        cout << count + 1 << endl;

    }
}


/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        // 计数空格的数量
        int count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
                count++;
            if (str[i] == '"')
            {
                do {
                    i++;
                } while (str[i] != '"');
            }
        }
        // 参数的个数一定比空格多1
        cout << count + 1 << endl;

        int flag = 1;
        for (int i = 0; i < str.size(); i++)
        {
            // 如果是“的话就flag置为0
            if (str[i] == '"')
                flag ^= 1;

            // 不是空格和双引号直接打印
            if (str[i] != ' ' && str[i] != '"')
                cout << str[i];

            // 不在双引号内的空格直接换行
            if (str[i] == ' ' && (flag))
                cout << ' ' << endl;

            // 双引号内的空格直接打印
            if (str[i] == ' ' && (!flag))
                cout << str[i];
        }
    }
    cout << endl;
    return 0;
}


/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string str;
    vector<string> str;
    while (getline(cin, str))
    {

    }

}

/*
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class b
{
public:
    b()
    {
        cout << " default construct" << " ";
    }
    ~b()
    {
        cout << "desstruct" << " ";
    }
    b(int i) :data(i)
    {
        cout << "constructed by parameter" << data << " ";
    }
private:
    int data;
};
b Play(b  B)
{
    return  B;
}int main()
{
    b temp = Play(5);
    return 0;
}




/*
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class A
{
public:
    virtual void print()
    {
        cout << "a::print()" << endl;
    }
};
class B :public A
{
public:
    virtual void print()
    {
        cout << "b::print()" << endl;
    }
};
class C :public A
{
public:
    virtual void print()
    {
        cout << "c::print()" << endl;
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
/*

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int i, a[10];
    for (i = 9; i >= 0; --i)
    {
        a[i] = 10 - i;
        
    }
    printf("%d%d%d", a[2], a[5], a[8]);
    return 0;
}




/*

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
    else //格子数为0，直接返回0
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
//根据字典排序
bool dec_inorder(vector<string>& v, int n)
{
        for (unsigned int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
                return false;
        }
        return true;
}
//根据长度排序
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
int cla::n = 0;//静态变量要在类外初始化
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
    // 利用vector的二维数组来解决
    vector<vector<int>> v;
    cin >> W >> H;
    // 开辟横排空间
    v.resize(W);
    // 开辟列排空间
    // 先将所有的数字全置为1，最后将不符合的置为0
    for (auto& e : v)
    {

        e.resize(H, 1);
    }

    // 循环遍历所有的数字
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (v[i][j] == 1)
            {
                ret++;
                // 任意横排或者裂开之间相距2，就可以直接置为0
                // ret控制最火有多少个蛋糕
                if ((i + 2) < W)
                    v[i + 2][j] = 0;
                if ((j + 2) < H)
                    v[i][j + 2] = 0;
            }
        }
    }
    // 打印
    cout << ret << endl;
    return 0;
}
/*把字符串转化成整数
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
	D* p = new D("class A"，"class B"，"class C"，"class D");
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