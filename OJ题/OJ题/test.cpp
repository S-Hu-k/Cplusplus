
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