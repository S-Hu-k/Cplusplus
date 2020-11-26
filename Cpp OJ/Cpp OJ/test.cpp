
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

//��ת�ַ�����https://leetcode-cn.com/problems/reverse-string/��
void reverseString(vector<char>& s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);

    }
}
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