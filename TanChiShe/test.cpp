//������������C����ʵ�ֵ�����ˮƽ����,ֻ����C++��ִ����,ע��: ����ʹ�õ��ַ���ΪUnicode


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define MY_BUFSIZE 1024    //����̨���ڱ���Ļ�������С
#define INITIALTIME 200

//�ߵ�״̬(��,��,��,��)
#define U 1    
#define D 2    
#define L 3    
#define R 4    



typedef struct Snake
{
	int x;                  //�ڵ��x����
	int y;                  //�ڵ��y����
	struct Snake* next;     //�������һ���ڵ�
}snake;

int score = 0, add = 0;          //�ܵ÷���ÿ�γ�ʳ��ĵ÷�
int HighScore = 0;               //��ߵĵ÷�
int status;                      //�ߵ�ǰ��״̬
int sleeptime = INITIALTIME;     //�ߵ�ʱ����
int endgamestatus = 0;           //��Ϸ�Ľ��������: ײ��ǽ,ҧ���Լ�,�����˳���Ϸ

HANDLE hOut;                     //����̨���
snake* head, * food;             //��ͷָ��,ʳ��ָ��
snake* q;                        //������ʱ�õ���ָ��

void gotoxy(int x, int y);       //���ù��λ��
void color(int col);             //����������ɫ
void printsnake();               //�ַ���,��
void welcometogame();            //��ʼ����
void createMap();                //���Ƶ�ͼ
void scoreandtips();             //��Ϸ�Ҳ�ĵ÷ֺ�С��ʾ
void initsnake();                //��ʼ������(��������)
void createfood();               //�������������ʳ��
bool biteself();                  //�ж��Ƿ�ҧ���Լ�
void cantcrosswall();            //�ж��Ƿ�ײǽ
void speedup();                  //����
void speedown();                 //����
void snakemove();                //�����ߵ�ǰ������
void keyboardControl();          //���Ƽ��̰���
void Lostdraw();                 //��Ϸ��������
void endgame();                  //��Ϸ����
void choose();                   //��Ϸʧ��֮���ѡ��
void File_out();                 //���ļ��ж�ȡ��߷�
void File_in();                  //����߷ִ����ļ�
void explation();                //��Ϸ˵��
HWND GetConsoleHwnd();           //��ȡ��ǰ���
int main(void)
{
	//���ô���
	system("mode con cols=100 lines=30");
	SetWindowLongPtr(GetConsoleHwnd(), GWL_STYLE, WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);

	printsnake();
	welcometogame();
	File_out();
	keyboardControl();
	endgame();
}

