#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//演示实例
int main()
{
	int n = 10;
	char* pc = (char*)&n;
	int* pi = &n;
	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	return 0;
}


//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//	
//			arr[i][j] = i * 4 + j;
//	}
//}
//for (i = 0; i < 3; i++)
//{
//	int j = 0;
//	for (j = 0; j < 4; j++)
//	{
//		printf("%d ", arr[i][j]);
//	}
//}
//return 0;
//}
//#include <stdio.h>
//void new_line()
//{
//	printf("hehe\n");
//}
//void three_line()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}

//#include <stdio.h>
//void Swap1(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//void Swap2(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	Swap1(num1, num2);
//	printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
//	Swap2(&num1, &num2);
//	printf("Swap2::num1 = %d num2 = %d\n", num1, num2);
//	return 0;
//}

//
//int fib(int n)
//{
//    int i, x1, x2, x;
//    x = 0;
//    x1 = 1;
//    x2 = 1;
//    for (i = 3; i <= n; i++)
//    {
//        x = x1 + x2;
//        x1 = x2;
//        x2 = x;
//    }
//  if (n == 1 || n == 2)
//        x = 1;
//    return x;
//}
//void PrintFN(int m, int n)
//{
//    int i, count, index, flag;
//    index = 0;
//    flag = 0;
//    i = 1;
//    while (fib(i) < 10000)
//        i++;
//    count = i;
//    for (i = 1; i < count; i++)
//    {
//        if (fib(i) >= m && fib(i) <= n)
//        {
//            flag = 1;
//            index++;
//            if (index == 1)
//            {
//                printf("%d", fib(i));
//                continue;
//            }
//            printf(" %d", fib(i));
//        }
//    }
//    if (!flag)
//        printf("No Fibonacci number");
//    putchar('\n');
//
//}

//#include <stdio.h>
//int main()
//{
//	int i = 10;
//	do
//	{
//		if (5 == i)
//			break;
//		printf("%d\n", i);
//	} while (i < 10);
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i = i + 1;
//	}
//	return 0;
//}

	//int main()
	//{
	//	int i = 1;
	//	while (i <= 10)
	//	{
	//		if (i == 5)
	//			break;
	//		printf("%d ", i);
	//		i = i + 1;
	//	}
	//	return 0;
	//}
//#include <stdio.h>
//int main()
//{
//	int i = 10;
//	do
//	{
//		if (5 == i)
//			continue;
//		printf("%d\n", i);
//	} while (i < 10);
//	return 0;
//}
//#include<string.h>
//#include <windows.h> 　
//#include <stdio.h>
//int main()
//{
//	char arr1[] = "welcome to bit...";
//	char arr2[] = "                 ";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s\n", arr2);
//	//while循环实现
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//	}
//	//for循环实现
//	/*for (left = 0, right = strlen(src) - 1;
//		left <= right;
//		left++, right--)
//
//	{
//	Sleep(1000);
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	printf("%s\n", target);
//	}*/
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int F, C;
//	scanf_s("%d", &F);
//	C = 5 * (F - 32) / 9;
//
//	printf("Celsius=%d", C);
//
//	return 0;
//
//}
//#include <stdio.h>
//
//int main()
//{
//	int c = 0, f;
//	f = 150;
//	c = 5 * (f - 32) / 9;
//	printf("fahr = %d,celsius=%d\n", f, c);
//	return 0;
//}
#include <stdio.h>

//int main()
//{
//	int fahr = 150, celsius;
//	celsius = 5 * (fahr - 32) / 9;
//
//
//	printf("fahr = 150, celsius = %d", celsius);
//
//	return 0;
//}