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