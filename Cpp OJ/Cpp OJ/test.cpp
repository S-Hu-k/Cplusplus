

/********************************************************************************************************************/

�������ڵ�����ת��
������������ڣ���������һ��ĵڼ��졣��

��ϸ������

����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
#include <iostream>
using namespace std;

// �ж��ǲ�������
bool boolyear(int _year)
{
    if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
        return true;
    return false;
}

int main()
{
    int year, month, day;
    // ʮ�����µ�������ֻ�ж���Ҫ�ж��Ƿ�����+1
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // ������е��µĺ�
    int sum = 0;
    while (cin >> year >> month >> day)
    {
        // ��Ϊ�������ݣ�����ÿ����Ϊ0
        sum = 0;
        // ��������꣬����϶�arr[1]�϶�����29������Ҫ�����������Ϊ28
        // ���ж��ǲ������꣬�Ƿ�Ҫ��+1
        arr[1] = 28;
        if (boolyear(year))
            arr[1] = 29;
        // ��ǰmonth - 1���µ�����������
        for (int i = 0; i < month - 1; i++)
            sum += arr[i];
        // �����һ����
        sum += day;
        // ��ӡ
        cout << sum << endl;
    }
    return 0;
}



/********************************************************************************************************************/
/*���˵Ĵ���*/
һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������� ����ĺ� ����������� ����Ļ��� ���磺��������������ĺ����� { 1, 1, 2, 3 }��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3 ������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��, ���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
���������� �յ�һ������һ��������n(n �� 1000) �ڶ���Ϊn����������xi(xi �� 1000)
��������� ������Բ��������˵Ĵ����� 
#include<iostream> 
#include<algorithm> 
using namespace std;

/*
getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������һ��λ�ý���
x[]: �����е�������
n: �������
pos: ��ǰ������λ��
sum: ��Ŀǰλ�õ��ۼӺ�
multi: ��Ŀǰλ�õ��ۻ�ֵ
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
    int count = 0;
    //ѭ����������λ��i��ʼ���п��ܵ���� 
    for (int i = pos; i < n; i++) {
        sum += x[i];
        multi *= x[i];
        if (sum > multi) {
            //�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ��� 
            count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
        }
        else if (x[i] == 1) {
            //��β�����Ҫ���ҵ�ǰԪ��ֵΪ1�������������� 
            count += getLuckyPacket(x, n, i + 1, sum, multi);
        }
        else {
            //���sum����multi,������û�з���Ҫ�������� 
            break;
        }
        //Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi 
        sum -= x[i];
        multi /= x[i];
        //������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������ 
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
        //�ӵ�һ��λ�ÿ�ʼ���� 
        cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
    }
    return 0;
}






/********************************************************************************************************************/
/*��ʯ��*/
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬
С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� 
С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��


����Ϊһ�У�����������N��M���Կո������
(4 �� N �� 100000)
(N �� M �� 100000)
���С��������Ҫ��Ծ�Ĳ���, ������ܵ������ - 1
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
/*��������
�������������������

xcopy /s c:\ d:\��

�����������£�

����1��������xcopy

����2���ַ���/s

����3���ַ���c:\

����4: �ַ���d:\

���дһ��������������ʵ�ֽ������и�����������������

��������

1.�����ָ���Ϊ�ո�
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ���������
����������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program
files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.����������
4.������������֤��������ֲ�����Ҫ�������

��ѭ�������ַ���
����forѭ���������ո������
����ӡcount�����countһ���Ǳȿո������Ҫ��1��
�ڶ���ѭ�����Ǵ�ӡ�ַ���
�ȸ�һ��flag���ж��ǲ�����˫��������
����ڵĻ��Ǿ�ֱ�Ӵ�ӡ�ո�
���ڵĻ��ͻ���
���������ֱ�Ӵ�ӡ�ַ�
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        // �����ո������
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
        // �����ĸ���һ���ȿո��1
        cout << count + 1 << endl;

        int flag = 1;
        for (int i = 0; i < str.size(); i++)
        {
            // ����ǡ��Ļ���flag��Ϊ0
            if (str[i] == '"')
                flag ^= 1;

            // ���ǿո��˫����ֱ�Ӵ�ӡ
            if (str[i] != ' ' && str[i] != '"')
                cout << str[i];

            // ����˫�����ڵĿո�ֱ�ӻ���
            if (str[i] == ' ' && (flag))
                cout << ' ' << endl;

            // ˫�����ڵĿո�ֱ�Ӵ�ӡ
            if (str[i] == ' ' && (!flag))
                cout << str[i];
        }
    }
    cout << endl;
    return 0;
}

/********************************************************************************************************************/

