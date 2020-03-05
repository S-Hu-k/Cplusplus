/*
#include<stdio.h>
int main()
{
	int a, b, c = 0;
	scanf_s("%d %d %d", &a, &b, &c);
	printf("%d %d %d", a, b, c);
	return 0;


}
















/*
#include<stdio.h>

int cnt = 0;
int fib(int n)
{
	cnt++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}
void main()
{
	fib(8);
	printf("%d", cnt);
}
/*
int main()
{
	int a[5] = { 1,3,5,7,9 };
	int* p = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(p - 1));
}














/*
#include<stdio.h>
int main()
{
	char a[10] = { '1','2','3','4','5','6','7','8','9',0 };
	int i;
	i = 8;
	int p = a + i;
	printf("%s", p - 3);
}










/*#include<stdio.h>
int main()
{
	int a[] = { 1,2,3,4 };
	int* b = a;
	*b += 2;
	*(b + 2) = 2;
	b++;
	printf("%d ,%d\n", *b, *(b + 2));
	return 0;
}*/