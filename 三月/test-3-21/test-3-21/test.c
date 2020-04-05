/*
#include<stdio.h>
int f(int n)
{
	static int i = 1;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}
int main()
{
	printf("%d", f(1));
}
/*
#define N 9
void fun(int a[], int n)
{
	int i, j, max, min, px, pn, t;
	for (i = 0; i < n - 1; i += 2)
	{
		max = min = a[i];
		px = pn = i;
		for (j = i + 1; j < n; j++)
		{
			if (max < a[j])
			{
				max = a[j];
				px = j;
			}
			if (min > a[j])
			{
				min = a[j];
				pn = j;
			}
		}
		if (pn != i)
		{
			t = a[i];
			a[i] = min;
			a[pn] = t;
			if (px == i)
				px = pn;
		}
		if (px != i + 1)
		{
			t = a[i + 1];
			a[i + 1] = max;
			a[px] = t;
		}
	}
}
int main()
{
	int b[N] = { 9,1,4,2,3,6,5,8,7 };
	printf("\n the original data:\n");
	for (int i = 0; i < N; i++)
		printf("%4d", b[i]);
	printf("\n");
	fun(b, N);
	printf("\n the data after coming\n");
	for (int i = 0; i < N; i++)
		printf("%4d", b[i]);
	printf("\n");
}*/