//������ɫ
void color(int col)
{
	//����API�ı����̨������ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

//�ı�����λ��
void gotoxy(int x, int y)
{
	COORD Position;
	Position.X = x;
	Position.Y = y;
	//����API�ı�����λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

//�ַ���,��
void printsnake()
{
	color(6);                   //������ɫ����Ϊ��ɫ 

	gotoxy(32, 3);
	printf("~~~~=_=~~~~\\\\   <----------------------˵����������,��������..");

	gotoxy(44, 4);
	printf("\\\\");

	gotoxy(45, 5);
	printf("\\\\");

	gotoxy(46, 6);
	printf("\\\\");

	gotoxy(47, 7);
	printf("\\\\");

	gotoxy(48, 8);
	printf("=========================");

	gotoxy(49, 26);
	return;
}

//��ʼ����
void welcometogame()
{
	int choice;
	int x, y;
	int count1 = 0, count2 = 0;
	gotoxy(37, 15);
	color(11);
	printf("̰   ��   ��   ��   ��   ս");

	for (x = 20; x < 80; x++)
	{
		count2++;
		for (y = 17; y < 26; y++)
		{
			count1++;
			if (x == 20 || x == 79)
			{
				if (count1 % 2 == 0)
					color(9);
				else
					color(13);

				gotoxy(x, y);
				printf("|");
			}

			if (y == 17 || y == 25)
			{
				if (count2 % 2 == 0)
					color(9);
				else
					color(13);

				gotoxy(x, y);
				printf("-");
			}
		}
	}

	gotoxy(32, 19);
	color(13);
	printf("1:��ʼ��Ϸ");

	gotoxy(58, 19);
	printf("2:��Ϸ˵��");

	gotoxy(32, 23);
	printf("3:�˳���Ϸ");

	gotoxy(43, 26);
	printf("��ѡ��[1 2 3]:[ ]\b\b");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		system("cls");
		createMap();
		initsnake();
		createfood();
		keyboardControl();
		break;

	case 2:
		explation();
		break;

	case 3:  exit(0);          break;

	default:

		gotoxy(40, 28);
		color(12);
		printf("�������,������1~3����!");
		_getch();             //����vsϵ��֮��ı�������Ҫ����һ�иĳ�: getch();
		system("cls");
		printsnake();
		welcometogame();
		break;

	};
	return;
}

//��ӡ��ͼ�еķ���
void createMap()
{
	int i, j;
	int count = 0;
	for (i = 0; i < 58; i += 2)
	{
		color(13);         //
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, 26);
		printf("��");
	}

	for (i = 1; i < 26; i++)
	{
		color(13);         //
		gotoxy(0, i);
		printf("��");
		gotoxy(56, i);
		printf("��");
	}

	 
		/*֮���Ƕ���Ч��(��Ȼ��̫�ÿ�)�����Ҫ����ɾ��*/


		color(13);
	for (j = 1; j < 26; j += 2)
	{
		for (i = 2; i < 56; i += 4)
		{
			gotoxy(i, j);
			printf("��");
			Sleep(2);       //���ӵ���ʱЧ��
		}
	}

	color(10);
	for (i = 2; i < 56; i += 4)
	{
		for (j = 2; j < 26; j += 2)
		{
			gotoxy(i, j);
			printf("��");
			Sleep(2);       //���ӵ���ʱЧ��
		}
	}


	/*����*/



	color(3);
	for (i = 2; i < 56; i += 2)
	{
		for (j = 1; j < 26; j++)
		{
			gotoxy(i, j);
			printf("��");
		}
		Sleep(10);       //���ӵ���ʱЧ��
	}
	return;
}

//��Ϸ�Ҳ�ĵ÷ֺ�С��ʾ
void scoreandtips()
{
	int i;
	//File_out();         //��ȡ�ļ��е���߷���
	gotoxy(64, 4);
	color(11);
	printf("����ʷ��߷�Ϊ: %d ��", 1);

	gotoxy(64, 8);
	color(14);
	printf("�÷�: %d", 2);

	gotoxy(73, 11);
	color(13);
	printf("С �� ʾ");

	gotoxy(60, 13);              //��һ���� 
	color(9);
	printf("�p ");
	for (i = 63; i < 92; i++)
	{
		if (i % 2 == 0)
			color(9);
		else
			color(13);
		printf("-");
		gotoxy(i, 13);
	}
	gotoxy(91, 13);
	color(9);
	printf("�p ");


	/*�������������м������*/

	color(3);
	gotoxy(64, 14);
	printf("ÿ��ʳ��÷�: %d��", add);
	gotoxy(64, 16);
	printf("����ײǽ��ҧ���Լ�Ŷ~");
	gotoxy(64, 18);
	printf("�� �� �� �� �� �ֱ�����ߵ��ƶ�");
	gotoxy(64, 20);
	printf("F1:���١�F2:����");
	gotoxy(64, 22);
	printf("�ո������ͣ��Ϸ");
	gotoxy(64, 24);
	printf("Esc����ͣ��Ϸ");

	/*����*/
		gotoxy(60, 25);              //�ڶ����� 
	color(13);
	printf("�p ");
	for (i = 63; i < 92; i++)
	{
		if (i % 2 == 0)
			color(9);
		else
			color(13);
		printf("-");
		gotoxy(i, 25);
	}
	gotoxy(91, 25);
	color(13);
	printf("�p ");
	return;
}

