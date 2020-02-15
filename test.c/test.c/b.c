#include<stdio.h>
void main()
{
	int a, b;
	scanf_s("%d,%d", &a, &b);
	if (a > b)
	{
		a = b;
		b = a;
	}

	else
		a++;
	b++;
	printf("%d,%d", a, b);
}