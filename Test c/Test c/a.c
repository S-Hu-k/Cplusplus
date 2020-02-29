#define _CRT_SECURE_NO_WARNINGS 1
1 #include<stdio.h>

2 #include<windows.h>

3 #include<stdlib.h>

4 #include<string.h>

5 #include<conio.h>

6 #define N 200

7 typedef struct birthday

8 {

    9     int year;

    10     int month;

    11     int day;

    12 }Birthday;

13 struct file

14 {

    15     char id[20];//学号

    16     char name[20];//姓名

    17     char sex[2];//性别

    18     int age;//年龄

    19     Birthday birthday;//出生日期

    20     char desc[20];//备注

    21 }File[N];

    22

        23 void toxy(int x, int y)      //将光标移动到X,Y坐标处

        24 {

        25 COORD pos = { x , y };

        26 HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);

        27 SetConsoleCursorPosition(Out, pos);

        28 }

    29

        30

        31

        32 void load();//系统登陆页面

    33 void save_password(char str[]);//保存密码

    34 void menu();//系统主菜单

    35 void input(int n);//学生信息录入

    36 void output();//学生信息显示

    37 void save(int n);//学生信息保存

    38 void dele();//学生信息删除

    39 void change();//学生信息修改

    40 void invest();//学生信息查询

    41 void change_password();//修改密码

    42 void over();//退出系统

    43

        44 void input(int n)//信息录入，录入学生的基本信息

        45 {

        46     int i;

        47     for (i = 0; i < n; i++)

            48     {

            49         system("cls");//清屏

            50         toxy(15, 6);

            51         printf("请输入学生学号:");

            52         scanf("%s", File[i].id);

            53         toxy(15, 7);

            54         printf("请输入学生姓名:");

            55         scanf("%s", File[i].name);

            56         toxy(15, 8);

            57         printf("请输入学生性别(男/女):");

            58         scanf("%s", File[i].sex);

            59         toxy(15, 9);

            60         printf("请输入学生年龄:");

            61         scanf("%d", &File[i].age);

            62         toxy(15, 10);

            63         printf("请输入学生的出生日期(年月日，以空格隔开):");

            64         scanf("%d%d%d", &File[i].birthday.year, &File[i].birthday.month, &File[i].birthday.day);

            65         toxy(15, 11);

            66         printf("请输入备注:");

            67       scanf("%s", File[i].desc);

            68     }

        69     system("cls");//清屏

        70     toxy(15, 6);

        71     printf("录入完毕，请记得返回保存(*^▽^*)");

        72     toxy(15, 8);

        73     printf("按任意键可返回主菜单！");

        74     getch();

        75

            76 }

    77

        78 void output()//信息显示，将学生的基本信息显示到屏幕上

        79 {

        80     system("cls");//清屏

        81     system("color F");//字体颜色为亮白色

        82     int i;

        83     FILE * fp;

        84     toxy(15, 6);

        85     printf("***********学生基本信息*************n");

        86     toxy(15, 8);

        87     printf(" 学号       姓名     性别     年龄    出生日期    备注");

        88     toxy(15, 10);

        89     if ((fp = fopen("stu", "r")) == NULL)//只用读，用r打开stu文件

            90     {

            91         system("cls");

            92         toxy(15, 6);

            93         printf("cannot open file");

            94         toxy(15, 8);

            95         exit(0);

            96     }

        97     else

            98     {

            99

                100       for (i = 0; i < N; i++)

                101       {

                102         fread(&File[i], sizeof(struct file), 1, fp);//从文件中读取数据到File中

                103         if (feof(fp))//判断文件是否读到了最后

                    104             break;

                105         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7sn", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                106         toxy(15, 11 + i);

                107       }

            108     memset(File, NULL, sizeof(File));//重置File

            109     }

        110     printf("显示完毕，请按任意键返回主菜单");

        111     getch();

        112

            113 }

    114

        115 void save(int n) //信息保存，将录入的学生信息保存到文件中

        116 {

        117     system("cls");//清屏

        118     system("color F");//字体颜色为亮白色

        119     FILE * fp;

        120     fp = fopen("stu", "a+");//以追加的方式打开文件，结束时指针停在文件尾

        121     int i;

        122     for (i = 0; i < n; i++)

            123     {

            124         if (File[i].age == NULL) continue;//避免空白数据

            125          fwrite(&File[i], sizeof(struct file), 1, fp);//向指定的文件中写入数据

            126     }

        127     fclose(fp);

        128     n = NULL;//重置

        129     memset(File, NULL, sizeof(File));//重置结构体数组File

        130     toxy(15, 8);

        131     printf("档案保存成功!即将返回主菜单……");

        132     Sleep(800);

        133

            134 }

    135

        136 void dele()//信息删除，把不要的学生基本信息删除

        137 {

        138

            139    system("cls");//清屏

        140    system("color F");//字体颜色为亮白色

        141    int i, flag = 0;//flag是否找到删除学生的标志

        142    char number[20];

        143    char name[20];

        144    char c;

        145  do

            146  {

            147      toxy(15, 6);

            148      printf("请输入要删除学生的学号和姓名:");

            149      toxy(15, 8);

            150   scanf("%s%s", number, name);

            151   FILE * fp1, * fp2;

            152   fp1 = fopen("stu", "r+");//为了读和写，用r+打开stu文本文件

            153   fp2 = fopen("linshi", "w+");//用w+打开一个临时的文本文件

            154   if (fp1 == NULL || fp2 == NULL)

                155   {

                156       toxy(15, 10);

                157       printf("cannot open file!");

                158       toxy(15, 12);

                159       exit(0);

                160   }

            161   for (i = 0; i < N; i++)

                162   {

                163       while (fread(&File[i], sizeof(struct file), 1, fp1))//从文件中读取数据到File

                    164       {

                    165           if (feof(fp1))// 判断文件是否读到了最后

                        166               break;

                    167           if (strcmp(number, File[i].id) == 0 && strcmp(name, File[i].name) == 0)//判断要删除的学号和姓名是否与文件数据有相同，若相同则跳过这次循环

                        168           {

                        169               flag = 1;

                        170               continue;

                        171           }

                    172           else

                        173           {

                        174               fwrite(&File[i], sizeof(struct file), 1, fp2);//将File的信息写入文件

                        175           }

                    176       }

                177   }

            178   fclose(fp1);

            179   fclose(fp2);

            180   if (system("copy linshi stu") == 0)//将linshi文件的内容复制覆盖到stu文件，若成功则返回0

                181   {

                182       system("cls");//清屏

                183       system("DEL linshi");//删除linshi文件

                184       system("cls");//清屏

                185   }

            186   if (flag == 1)//找到删除学生            

                187   {

                188

                    189       toxy(15, 10);

                190       printf("成功删除该学生，系统将自动帮您更新并保存档案n");

                191       Sleep(800);

                192       menu();

                193

                    194   }

            195   if (flag == 0)//无法找到被删除学生

                196   {

                197       toxy(15, 10);

                198       printf("删除失败!学号或姓名输入错误");

                199       toxy(15, 11);

                200       printf("按1返回主菜单，按2重新输入n");

                201       toxy(15, 11);

                202       while (1)

                    203       {

                    204           c = getch();

                    205           if (c == '1')

                        206           {

                        207               menu();

                        208           }

                    209           else if (c == '2')

                        210               dele();

                    211       }

                212   }

            213

                214  }while (1);

            215 }

    216 void change()//修改信息，修改错误的学生信息

        217 {

        218     int sign = 0;//用来标志密码验证成功或否

        219     int j = 3;//每次进入此功能，用户有3次验证密码机会

        220     do

            221     {

            222     system("cls");//清屏

            223     system("color F");//字体颜色为亮白色

            224     char str[18];

            225     FILE * fp;

            226     if ((fp = fopen("password", "r")) == NULL)

                227     {

                228         printf("cannot open filen");

                229         exit(0);

                230     }

            231     fgets(str, 18, fp);//从文件中读取密码数据保存到str数组中

            232     fclose(fp);

            233     toxy(15, 6);

            234     printf("进入该功能，须再次验证登陆密码:n");

            235     toxy(15, 8);

            236         char c;

            237         char password[18];

            238         int i = 0;

            239         for (;;)//此处为输入密码不回显操作

                240         {

                241             c = getch();//输入c

                242             if (c == 'r')//如果输入c为回车，则跳出循环

                    243             {

                    244                 break;

                    245             }

                246             if (c == 'b') //如果输入c为删除键

                    247             {

                    248                 printf("b");

                    249                 printf(" ");

                    250                 printf("b");

                    251             }

                252             else

                    253             {

                    254                 password[i] = c;

                    255                 printf("*");

                    256                 i++;

                    257             }

                258         }

            259         password[i] = '';//在字符串结尾作结束符标记

            260         if (strcmp(str, password) == 0)//验证密码是否正确

                261         {

                262           system("cls");//清屏

                263           toxy(15, 10);

                264           printf("验证成功！即将进入修改功能!");

                265           Sleep(600);

                266           sign = 1;

                267           break;

                268         }

            269         else

                270         {

                271             toxy(15, 10);

                272             j--;

                273             printf("密码错误!您还有%d次验证机会", j);

                274             Sleep(600);

                275         }

            276     }while (j > 0);//验证机会不为0

            277     if (j == 0)

                278     {

                279         system("cls");

                280         toxy(15, 6);

                281         printf("验证机会已用完，即将返回主菜单……");

                282         Sleep(600);

                283         menu();

                284     }

            285

                286     int select, i;

            287     char number[20];

            288     int count = 0;

            289     if (sign)

                290     {

                291         system("cls");

                292         while (select != 7)

                    293         {

                    294         system("cls");

                    295         toxy(15, 6);

                    296         printf("--------------1.修改学号-------------");

                    297         toxy(15, 7);

                    298         printf("--------------2.修改姓名-------------");

                    299         toxy(15, 8);

                    300         printf("--------------3.修改性别-------------");

                    301         toxy(15, 9);

                    302         printf("--------------4.修改年龄-------------");

                    303         toxy(15, 10);

                    304         printf("--------------5.修改出生日期---------");

                    305         toxy(15, 11);

                    306         printf("--------------6.修改备注 ------------");

                    307         toxy(15, 12);

                    308         printf("--------------7. 退出 ---------------");

                    309         toxy(15, 13);

                    310         printf("请输入1~6进行选择:");

                    311         toxy(15, 14);

                    312         scanf("%d", &select);

                    313         FILE * fp1;

                    314         toxy(15, 15);

                    315      if ((fp1 = fopen("stu", "r+")) == NULL)//为了读和写，用r+打开stu文件

                        316      {

                        317          system("cls");//清屏

                        318          toxy(15, 6);

                        319         printf("cannot open file!");

                        320         toxy(15, 8);

                        321         exit(0);

                        322      }

                    323      for (i = 0; i < N; i++)

                        324     {

                        325         fread(&File[i], sizeof(struct file), 1, fp1);//从文件中读取数据到File

                        326          if (feof(fp1))//判断文件是否读到了最后

                            327             break;

                        328         count++;//每次成功从stu文件中读取信息，则学生数据个数加1

                        329     }

                    330      int flag = 0;

                    331         switch (select)

                        332         {

                    333         case 1://修改学号

                        334                 system("cls");//清屏

                        335                 toxy(15, 5);

                        336                 printf("请输入要修改学生的学号:");

                        337                 toxy(15, 6);

                        338                 scanf("%s", number);

                        339                 for (i = 0; i < count; i++)

                            340                 {

                            341                     if ((strcmp(number, File[i].id)) == 0)

                                342                     {

                                343                         toxy(15, 7);

                                344                         printf("*********************学生基本信息*********************");

                                345                         toxy(15, 8);

                                346                         printf(" 学号       姓名     性别     年龄    出生日期    备注");

                                347                         toxy(15, 9);

                                348                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                349                         toxy(15, 10);

                                350                         printf("重新输入该学生的学号进行修改:");

                                351                         toxy(15, 11);

                                352                         scanf("%s", File[i].id);

                                353                         flag = 1;

                                354                         break;

                                355                     }

                            356                 }

                        357                 fclose(fp1);

                        358                 if (flag == 1)

                            359                 {

                            360                     system("cls");//清屏

                            361                     toxy(15, 12);

                            362                     printf("修改成功！系统已自动保存！");

                            363                     toxy(15, 13);

                            364                     printf("正在自动跳转到主菜单....");

                            365                     FILE * fp2;

                            366                     if ((fp2 = fopen("stu", "w+")) == NULL)//用w+打开stu文件同时清空文件内容

                                367                     {

                                368                         printf("cannot open file!");

                                369                         exit(0);

                                370                     }

                            371                     for (i = 0; i < count; i++)

                                372                         fwrite(&File[i], sizeof(file), 1, fp2);//将File的信息写入stu文件

                            373                     fclose(fp2);

                            374                     Sleep(600);

                            375                     menu();

                            376

                                377                 }

                        378                 if (flag == 0)

                            379                 {

                            380                     toxy(15, 12);

                            381                     printf("该学生不存在!");

                            382                     toxy(15, 13);

                            383                     char c;

                            384                     printf("1.返回上一级  2.返回主菜单");

                            385                     toxy(15, 14);

                            386                     c = getch();

                            387                     if (c == '1') break;

                            388                     if (c == '2') menu();

                            389                 }

                        390

                    391         case 2://修改姓名

                        392             system("cls");//清屏

                        393             toxy(15, 5);

                        394                 printf("请输入要修改学生的学号:");

                        395                 toxy(15, 6);

                        396                 scanf("%s", number);

                        397                 for (i = 0; i < count; i++)

                            398                 {

                            399                     if ((strcmp(number, File[i].id)) == 0)

                                400                     {

                                401                         toxy(15, 7);

                                402                         printf("*********************学生基本信息*********************");

                                403                         toxy(15, 8);

                                404                         printf(" 学号       姓名     性别     年龄    出生日期    备注");

                                405                         toxy(15, 9);

                                406                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                407                         toxy(15, 10);

                                408                         printf("重新输入该学生的姓名进行修改:");

                                409                         toxy(15, 11);

                                410                         scanf("%s", File[i].name);

                                411                         flag = 1;

                                412                         break;

                                413                     }

                            414                 }

                        415                 if (flag == 1)

                            416                 {

                            417                     system("cls");//清屏

                            418                     toxy(15, 12);

                            419                     printf("修改成功！系统已自动保存！");

                            420                     toxy(15, 13);

                            421                     printf("正在自动跳转到主菜单....");

                            422                     FILE * fp2;

                            423                     if ((fp2 = fopen("stu", "w+")) == NULL)//用w+打开stu文件同时清空文件内容

                                424                     {

                                425                         printf("cannot open file!");

                                426                         exit(0);

                                427                     }

                            428                     for (i = 0; i < count; i++)

                                429                         fwrite(&File[i], sizeof(file), 1, fp2);//将File的信息写入stu文件

                            430                     fclose(fp2);

                            431                     Sleep(600);

                            432                     menu();

                            433

                                434                 }

                        435                 if (flag == 0)

                            436                 {

                            437                     toxy(15, 12);

                            438                     printf("该学生不存在!");

                            439                     toxy(15, 13);

                            440                     char c;

                            441                     printf("1.返回上一级  2.返回主菜单");

                            442                     toxy(15, 14);

                            443                     c = getch();

                            444                     if (c == '1') break;

                            445                     if (c == '2') menu();

                            446                 }

                        447

                    448         case 3://修改性别

                        449             system("cls");//清屏

                        450             toxy(15, 5);

                        451                 printf("请输入要修改学生的学号:");

                        452                 toxy(15, 6);

                        453                 scanf("%s", number);

                        454                 for (i = 0; i < count; i++)

                            455                 {

                            456                     if ((strcmp(number, File[i].id)) == 0)

                                457                     {

                                458                         toxy(15, 7);

                                459                         printf("*********************学生基本信息*********************");

                                460                         toxy(15, 8);

                                461                         printf(" 学号       姓名     性别     年龄    出生日期    备注");

                                462                         toxy(15, 9);

                                463                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                464                         toxy(15, 10);

                                465                         printf("重新输入该学生的性别进行修改:");

                                466                         toxy(15, 11);

                                467                         scanf("%s", File[i].sex);

                                468                         flag = 1;

                                469                         break;

                                470                     }

                            471                 }

                        472                 if (flag == 1)

                            473                 {

                            474                     system("cls");//清屏

                            475                     toxy(15, 12);

                            476                     printf("修改成功！系统已自动保存！");

                            477                     toxy(15, 13);

                            478                     printf("正在自动跳转到主菜单....");

                            479                     FILE * fp2;

                            480                     if ((fp2 = fopen("stu", "w+")) == NULL)//用w+打开stu文件同时清空文件内容

                                481                     {

                                482                         printf("cannot open file!");

                                483                         exit(0);

                                484                     }

                            485                     for (i = 0; i < count; i++)

                                486                         fwrite(&File[i], sizeof(file), 1, fp2);//将File的信息写入stu文件

                            487                     fclose(fp2);

                            488                     Sleep(600);

                            489                     menu();

                            490

                                491                 }

                        492                 if (flag == 0)

                            493                 {

                            494                     toxy(15, 12);

                            495                     printf("该学生不存在!");

                            496                     toxy(15, 13);

                            497                     char c;

                            498                     printf("1.返回上一级  2.返回主菜单");

                            499                     toxy(15, 14);

                            500                     c = getch();

                            501                     if (c == '1') break;

                            502                     if (c == '2') menu();

                            503                 }

                    504         case 4://修改年龄

                        505             system("cls");//清屏

                        506             toxy(15, 5);

                        507                 printf("请输入要修改学生的学号:");

                        508                 toxy(15, 6);

                        509                 scanf("%s", number);

                        510                 for (i = 0; i < count; i++)

                            511                 {

                            512                     if ((strcmp(number, File[i].id)) == 0)

                                513                     {

                                514                         toxy(15, 7);

                                515                         printf("*********************学生基本信息*********************");

                                516                         toxy(15, 8);

                                517                         printf(" 学号       姓名     性别     年龄    出生日期    备注");

                                518                         toxy(15, 9);

                                519                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                520                         toxy(15, 10);

                                521                         printf("重新输入该学生的年龄进行修改:");

                                522                         toxy(15, 11);

                                523                         scanf("%d", &File[i].age);

                                524                         flag = 1;

                                525                     }

                            526                 }

                        527                 if (flag == 1)

                            528                 {

                            529                     system("cls");//清屏

                            530                     toxy(15, 12);

                            531                     printf("修改成功！系统已自动保存！");

                            532                     toxy(15, 13);

                            533                     printf("正在自动跳转到主菜单....");

                            534                     FILE * fp2;

                            535                     if ((fp2 = fopen("stu", "w+")) == NULL)//用w+打开stu文件同时清空文件内容

                                536                     {

                                537                         printf("cannot open file!");

                                538                         exit(0);

                                539                     }

                            540                     for (i = 0; i < count; i++)

                                541                         fwrite(&File[i], sizeof(file), 1, fp2);//将File的信息写入stu文件

                            542                     fclose(fp2);

                            543                     Sleep(600);

                            544                     menu();

                            545

                                546                 }

                        547                 if (flag == 0)

                            548                 {

                            549                     toxy(15, 12);

                            550                     printf("该学生不存在!");

                            551                     toxy(15, 13);

                            552                     char c;

                            553                     printf("1.返回上一级  2.返回主菜单");

                            554                     toxy(15, 14);

                            555                     c = getch();

                            556                     if (c == '1') break;

                            557                     if (c == '2') menu();

                            558                 }

                        559

                    560         case 5://修改出生日期

                        561             system("cls");//清屏

                        562             toxy(15, 5);

                        563             printf("请输入要修改学生的学号:");

                        564             toxy(15, 6);

                        565                 scanf("%s", number);

                        566                 for (i = 0; i < count; i++)

                            567                 {

                            568                     if ((strcmp(number, File[i].id)) == 0)

                                569                     {

                                570                         toxy(15, 7);

                                571                         printf("*********************学生基本信息*********************");

                                572                         toxy(15, 8);

                                573                         printf(" 学号       姓名     性别     年龄    出生日期    备注");

                                574                         toxy(15, 9);

                                575                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                576                         toxy(15, 10);

                                577                         printf("重新输入该学生的出生日期(年 月 日)进行修改:");

                                578                         toxy(15, 11);

                                579                         scanf("%d%d%d", &File[i].birthday.year, &File[i].birthday.month, &File[i].birthday.day);

                                580                         flag = 1;

                                581                     }

                            582                 }

                        583                 if (flag == 1)

                            584                 {

                            585                     system("cls");//清屏

                            586                     toxy(15, 12);

                            587                     printf("修改成功！系统已自动保存！");

                            588                     toxy(15, 13);

                            589                     printf("正在自动跳转到主菜单....");

                            590                     FILE * fp2;

                            591                     if ((fp2 = fopen("stu", "w+")) == NULL)//用w+打开stu文件同时清空文件内容

                                592                     {

                                593                         printf("cannot open file!");

                                594                         exit(0);

                                595                     }

                            596                     for (i = 0; i < count; i++)

                                597                         fwrite(&File[i], sizeof(file), 1, fp2);//将File的信息写入stu文件

                            598                     fclose(fp2);

                            599                     Sleep(600);

                            600                     menu();

                            601

                                602                 }

                        603                 if (flag == 0)

                            604                 {

                            605                     toxy(15, 12);

                            606                     printf("该学生不存在!");

                            607                     toxy(15, 13);

                            608                     char c;

                            609                     printf("1.返回上一级  2.返回主菜单");

                            610                     toxy(15, 14);

                            611                     c = getch();

                            612                     if (c == '1') break;

                            613                     if (c == '2') menu();

                            614                 }

                        615

                    616         case 6://修改备注

                        617         system("cls");//清屏

                        618             toxy(15, 5);

                        619                 printf("请输入要修改学生的学号:");

                        620                 toxy(15, 6);

                        621                 scanf("%s", number);

                        622                 for (i = 0; i < count; i++)

                            623                 {

                            624                     if ((strcmp(number, File[i].id)) == 0)

                                625                     {

                                626                         toxy(15, 7);

                                627                         printf("*********************学生基本信息*********************");

                                628                         toxy(15, 8);

                                629                         printf(" 学号       姓名     性别     年龄    出生日期    备注");

                                630                         toxy(15, 9);

                                631                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                632                         toxy(15, 10);

                                633                         printf("重新输入该学生的备注进行修改:");

                                634                         toxy(15, 11);

                                635                         scanf("%s", &File[i].desc);

                                636                         flag = 1;

                                637                     }

                            638                 }

                        639                 if (flag == 1)

                            640                 {

                            641                     system("cls");//清屏

                            642                     toxy(15, 12);

                            643                     printf("修改成功！系统已自动保存！");

                            644                     toxy(15, 13);

                            645                     printf("正在自动跳转到主菜单....");

                            646                     FILE * fp2;

                            647                     if ((fp2 = fopen("stu", "w+")) == NULL)//用w+打开stu文件同时清空文件内容

                                648                     {

                                649                         printf("cannot open file!");

                                650                         exit(0);

                                651                     }

                            652                     for (i = 0; i < count; i++)

                                653                         fwrite(&File[i], sizeof(file), 1, fp2);//将File的信息写入stu文件

                            654                     fclose(fp2);

                            655                     Sleep(600);

                            656                     menu();

                            657

                                658                 }

                        659                 if (flag == 0)

                            660                 {

                            661                     toxy(15, 12);

                            662                     printf("该学生不存在!");

                            663                     toxy(15, 13);

                            664                     char c;

                            665                     printf("1.返回上一级  2.返回主菜单");

                            666                     toxy(15, 14);

                            667                     c = getch();

                            668                     if (c == '1') break;

                            669                     if (c == '2') menu();

                            670                 }

                        671

                    672         case 7:system("cls");//清屏

                    673         default:break;

                                       674         }

                    675         }

                676

                    677     }

            678 }

    679 void invest()//查询信息，可按学号、姓名、性别、年龄、出生日期查询学生的基本信息

        680 {

        681     system("cls");//清屏

        682     system("color F");//字体颜色为亮白色

        683     int i, x, flag, year, month, day, age;

        684     char number[20];

        685     char name[20];

        686     char sex[5];

        687     while (x != 6)

            688     {

            689     system("cls");

            690     toxy(15, 6);

            691     printf("请选择查询功能:n");

            692     toxy(15, 7);

            693     printf("t1.查询学号n");

            694     toxy(15, 8);

            695     printf("t2.查询姓名n");

            696     toxy(15, 9);

            697     printf("t3.查询性别n");

            698     toxy(15, 10);

            699     printf("t4.查询出生日期n");

            700     toxy(15, 11);

            701     printf("t5.查询年龄n");

            702     toxy(15, 12);

            703     printf("t6.退出n");

                 toxy(15, 13);

               printf("请输入选择:");

                 scanf("%d", &x);

                 FILE * fp;

                if ((fp = fopen("stu", "r")) == NULL)//只用读，用r打开stu文件

                     {

                         system("cls");//清屏

                         toxy(15, 6);

                        printf("cannot open filen");

                         toxy(15, 8);

                        exit(0);

                    }

                int count = 0;//用来记录文件中学生数据的个数

               for (i = 0; i < N; i++)

                         {

                        fread(&File[i], sizeof(struct file), 1, fp);//将stu文件信息传到File中
        if (feof(fp))//判断文件是否读到了最后

                             break;
         count++;//每次成功从stu文件中读取信息，则学生数据个数加1
         }

                 fclose(fp);

             switch (x)

                    {
    case 1:

                         system("cls");//清屏

                      toxy(15, 6);

                       printf("请输入学号:");

                         toxy(15, 8);

                       scanf("%s", number);

                       system("cls");//清屏

                       flag = 0;

                       toxy(15, 6);

                         printf("学号为%s的学生信息如下:", number);

                       for (i = 0; i < count; i++)

                        {

                              if ((strcmp(number, File[i].id)) == 0)
             {
                 toxy(15, 7 + i);

                                       printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                       flag = 1;

                                   }

                          }

                         if (flag == 0)

                            {

                              toxy(15, 8);

                           printf("无法找到你要找的学生!");

                           }

                         toxy(15, 11 + count);

                       printf("按任意键后可返回……");

                                getch();

                       break;

                case 2:

                        system("cls");//清屏

                        toxy(15, 6);

                         printf("请输入姓名:");
        toxy(15, 8);
         scanf("%s", name);
          flag = 0;

                         system("cls");//清屏
          toxy(15, 6);

                          printf("姓名为%s的学生信息如下:", name);

                         for (i = 0; i < count; i++)

                            {
            if (strcmp(name, File[i].name) == 0)

                                  {

                                        toxy(15, 7 + i);

                                        printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                        flag = 1;

                                     }

                             }

                         if (flag == 0)
        {

                             toxy(15, 8);

                                 printf("无法找到你要找的学生!");

                             }

                      toxy(15, 11 + count);

                      printf("按任意键后可返回……");

                         getch();

                         break;

               case 3:

                       system("cls");//清屏

                         toxy(15, 6);

                       printf("请输入性别(男/女):");

                         toxy(15, 8);

                         scanf("%s", sex);

                        system("cls");//清屏

                      flag = 0;

                         toxy(15, 6);

                       printf("性别为%s的学生信息如下:", sex);

                        for (i = 0; i < count; i++)

                           {

                               if (strcmp(sex, File[i].sex) == 0)

                                     {

                                       toxy(15, 7 + i);

                                       printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                    flag = 1;

                                    }

                            }

                         if (flag == 0)

                             {

                             toxy(15, 8);

                               printf("无法找到你要找的学生!");

                           }

                       toxy(15, 11 + count);

                       printf("按任意键后可返回……");

                        getch();

                          break;

                 case 4:

                        system("cls");//清屏
       toxy(15, 6);
        printf("请输入出生日期(年 月 日):");

                        toxy(15, 8);
       scanf("%d%d%d", &year, &month, &day);

                      system("cls");//清屏

                        flag = 0;

                         toxy(15, 6);

                       printf("出生日期为%d年%d月%d日的学生信息如下:", year, month, day);

                         for (i = 0; i < count; i++)

                            {

                                if (year == File[i].birthday.year && year == File[i].birthday.month && year == File[i].birthday.day)

                                   {
                toxy(15, 7 + i);
                printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                        flag = 1;

                                    }

                          }
        if (flag == 0)

                           {

                               toxy(15, 8);
             printf("无法找到你要找的学生!");
       }
        toxy(15, 11 + count);
      printf("按任意键后可返回……");

                      getch();

                       break;

                case 5:

                        system("cls");//清屏

                        toxy(15, 6);

                        printf("请输入年龄:");
        toxy(15, 8);
         scanf("%d", &age);
       system("cls");//清屏

                       flag = 0;

                       toxy(15, 6);

                      printf("年龄为%d的学生信息如下:", age);
        for (i = 0; i < count; i++)

                           {

                              if (age == File[i].age)

                               {

                                     toxy(15, 7 + i);

                                      printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                        flag = 1;

                                 }
        }
     if (flag == 0)
       {
          toxy(15, 8);
           printf("无法找到你要找的学生!");

                          }

                      toxy(15, 11 + count);

                       printf("按任意键后可返回……");

                      getch();

                     break;

              case 6:system("cls");//清屏

                               toxy(15, 8);

                                  printf("即将返回主菜单……");

                                  Sleep(700);

                                break;
    }
    }

         }

     void over()//退出功能，显示退出软件的提示 

      {

           char t;

            system("color F");//字体颜色为亮白色

            toxy(15, 11);

            printf("--------------------------");

            toxy(15, 12);

            printf("|    您确定要退出吗？    |");

            toxy(15, 14);

            printf("|  1.确定      2.取消    |");
     toxy(15, 15);
     printf("--------------------------");

           while (1)

               {

                   t = getch();         //输入t

                    switch (t)

                        {

                         case '1':

                             system("cls");//清屏

                             system("color F");//字体颜色为亮白色

                             toxy(15, 10);
            printf("正在安全退出....");
            Sleep(1000);     //暂停1秒 
             system("cls");
             system("color F");//字体颜色为亮白色
             toxy(15, 10);
             printf("已安全退出软件");
            toxy(15, 12);
             printf("谢谢使用！");
           toxy(15, 14);
             printf("bye-bye^_^");
             toxy(15, 16);
           exit(0);  break; //终止程序 
          case '2':

                            menu(); break;   //调用函数，进入菜单 

                        default:break;

                                            }
    }
 }

 void menu()//菜单功能，显示各种操作功能
{
    system("cls");//清屏
    fflush(stdin);//清空缓存
   char x;
    int n;
    while (x != 'h')
     {
        system("color F");//字体颜色为亮白色
         system("cls");
        toxy(15, 4);
        printf("-----班级档案管理系统-----");
        toxy(15, 5);
         printf("|                        |");
        toxy(15, 6);
        printf("|    a.学生基本信息录入  |");
        toxy(15, 7);
       printf("|                        |");
        toxy(15, 8);
        printf("|    b.学生基本信息显示  |");
         toxy(15, 9);
        printf("|                        |");

                     toxy(15, 10);

                     printf("|    c.学生基本信息保存  |");

                     toxy(15, 11);

                    printf("|                        |");
        toxy(15, 12);
        printf("|    d.学生基本信息删除  |");

                    toxy(15, 13);
       printf("|                        |");
        toxy(15, 14);
        printf("|    e.学生基本信息修改  |");
         toxy(15, 15);
        printf("|                        |");
        toxy(15, 16);
        printf("|    f.学生基本信息查询  |");
        toxy(15, 17);
        printf("|                        |");
         toxy(15, 18);
         printf("|    g.修  改   密   码  |");

                     toxy(15, 19);
         printf("|                        |");
         toxy(15, 20);
        printf("|    h.退  出   系   统  |");
         toxy(15, 21);
         printf("|                        |");
        toxy(15, 22);
         printf("--------------------------");
        toxy(15, 23);
        printf("请输入选择:");
         x = getch();
         if (x < 'A' || x>'H' && x < 'a' || x>'h')//如果输入的范围不是在A-H或a-h
         {
             toxy(15, 25);
            printf("输入选项有误,请重新输入");
             Sleep(700);
            continue;
        }
         if (x >= 'A' && x <= 'H')
            x = x + 32;//将大写转换为小写

                     switch (x)
         {
        case 'a':
            system("cls");
             system("color F");//字体颜色为亮白色
            toxy(15, 8);
            printf("请输入录入学生人数:");
             scanf("%d", &n);
            input(n);
            break;
       case 'b':
             output();
                  break;
        case 'c':
             save(n);
                  break;
       case 'd':dele();
                 break;
        case 'e':
             change();
                break;
        case 'f':invest(); break;
        case 'g':change_password();

                                998             break;
       case'h':
            over();
            break;

        default:break;
        }
    }
 }

 void save_password(char str[])//保存密码到password文本文件中
 {
     FILE * fp;
    fp = fopen("password", "w");//打开文本文件
   if (fp == NULL)
    {
         printf("cannot open file");
    }
    if (fputs(str, fp) != 0)//使用fputs将密码写入密码文件，成功则返回0，否则返回非0值
    {
       printf("write error!");

                 }

            fclose(fp);
 }

   

         void load()//密码登陆，通过验证读取文件的密码与用户输入的密码是否一致，从而进入系统

         {
     char _password[18];

            int p = 3;//有3次验证密码机会

         do

                 {

                     system("cls");//清屏

                    system("color F");//字体颜色为亮白色

                    int i = 0;

                     char password[18];
         char str[] = "hstc2018";//第一次登陆的初始密码
        char k;
        FILE * fp;
         if ((fp = fopen("password", "a+")) == NULL)
         {
             printf("cannot open file");
             exit(0);
        }
         fseek(fp, 0L, SEEK_END);//把文件指针移到最后
         int size = ftell(fp);//用ftell函数测定文件位置标记的当前位置
         rewind(fp);//使文件位置标记重新返回文件的开头
        if (size == 0)//如果文件的长度为空，则说明是第一次登陆使用
         {
             strcpy(password, str);//将初始密码复制到password数组
             save_password(password);//保存密码到文件中
         }
        else
            fgets(password, 18, fp);//从文件中读取密码
        toxy(15, 6);
        printf("----------学生档案管理系统---------n");
         toxy(15, 8);
       printf("请输入管理者密码:");
       for (;;)//此处为输入密码不回显操作 
        {
            k = getch();//输入k
            if (k == 'r') //如果输入k为回车，则跳出循环 
          {
                break;
            }
            if (k == 'b')//如果输入k为删除键 
             {
               if (i > 0)//如果密码还没完全删除 
                 {
                   printf("b");
                    printf(" ");
                     printf("b");
                     i--;
                }
             }
            else  //如果输入的k既不是删除键，也不是回车键
           {
                _password[i] = k;
                printf("*");
                i++;
            }
        }
        _password[i] = '';//在字符串结尾作结束符标记
         if (strcmp(password, _password) == 0)//判断密码是否输入正确
         {
             system("cls");//清屏
            toxy(15, 10);
             printf("正在登陆……");
             Sleep(500);
6             menu();
         }
         else
         {
            toxy(15, 10);
             p--;
             printf("密码错误!您还有%d次机会", p);
             Sleep(600);

                         }

           
     }while (p > 0);//验证机会不为0
     if (p == 0)
     {
        system("cls");//清屏
        toxy(15, 6);
         printf("机会已用完!");
         toxy(15, 8);
     }
 }
 void change_password()//修改密码，需要输入旧密码和新密码，如果旧密码验证正确则可成功修改
 {
7     system("cls");//清屏
     system("color F");//字体颜色为亮白色
     char str[18];
     FILE * fp;

             if ((fp = fopen("password", "r")) == NULL)//只用读，用r打开stu文件
     {
         printf("cannot open file");
         exit(0);
     }

             fgets(str, 18, fp);//从fp指向的password文件读入字符串，存放到字符数组str中
    fclose(fp);

         do

                 {

                     system("cls");//清屏

                  char password[18], newpassword[18], c, t;

                    int i = 0;
        toxy(15, 6);
        printf("学生管理系统");
        toxy(15, 8);

                    printf("修改密码");

                     toxy(15, 10);

                     printf("请输入旧密码:");
         for (;;)//此处为密码不回显操作

                    {

                             c = getch();

                            if (c == 'r')//如果输入为回车键
             {
                break;
            }
             else if (c == 'b')//如果输入c为删除键

                                {

                                    if (i > 0) //如果密码还没完全删除

                                      {

                                          printf("b");

                                           printf(" ");

                                          printf("b");

                                           i--;

                                      }

                              }

                             else  //如果输入的c既不是删除键，也不是回车键

                              {

                                    password[i] = c;

                                    printf("*");

                                     i++;
          }
         }
        password[i] = '';//在字符串结尾作结束符标记

                     i = 0;

                    toxy(15, 12);

                    printf("请输入新密码:");
        for (;;)//此处为输入密码不回显操作

                         {

                           c = getch();

                            if (c == 'r') //如果输入c为回车，则跳出循环

                               {

                                   break;

                               }

                        else if (c == 'b')//如果输入c为删除键

                                {

                                   if (i > 0)//如果密码还没完全删除

                                      {

                                             printf("b");

                                            printf(" ");

                                         printf("b");

                                            i--;

                                  }

                                }

                           else
            {
                newpassword[i] = c;

                    1                printf("*");

                                  i++;

                              }

                        }

                  newpassword[i] = '';//在字符串结尾作结束符标记

                 if (strcmp(str, password) == 0)//如果旧密码与原来密码验证成功

                   {

                       save_password(newpassword);//保存新密码

                       system("cls");//清屏

                            toxy(15, 6);

                         printf("修改成功,即将返回主菜单……");

                            Sleep(600);

                         menu();

                      }

                  else

                   {

                        system("cls");//清屏

                      toxy(15, 8);

                              printf("-------------------------------------");

                               toxy(15, 9);

                                printf("|                                   |");

                                 toxy(15, 10);

                              printf("|        密码错误！是否继续?        |");

                           toxy(15, 11);

                                 printf("|                                   |");

                             toxy(15, 12);

                                 printf("| 1.是                      2.否    |");

                             toxy(15, 13);

                          printf("|                                   |");

                             toxy(15, 14);

                             printf("-------------------------------------");

                           while (1)

                                   {

                                   t = getch();

                                    if (t == '1')

                                          {

                                              system("cls");//清屏
                       break;

                                           }

                                    else if (t == '2')

                                         {

                                          menu();
                    }
               }

                      }

              }while (1);

            

               }

     int main()

         {

             load();

            return 0;

         }




