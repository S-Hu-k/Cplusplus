/*
#include<stdio.h>
int main() 
{
    int i, j, s, k, tag;
    int x = 0;
    printf("请输入要操作的数:>");
    scanf_s("%d", &x);
    for (i = 1; i <= x; i++)
    {
        s = 0;
        for (j = 1; j <= i / 2; j++) 
        {
            if (i % j == 0)
                s = s + j;
        }
        if (s == i)
        {
            printf("%d\n", i);
           
        }
    }
    return 0;
}


/*
#include <stdio.h>
int main()
{
	int N = 0;
	scanf_s("%d",&N);
	for(int i=1;i<=100;i++)
	{
		
		for (int j = i; j <= 100; j++)

		{
				if ((i + j) * (j - i + 1) / 2 == N)
				{
					printf("i=%d \n", i);
					printf("j=%d \n", j);
				}
		}
	}		
	return 0;
}
*/
#include<stdio.h>
int main()
{
    int flag = 1;
    int x = 1;
    float a = 1.0;
    int b = 0;
    while (fabs(a) >= 0.0001)
    {
        a = flag * 1.0 / x;
        b = b + a;
        flag = -flag;
        x = x + 2;
    }
    printf("%p", &a);

}