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
/*
int f(int n)
{
	if (n) 
		return f(n - 1) + n;
	else 
		return n;
}
void main()
{
	printf("%d", f(4));
}
/*
int main()
{
	float func(float a, int b)
	{
		float m = 1, n = 1;
		int i;
		for (i = 1; i < b; i++)
		{
			m *= a / i;
			n += m;
		}
		return n;
	}
}


/*
int main()
{
	char str[] = "ABCD", * p = str;
	printf("%d\n", *(p + 4));
	return 0;
};

/*#include<stdio.h>
int main()
{
	char* p = "abcdefgh", * r;
	long* q;
	q = (long*)p;
	q++;
	r = (char*)q;
	printf("%s\n", r);
}
/*
int func(int a)
{
	int b;
	switch (a)
	{
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 16;
	default: b = 0;
	} 
		return b;
}
void main()
{
	printf("%d", func(1));
}
/*
#define N 2
#define M N+1
#define NUM (M+1)*M/2
	int main()
	{
		printf("%d\n", NUM);
	}

/*
int main()
{
		int i = 0, a = 0;
		while (i < 20)
		{
			for (;;)
			{
				if ((i % 10) == 0) break;
				else i--;
			} i
				+= 11; a += i;
		}
		printf("%d\n", a);
		return 0;

}*/