/*
#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct Student
{
	char xuehao[100];
	char name[100];
	char sex[100];
	int age;
	float score;

};
int n;
void menu()
{
	printf("*************************************************\n");
	printf("*************    1.创建数据         *************\n");
	printf("*************    2.添加数据         *************\n");
	printf("*************    3.删除数据         *************\n");
	printf("*************    4.查找数据         *************\n");
	printf("*************    5.按成绩进行排序   *************\n");
	printf("*************    6.退出             *************\n");
	printf("*************************************************\n");
	printf("请选择:>");
	scanf("%d", n);
}
void scanfstudent(struct Student* p, int len)//输入学生的信息 学号 姓名 性别 年龄 得分
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d学生的信息:\n", i + 1);
		printf("学号:");
		scanf("%s", p[i].xuehao);
		printf("姓名:");
		scanf("%s", p[i].name);
		printf("性别:");
		scanf("%s", p[i].sex);
		printf("年龄:");
		scanf("%d", &p[i].age);
		printf("得分:");
		scanf("%f", &p[i].score);
		printf("\n");
	}

}

void printfstudent(struct Student* p, int len)//对学生的信息进行输出
{
	int i;
	printf("学号\t\t姓名\t\t性别\t\t年龄\t\t分数\n\n");

	for (i = 0; i < len; i++)
	{
		printf("%s\t\t", p[i].xuehao);
		printf("%s\t\t", p[i].name);
		printf("%s\t\t", p[i].sex);
		printf("%d\t\t", p[i].age);
		printf("%.2f\n", p[i].score);

	}
}
void createdata(struct Student* p, int* len)
{
	int n;

	printf("请输入要创建数组的长度：");
	scanf("%d", &n);
	scanfstudent(p, n);
	*len = n;
	printfstudent(p, *len);

}
void add(struct Student* p, int* len)//增加一个学生的信息。并且按照顺序排列
{
	// int i,j;

	//int pos = 0;
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		struct Student st;
		printf("请输入要添加学生的信息:\n");
		printf("学号:");
		scanf("%s", st.xuehao);
		printf("姓名:");
		scanf("%s", st.name);
		printf("性别:");
		scanf("%s", st.sex);
		printf("年龄:");
		scanf("%d", &st.age);
		printf("得分:");
		scanf("%f", &st.score);
		printf("\n");

		p[mylen] = st;
		*len = mylen + 1;
		printfstudent(p, *len);
		printf("\n");
		printf("是否继续添加？输入:\n1.继续\n2.退出\n");
		scanf("%d", &c);
	}
}
void Sort(struct Student* p, int len)//按照分数从大到小排列选择排序法
{
	struct Student st;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
			if (p[i].score < p[j].score)
			{
				st = p[i];
				p[i] = p[j];
				p[j] = st;

			}
	}
	printfstudent(p, len);
}

void del(struct Student* p, int* len)//删除学生的信息
{
	int i, j;
	char p1[1024];
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		printf("请输入要删除学生的学号:");
		scanf("%s", p1);
		for (i = 0; i < *len; i++)
		{
			if (strcmp(p[i].xuehao, p1) == 0)
				break;
		}
		if (i == 0)//删除的是第一个元素
		{
			for (j = 0; j < (*len) - 1; j++)
				p[j] = p[j + 1];
		}
		else if (i > 0 && i < (*len) - 1)//删除中间的元素
		{

			for (j = i; j < (*len) - 1; j++)
				p[j] = p[j + 1];

		}
		else if (i == (*len) - 1)
			;
		else
			printf("error,学号输入有误!\n");
		*len = mylen - 1;//数组长度减少一个
		printfstudent(p, *len);
		printf("\n");
		printf("是否继续删除？输入:\n1.继续\n2.退出\n");
		scanf("%d", &c);
	}
}

void serch(struct Student* p, int len)//按学号或者姓名查找学生信息
{

	int i, j;
	int flat = 0;
	char num[100];
	char name1[100];
	printf("请输入1或2,1按学号查找,2按姓名查找:");
	scanf("%d", &i);

	if (i == 1)
	{
		printf("请输入要查找的学号:");
		scanf("%s", num);
		for (j = 0; j < len; j++)
		{
			if (strcmp(p[j].xuehao, num) == 0)

			{
				flat++;

				break;
			}

		}
		if (!flat)
		{
			printf("学号输入有误!\n");
		}
		else
		{
			printf("学号:%s,姓名:%s,性别:%s,年龄:%d,得分:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
		}
	}
	else if (i == 2)
	{
		flat = 0;
		printf("请输入要查找的姓名:");
		scanf("%s", name1);
		for (j = 0; j < len; j++)
		{
			if (strcmp(p[j].name, name1) == 0)
			{
				flat++;
				printf("学号:%s,姓名:%s,性别:%s,年龄:%d,得分:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
				break;
			}

		}
		if (!flat)
		{
			printf("姓名输入有误!\n");
		}
	}
}

int main(void)
{
	int n;
	struct Student p[1024];
	int len = 0;
	while (1)
	{
		menu(&n);
		switch (n)
		{
		case 1:createdata(p, &len); break;
		case 2:add(p, &len); break;
		case 3:del(p, &len); break;
		case 4:serch(p, len); break;
		case 5:Sort(p, len); break;
		case 6:printf("谢谢您的使用!\n\n"); break;
		default:printf("输入有误重新输入!\n\n"); break;
		}
		if (n == 6)
			break;
	}
	return 0;
}
*/
/*
#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct Student
{
	char xuehao[100];
	char name[100];
	char sex[100];
	int age;
	float score;

}; 
int n;
void menu()
{
	printf("*************************************************\n");
	printf("*************    1.创建数据         *************\n");
	printf("*************    2.添加数据         *************\n");
	printf("*************    3.删除数据         *************\n");
	printf("*************    4.查找数据         *************\n");
	printf("*************    5.按成绩进行排序   *************\n");
	printf("*************    6.退出             *************\n");
	printf("*************************************************\n");
	printf("请输入数字1-6:");
	scanf("%d", n);
}
void scanfstudent(struct Student* p, int len)//输入学生的信息 学号 姓名 性别 年龄 得分
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d学生的信息:\n", i + 1);
		printf("学号:");
		scanf("%s", p[i].xuehao);
		printf("姓名:");
		scanf("%s", p[i].name);
		printf("性别:");
		scanf("%s", p[i].sex);
		printf("年龄:");
		scanf("%d", &p[i].age);
		printf("得分:");
		scanf("%f", &p[i].score);
		printf("\n");
	}

}

void printfstudent(struct Student* p, int len)//对学生的信息进行输出
{
	int i;
	printf("学号\t\t姓名\t\t性别\t\t年龄\t\t分数\n\n");

	for (i = 0; i < len; i++)
	{
		printf("%s\t\t", p[i].xuehao);
		printf("%s\t\t", p[i].name);
		printf("%s\t\t", p[i].sex);
		printf("%d\t\t", p[i].age);
		printf("%.2f\n", p[i].score);

	}
}
void createdata(struct Student* p, int* len)
{
	int n;
	printf("请输入要创建数组的长度：");
	scanf("%d", &n);
	scanfstudent(p, n);
	*len = n;
	printfstudent(p, *len);

}
void add(struct Student* p, int* len)//增加一个学生的信息。并且按照顺序排列
{
	// int i,j;

	//int pos = 0;
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		struct Student st;
		printf("请输入要添加学生的信息:\n");
		printf("学号:");
		scanf("%s", st.xuehao);
		printf("姓名:");
		scanf("%s", st.name);
		printf("性别:");
		scanf("%s", st.sex);
		printf("年龄:");
		scanf("%d", &st.age);
		printf("得分:");
		scanf("%f", &st.score);
		printf("\n");

		p[mylen] = st;
		*len = mylen + 1;
		printfstudent(p, *len);
		printf("\n");
		printf("是否继续添加？输入:\n1.继续\n2.退出\n");
		scanf("%d", &c);
	}
}
void Sort(struct Student* p, int len)//按照分数从大到小排列选择排序法
{
	struct Student st;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
			if (p[i].score < p[j].score)
			{
				st = p[i];
				p[i] = p[j];
				p[j] = st;

			}
	}
	printfstudent(p, len);
}

/*if(myp->score >= p[0].score)//
{

for(i = mylen; i > 0 ; i--)
p[i] = p[i-1];
p[0] = *myp;

}
else if(myp->score <= p[mylen-1].score)
{
p[mylen] = *myp;
}
*/
//else
//{
/*for(i = 0; i < mylen; i++)
{
if(myp->score >= p[i].score)
break;
}
pos = i;
for(j = mylen; j > pos; j--)
{
p[j] = p[j-1];
}
p[pos] = *myp;

*len = mylen+1;

}*/
/*
void del(struct Student* p, int* len)//删除学生的信息
{
	int i, j;
	char p1[1024];
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		printf("请输入要删除学生的学号:");
		scanf("%s", p1);
		for (i = 0; i < *len; i++)
		{
			if (strcmp(p[i].xuehao, p1) == 0)
				break;
		}
		if (i == 0)//删除的是第一个元素
		{
			for (j = 0; j < (*len) - 1; j++)
				p[j] = p[j + 1];
		}
		else if (i > 0 && i < (*len) - 1)//删除中间的元素
		{

			for (j = i; j < (*len) - 1; j++)
				p[j] = p[j + 1];

		}
		else if (i == (*len) - 1)
			;
		else
			printf("error,学号输入有误!\n");
		*len = mylen - 1;//数组长度减少一个
		printfstudent(p, *len);
		printf("\n");
		printf("是否继续删除？输入:\n1.继续\n2.退出\n");
		scanf("%d", &c);
	}
}

void serch(struct Student* p, int len)//按学号或者姓名查找学生信息
{

	int i, j;
	int flat = 0;
	char num[100];
	char name1[100];
	printf("请输入1或2,1按学号查找,2按姓名查找:");
	scanf("%d", &i);

	if (i == 1)
	{
		printf("请输入要查找的学号:");
		scanf("%s", num);
		for (j = 0; j < len; j++)
		{
			if (strcmp(p[j].xuehao, num) == 0)

			{
				flat++;

				break;
			}

		}
		if (!flat)
		{
			printf("学号输入有误!\n");
		}
		else
		{
			printf("学号:%s,姓名:%s,性别:%s,年龄:%d,得分:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
		}
	}
	else if (i == 2)
	{
		flat = 0;
		printf("请输入要查找的姓名:");
		scanf("%s", name1);
		for (j = 0; j < len; j++)
		{
			if (strcmp(p[j].name, name1) == 0)
			{
				flat++;
				printf("学号:%s,姓名:%s,性别:%s,年龄:%d,得分:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
				break;
			}

		}
		if (!flat)
		{
			printf("姓名输入有误!\n");
		}
	}
}*/
/*int main(void)
{

int len;
int c;
// char c;
// char xuehao11[1024];
// struct Student *p;
//静态构造结构数组
struct Student p[1024];

printf("请输入学生的个数：");
scanf("%d",&len);

// p = (struct Student*)malloc(sizeof(struct Student)*len);动态构造一个结构数组

scanfstudent(p,len);
Sort(p,len);
printfstudent(p,len);
do
{
struct Student st;

printf("\n请输入增加的学生的信息：\n");
printf("学号:");
scanf("%s",st.xuehao);
printf("姓名:");
scanf("%s",st.name);
printf("性别:");
scanf("%s",st.sex);
printf("年龄:");
scanf("%d",&st.age);
printf("得分:");
scanf("%f",&st.score);

// serch(p,len);

printf("\n");
//printf("请输入要删除的学生的学号:");
printf("\n");
//scanf("%s",xuehao11);
add(p,&st,&len);
// del(p,xuehao11,&len);删除一个学生的信息
printfstudent(p,len);
printf("是否继续添加？\n1:是\n2不添加\n");
scanf("%d",&c);

}
while(c==1);

}*/
/*
int main(void)
{
	int n;
	struct Student p[1024];
	int len = 0;
	while (1)
	{
		menu(&n);
		switch (n)
		{
		case 1:createdata(p, &len); break;
		case 2:add(p, &len); break;
		case 3:del(p, &len); break;
		case 4:serch(p, len); break;
		case 5:Sort(p, len); break;
		case 6:printf("谢谢您的使用!\n\n"); break;
		default:printf("输入有误重新输入!\n\n"); break;
		}
		if (n == 6)
			break;
	}
	return 0;
}
*/



















/*
#include<stdio.h>   //标准输入输出函数库
#include<string.h>   //字符串函数库
#include<stdlib.h>
struct clothing
{
	int num;   //服装编号
	char Name[10];   //商品名称
	int price;   //价格
	char type;   //型号
}clothing[100];   //定义一个结构体
int main()   //函数主体
{
	void welcomemenu()  //主菜单
	{
		{
			printf("请选择您需要的步骤<1-6>:\n");
			scanf("%d", &n);
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
			while (flag == 1)
			{
				switch (n)
				{
					case 1:
						inputmessage();
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
	}
	void save(int m);   //保存文件函数
	void inputmessage();  //录入服装信息
	void inquiremessage();   //查询服装信息
	void addmessage();   //添加服装
	void delmessage();   //删除服装
	void modifymessage();   //修改服装信息
	void exit();   //退出
	int n, flag;
	char a;


	getchar();
	printf("是否继续进行操作?回复y or n:\n");
	a = getchar();
	if (a == 'y')
	{
		flag = 1;
		system("cls");   //清屏
		welcomemenu();   //调用主菜单函数
		printf("请再次选择您的操作<1-6>:\n");
		scanf("%d", &n);
	}
	else
		exit(0);
}*/