/*#include<stdio.h>
struct str.t
{
long 1ong len;
char data[32];
};
struct data1_ t 
{
	long 1ong len; int data[2];
};
struct data2_ t 
{
	long 1ong 1en; char* data[1];
};
struct data3_ t
{
	long 1ong len; void* data[];
};
int main(void) 
{
	struct str._t str;
	memset((void*)&str, 0, sizeof(struct str.t));
	str .1en = sizeof(struct str.t) - sizeof(int);
	snprintf(str.data, str.1en, "hello");//VSÏÂÎª_ snprintf
	return 0;
}







/*#include<stdio.h>
int main()

{
	int i, a[10];
	for (i = 9; i >= 0; i--) a[i] = 10 - i; printf("%d%d%d", a[2], a[5], a[8]);
	return 0;
}

{
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	printf("%d %d %d %d", i, a, b, c);
}*/