
/*
#include <stdio.h>
int main() {
	char c;
	while ((c = getchar()) != EOF) {
		if ('A' <= c && 'Z' >= c) {
			c = (c > 'E') ? (c - 5) : (c + 21);
		}
		putchar(c);
	}
	return 0;
}

/*
#include <iostream>
#include<cmath>
using namespace std;
int main() {
	int n, k, i;
	while (cin >> n) {
		k = 0;
		for (i = 2; i <= sqrt(n); ++i)
			if (n % i == 0) {
				while (n % i == 0)
					n /= i;
				k++;
			}
		if (n != 1)	// �������
			k++;
		cout << k << endl;
	}
	return 0;
}

/*
#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
	int getFirstUnFormedNum(std::vector<int>& arr, int length) {
		int sum = 0, min = arr[0];
		int i, j;
		for (int i = 0; i < length; i++)
		{
			sum += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}
		std::vector<int> dp(sum + 1, 0);
		for (i = 0; i < length; i++) {//��length������--��length���׶�
			//{2�� 3�� 5}
			//i=0--d[10]=2 d[9]=2 d[8]=2 d[7]=2...d[2]=2
			//i=1--d[10]=5 d[9]=5...d[5]=5 d[4]=3 d[3]=3
			//i=2--d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5
			for (j = sum; j >= arr[i]; j--) {
				//�����жϱ����������ܹ����������
				//��������ֻ��2��ʱ�򣬱������ش�2-10�����Է���2����ֵ
				//�������з���2��3��ʱ�򣬱������ش�5-10���Է���5��3-4����
				//3��2ֻ�ܷ���2				
				//�������з���2��3��5ʱ����������10����10��8-9����8��7����
				//7��5-6����5...
				//dp[j-arr[i]]��˼�Ǳ�������Ϊjʱ������Ѿ�������arr[i]��
				//�������ܷ��õ��������
				if (dp[j] < dp[j - arr[i]] + arr[i])
					//���±������ܹ���������ֵ
					dp[j] = dp[j - arr[i]] + arr[i];
				else
					dp[j] = dp[j];
			}
		}
		//��󵱳���Ϊnʱ�������������Ϊn����Ϊ����󲻿����
		for (i = min; i <= sum; i++)
		{
			if (i != dp[i])
				return i;
		}
		return sum + 1;
	}
};


/*
#include<iostream>
using namespace std;
int judge(int n, int count)
{
	if (n == 1)
		count += 1;
	if (1 < n && n <= 3)
		count += 2;
	return count;
}
int main()
{
	int n;
	int count = 0;
	cin >> n;//�ܹ��ж���Ǯ
	if (n != 0)
	{
		if (n <= 3)
			judge(n, count);
		if (n > 3)
		{
			while (n > 3)
			{

				n /= 3;
				count++;
			}
			judge(n, count);
		}
		cout << count+1 << endl;
	}
}
/*int main() 
{
	long long n;
	int cnt;
	while (cin >> n) 
	{
		if (n == 0)
			break;
		cnt = 0;
		while (n >= 2) 
		{
			if (n % 3)
				// ������������ȡ�����������ص�һ��Ϊn/3 + 1�����
				n = n / 3 + 1;
			else
				n /= 3;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
*/
/*
int judge(int n,int count)
{
	if (n == 1)
		count += 1;
	if (1 < n && n <= 3)
		count += 2;
	return count;
}
int main()
{
	int n;
	int count=0;
	cin >> n;//�ܹ��ж���Ǯ
	if (n != 0)
	{
		if (n <= 3)
			judge(n,count);
		if (n > 3)
		{
			while (n > 3)
			{
				
				n /= 2;
				count++;
			}
			judge(n,count);
		}
		cout << count<< endl;
	}
}*/