
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
//
//输入描述 :
//每个测试输入包含2个字符串
//输出描述 :
//输出删除后的字符串
//示例1
//输入
//They are students.aeiou
//输出
//Thy r stdnts.
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string str1, str2;
//    //使用 cin，会导致遇到空格就结束的情况
//    getline(cin, str1);
//    getline(cin, str2);
//    //创建哈希数组计算字符出现的次数
//    int hashtable[256] = { 0 };
//    for (size_t i = 0; i < str2.size(); i++) {
//        hashtable[str2[i]]++;
//    }
//    //创建临时对象，然后将没有重复的字符，返回到 ret 对象中
//    string ret;
//    for (size_t i = 0; i < str1.size(); i++) {
//        if (hashtable[str1[i]] == 0)
//            ret += str1[i];
//    }
//
//    cout << ret << endl;
//    return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string s1, s2;
//    getline(cin, s1);
//    getline(cin, s2);
//    for (int i = 0; i < s2.size(); i++)
//    {
//        int index;
//        while ((index = s1.find(s2[i])) != -1)
//        {
//            s1.erase(index, 1);
//        }
//    }
//    cout << s1 << endl;
//    return 0;
//}





//牛牛举办了一次编程比赛, 参加比赛的有3* n个选手,【https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b】
//每个选手都有一个水平值a_i.现在要将这些选手进行组队,
//一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如 :
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//而如果方案为 :
//    team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//    没有比总和为10更大的方案, 所以输出10.
//
//    输入描述 :
//    输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//
//    第二行包括3* n个整数a_i(1 ≤ a_i ≤ 10 ^ 9), 表示每个参赛选手的水平值.
//
//    输出描述 :
//    输出一个整数表示所有队伍的水平值总和最大值.
//
//    输入例子 :
//    2
//    5 2 8 5 1 5
//
//    输出例子 :
//    10
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    while (cin >> n) {
//        long long sum = 0;//因为其累加和的数据较大
//        vector<int> a;
//        a.resize(3 * n);
//        for (int i = 0; i < 3 * n; i++) {
//            cin >> a[i];
//        }
//    std:sort(a.begin(), a.end());//排序
//        for (int i = n; i <= 3 * n - 2; i += 2) {//取每一个中间值
//            sum += a[i];//进行累加
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}




