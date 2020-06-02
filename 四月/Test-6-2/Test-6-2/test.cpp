/*NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
���ڸ���һ��ʱ�����䣬������������������ж��١�

�������� :
��������������ݡ�
ÿ�����ݰ�����������from��to(2000 - 01 - 01 �� from �� to �� 2999 - 12 - 31)��
������������������ʾ���ÿո������year month day��

������� :
��Ӧÿһ�����ݣ�����ڸ��������ڷ�Χ��������ʼ�ͽ������ڣ�����׬����Ǯ��

ʾ��
����
2000 1 1 2000 1 31
2000 2 1 2000 2 29
���
62
29

����˼·
��Ϊ�����������

ͬ��ͬ����ֱ�����������������������������ڰ��������2�£�����1.
ͬ�겻ͬ��ʱ���ȼ������µ������ٽ�������󵥶����㡣
��ͬ��ʱ����������������������µ������ٽ��쵥�����㡣
#include <iostream>
using namespace std;

bool IsSu(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool IsRun(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Money(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int sum = 0;
	int s1[] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
	int s2[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y1 == y2 && m1 == m2)
	{
		int n = 0;
		if (IsSu(m1))
			n += d2 - d1 + 1;
		else
			n += 2 * (d2 - d1 + 1);
		sum = n;
	}
	else if (y1 == y2 && m1 != m2)
	{
		int n = 0;
		if (!IsRun(y1))
		{
			for (int i = m1 + 1; i < m2; i++)
				n += s1[i];
			if (IsSu(m1) && IsSu(m2))
				n += s2[m1] - d1 + 1 + s2[m2] - d2 + 1;
			else if (!IsSu(m1) && !IsSu(m2))
				n += 2 * (s2[m1] - d1 + 1 + s2[m2] - d2 + 1);
			else if (!IsSu(m1) && IsSu(m2))
				n += 2 * (s2[m1] - d1 + 1) + s2[m2] - d2 + 1;
			else
				n += s2[m1] - d1 + 1 + 2 * (s2[m2] - d2 + 1);
		}
		else
		{
			if (m1 < 2 && 2 < m2)
				n += 1;
		}
		sum = n;
	}
	else
	{
		int n = 0;
		for (int i = y1 + 1; i < y2; i++)
		{
			if (!IsRun(i))
				n += 579;
			else
				n += 580;
		}
		for (int i = m1 + 1; i <= 12; i++)
		{
			if (IsRun(y1) && i == 2)
				n += 1;
			n += s1[i];
		}
		if (IsSu(m1))
			n += s2[m1] - d1 + 1;
		else
			n += 2 * (s2[m1] - d1 + 1);
		for (int i = 1; i < m2; i++)
		{
			if (IsRun(y2) && i == 2)
				n += 1;
			n += s1[i];
		}
		if (IsSu(m2))
			n += d2;
		else
			n += 2 * d2;
		sum = n;
	}
	return sum;
}

int main()
{
	int y1 = 0; int y2 = 0;
	int m1 = 0; int m2 = 0;
	int d1 = 0; int d2 = 0;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		int sum = 0;
		sum = Money(y1, m1, d1, y2, m2, d2);
		cout << sum << endl;
	}
	system("pause");
	return 0;
}


/*NowCoder�ų��Լ��Ѿ���ס��1 - 100000֮�����е�쳲���������

Ϊ�˿���������������һ����n������˵����n��쳲�����������Ȼ��쳲���������ܴ�
��ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ��


�������� :
�����ж������ݡ�

ÿ������һ�У�����һ������n(1��n��100000)��



�������:
��Ӧÿһ�����룬�����n��쳲������������6λ��


�������� :
1
2
3
4
100000


������� :
	1
	2
	3
	5
	537501


#include<iostream>
#include<stdio.h> 
using namespace std;
int a[100005];
int main()
{
	int n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 100000; i++)
		a[i] = (a[i - 1] + a[i - 2]) % 1000000;
	while (scanf("%d", &n) != EOF)
	{
		if (n >= 30)//��Ų��µ�����λ��ʱ��ͳ�����λ��
			printf("%06d\n", a[n]);
		else
			printf("%d\n", a[n]);
	}
	return 0;

}*/