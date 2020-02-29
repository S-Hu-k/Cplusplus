/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct clothing
{
	int num;   
	char Name[10];   
	int price;  
	char type;
}clothing[100];
int n, flag;
void save()
{

}
void inputmessage()
{
	
}

void inquiremessage()
{

}
		
void addmessage()
{

}
	
void delmessage()
{

}
void modifymessage()
{

}
int main()
{
	printf("**********************************************\n");
	printf("*********      1.请输入服装信息     **********\n");
	printf("*********      2.查询服装信息       **********\n");
	printf("*********      3.添加服装           **********\n");
	printf("*********      4.删除服装           **********\n");
	printf("*********      5.修改服装信息       **********\n");
	printf("*********      6.exit               **********\n");
	printf("**********************************************\n");
	printf("请选择您需要的步骤<1-6>:\n");
	scanf_s("%d", &n);
	do
	{
		if (n >= 1 && n <= 6)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
			printf("您的输入有误请重新选择!");
		}
	} while (flag == 0);
	while(flag)
	{
		switch (flag)
		{
		case 1:
			inputmessage();
			break;
		case 2:
			inquiremessage();
		case 3:
			addmessage();
		case 4:
			delmessage();
		case 5:
			modifymessage();
		case 6:
			exit(0);
		default:
			break;
		}

	}
}






*/