/*
#include<iostream>
using namespace std;
struct a
{
    void foo() { printf("foo"); }
    virtual void bar(){ printf("bar"); }
    a() { bar(); }
};
struct b :a {
    void foo() { printf("b-foo"); }
    void bar() { printf("b-bar"); }
};
void main()
{
    a* p = new b;
    p->foo();
    p->bar();
}
/*
#include<iostream>
using namespace std;
int fun(int n, int m)
{
    if (m <= 0 || n <= 0)
        return 0;
    else if (n == 1 || m == 1)
        return 1;
    else
        return fun(n - 1, m) + fun(n, m - 1);

}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << fun(n, m) << endl;
    return 0;
}










/*
#include<iostream>
using namespace std;
class MyClass {
public:
    MyClass(int i = 0) { cout << 1; }
    MyClass(const MyClass& x) { cout << 2; }
    MyClass& operator=(const MyClass& x) { cout << 3; }
    ~MyClass() { cout << 4; }

};
int main()
{
    MyClass obj1(1), obj2(2), obj3(obj1);
    return 0;
}
/*
class Test {
public:
    int a;
    int b;
    virtual void fun(){}
    Test(int temp1 = 0, int temp2 = 0)
    {
        a = temp1;
        b = temp2;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;                       
    }
};
int main()
{
    Test obj(5, 10);
    int* pInt = (int*)&obj;
    *(pInt + 0) = 100;
    *(pInt + 1) = 200;
    cout << "a=" << obj.getA() << endl;
    cout << "b=" << obj.getB() << endl;
    return 0;

}














/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//判断一个字符串数组中的字符串是不是按照字典排序的
bool is_dict_rank(vector<string>& vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}
//判断一个字符串数组中的字符串是不是按照长度排序
bool is_len_rank(vector<string>& vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i].size() > vec[i + 1].size())
        {
            return false;
        }
    }	return true;
}
int main()
{
    int n;
    cin >> n;//输入几个字符串 
    vector<string> v;
    v.resize(n+1); 	//将字符串输入到字符串数组v中	
    for (int i = 0; i < n; i++)
    {
        cin.get();//取走缓冲区中的\n符	
        getline(cin, v[i]);
    }
    if (is_dict_rank(v) && !is_len_rank(v))
    {
        cout << "lexicographically" << endl;
    }
    else if (!is_dict_rank(v) && is_len_rank(v))
    {
        cout << "lengths" << endl;
    }
    else if (is_dict_rank(v) && is_len_rank(v))
    {
        cout << "both" << endl;
    }
    else if (!is_dict_rank(v) && !is_len_rank(v))
    {
        cout << "none" << endl;
    }
    return 0;
}



/*
#include<iostream>
#include<string>
using namespace std;
void main()
{
    char array[] = "abcdefghijklmnopqrstuvwxyz";
    string str;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
    }

}





/*
#include<iostream>
using namespace std;
class cla {
    static int n;
public:
    cla() { n++; }
    ~cla() { n--; }
    static int get_n() { return n; }
};
int cla::n = 0;
int main()

{
    cla* p = new cla;
    delete p;
    cout << "n=" << cla::get_n() << endl;
    return 0;
}


/*
#include<iostream>
using namespace std;
class a
{
public:
    a() :m_ival(0) { test(); }
    virtual void func() { std::cout << m_ival << ' '; }
    void test() { func(); }
public:
    int m_ival;
};
class b :public a
{
public:
    b() { test(); }
    virtual void func()
    {
        ++m_ival;
        std::cout << m_ival << ' ';
    }
};
int main(int argc, char* argv[])
{
    a* p = new b;
    p->test();
    return 0;
}



/*
#include<iostream>
using namespace std;
int main()
{
    int x;
    int y;
    cin >> x;
    cin >> y;
    cout << x << endl;
    cout << y << endl;
}
/*
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int m = 0123, n = 123;
    printf("%o %o\n", m, n);
    return 0;
}

/*
#include<iostream>
using namespace std;
int f(int n) {
    if (n == 1)
        return 1;
    else
        return (f(n - 1) + n * n * n);
}
int main()
{
    int s = f(3);
    cout << s << endl;
    return 0;
}

/*
#include<iostream>
using namespace std;
char fun(char x, char y) {
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
#include<string>
using namespace std;
int main()
{
    string str1, str2;
    //str1.size()计算出有多少种插法
    int len = str1.size() + str2.size() / 2;
    
    string str3 = str1;
    int* pc;
    for (int i = 0; i < str1.size(); ++i)
    {
        //str1.size()+str2.size()/2找出中间元素 定义两个指针 分别向前向后查找
        int* p1, * p2;
        int count = 0;
        str1.insert(pc, str2);
        while (len--)
        {
            if (str1[p1] == str1[p2])
            {
                p1--;
                p2++;
            }
        }
        pc++;
        count++;
    }
    cout << count << endl;
}
/*
#include<iostream>
using namespace std;
void main()
{
    int n[][3] = { 10,20,30,40,50,60 };
    int(*p)[3];
    p = n;
    cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
}
/*
#include<iostream>
using namespace std;
class b0
{
public:
    virtual void display()
    {
        cout << "bo::display0" << endl;
    }
};
class b1 :public b0
{
public:
    void display()
    {
        cout << "b1::display0" << endl;
    }
};
class d1 :public b1
{
public:
    void display() { cout << "d1::display0" << endl;}
};
void fun(b0 ptr)
{
    ptr.display();
}
int main()
{
    b0 B0;
    b1 B1;
    d1 D1;
    fun(B0);
    fun(B1);
    fun(D1);
}




//进制转换--给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

/*
#include<iostream>
using namespace std;
int main()
{
    //s表示通过进制转换后M的N进制数
    string s = "";
    string tables = "0123456789ABCDEF";//从二进制到十六进制的数的集合
    //输入某个数M，和需要转换的进制N
    int M = 0;
    int N = 0;
    cin >> M >> N;
    if (M == 0)
    {
        s = "0";
    }
    while (M)
    {
        if (M < 0)
        {
            M = -M;
            cout << "-";
        }
        s = tables[M % N] + s;
        M /= N;
    }
    //注意：因为s是字符串，最好在输出的时候将该字符串以C风格显示出来即就是s.c_str(),
    //某些编译器可以跑过，但有的编译器就必须加上
    cout << s.c_str() << endl;
    return 0;
}






/*
#include<iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}



/*
#include<iostream>
using namespace std;
class a {
public:
    a(char* s)
    {
        cout << s << endl;
    }
    ~a() {}
};
class b :virtual public a
{
public:
    b(char* s1, char* s2) :a(s1) {
        cout << s2 << endl;
    }
};
class c :virtual public a
{
public:
    c(char* s1, char* s2) :a(s1) {
        cout << s2 << endl;
    }
};
class d :public b, public c
{
public:
    d(char* s1, char* s2, char* s3, char* s4) :b(s1, s2), c(s1, s3), a(s1)
    {
        cout << s4 << endl;
    }
};
int main()
{
    d *p = new d("class a", "class b", "class c", "class d");
    delete p;
    return 0;
}



//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        int num = numbers.size();
        int count = 0;
        for (int i = 0; i < num; i++)
            if (numbers[i] == numbers[num / 9])
                count++;
        if (count > num / 2)
            return numbers[num / 2];
        else
            return 0;
    }
};



/*#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int MoreThanHalfNum_Solution()

{
    vector<int> numbers;
    int len = numbers.size() / 2;
    sort(numbers.begin(), numbers.end());
    auto start = numbers.begin();
    while (start != numbers.end())
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            vector<int>::iterator k = numbers.find(numbers.begin(), numbers.end(), numbers[i]);
            vector<int>::iterator j = numbers.find(numbers.rbegin(), numbers.rend(), numbers[i]);
            if (j - k > len)
                return numbers[j];
            else
                return 0;
        }
    }

};



#include<algorithm>
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int len = numbers.size() / 2;
        sort(numbers.begin(), numbers.end());
        auto start = numbers.begin();
        while (start != numbers.end())
        {
            for (int i = 0; i < numbers.size(); i++)
            {
                int k = numbers.find(numbers.begin(), numbers.end(), numbers[i]);
                int j = numbers.find(numbers.rbegin(), numbers.rend(), numbers[i]);
                if (j - k > len)
                    return numbers[j];
                else
                    return 0;
            }
        }

    }
};

for (int i = 0; i < len; i++) {
	int count = 0;
	for (int j = 0; j < len; j++) {
		if (array[j] == array[i]) {
			count++;
		}
	}
	if (count > (len / 2)) {
		return array[i];
 */


