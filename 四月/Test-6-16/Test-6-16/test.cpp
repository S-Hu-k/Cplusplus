/*                    
                  /////////////////骆驼命名法////////////////////////
题目描述
从C / C++转到Java的程序员，一开始最不习惯的就是变量命名方式的改变。C语言风格使用下划线分隔多个单词，例如“hello_world”；而Java则采用一种叫骆驼命名法的规则：除首个单词以外，所有单词的首字母大写，例如“helloWorld”。
请你帮可怜的程序员们自动转换变量名。

输入描述 :
输入包含多组数据。
每组数据一行，包含一个C语言风格的变量名。每个变量名长度不超过100。

输出描述 :
对应每一组数据，输出变量名相应的骆驼命名法。

示例
输入
hello_world
nice_to_meet_you
输出
helloWorld
niceToMeetYou

解题思路
思路 1 遍历原串，若是字母字符直接移入新串，若碰到下划线则将它的下一个字符改为大写，
下划线不移入新串继续遍历后面。直至全部移完，返回新串。

//string CtoJ(string s)   //C风格转化成Java风格
//{
//	string s1 = "";   //定义一个空串
//	for (int i = 0; i < s.size(); i++)   //遍历原串
//	{
//		if (s[i] == '_')    //若碰到下划线，则将它的下一个改成大写字母
//			s[i + 1] -= 32;
//		else            //否则直接将字符放入新的字符串
//			s1.push_back(s[i]);
//	}
//	return s1;    //返回新字符串
//}

思路 2 定义新串，在原串中用find()函数找到下划线，将下划线的前半部分直接移入新串，
再继续在后面的串中找下划线移入前半部分，直至移完，返回新串。

//string CtoJ(string s)   //C风格转化成Java风格
//{
//	string s1 = "";
//	int i = 0;
//	while (i < s.size())
//	{
//		int pos = s.find('_', i);   //每次从第一个字符开始找到下划线
//		if (pos < s.size())   //如果找到
//		{
//			s1 += s.substr(i, pos - i);   //将下划线的前半部分放入s1中
//			s[pos + 1] -= 32;   //下划线的下一个字符改成大写
//			s = s.substr(pos + 1, s.size() - (pos + 1));   //在下划线的后半部分继续找下一个下划线
//		}
//		else     //如果s中没有下划线则直接将s放入s1中，循环结束
//		{
//			s1 += s;
//			break;
//		}
//	}
//	return s1;
//}







#include <iostream>
#include <string>
using namespace std;

string CtoJ(string s)   //C风格转化成Java风格
{
	string s1 = "";   //定义一个空串
	for (int i = 0; i < s.size(); i++)   //遍历原串
	{
		if (s[i] == '_')    //若碰到下划线，则将它的下一个改成大写字母
			s[i + 1] -= 32;
		else            //否则直接将字符放入新的字符串
			s1.push_back(s[i]);
	}
	return s1;    //返回新字符串
}

int main()
{
	string s;
	while (cin >> s)
		cout << CtoJ(s) << endl;
	return 0;
}
*/
/*                /////////////单词倒排////////////
题目描述
对字符串中的所有单词进行倒排。
说明：
1、每个单词是以26个大写或小写英文字母构成；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；

输入描述 :
输入一行以空格来分隔的句子

输出描述 :
输出句子的逆序

示例
输入
I am a student
输出
student a am I

解题思路
先将每个单词分割出来放在vector中，再将vector逆序输出即可


#include <iostream>
#include <string>
#include <vector>
using namespace std;

string niXu(string s)
{
	vector <string> v;
	string s1 = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')  //找到每个单词
		{
			s1.push_back(s[i]);
		}
		else     //找到分隔符
		{
			if (s1.size() > 0)    //若s1中存有已找到的字符串
			{
				v.push_back(s1);   //放在vector中
				s1 = "";    //置空s1
			}
		}
	}
	if (s1.size() > 0)      //若最后一个字符串有单词则放入vector中
		v.push_back(s1);
	string ret = "";
	for (int j = v.size() - 1; j > 0; j--)    //按要求逆序输出vector
	{
		ret += v[j];
		ret.push_back(' ');
	}
	ret += v[0];
	return ret;
}

int main()
{
	string s;
	while (getline(cin, s))
		cout << niXu(s) << endl;
	return 0;
}*/