//���ļ��ж�ȡ��߷�
void File_out()
{
	FILE* fp = NULL;
	fp = fopen("snake.data", "r+");
	if (fp == NULL)     //�ж��ļ��Ƿ�򿪳ɹ�,ʧ������ʾ���˳���Ϸ
	{
		//������һ����vs������,������������Ҫ��MessageBox��MessageBox���滻��(������������ char* �����ǿ���ֱ��ת��Ϊ LPCWSTR ���͵Ķ�vsϵ���и�ΪUnicode�ַ������ǲ�����)
		MessageBoxA(NULL, "Data file read / write failure,Please press OK to exit", "Greedy_snake", MB_OK | MB_ICONERROR);
		exit(1);
	}

	fscanf(fp, "%d", &HighScore);    //��ȡ����
	fclose(fp);                      //�ر��ļ�
}

//��ʼ������
void initsnake()
{
	snake* tail;
	int i;
	tail = (snake*)malloc(sizeof(snake));       //������β����β��ʼ��(��������һ���ڵ�),��ͷ�巨,��x,y��Ϊ��ʼλ��

	tail->x = 24;        //��ʼ��λ��Ϊ24,5
	tail->y = 5;
	tail->next = NULL;

	for (i = 0; i <= 4; i++)        //����������Ϊ:5
	{
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;             //��ͷ����һλ��Ϊ��β

		head->x = 24 + 2 * i;          //������ͷ��λ��
		head->y = 5;

		tail = head;                   //��ͷ�����β,Ȼ���ظ�ѭ��(�����е���,�����������)
	}

	while (tail != NULL)
	{
		color(14);
		gotoxy(tail->x, tail->y);
		printf("��");               //������ �� ��ʾ
		tail = tail->next;         //����һ��һ�����,һֱ�������β
	}
	return;
}

//�������ʳ��
void createfood()
{
	snake* food_1 = NULL;

	food_1 = (snake*)malloc(sizeof(snake));

	food_1->x = 1;
	food_1->y = 0;
	food_1->next = NULL;

	srand((unsigned)time(NULL));     //��ʼ������� 

	//food_1->x = rand() % 52 + 2;

	while ((food_1->x % 2) != 0)
	{
		food_1->x = rand() % 52 + 2;          //ʳ���x����(52���ұߵ����ڶ��е�x����, +2����Ϊ��ֹ�����ڱ߿���)
	}

	food_1->y = rand() % 24 + 1;               //ʳ���y����(ΪʲôҪ %24 �� +1 ��ԭ�������һ��)  

	q = head;

	while (q->next == NULL)                    //!!!!!!!!!!!!!!!!!!!!!!!!!1
	{
		if (q->x == food_1->x && q->y == food_1->y)
		{
			free(food_1);    //�������ʳ���غ����ͷ�ʳ��ָ��

			createfood();    //���´���ʳ��
		}
		q = q->next;
	}
	gotoxy(food_1->x, food_1->y);  //����ʳ��λ��

	food = food_1;
	color(12);
	printf("��");               //�Ժ�ɫ��ɫ���ʳ��

	return;
}

//�ж��Ƿ�ҧ���Լ�
bool biteself()
{
	snake* self;               //self�������ϵ�һ���ڵ�(��������֮��Ľڵ�)
	self = head->next;

	while (self != NULL)       //�ж���ͷ�Ƿ���������ͬ,��ͬ����ҧ���Լ���,ҧ���Լ��ͷ���true���򷵻�fslse
	{
		if (self->x == head->x && self->y == head->y)
			return true;
		self = self->next;
	}
	return false;
}

//�ж��Ƿ�ײǽ
void cantcrosswall()
{
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)  //�ж��Ƿ�ײ��ǽ
	{
		endgamestatus = 1;              //������Ϸ��һ�����,endgamestatus����1ʱΪʧ�ܽ���
		endgame();
	}
}

//����
void speedup()
{
	if (sleeptime >= 50)       //���ʱ����ڻ����50ִ������Ĵ���
	{
		sleeptime += 10;       //ʱ������10
		add += 2;              //ÿ�γԵ���ʳ��ķ�����2
	}
}