/*
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    vector<int> array;
    array.push_back(100);
    array.push_back(300);
    array.push_back(300);
    array.push_back(300);
    array.push_back(300);
    array.push_back(500);
    vector<int>::iterator itor;
    for (itor = array.begin(); itor != array.end(); itor++)
    {
        if (*itor == 300)
        {
            itor = array.erase(itor);
        }
        for (itor = array.begin(); itor != array.end(); itor++)
        {
            cout << *itor << " ";
        }
        return 0;
    }

}



/*
int func()
{
    int i, j, k = 0;
    for(i=0,j=-1;j=0;i++,j++)
    {
        k++;
    }
    return k;
}
int main()
{
    cout << (func());
}

//在未排序的数组中找到第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};


//将一句话的单词进行倒置  标点符号不倒置
//比如 I like beijing.经过函数后变为：beijing.like I
/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int count = 0;
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    auto start = s.begin();
    while (start != s.end())
    {
        auto end = start;
        while (end != s.end() && *end != ' ')
        {
            end++;
        }
        reverse(start, end);
        if (end != s.end())
        {
            start = end + 1;
        }
        else
        {
            start = end;
        }
    }
    cout << s << endl;
}



/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{    
    string s= "hecdlo.";   
  
    reverse(s.begin(),s.end());   
    cout<<s<<endl;   
    cout <<  s.size() << endl;
    return 0;
}

/*
#include<iostream>
using namespace std;
class sample 
{
public:
    sample(int x) 
    {
        p = new int(x);
    }
    ~sample() 
    {
        if (p)
            delete p;
    }
    int show() 
    {
        return *p;
    }
private:
    int* p;
};
int main()
{
    sample s(5);
    cout << s.show() << endl;
    return 0;
}
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//举个例子：输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string longstr;
    string shortstr;
    getline(cin, longstr);
    getline(cin, shortstr);
    for (auto i = longstr.begin(); i != longstr.end(); ++i)
    {
        //将长字符串中每个字符取出，在短字符串中依次匹配，保存该位置
        auto ret = find(shortstr.begin(), shortstr.end(), (*i));
        if (ret != shortstr.end())
        {
            //若该位置有效，则删除长字符串中该字符
            longstr.erase(i);
            //i位置的被删除了，必须将i--
            --i;
        }
    }
    cout << longstr << endl;
    return 0;
}
*/

/*
#include<iostream> 
#include<string.h>
using namespace std;
char* Function(char* str1, char* str2)
{
    if (str1 == nullptr || str2 == nullptr)
        return str1;
    const int tableSize = 256;
    unsigned int hashTable[tableSize] = { 0 };
    for (int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;
    char* pHashKey = str2;
    while (*pHashKey != '\0')
        hashTable[*(pHashKey++)]++;
    int len1 = strlen(str1);
    char* temp = (char*)malloc(len1 * sizeof(char));
    temp[len1] = '\0';
    int j = 0;
    for (int i = 0; i < len1; ++i)
    {
        if (hashTable[str1[i]] == 0)
            temp[j++] = str1[i];
    }
    temp[j] = '\0';
    return temp;
} int main()
{
    char str1[] = "They are students.";
    char str2[] = "aeiou";
    char* str3 = Function(str1, str2);
    cout << str3 << endl;
    system("pause");
    return 0;
}
*/