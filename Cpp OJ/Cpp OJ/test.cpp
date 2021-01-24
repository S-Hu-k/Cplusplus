

/********************************************************************************************************************/
年终奖

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int length = board.size();
        int wideth = board[0].size();
        vector<vector<int>> allPrice;
        for (int i = 0; i < length; i++) {
            vector<int> tmp(wideth, 0);
            allPrice.push_back(tmp);
        }
        allPrice[0][0] = board[0][0];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < wideth; j++) {
                //如果是起点坐标，不做任何处理。                
                if (i == 0 && j == 0) {
                    continue;
                }
                //如果走在行的临界边，也就是第一行，那么他只能向右走             
                //向右走的时候该点就要将后面的值加起来。
                else if (i == 0) {
                    allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
                }
                //如果走在列的临界边，也就是第一列，那么他只能向下走             
                //向下走的时候该点就要将上面的值加起来。                
                else if (j == 0) {
                    allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
                }
                else {
                    //除去两个临界边，剩下的就是既能向右走，也能向下走，                 
                    //这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点                 
                    //各自路径的和是不是这些所有到达该点路径当中最大的了。                    
                    allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) +
                        board[i][j];
                }
            }
        }
        // 返回最后一个坐标点的值，它就表示从左上角走到右下角的最大奖励        
        return allPrice[length - 1][wideth - 1];
    }
};
/********************************************************************************************************************/
迷宫问题   回溯算法

#include <string.h>


#include <stdlib.h>
#include <stdio.h>

int maze[10][10];
int flag = 0;

int DRV_SearchMaze(int max_line, int max_col, int line, int col)
{
    if (flag)
    {
        return 0;
    }
    if (line == (max_line - 1) && col == (max_col - 1))  //是否到达迷宫边界
    {
        printf("(%d,%d)\n", line, col);
        flag = 1;
        return 0;
    }
    if ((col + 1 < max_col) && (maze[line][col + 1] == 0))//判断行上是否满足
    {
        printf("(%d,%d)\n", line, col);
        DRV_SearchMaze(max_line, max_col, line, col + 1);   //递归
    }
    if ((line + 1 < max_line) && (maze[line + 1][col] == 0))//判断列上是否满足
    {
        if (flag == 0)
        {
            printf("(%d,%d)\n", line, col);
            DRV_SearchMaze(max_line, max_col, line + 1, col);//递归
        }
    }
    return 0;
}
int main()
{
    int line, col;
    int i, j;
    while (~scanf("%d %d", &line, &col))
    {
        flag = 0;
        for (i = 0; i < line; i++)
        {
            for (j = 0; j < col; j++)
                scanf("%d", &maze[i][j]);
        }
        DRV_SearchMaze(line, col, 0, 0);
    }
    return 0;
}

/********************************************************************************************************************/

MP3光标位置

#include <iostream> 
#include <string> 
using namespace std;
int main() {
    //歌曲数量    
    int n;
    //命令    
    string order;
    while (cin >> n >> order) {
        //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示
        //页的第一首歌曲的编号        
        int num = 1, first = 1;
        //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变		
        if (n <= 4) {
            for (int i = 0; i < order.size(); i++) {
                if (num == 1 && order[i] == 'U') {
                    num = n;
                }
                else if (num == n && order[i] == 'D') {
                    num = 1;
                }
                else if (order[i] == 'U') {
                    num--;
                }
                else {
                    num++;
                }
            }
            for (int i = 1; i <= n - 1; i++) {
                cout << i << ' ';
            }
            cout << n << endl;
            cout << num << endl;
        }
        //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
        else {
            for (int i = 0; i < order.size(); i++) {
                if (first == 1 && num == 1 && order[i] == 'U') {
                    first = n - 3;
                    num = n;
                }
                //特殊翻页1                
                else if (first == n - 3 && num == n && order[i] == 'D') {
                    first = 1; num = 1;
                }
                //特殊翻页2               
                else if (first != 1 && num == first && order[i] == 'U') {
                    first--; num--;
                }
                //一般翻页1                
                else if (first != n - 3 && num == first + 3 && order[i] == 'D') {
                    first++; num++;
                }
                //一般翻页2                
                else if (order[i] == 'U') {
                    num--;
                }
                //其他情况1                
                else {
                    num++;
                }
                //其他情况2            
            }
            for (int i = first; i < first + 3; i++) {
                cout << i << ' ';
            }
            cout << first + 3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}

//第六十二题  MP3光标位置
#include<iostream>
#include<string>
using namespace std;
void Short(string str, int  n)
{
    int initial = 1, current = 1;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'U')
        {
            if (current == 1)
                current = n;
            else
                current--;
        }
        else if (str[i] == 'D')
        {
            if (current == n)
                current = 1;
            else
                current++;
        }
    }
    for (int i = 1; i < n; i++)
        cout << i << " ";
    cout << n << endl;
    cout << current << endl;
}