//����
void speeddown()
{
	if (sleeptime < 350)       //���ʱ����ڻ����50ִ������Ĵ���
	{
		sleeptime += 30;       //ʱ������10
		add += 2;              //ÿ�γԵ���ʳ��ķ�����2
		if (sleeptime == 350)
		{
			add = 1;           //��֤��ͷ�Ϊ 1 ��
		}
	}
}

//�ߵ��ƶ�����
void snakemove()
{
	snake* nexthead;

	cantcrosswall();
	nexthead = (snake*)malloc(sizeof(snake));


	/*
		���������ֻ�����������δ�����Ҫ���������Ķ�����Ҫ����һ�¾ͺ�
			nexthead->x = head->x;
			nexthead->y = head->y - 1;
	*/

	if (status == U)    //�����ƶ�
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;

		nexthead->next = head;
		head = nexthead;
		q = head;          //ָ������ͷ׼����������

		if (nexthead->x == food->x && nexthead->y == food->y)      //���������ʳ��
		{
			color(14);
			while (q != NULL)            //��ӡ����
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score += add;               //����ʳ���ӷ�
			speedup();                  //�������ٶ�
			createfood();               //����ʳ����ٴ���һ��
		}
		else           //���û����ʳ��
		{
			color(14);
			while (q->next->next != NULL)               //����ǰ�ƶ���ǰ���һ,�����һ   �����ƶ�������ǰn-1������(��һ���������) 
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}

			color(3);
			gotoxy(q->x, q->y);
			printf("��");              //�����������ڶ����������
			free(q->next);            //�ͷŵ�ԭ�������һ���������
			q->next = NULL;
		}
	}
	if (status == D)     //�����ƶ�
	{

		nexthead->x = head->x;
		nexthead->y = head->y + 1;

		nexthead->next = head;
		head = nexthead;
		q = head;          //ָ������ͷ׼����������

		if (nexthead->x == food->x && nexthead->y == food->y)      //���������ʳ��
		{
			color(14);
			while (q != NULL)            //��ӡ����
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score += add;               //����ʳ���ӷ�
			speedup();                  //�������ٶ�
			createfood();               //����ʳ����ٴ���һ��
		}
		else
		{
			color(14);
			while (q->next->next != NULL)               //����ǰ�ƶ���ǰ���һ,�����һ   �����ƶ�������ǰn-1������(��һ���������) 
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}

			color(3);
			gotoxy(q->x, q->y);
			printf("��");              //�����������ڶ����������
			free(q->next);            //�ͷŵ�ԭ�������һ���������
			q->next = NULL;
		}
	}

	if (status == L)     //�����ƶ�
	{

		nexthead->x = head->x - 2;
		nexthead->y = head->y;

		nexthead->next = head;
		head = nexthead;
		q = head;          //ָ������ͷ׼����������

		if (nexthead->x == food->x && nexthead->y == food->y)      //���������ʳ��
		{
			color(14);
			while (q != NULL)            //��ӡ����
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score += add;               //����ʳ���ӷ�
			speedup();                  //�������ٶ�
			createfood();               //����ʳ����ٴ���һ��
		}
		else
		{
			color(14);
			while (q->next->next != NULL)               //����ǰ�ƶ���ǰ���һ,�����һ   �����ƶ�������ǰn-1������(��һ���������) 
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}

			color(3);
			gotoxy(q->x, q->y);
			printf("��");              //�����������ڶ����������
			free(q->next);            //�ͷŵ�ԭ�������һ���������
			q->next = NULL;
		}
	}

	if (status == R)     //�����ƶ�
	{

		nexthead->x = head->x + 2;
		nexthead->y = head->y;

		nexthead->next = head;
		head = nexthead;
		q = head;          //ָ������ͷ׼����������

		if (nexthead->x == food->x && nexthead->y == food->y)      //���������ʳ��
		{
			color(14);
			while (q != NULL)            //��ӡ����
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score += add;               //����ʳ���ӷ�
			speedup();                  //�������ٶ�
			createfood();               //����ʳ����ٴ���һ��
		}
		else
		{
			color(14);
			while (q->next->next != NULL)               //����ǰ�ƶ���ǰ���һ,�����һ   �����ƶ�������ǰn-1������(��һ���������) 
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}

			color(3);
			gotoxy(q->x, q->y);
			printf("��");              //�����������ڶ����������
			free(q->next);            //�ͷŵ�ԭ�������һ���������
			q->next = NULL;
		}
	}

	if (biteself() == true)           //�ж��Ƿ�ҧ���Լ�
	{
		endgamestatus = 2;
		endgame();
	}
	return;
}

