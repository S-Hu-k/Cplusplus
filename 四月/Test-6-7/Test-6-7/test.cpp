//�����ж������ݣ�ÿ�����������С�
//��һ�г����б�����֮����һ�����Ÿ�������������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���
//�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���
//
//����ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ�����������Important!������ʾ����ʼ���Ҫ�����ȴ���
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string namelist;
	string name;
	while (getline(cin, namelist))
	{
		getline(cin, name);
		vector<string> str;
		for (size_t i = 0; i < namelist.size(); ++i)
		{
			if (namelist[i] == '\"')//��������""�����
			{
				str.push_back(namelist.substr(i + 1, namelist.find('\"', i + 1) - i - 1));//��vector��β��ȥ��""������
				i = namelist.find('\"', i + 1) + 1;
			}
			else//��������""�����
			{
				if (namelist.find(',', i) == namelist.npos)//���һ��ĩβ���� ���û��,�ַ�
				{
					str.push_back(namelist.substr(i, namelist.size() - i));
					i = namelist.size();
				}
				else//�м䶼��,����������
				{
					str.push_back(namelist.substr(i, namelist.find(',', i) - i));//��Ҫ��,һ��β���ȥ���� ��ֹǰ�������ظ�
					i = namelist.find(',', i);
				}
			}
		}
		if (find(str.begin(), str.end(), name) != str.end())
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}








/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string ss, s;
	while (getline(cin, ss))
	{
		getline(cin, s);
		bool flag = false;
		for (int i = 0; i < ss.length(); i++)
		{
			string str;
			if (ss[i] == '"')
			{
				i++;
				while (i < ss.length() && ss[i] != '"')
				{
					str += ss[i];
					i++;
				}
				if (str == s)
				{
					flag = true;
					break;
				}
			}
			else if (ss[i] != ',')
			{
				while (i < ss.length() && ss[i] != ',')
				{
					str += ss[i];
					i++;
				}
				if (str == s)
				{
					flag = true;
					break;
				}
			}
			else
			{
				;
			}
		}
		if (flag == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}
 
/*���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
2. ����������������ϣ�ÿ�˴�����ȡһ��������
3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�



��������:
��������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����

�������:
��Ӧÿһ�����ݣ��ԡ�xx.xx % ���ĸ�ʽ����������˻񽱵ĸ��ʡ�
ʾ��1

����
2
���
50.00 %
n�������Ԫ��Ӧ��n!����ͬ�����У�����һ������ʹ�����е�Ԫ�ز���ԭ����λ���ϣ�����������Ϊ���ţ��еĽ����š�
�磬1 2�Ĵ�����Ψһ�ģ���2 1��1 2 3�Ĵ�����31 2��2 3 1������߿��Կ�����1 2���ţ�3�ֱ���1��2��λ���õġ�

�ٶȴ����㷨
��Դ����㷨�� ΪʲôҪ(n - 1)[D(n - 2) + D(n - 1)]
����n - 1�ǵ�һ��ѡ������ݵĴ�λ���ܣ�������ݿ���������һ����
���������һ��ѡ������ݺ�������������ѡ����Ϊ��һ��ѡ�������ռ����һ������������λ�ã�
�Ǹ�λ��ԭ�������ݾͿ϶���һ���������ݣ���������������ѡ��
1.ռ�ݵ�һ�����ݵĿ�λ--n - 2������
2.��ռ��һ�����ݵĿ�λ�����Լ��������Ե�һ�����ݿ�λΪλ�õ����ݽ�������-- - n - 1������


#include<iostream>
using namespace std;

int main() {
	int n;
	long long a[21] = { 0,0,1 }, b[21] = { 1,1,2 };
	while (cin >> n) {
		for (int i = 3; i <= n; i++) {
			b[i] = i * b[i - 1];
			a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
			//		cout << "a[i]=" << a[i] << endl;
			//		cout << "b[i]=" << b[i] << endl;

		}
		//	cout << 1.0 * a[n] / b[n]*100 << endl;
		printf("%.2f%c\n", 1.0 * a[n] / b[n] * 100, '%');

	}
	return 0;
}*/
