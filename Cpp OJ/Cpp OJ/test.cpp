
/* 密码强度

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long score = 0;
    string str;
    getline(cin, str);

    if (str.size() <= 4)
        score += 5;
    else if (str.size() > 5 && str.size() < 7)
        score += 10;
    else if (str.size() >= 8)
        score += 25;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
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
【题目描述】请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
【输入描述】
输入两个正整数

【输出描述】
返回结果

示例1
【输入】
2
2
【输出】
6
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
最小公倍数
题目描述

正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

输入描述 :

输入两个正整数A和B。

输出描述 :

输出A和B的最小公倍数。

示例1

输入
5 7
输出
35

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int Mul = num1 * num2;

    while (num2)
    {
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    cout << Mul / num1 << endl;
}
    
/*两种排序方法
题目描述
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根 据字符串的字典序排序。例如：
“car” < “carriage” < “cats” < "doggies < “koala”
    2.根据字符串的长度排序。例如：
    “car” < “cats” < “koala” < “doggies” < “carriage”
    考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验 证。

    输入描述： 输入第一行为字符串个数n(n ≤ 100) 接下来的n行, 每行一个字符串, 字符串长度均小于100，均由小写字母组成
    输出描述： 如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
    如果根据长度排列而不是字典序排列输出"lengths",
    如果两种方式都符合输出"both"，否则输出"none"

    示例
    输入 : 3 a aa bbb
    输出 : both

    解题思路
    思路很简单，将接受的字符串都放到vector容器中，利用string的operator >= 运算符重载来按ascii比较字符 串，
    利用string的size来比较字符串的长度

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsE(vector<string> v)   //判断是否按字典排序
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

bool IsL(vector<string> v)    //判断是否按长度排序
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].size() > v[i + 1].size())
            return false;
    }
    return true;
}

int main()
{
    vector<string> v;
    int n = 0;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    if (IsE(v) && IsL(v))
        cout << "both" << endl;
    else if (IsE(v) && !IsL(v))
        cout << "lexicographically" << endl;
    else if (!IsE(v) && IsL(v))
        cout << "lengths" << endl;
    else
        cout << "none" << endl;
    system("pause");
    return 0;
}


/*
一，题目描述

Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
1
2
3
4
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, …，在Fibonacci数列中的数我们称为Fibonacci数。
给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入描述 :

输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)

输出描述 :

    输出一个最小的步数变为Fibonacci数"

    示例1

    输入

    15
    1
    输出

    2
    1
    二，程序分析过程

    1.根据题目分析，我们可以得出，就是要在斐波那契数列中找到我们输入进去的值，
    和数列中的数字，增加或者减少几次可以到输入的值。

    2.所以，根据这个道理，实现起来，就比较简单了，我们可以找到离输入值最近的两个数值，
    然后将这个值的左边被输入值减找小值，然后大的数值减输入值找到最大值。
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N, l = 0, r = 0, f, f0 = 0, f1 = 1;
    cin >> N;
    while (1)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        //寻找比f小的数
        if (f < N)
            l = N - f;
        else
        {
            //寻找比N大的值
            r = f - N;
            break;
        }
    }
    cout << min(l, r) << endl;
    return 0;
}

/*
不要二
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

/*
把字符串转化成整数
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
字符集合
题目描述
输入一个字符串，求出该字符串包含的字符集合

输入描述:
每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
输出描述:
每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
示例1

输入 复制    abcqweracb
输出 复制    abcqwer


#include "stdio.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        string ans;
        unordered_map<char, bool> table;
        for (auto item : str)
        {
            if (table.find(item) == table.end())
            {
                table[item] = 1;
                ans += item;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


#include<iostream>
#include<string>
#include<vector>
using namespace std;
void one(string str)
{
    vector<bool> a(256, false);
    for (int i = 0; i < str.size(); ++i)
    {
        if (a[str[i]] == false)
        {
            cout << str[i];
            a[str[i]] = true;
        }
    }
    cout << endl;
}
int main()
{
    string str;
    while (cin >> str)
    {
        one(str);

    }
    return 0;
}
/*
分糖果【https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34】
A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。

输入描述 :

输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。
输出描述 :

输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例1

输入
1 - 2 3 4
输出
2 1 3

#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    int A, B, C;
    while (cin >> a >> b >> c >> d)
    {
        A = (a + c) / 2;
        B = (b + d) / 2;
        C = (d - b) / 2;
        if (A - B == a && B - C == b && A + B == c && B + C == d)
        {
            cout << A << " " << B << " " << C << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
/*进制转换


#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxM = 36;    // 最大进制数 '0'-'9' + 'a'-'z' 共 36 种
const int maxn = 10000;

int M = 2;      // 原始进制
int N = 2;      // 目标进制

string str;     // 存储输入

// 所有数组 0 号元素均表示数组长度
int dr[maxn];       // 存储由字符串转过来的大数
int drans[maxn];    // 求余过程中的商
int drres[maxn];    // 余数

map<char, int> mci; // 字符与数字对应的map
map<int, char> mic; // 数字与字符对应的map

// 字符与数值对应map初始化
void initialization()
{
    // 字符与数字对应的map构建
    for (int i = 0; i < maxM; ++i)
    {
        if (i < 10)
        {
            // '0' - '9'
            mci['0' + i] = i;
            mic[i] = '0' + i;
        }
        else
        {
            // 'a' - 'z'
            mci['a' + i - 10] = i;
            mic[i] = 'a' + i - 10;
        }
    }
}

// 判断是否是大写字母
int isCapital(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 字符串预处理，并给存储原始进制的数组赋值
void pretreatment()
{
    // 将所有大写字母转换成小写
    for (int i = 0; i < str.length(); ++i)
    {
        // 大写字母转小写
        if (isCapital(str[i]) == 1)
        {
            str[i] = 'a' + str[i] - 'A';
        }
    }
    // 给存储原始进制的数组赋值
    memset(dr, 0, sizeof(dr));
    for (int i = 0; i < str.length(); ++i)
    {
        dr[++dr[0]] = mci[str[i]];
    }
}

// 将 M 进制的 dr 转换成 N 进制
void solve()
{
    memset(drres, 0, sizeof(drres));

    int i, j, y;

    // 模 n 取余法，（总体规律是先余为低位，后余为高位）
    while (dr[0] >= 1)
    {
        // 只要被除数仍然 >= 1，则继续操作
        y = 0;
        i = 1;
        drans[0] = dr[0];       // 商的长度与被除数相同（包含前导0）
        while (i <= dr[0])
        {
            y = y * M + dr[i];
            drans[i++] = y / N;
            y %= N;
        }
        drres[++drres[0]] = y;  // 本轮计算得到的余数
        i = 1;
        // 找到下一轮商的起始位置
        while ((i <= drans[0]) && (drans[i] == 0)) ++i;
        // 清除这一轮使用的被除数
        memset(dr, 0, sizeof(dr));
        // 本轮得到的商为下一轮的被除数
        for (j = i; j <= drans[0]; ++j)
        {
            dr[++dr[0]] = drans[j];
        }
        // 清除本轮的商
        memset(drans, 0, sizeof(drans));
    }
}

// 输出 N 进制的结果
void output()
{
    for (int i = drres[0]; i >= 1; --i)
    {
        cout << mic[drres[i]];
    }
}

int main()
{

    initialization();   // 字符与数值对应的map的构建
    while (cin >> M >> N)
    {
        cin >> str;
        pretreatment();     // 预处理字符串，并给存储原始进制的数组赋值
        solve();            // 将 M 进制的 dr 转换成 N 进制
        output();           // 输出 N 进制的结果
        cout << endl;
    }

    return 0;
}


/*
排序子序列

牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; //总共有多少个数
    cin >> n;
    vector<int> a_n(100000, 0); //创建一个数组,数组长度为最大值
    int i = 0;
    while (i < n)
    {
        cin >> a_n[i]; //将数保存到数组中
        i++;
    }
    int cut = 0, j = 0; //定义cut来计数
    //
    //思路:	当一个新序列进来时
    //        首先判断它是递减数列,还是递增数列或者连等数列,
    //        当它是连等数列的时候,直接进行下一个循环
    //        当它是递减数列或者递增数列的时候,判断他是否是连续的,
    //        如果是连续的就继续向后判断,直到跳出;
    //        这时的跳出,代表这个序列已经划分出来,要重新进行下一个序列的判断
    //
    while (j < n)
    {
        if (a_n[j] < a_n[j + 1]) { //如果为递增数列
            while (j < n && a_n[j] <= a_n[j + 1]) //判断是否为连续递增
            {
                j++; //如果是连续的就继续向后判断, 直到跳出
            }
            cut++; //当不在是递增的时候cut+1;并跳出递增判断
            j++;
        }
        else if (a_n[j] == a_n[j + 1]) {  //判断是否为相等的
            j++;
        }
        else {  //如果是递减数列
            while (j < n && a_n[j] >= a_n[j + 1]) //判断是否为连续递减
            {
                j++; //如果是连续的就继续向后判断,直到跳出
            }
            cut++; //跳出时cut + 1
            j++;
        }
    }
    cout << cut << endl;
    return 0;
}

/*
倒置字符串

题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
输入描述 :
每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
输出描述 :
依次输出倒置之后的字符串, 以空格分割
示例1
输入
I like beijing.
输出
beijing.like I



#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());//翻转整个句子
    auto start = s.begin();
    while (start != s.end())
    {
        auto end = start;
        while (end != s.end() && *end != ' ')
            end++;
        reverse(start, end);

        if (end != s.end())
            start = end + 1;
        else
            start = end;
    }
    cout << s << endl;
    return 0;
}

/*
//字符串最后一个单词的长度【https://www.nowcoder.com/questionTerminal/8c949ea5f36f422594b306a2300315da】
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        size_t pos=str.rfind(" ");
        if(pos==string::npos)
            printf("%d",str.size());
        else
            printf("%d",str.size()-pos-1);
    }
    return 0;
}
//字符串中第一个唯一字符【https://leetcode-cn.com/problems/first-unique-character-in-a-string/submissions/】
//解法一
int firstUniqChar(string s)
{
    int count[256] = { 0 };
    for (int i = 0; i < s.size(); ++i)
    {
        count[s[i]] += 1;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (count[s[i]] == 1)
            return i;
    }
    return -1;
}
//解法二
    int firstUniqChar(string s)
    {
        for(int i=0;i<s.size();++i)
        {
            int index1=s.find(s[i]);
            int index2=s.rfind(s[i]);
            if(index1==index2)
            return i;
        }
        return -1;

    }

//反转字符串【https://leetcode-cn.com/problems/reverse-string/】
void reverseString(vector<char>& s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);

    }
}
 /*
 //仅仅反转字母【https://leetcode-cn.com/problems/reverse-only-letters/】
string reverseOnlyLetters(string S)
{
    int start = 0;
    int end = S.size() - 1;
    while (start < end)
    {
        //查找左边第一个字母
        while (start < end)
        {
            if ((S[start] >= 'a' && S[start] <= 'z')
                || (S[start] >= 'A' && S[start] <= 'Z'))
                break;
            start++;
        }
        //查找右边第一个字母
        while (start < end)
        {
            if ((S[end] >= 'a' && S[end] <= 'z')
                || (S[end] >= 'A' && S[end] <= 'Z'))
                break;
            end--;
        }
        if (start < end)
        {
            char tmp = S[start];
            S[start] = S[end];
            S[end] = tmp;
            start++;
            end--;
        }
    }
    return S;
}*/