/* ����ǿ��

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
����Ŀ���������дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
������������
��������������

�����������
���ؽ��

ʾ��1
�����롿
2
2
�������
6
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
/********************************************************************************************************************/

/*
��С������
��Ŀ����

������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������

�������� :

��������������A��B��

������� :

���A��B����С��������

ʾ��1

����
5 7
���
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

/*�������򷽷�
��Ŀ����
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�� ���ַ������ֵ����������磺
��car�� < ��carriage�� < ��cats�� < "doggies < ��koala��
    2.�����ַ����ĳ����������磺
    ��car�� < ��cats�� < ��koala�� < ��doggies�� < ��carriage��
    ������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ�� ֤��

    ���������� �����һ��Ϊ�ַ�������n(n �� 100) ��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ���
    ��������� �����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
    ������ݳ������ж������ֵ����������"lengths",
    ������ַ�ʽ���������"both"���������"none"

    ʾ��
    ���� : 3 a aa bbb
    ��� : both

    ����˼·
    ˼·�ܼ򵥣������ܵ��ַ������ŵ�vector�����У�����string��operator >= �������������ascii�Ƚ��ַ� ����
    ����string��size���Ƚ��ַ����ĳ���

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsE(vector<string> v)   //�ж��Ƿ��ֵ�����
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

bool IsL(vector<string> v)    //�ж��Ƿ񰴳�������
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
һ����Ŀ����

Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i - 1] + F[i - 2]
1
2
3
4
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ������Fibonacci�����е������ǳ�ΪFibonacci����
����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1��
���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
�������� :

����Ϊһ��������N(1 �� N �� 1, 000, 000)

������� :

    ���һ����С�Ĳ�����ΪFibonacci��"

    ʾ��1

    ����

    15
    1
    ���

    2
    1
    ���������������

    1.������Ŀ���������ǿ��Եó�������Ҫ��쳲������������ҵ����������ȥ��ֵ��
    �������е����֣����ӻ��߼��ټ��ο��Ե������ֵ��

    2.���ԣ������������ʵ���������ͱȽϼ��ˣ����ǿ����ҵ�������ֵ�����������ֵ��
    Ȼ�����ֵ����߱�����ֵ����Сֵ��Ȼ������ֵ������ֵ�ҵ����ֵ��
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
        //Ѱ�ұ�fС����
        if (f < N)
            l = N - f;
        else
        {
            //Ѱ�ұ�N���ֵ
            r = f - N;
            break;
        }
    }
    cout << min(l, r) << endl;
    return 0;
}
/********************************************************************************************************************/

/*
��Ҫ��
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
/********************************************************************************************************************/

/*
���ַ���ת��������
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
�ַ�����
��Ŀ����
����һ���ַ�����������ַ����������ַ�����

��������:
ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
�������:
ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
ʾ��1

���� ����    abcqweracb
��� ����    abcqwer


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
���ǹ���https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34��
A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������

�������� :

����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ���� - 30��30֮��(������)��
������� :

���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո� �������������������A��B��C�������No
ʾ��1

����
1 - 2 3 4
���
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
/*����ת��


#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxM = 36;    // �������� '0'-'9' + 'a'-'z' �� 36 ��
const int maxn = 10000;

int M = 2;      // ԭʼ����
int N = 2;      // Ŀ�����

string str;     // �洢����

// �������� 0 ��Ԫ�ؾ���ʾ���鳤��
int dr[maxn];       // �洢���ַ���ת�����Ĵ���
int drans[maxn];    // ��������е���
int drres[maxn];    // ����

map<char, int> mci; // �ַ������ֶ�Ӧ��map
map<int, char> mic; // �������ַ���Ӧ��map

// �ַ�����ֵ��Ӧmap��ʼ��
void initialization()
{
    // �ַ������ֶ�Ӧ��map����
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

// �ж��Ƿ��Ǵ�д��ĸ
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

// �ַ���Ԥ���������洢ԭʼ���Ƶ����鸳ֵ
void pretreatment()
{
    // �����д�д��ĸת����Сд
    for (int i = 0; i < str.length(); ++i)
    {
        // ��д��ĸתСд
        if (isCapital(str[i]) == 1)
        {
            str[i] = 'a' + str[i] - 'A';
        }
    }
    // ���洢ԭʼ���Ƶ����鸳ֵ
    memset(dr, 0, sizeof(dr));
    for (int i = 0; i < str.length(); ++i)
    {
        dr[++dr[0]] = mci[str[i]];
    }
}

// �� M ���Ƶ� dr ת���� N ����
void solve()
{
    memset(drres, 0, sizeof(drres));

    int i, j, y;

    // ģ n ȡ�෨�����������������Ϊ��λ������Ϊ��λ��
    while (dr[0] >= 1)
    {
        // ֻҪ��������Ȼ >= 1�����������
        y = 0;
        i = 1;
        drans[0] = dr[0];       // �̵ĳ����뱻������ͬ������ǰ��0��
        while (i <= dr[0])
        {
            y = y * M + dr[i];
            drans[i++] = y / N;
            y %= N;
        }
        drres[++drres[0]] = y;  // ���ּ���õ�������
        i = 1;
        // �ҵ���һ���̵���ʼλ��
        while ((i <= drans[0]) && (drans[i] == 0)) ++i;
        // �����һ��ʹ�õı�����
        memset(dr, 0, sizeof(dr));
        // ���ֵõ�����Ϊ��һ�ֵı�����
        for (j = i; j <= drans[0]; ++j)
        {
            dr[++dr[0]] = drans[j];
        }
        // ������ֵ���
        memset(drans, 0, sizeof(drans));
    }
}

// ��� N ���ƵĽ��
void output()
{
    for (int i = drres[0]; i >= 1; --i)
    {
        cout << mic[drres[i]];
    }
}

int main()
{

    initialization();   // �ַ�����ֵ��Ӧ��map�Ĺ���
    while (cin >> M >> N)
    {
        cin >> str;
        pretreatment();     // Ԥ�����ַ����������洢ԭʼ���Ƶ����鸳ֵ
        solve();            // �� M ���Ƶ� dr ת���� N ����
        output();           // ��� N ���ƵĽ��
        cout << endl;
    }

    return 0;
}
/********************************************************************************************************************/