//���Ƽ��̰���
void keyboardControl()
{
	status = R;     //��ʼ�������ƶ�

	while (1)
	{
		scoreandtips();      //��Ϸ�ұߵ�С��ʾ�͵÷�

		//GetAsyncKeyState���������жϵ���ʱָ����ټ���״̬
		if (GetAsyncKeyState(VK_UP) && status != D)         //������Ĳ��� �� ������ �� �ƶ�
			status = U;
		else if (GetAsyncKeyState(VK_DOWN) && status != U)  //������Ĳ��� �� ������ �� �ƶ�
			status = D;
		else if (GetAsyncKeyState(VK_LEFT) && status != R)  //������Ĳ��� �� ������ �� �ƶ�
			status = L;
		else if (GetAsyncKeyState(VK_RIGHT) && status != L) //������Ĳ��� �� ������ �� �ƶ�
			status = R;

		if (GetAsyncKeyState(VK_SPACE))          //���ո����ͣ
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE))          //�ٰ�һ�οո������
					break;
			}
		}
		else if (GetAsyncKeyState(VK_ESCAPE))            //��Esc��ת����������
		{
			endgamestatus = 3;
			break;
		}
		else if (GetAsyncKeyState(VK_F1))                //F1����
			speedup();
		else if (GetAsyncKeyState(VK_F2))                //F2����
			speeddown();

		Sleep(sleeptime);            //�ƶ��ٶ�
		snakemove();                 //û�а��⼸����ʱ�����ƶ�
	}
	return;
}

//ʧ�ܽ���
void Lostdraw()
{
	int i;
	system("cls");

	//�ĸ����ϵ������			
	color(13);
	gotoxy(4, 6);
	printf("��");
	gotoxy(96, 6);
	printf("��");
	gotoxy(4, 29);
	printf("��");
	gotoxy(96, 29);
	printf("��");

	//��ӡ�߿��������
	for (i = 6; i < 96; i++)
	{
		if (i % 2 == 0)
			color(3);
		else
			color(13);

		gotoxy(i, 6);
		printf("-");
		gotoxy(i, 29);
		printf("-");
	}

	for (i = 7; i < 29; i++)
	{
		if (i % 2 == 0)
			color(3);
		else
			color(13);
		gotoxy(4, i);
		printf("|");
		gotoxy(97, i);
		printf("|");
	}

	//��ӡ�߿��ϵ�װ��
	color(14);
	gotoxy(30, 6);
	printf("o00o");
	gotoxy(71, 6);
	printf("o00o");

	gotoxy(48, 5);
	color(14);
	printf("<  @ @  >");

	gotoxy(50, 6);
	color(3);
	printf("��_��");

	gotoxy(47, 29);
	color(13);
	printf("�������");
	return;
}

//������Ϸ
void endgame()
{
	system("cls");
	if (endgamestatus == 1)
	{
		Lostdraw();
		gotoxy(35, 9);
		color(12);
		printf("�Բ�����ײ��ǽ�ˣ���Ϸ����!");
	}
	else if (endgamestatus == 2)
	{
		Lostdraw();
		gotoxy(35, 9);
		color(14);
		printf("�Բ�����ҧ���Լ��ˣ���Ϸ����!");
	}
	else if (endgamestatus == 3)
	{
		Lostdraw();
		gotoxy(40, 9);
		color(14);
		printf("���Ѿ���������Ϸ��");
	}

	gotoxy(43, 12);
	color(13);
	printf("���ĵ÷���: %d", score);
	if (score >= HighScore)
	{
		color(10);
		gotoxy(33, 16);
		printf("���¼�¼����߷ֱ���ˢ��������������");
		File_in();
	}
	else
	{
		color(10);
		gotoxy(33, 16);
		printf("����Ŭ��Ŷ,������߷�ֻ�� %d �~", HighScore - score);
	}
	choose();
	return;
}

