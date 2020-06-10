
/*
��Ŀ����
�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼�� / usr / local / bin��������Ҫ�˴δ����� / usr������ / usr / local���Լ��� / usr / local / bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ� - p��ѡ�ֻҪһ�����mkdir - p / usr / local / bin�������Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir - p�����

�������� :
��������������ݡ�
ÿ�����ݵ�һ��Ϊһ��������n(1��n��1024)��
������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200���ַ���

������� :
��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������ġ�mkdir - p�����
ÿ������֮�����һ��������Ϊ�ָ���

ʾ��
����
3
/ a
/ a / b
/ a / b / c
3
/ usr / local / bin
/ usr / bin
/ usr / local / share / bin
���
mkdir - p / a / b / c

mkdir - p / usr / bin
mkdir - p / usr / local / bin
mkdir - p / usr / local / share / bin



��������ַ�����������vector�У���sort����������ʵ�ְ��ֵ�����
���ж���ǰһ�������Ǻ�һ�����ݵ��Ӵ��Һ�һ�����ݵ���һ��λ���� �� / �� ����������׳���������
��ɾ��ǰһ�����ݣ�����ж������ÿ�����ݡ������û���ظ���vector�У���ÿ���ַ���ǰ��� ��mkdir - p ������������ɡ�


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsZi(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	string mk = "mkdir -p ";
	int i = 0;
	while (i < v.size() - 1)
	{
		//ǰһ���Ǻ�һ�����Ӵ����Һ�һ���Ӵ�����һ��λ��Ϊ /
		if (IsZi(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (auto& e : v)
		cout << mk << e << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string s1;
			cin >> s1;
			v.push_back(s1);
		}
		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}

/*
��������:
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000������ʾ�����������
������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����

������� :
��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�

ʾ��
����
6
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
���
2


�������Id �� op ���δ�������v�У�Ȼ���ж������е�op����Ϊ�����δ���ģ�
����opһ�������������λ�ϣ���op ��"connect" ��op ǰ���id �������q�У�
�����ȼ�¼q �ĳ��ȣ��ٽ�opǰ��id�����С�ȡ����ĳ��ȼ��ɡ�������ʵ�ֵĲ��ֺ�����



#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int con = 0;
		queue<char> q;
		for (int i = 0; i < n; i++)
		{
			char ID;
			cin >> ID;
			string OP;
			cin >> OP;
			if (OP == "connect")
				q.push(ID);
			else
			{
				con = q.size() > con ? q.size() : con;
				q.pop();
			}
		}
		cout << con << endl;
	}
	return 0;
}*/