void Long(string str, int n)
{
    int initial = 1, current = 1;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'U')
        {
            if (initial == 1 && current == 1)
            {
                current = n;
                initial = n - 3;
            }
            else if (initial == current)
            {
                current--;
                initial--;
            }
            else
                current--;
        }
        else if (str[i] == 'D')
        {
            if (initial == n - 3 && current == n)
            {
                current = 1;
                initial = 1;
            }
            else if (initial == current - 3)
            {
                current++;
                initial++;
            }
            else
                current++;
        }
    }
    for (int i = initial; i != initial + 3; i++)
        cout << i << " ";
    cout << initial + 3 << endl;
    cout << current << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string str;
        cin >> str;
        if (n <= 4)
            Short(str, n);
        else
            Long(str, n);
    }
    return 0;
}

/********************************************************************************************************************/


//单词搜索
//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”
//单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//示例 :
//
//board =
//[
//    ['A', 'B', 'C', 'E'],
//    ['S', 'F', 'C', 'S'],
//    ['A', 'D', 'E', 'E']
//]
//
//给定 word = "ABCCED", 返回 true.
//给定 word = "SEE", 返回 true.
//给定 word = "ABCB", 返回 false.
class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int i, int j, int pos) {
        if (pos == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
            return false;
        if (word[pos] != board[i][j])
            return false;
        char temp = board[i][j];
        board[i][j] = '.';
        bool result = search(board, word, i + 1, j, pos + 1) || 
            search(board, word, i - 1, j, pos + 1) || search(board, word, i, j - 1, pos + 1) ||
            search(board, word, i, j + 1, pos + 1);
        board[i][j] = temp;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (search(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};


/********************************************************************************************************************/
Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。【字节跳动】
现在小Y使用1024元的纸币购买了一件价值为N(0 < N \le 1024)N(0 < N≤1024)的商品，
    请问最少他会收到多少硬币
#include<iostream>
using namespace std;
int main()
{
    int sum = 0;
    int n = 0;
    while (cin >> n && (n > 0 && n < 1024))
    {

        int money = 1024 - n;

        int x = money / 64;//+1
        money = money % 64;
        int z = money / 16;//+1
        money = money % 16;
        int y = money / 4;//+1
        money = money % 4;
        int d = money / 1;//+1
        sum = x + z + y + d;

    }
    cout << sum << endl;
}
/********************************************************************************************************************/

题目描述
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述 :

先输入键值对的个数
然后输入成对的index和value值，以空格隔开

输出描述 :

输出合并后的键值对（多行）

示例1
输入

4
0 1
0 2
1 2
3 4

输出

0 3
1 2
3 4

#include <iostream>
#include <map>
using namespace std;

int main()
{

    int n;
    while (cin >> n)
    {
        map<int, int> mymap;
        while (n--)
        {
            int a, b;
            cin >> a; cin >> b;
            auto it = mymap.find(a);
            if (it != mymap.end())
                mymap[a] += b;
            else
                mymap[a] = b;
        }
        for (auto it = mymap.begin(); it != mymap.end(); ++it)
        {
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}

/********************************************************************************************************************/
/*密码验证合格程序*/
#include <iostream>
#include <string>
using namespace std;
int sum(int a[4]) {
    int ans = 0;
    for (int j = 0; j < 4; j++) {
        ans += a[j];
    }
    return ans;
}
int main() {
    string s;
    while (cin >> s) {
        int buf[100];
        bool is_ok = true;
        int buf_num = 0;
        int is_full[4] = { 0,0,0,0 };
        int s_l = s.length();
        for (int i = 0; i < s_l; i++) {
            buf[buf_num++] = s[i];
            if (s[i] >= '0' && s[i] <= '9') {
                is_full[0] = 1;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                is_full[1] = 1;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                is_full[2] = 1;
            }
            else {
                is_full[3] = 1;
            }
        }
        if (sum(is_full) < 3 || s_l <= 8) {
            is_ok = false;
        }
        else if (sum(is_full) >= 3 && s_l > 8) {
            for (int i = 0; i < buf_num - 3; i++) {
                for (int j = i + 1; j < buf_num; j++) {
                    if (buf[i] == buf[j] && buf[i + 1] == buf[j + 1] && buf[i + 2] == buf[j + 2]) {
                        is_ok = false;
                    }
                }
            }
        }
        if (is_ok == false) {
            cout << "NG" << endl;
        }
        else {
            cout << "OK" << endl;
        }
    }
    return 0;
}
/********************************************************************************************************************/

/*通配字符串*/
#include<iostream>
#include<string>
using namespace std;
bool judge(const char* yzf, const char* ppzf)
{
    if (*yzf == '\0' && *ppzf == '\0')
        return true;
    if (*yzf == '\0' || *ppzf == '\0')
        return false;
    if (*yzf == '?') {
        // ? 匹配一个字符，直接跳过一个位置
        return judge(yzf + 1, ppzf + 1);
    }
    else if (*yzf == '*') {
        // * 匹配0个字符，或者匹配一个字符，或者匹配大于一个字符，一个为真即为真
        return judge(yzf + 1, ppzf) || judge(yzf + 1, ppzf + 1) || judge(yzf, ppzf + 1);
    }
    else if (*yzf == *ppzf) {
        // 当前字符相等，匹配下一个字符
        return judge(yzf + 1, ppzf + 1);
    }
    return false;
}
int main()
{
    string yzf;
    string ppzf;
    while (cin >> yzf >> ppzf)
    {
        if (judge(yzf.c_str(), ppzf.c_str()))
        {
            cout << "true" << endl;
        }
        else
            cout << "false" << endl;
    }
}

/********************************************************************************************************************/
/*完全数*/
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。
给定函数count(int n), 用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
    返回n以内完全数的个数。 异常情况返回 - 1
#include<iostream>
using namespace std;
bool Judgeperfect(int x)
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
    while (cin >> a)
    {
        int count = 0;
        for (int j = 1; j < a; ++j)
        {
            if (Judgeperfect(j) == true)
                count++;
        }
        cout << count << endl;
    }

    return 0;
}
/********************************************************************************************************************/
/*一个数的二进制中的一的个数*/
using namespace std;

int f(int x) {
    int n = 0;
    while (x) {
        n++;
        x &= x - 1;
    }
    return n;
}

int main() {
    cout << f(26) << endl;
    return 0;
}
/* ------------------------------------------------------------- */

#include<stdio.h>
int Number(unsigned int num)
{
    int tmp, count = 0;
    while (num != 0)
    {
        tmp = num & 1;
        if (tmp == 1)
            count++;
        num = num >> 1;
    }
    return count;
}
int main()
{
    int num = -1;
    int n = Number(num);
    printf("%d\n", n);
    return 0;
}

/* ------------------------------------------------------------- */
#include<stdio.h>
int Number(unsigned int num)
{
    int tmp, count = 0;
    while (num != 0)
    {
        tmp = num % 2;
        num = num / 2;
        if (tmp == 1)
            count++;
    }
    return count;
}
int main()
{
    int num = -1;
    int n = Number(num);
    printf("%d\n", n);
    system("pause");
    return 0;
}


/********************************************************************************************************************/

计算日期到天数转换
根据输入的日期，计算是这一年的第几天。。

详细描述：

输入某年某月某日，判断这一天是这一年的第几天？。
#include <iostream>
using namespace std;

// 判断是不是闰年
bool boolyear(int _year)
{
    if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
        return true;
    return false;
}

int main()
{
    int year, month, day;
    // 十二个月的天数，只有二月要判断是否闰年+1
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // 算出所有的月的和
    int sum = 0;
    while (cin >> year >> month >> day)
    {
        // 因为多组数据，所以每次置为0
        sum = 0;
        // 如果是闰年，下面肯定arr[1]肯定会是29，所以要在这里把他置为28
        // 在判断是不是闰年，是否要在+1
        arr[1] = 28;
        if (boolyear(year))
            arr[1] = 29;
        // 将前month - 1个月的天数加起来
        for (int i = 0; i < month - 1; i++)
            sum += arr[i];
        // 加最后一个月
        sum += day;
        // 打印
        cout << sum << endl;
    }
    return 0;
}



/********************************************************************************************************************/
/*幸运的袋子*/
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的 号码的和 大于所有球的 号码的积。 例如：如果袋子里面的球的号码是 { 1, 1, 2, 3 }，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3 你可以适当从袋子里移除一些球(可以移除0个, 但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述： 空第一行输入一个正整数n(n ≤ 1000) 第二行为n个数正整数xi(xi ≤ 1000)
输出描述： 输出可以产生的幸运的袋子数 
#include<iostream> 
#include<algorithm> 
using namespace std;

/*
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x[]: 袋子中的所有球
n: 球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
    int count = 0;
    //循环，搜索以位置i开始所有可能的组合 
    for (int i = pos; i < n; i++) {
        sum += x[i];
        multi *= x[i];
        if (sum > multi) {
            //找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合 
            count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
        }
        else if (x[i] == 1) {
            //如何不符合要求，且当前元素值为1，则继续向后搜索 
            count += getLuckyPacket(x, n, i + 1, sum, multi);
        }
        else {
            //如何sum大于multi,则后面就没有符合要求的组合了 
            break;
        }
        //要搜索下一个位置之前，首先恢复sum和multi 
        sum -= x[i];
        multi /= x[i];
        //数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过 
        while (i < n - 1 && x[i] == x[i + 1]) {
            i++;
        }
    }
    return count;
}
int main() {
    int n = 0;
    while (cin >> n) {
        int x[1000];
        //int* x = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort(x, x + n);
        //从第一个位置开始搜索 
        cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
    }
    return 0;
}






/********************************************************************************************************************/
/*跳石板*/
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个非1和本身的约数)的位置。 
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板


输入为一行，有两个整数N，M，以空格隔开。
(4 ≤ N ≤ 100000)
(N ≤ M ≤ 100000)
输出小易最少需要跳跃的步数, 如果不能到达输出 - 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> getyueshu(int n)
{
    vector<int> res;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
            {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> dp(M + 1, M);
    dp[N] = 0;
    for (int i = N; i <= M; i++)
    {
        vector<int> path = getyueshu(i);
        for (int j = 0; j < path.size(); j++)
        {
            if (i + path[j] <= M)
            {
                dp[i + path[j]] = min(dp[i] + 1, dp[i + path[j]]);
            }
        }
    }
    if (dp[M] == M)
    {
        cout << -1;
    }
    else
    {
        cout << dp[M];
    }
    return 0;
}



/********************************************************************************************************************/
/*参数分析
在命令行输入如下命令：

xcopy /s c:\ d:\，

各个参数如下：

参数1：命令字xcopy

参数2：字符串/s

参数3：字符串c:\

参数4: 字符串d:\

请编写一个参数解析程序，实现将命令行各个参数解析出来。

解析规则：

1.参数分隔符为空格
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。
比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program
files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长
4.输入由用例保证，不会出现不符合要求的输入

先循环出入字符串
利用for循环来计数空格的数量
最后打印count（这个count一定是比空格的数量要大1）
第二次循环就是打印字符串
先给一个flag来判断是不是在双引号里面
如果在的话那就直接打印空格
不在的话就换行
其他情况就直接打印字符
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

/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/

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

/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/


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
/********************************************************************************************************************/

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
/********************************************************************************************************************/

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
/********************************************************************************************************************/
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
    /********************************************************************************************************************/

//反转字符串【https://leetcode-cn.com/problems/reverse-string/】
void reverseString(vector<char>& s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);

    }
    
}/********************************************************************************************************************/
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