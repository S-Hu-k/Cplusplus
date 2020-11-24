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