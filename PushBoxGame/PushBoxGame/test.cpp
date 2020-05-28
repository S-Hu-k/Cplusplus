#include <iostream>
#include <windows.h>
#include <conio.h>
//#include <stdio.h>
int sign_win = 0;
using namespace std;

void start_map(int a[15][15]);//将数组对应的地图显示出来，地图大小为15*15
int* man_move(int* p);
int* move_step(int pointer_move_number, int* p);

int main()
{
    int a[15][15] = { 0 };
    /* a[1][3]=a[3][1]=a[5][3]=a[3][5]=3;
     a[2][3]=a[3][2]=a[3][4]=a[4][3]=2;
     a[3][3]=1;
     int *p=&a[3][3];//指向操作对象
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
    int* p = &a[3][3];//指向操作对象
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

void start_map(int a[15][15])  //将数组对应的地图显示出来
{
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            switch (a[i][j])
            {
            case 6:
                cout << "▼";
                break;//箱子已到达目的地
            case 5:
                cout << "卍";
                break;//操作对象与箱子要到达的地方在同一位置
            case 4:
                cout << "  ";
                break;//空白区域
            case 3:
                cout << "□";
                break;//箱子要到达的地方
            case 2:
                cout << "▼";
                break;//箱子
            case 1:
                cout << "卍";
                break;//操作对象
            default:
                cout << "■";//墙壁
            }
        }
        cout << endl;
    }
}

int* man_move(int* p)
{
    char input_move;
    input_move = _getch();//输入移动方向
    switch (input_move)
    {
    case 'w':
        p = move_step(-15, p);//上移
        break;
    case 's':
        p = move_step(15, p);//下移
        break;
    case 'a':
        p = move_step(-1, p);//左移
        break;
    case 'd':
        p = move_step(1, p);//右移
        break;
    }
    return p;
}

int* move_step(int pointer_move_number, int* p)
{
    int* p1 = p;
    if (*(p + pointer_move_number) == 4 || *(p + pointer_move_number) == 3)  //移动方向上第一格为空
    {
        if (*p == 5)//原位置与目标点重合
            *p1 = 3;//原位置置移动目标□
        else
            *p1 = 4;   //原位置置空
        p = p1 + pointer_move_number;   //人物移一格
        if (*p == 4)
            *p = 1;
        else//人物移动位置为某一箱子指定位置
            *p = 5;
    }
    else if (*(p + pointer_move_number) == 2 || *(p + pointer_move_number) == 6)  //移动方向上第一格有箱子
    {
        if (*(p + pointer_move_number * 2) == 4 || *(p + pointer_move_number * 2) == 3)//移动方向上第二格为空
        {

            if (*p == 5)//原位置与目标点重合
                *p1 = 3;//原位置置移动目标□
            else
                *p1 = 4;   //原位置置空
            if (*(p1 + pointer_move_number) == 2)//箱子原位置未到达指定点
                *(p + pointer_move_number) = 1;//人物移一格
            else//箱子原位置已到达目标点
                *(p + pointer_move_number) = 5;
            if (*(p1 + pointer_move_number * 2) == 3)//箱子到达指定位置
            {
                *(p1 + pointer_move_number * 2) = 6;//箱子移一格
                sign_win++;
            }
            else
                *(p1 + pointer_move_number * 2) = 2; //箱子移一格
            p = p1 + pointer_move_number; //p指向现在的位置
        }
    }

    return p;
}