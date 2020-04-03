
#include <stdio.h>
struct A {
	long a1;
	short a2;
	int a3;
	int* a4;
};
int main()
{
	printf("%d", sizeof(struct A));
	return 0;
}
/*
void main()
{
	short i = 65537;
	int j = i + 1;
	printf("i=%d,j=%d\n", i, j);
}

/*
void main()
{
	int a = 1; int b = 2;
	for (; a < 8; a++)
	{
		b += a; a += 2;
	}
	printf("%d£¬%d\n", a, b);
}/*
#include <stdio.h>
int main()
{
	int a[] = { 2,4,6,8 }, * p = a, i;
	for (i = 0; i < 4; i++)
		a[i] = *p++;
	printf("%d\n", a[2]);
	return 0;
}
/*
int func(int i, int j)
	{
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func(i - 3, j / 2);
	}
void main()
{
	printf("%d",func(15, 20));
}

/*struct HAR{ int x,y; struct HAR* p; } h[2];
void main()
{
	h[0].x = 1; h[0].y = 2;
	h[1].x = 3; h[1].y = 4;
	h[0].p = &h[1]; h[1].p = h;
	printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);
	return 0;
}



/*#include<stdio.h>
int a, b;
void fun()
{
	a = 100;
	b = 200;
} 
int main()
{
	int a = 5, b = 7;
	fun();
	printf("% d % d / n", a, b);
	return 0;
}*/