/*
����������

ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; //�ܹ��ж��ٸ���
    cin >> n;
    vector<int> a_n(100000, 0); //����һ������,���鳤��Ϊ���ֵ
    int i = 0;
    while (i < n)
    {
        cin >> a_n[i]; //�������浽������
        i++;
    }
    int cut = 0, j = 0; //����cut������
    //
    //˼·:	��һ�������н���ʱ
    //        �����ж����ǵݼ�����,���ǵ������л�����������,
    //        �������������е�ʱ��,ֱ�ӽ�����һ��ѭ��
    //        �����ǵݼ����л��ߵ������е�ʱ��,�ж����Ƿ���������,
    //        ����������ľͼ�������ж�,ֱ������;
    //        ��ʱ������,������������Ѿ����ֳ���,Ҫ���½�����һ�����е��ж�
    //
    while (j < n)
    {
        if (a_n[j] < a_n[j + 1]) { //���Ϊ��������
            while (j < n && a_n[j] <= a_n[j + 1]) //�ж��Ƿ�Ϊ��������
            {
                j++; //����������ľͼ�������ж�, ֱ������
            }
            cut++; //�������ǵ�����ʱ��cut+1;�����������ж�
            j++;
        }
        else if (a_n[j] == a_n[j + 1]) {  //�ж��Ƿ�Ϊ��ȵ�
            j++;
        }
        else {  //����ǵݼ�����
            while (j < n && a_n[j] >= a_n[j + 1]) //�ж��Ƿ�Ϊ�����ݼ�
            {
                j++; //����������ľͼ�������ж�,ֱ������
            }
            cut++; //����ʱcut + 1
            j++;
        }
    }
    cout << cut << endl;
    return 0;
}
/********************************************************************************************************************/

/*
�����ַ���

��Ŀ����
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
�������� :
ÿ�������������1������������ I like beijing.�����������Ȳ�����100
������� :
�����������֮����ַ���, �Կո�ָ�
ʾ��1
����
I like beijing.
���
beijing.like I



#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());//��ת��������
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
//�ַ������һ�����ʵĳ��ȡ�https://www.nowcoder.com/questionTerminal/8c949ea5f36f422594b306a2300315da��
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
//�ַ����е�һ��Ψһ�ַ���https://leetcode-cn.com/problems/first-unique-character-in-a-string/submissions/��
//�ⷨһ
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
//�ⷨ��
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

//��ת�ַ�����https://leetcode-cn.com/problems/reverse-string/��
void reverseString(vector<char>& s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);

    }
    
}/********************************************************************************************************************/
 /*
 //������ת��ĸ��https://leetcode-cn.com/problems/reverse-only-letters/��
string reverseOnlyLetters(string S)
{
    int start = 0;
    int end = S.size() - 1;
    while (start < end)
    {
        //������ߵ�һ����ĸ
        while (start < end)
        {
            if ((S[start] >= 'a' && S[start] <= 'z')
                || (S[start] >= 'A' && S[start] <= 'Z'))
                break;
            start++;
        }
        //�����ұߵ�һ����ĸ
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