//����߷�д���ļ�
void File_in()
{
	FILE* fp;
	fp = fopen("snake.data", "w+");    //��ֻд�ķ�ʽ���ļ�
	fprintf(fp, "%d", score);          //���ļ��ж�����߷�д�뵽score��
	fclose(fp);                        //�ر��ļ�
}

//�߿������ѡ��
void choose()
{
	int n;
	gotoxy(25, 23);
	color(10);
	printf("��Ҫ������һ��------1");
	gotoxy(52, 23);
	printf("�����ˣ��˳���------2");
label:
	gotoxy(46, 25);
	color(13);
	printf("ѡ��[   ]\b\b\b");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		score = 0;                     //������ʼ��Ϊ 0
		sleeptime = INITIALTIME;       //�ٶȳ�ʼ��Ϊ 0
		add = 10;                      //ʳ��÷�Ϊ��ʼ��Ϊ 10
		printsnake();                  //���ػ�ӭ����
		welcometogame();

	case 2:
		exit(0);
		break;
	default:
		gotoxy(35, 27);
		color(12);
		printf("���������������������������");
		system("pause >nul");
		endgame();
		choose();               //�߿��µķ�֧ѡ��
		goto label;
		break;
	}
	return;
}

//��Ϸ˵��
void explation()
{
	int i, j = 1;
	system("cls");
	gotoxy(42, 4);
	printf("��   Ϸ   ˵   ��");
	color(2);
	for (i = 6; i <= 25; i++)
	{
		for (j = 20; j <= 76; j++)
		{
			gotoxy(j, i);
			if (i == 6 || i == 25)
			{
				if (i % 2 == 0)
					color(3);
				else
					color(13);
				printf("=");
			}
			else if (j == 20 || j == 76)
			{
				if (i % 2 == 0)
					color(3);
				else
					color(13);
				printf("||");
			}
		}
	}

	color(13);
	gotoxy(76, 6);
	printf("��");
	gotoxy(76, 25);
	printf("��");

	color(3);
	gotoxy(30, 8);
	printf("tipl: ����ײǽ������ҧ���Լ�");

	color(10);
	gotoxy(30, 11);
	printf("tip2: �á��������������ֱ�����ߵ��ƶ�");

	color(13);
	gotoxy(30, 14);
	printf("tip3: F1�Ǽ��٣�F2�Ǽ���");

	color(14);
	gotoxy(30, 17);
	printf("tip4: ���ո����ͣ��Ϸ���ٰ�һ�μ�����Ϸ");

	color(4);
	gotoxy(30, 20);
	printf("tip5: Esc���˳���Ϸ");

	color(1);
	gotoxy(30, 23);
	printf("tip6: �Լ��ķ����Լ���Ҫ����");

	_getch();                        //�������������������

	system("cls");
	printsnake();
	welcometogame();
}

HWND GetConsoleHwnd()            //��ȡ���ھ��      
{

	HWND hwndFound;                      //����õľ�� 
	WCHAR pszNewWindowTitle[MY_BUFSIZE]; //���ڱ���

	WCHAR pszOldWindowTitle[MY_BUFSIZE]; //�ɵľ�� 


	//��ȡ��ǰ���ڱ���

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

	//����Ψһ�������ӡ� 

	char szStr[MY_BUFSIZE];

	sprintf(szStr, "%d%d", GetTickCount(), GetCurrentProcessId());   //��ΪΪ�˼��������MessagrBox�����õ�

	memset(pszNewWindowTitle, 0, sizeof(pszNewWindowTitle));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, pszNewWindowTitle, sizeof(pszNewWindowTitle) / sizeof(pszNewWindowTitle[0]));

	//���ĵ�ǰ���ڱ��� 
	SetConsoleTitle(pszNewWindowTitle);

	//ȷ�����ڱ����Ѹ��� 
	Sleep(40);

	//�����´��ڱ���
	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	//��ԭԭʼ���ڱ���
	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);        //���ؾ��
}
