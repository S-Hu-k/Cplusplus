#include <iostream>
#include <windows.h>
#include <conio.h>
//#include <stdio.h>
int sign_win = 0;
using namespace std;

void start_map(int a[15][15]);//�������Ӧ�ĵ�ͼ��ʾ��������ͼ��СΪ15*15
int* man_move(int* p);
int* move_step(int pointer_move_number, int* p);

int main()
{
    int a[15][15] = { 0 };
    /* a[1][3]=a[3][1]=a[5][3]=a[3][5]=3;
     a[2][3]=a[3][2]=a[3][4]=a[4][3]=2;
     a[3][3]=1;
     int *p=&a[3][3];//ָ���������
     p=&a[3][3];
     while(1)
     {
         start_map(a);
         p=man_move(p);
         system("cls");
     }*/
    a[1][1] = a[1][3] = a[2][1] = a[3][1] = a[3][3] = a[4][3] = a[5][3] = a[5][4] = a[5][5] = a[5][6] = a[6][2] = a[6][3] = a[6][4] = a[6][6] = a[6][7] = a[7][2] = a[7][3] = a[7][4] = 4;
    a[3][7] = a[4][7] = a[5][7] = 3;
    a[2][3] = a[2][2] = a[3][2] = 2;
    a[1][2] = 1;
    int* p = &a[3][3];//ָ���������
    p = &a[1][2];
    while (1)
    {
        start_map(a);
        p = man_move(p);
        system("cls");
    }

    system("pause");
    return 0;
}

void start_map(int a[15][15])  //�������Ӧ�ĵ�ͼ��ʾ����
{
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            switch (a[i][j])
            {
            case 6:
                cout << "��";
                break;//�����ѵ���Ŀ�ĵ�
            case 5:
                cout << "�d";
                break;//��������������Ҫ����ĵط���ͬһλ��
            case 4:
                cout << "  ";
                break;//�հ�����
            case 3:
                cout << "��";
                break;//����Ҫ����ĵط�
            case 2:
                cout << "��";
                break;//����
            case 1:
                cout << "�d";
                break;//��������
            default:
                cout << "��";//ǽ��
            }
        }
        cout << endl;
    }
}

int* man_move(int* p)
{
    char input_move;
    input_move = _getch();//�����ƶ�����
    switch (input_move)
    {
    case 'w':
        p = move_step(-15, p);//����
        break;
    case 's':
        p = move_step(15, p);//����
        break;
    case 'a':
        p = move_step(-1, p);//����
        break;
    case 'd':
        p = move_step(1, p);//����
        break;
    }
    return p;
}

int* move_step(int pointer_move_number, int* p)
{
    int* p1 = p;
    if (*(p + pointer_move_number) == 4 || *(p + pointer_move_number) == 3)  //�ƶ������ϵ�һ��Ϊ��
    {
        if (*p == 5)//ԭλ����Ŀ����غ�
            *p1 = 3;//ԭλ�����ƶ�Ŀ���
        else
            *p1 = 4;   //ԭλ���ÿ�
        p = p1 + pointer_move_number;   //������һ��
        if (*p == 4)
            *p = 1;
        else//�����ƶ�λ��Ϊĳһ����ָ��λ��
            *p = 5;
    }
    else if (*(p + pointer_move_number) == 2 || *(p + pointer_move_number) == 6)  //�ƶ������ϵ�һ��������
    {
        if (*(p + pointer_move_number * 2) == 4 || *(p + pointer_move_number * 2) == 3)//�ƶ������ϵڶ���Ϊ��
        {

            if (*p == 5)//ԭλ����Ŀ����غ�
                *p1 = 3;//ԭλ�����ƶ�Ŀ���
            else
                *p1 = 4;   //ԭλ���ÿ�
            if (*(p1 + pointer_move_number) == 2)//����ԭλ��δ����ָ����
                *(p + pointer_move_number) = 1;//������һ��
            else//����ԭλ���ѵ���Ŀ���
                *(p + pointer_move_number) = 5;
            if (*(p1 + pointer_move_number * 2) == 3)//���ӵ���ָ��λ��
            {
                *(p1 + pointer_move_number * 2) = 6;//������һ��
                sign_win++;
            }
            else
                *(p1 + pointer_move_number * 2) = 2; //������һ��
            p = p1 + pointer_move_number; //pָ�����ڵ�λ��
        }
    }

    return p;
}