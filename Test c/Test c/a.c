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

    15     char id[20];//ѧ��

    16     char name[20];//����

    17     char sex[2];//�Ա�

    18     int age;//����

    19     Birthday birthday;//��������

    20     char desc[20];//��ע

    21 }File[N];

    22

        23 void toxy(int x, int y)      //������ƶ���X,Y���괦

        24 {

        25 COORD pos = { x , y };

        26 HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);

        27 SetConsoleCursorPosition(Out, pos);

        28 }

    29

        30

        31

        32 void load();//ϵͳ��½ҳ��

    33 void save_password(char str[]);//��������

    34 void menu();//ϵͳ���˵�

    35 void input(int n);//ѧ����Ϣ¼��

    36 void output();//ѧ����Ϣ��ʾ

    37 void save(int n);//ѧ����Ϣ����

    38 void dele();//ѧ����Ϣɾ��

    39 void change();//ѧ����Ϣ�޸�

    40 void invest();//ѧ����Ϣ��ѯ

    41 void change_password();//�޸�����

    42 void over();//�˳�ϵͳ

    43

        44 void input(int n)//��Ϣ¼�룬¼��ѧ���Ļ�����Ϣ

        45 {

        46     int i;

        47     for (i = 0; i < n; i++)

            48     {

            49         system("cls");//����

            50         toxy(15, 6);

            51         printf("������ѧ��ѧ��:");

            52         scanf("%s", File[i].id);

            53         toxy(15, 7);

            54         printf("������ѧ������:");

            55         scanf("%s", File[i].name);

            56         toxy(15, 8);

            57         printf("������ѧ���Ա�(��/Ů):");

            58         scanf("%s", File[i].sex);

            59         toxy(15, 9);

            60         printf("������ѧ������:");

            61         scanf("%d", &File[i].age);

            62         toxy(15, 10);

            63         printf("������ѧ���ĳ�������(�����գ��Կո����):");

            64         scanf("%d%d%d", &File[i].birthday.year, &File[i].birthday.month, &File[i].birthday.day);

            65         toxy(15, 11);

            66         printf("�����뱸ע:");

            67       scanf("%s", File[i].desc);

            68     }

        69     system("cls");//����

        70     toxy(15, 6);

        71     printf("¼����ϣ���ǵ÷��ر���(*^��^*)");

        72     toxy(15, 8);

        73     printf("��������ɷ������˵���");

        74     getch();

        75

            76 }

    77

        78 void output()//��Ϣ��ʾ����ѧ���Ļ�����Ϣ��ʾ����Ļ��

        79 {

        80     system("cls");//����

        81     system("color F");//������ɫΪ����ɫ

        82     int i;

        83     FILE * fp;

        84     toxy(15, 6);

        85     printf("***********ѧ��������Ϣ*************n");

        86     toxy(15, 8);

        87     printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

        88     toxy(15, 10);

        89     if ((fp = fopen("stu", "r")) == NULL)//ֻ�ö�����r��stu�ļ�

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

                102         fread(&File[i], sizeof(struct file), 1, fp);//���ļ��ж�ȡ���ݵ�File��

                103         if (feof(fp))//�ж��ļ��Ƿ���������

                    104             break;

                105         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7sn", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                106         toxy(15, 11 + i);

                107       }

            108     memset(File, NULL, sizeof(File));//����File

            109     }

        110     printf("��ʾ��ϣ��밴������������˵�");

        111     getch();

        112

            113 }

    114

        115 void save(int n) //��Ϣ���棬��¼���ѧ����Ϣ���浽�ļ���

        116 {

        117     system("cls");//����

        118     system("color F");//������ɫΪ����ɫ

        119     FILE * fp;

        120     fp = fopen("stu", "a+");//��׷�ӵķ�ʽ���ļ�������ʱָ��ͣ���ļ�β

        121     int i;

        122     for (i = 0; i < n; i++)

            123     {

            124         if (File[i].age == NULL) continue;//����հ�����

            125          fwrite(&File[i], sizeof(struct file), 1, fp);//��ָ�����ļ���д������

            126     }

        127     fclose(fp);

        128     n = NULL;//����

        129     memset(File, NULL, sizeof(File));//���ýṹ������File

        130     toxy(15, 8);

        131     printf("��������ɹ�!�����������˵�����");

        132     Sleep(800);

        133

            134 }

    135

        136 void dele()//��Ϣɾ�����Ѳ�Ҫ��ѧ��������Ϣɾ��

        137 {

        138

            139    system("cls");//����

        140    system("color F");//������ɫΪ����ɫ

        141    int i, flag = 0;//flag�Ƿ��ҵ�ɾ��ѧ���ı�־

        142    char number[20];

        143    char name[20];

        144    char c;

        145  do

            146  {

            147      toxy(15, 6);

            148      printf("������Ҫɾ��ѧ����ѧ�ź�����:");

            149      toxy(15, 8);

            150   scanf("%s%s", number, name);

            151   FILE * fp1, * fp2;

            152   fp1 = fopen("stu", "r+");//Ϊ�˶���д����r+��stu�ı��ļ�

            153   fp2 = fopen("linshi", "w+");//��w+��һ����ʱ���ı��ļ�

            154   if (fp1 == NULL || fp2 == NULL)

                155   {

                156       toxy(15, 10);

                157       printf("cannot open file!");

                158       toxy(15, 12);

                159       exit(0);

                160   }

            161   for (i = 0; i < N; i++)

                162   {

                163       while (fread(&File[i], sizeof(struct file), 1, fp1))//���ļ��ж�ȡ���ݵ�File

                    164       {

                    165           if (feof(fp1))// �ж��ļ��Ƿ���������

                        166               break;

                    167           if (strcmp(number, File[i].id) == 0 && strcmp(name, File[i].name) == 0)//�ж�Ҫɾ����ѧ�ź������Ƿ����ļ���������ͬ������ͬ���������ѭ��

                        168           {

                        169               flag = 1;

                        170               continue;

                        171           }

                    172           else

                        173           {

                        174               fwrite(&File[i], sizeof(struct file), 1, fp2);//��File����Ϣд���ļ�

                        175           }

                    176       }

                177   }

            178   fclose(fp1);

            179   fclose(fp2);

            180   if (system("copy linshi stu") == 0)//��linshi�ļ������ݸ��Ƹ��ǵ�stu�ļ������ɹ��򷵻�0

                181   {

                182       system("cls");//����

                183       system("DEL linshi");//ɾ��linshi�ļ�

                184       system("cls");//����

                185   }

            186   if (flag == 1)//�ҵ�ɾ��ѧ��            

                187   {

                188

                    189       toxy(15, 10);

                190       printf("�ɹ�ɾ����ѧ����ϵͳ���Զ��������²����浵��n");

                191       Sleep(800);

                192       menu();

                193

                    194   }

            195   if (flag == 0)//�޷��ҵ���ɾ��ѧ��

                196   {

                197       toxy(15, 10);

                198       printf("ɾ��ʧ��!ѧ�Ż������������");

                199       toxy(15, 11);

                200       printf("��1�������˵�����2��������n");

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

    216 void change()//�޸���Ϣ���޸Ĵ����ѧ����Ϣ

        217 {

        218     int sign = 0;//������־������֤�ɹ����

        219     int j = 3;//ÿ�ν���˹��ܣ��û���3����֤�������

        220     do

            221     {

            222     system("cls");//����

            223     system("color F");//������ɫΪ����ɫ

            224     char str[18];

            225     FILE * fp;

            226     if ((fp = fopen("password", "r")) == NULL)

                227     {

                228         printf("cannot open filen");

                229         exit(0);

                230     }

            231     fgets(str, 18, fp);//���ļ��ж�ȡ�������ݱ��浽str������

            232     fclose(fp);

            233     toxy(15, 6);

            234     printf("����ù��ܣ����ٴ���֤��½����:n");

            235     toxy(15, 8);

            236         char c;

            237         char password[18];

            238         int i = 0;

            239         for (;;)//�˴�Ϊ�������벻���Բ���

                240         {

                241             c = getch();//����c

                242             if (c == 'r')//�������cΪ�س���������ѭ��

                    243             {

                    244                 break;

                    245             }

                246             if (c == 'b') //�������cΪɾ����

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

            259         password[i] = '';//���ַ�����β�����������

            260         if (strcmp(str, password) == 0)//��֤�����Ƿ���ȷ

                261         {

                262           system("cls");//����

                263           toxy(15, 10);

                264           printf("��֤�ɹ������������޸Ĺ���!");

                265           Sleep(600);

                266           sign = 1;

                267           break;

                268         }

            269         else

                270         {

                271             toxy(15, 10);

                272             j--;

                273             printf("�������!������%d����֤����", j);

                274             Sleep(600);

                275         }

            276     }while (j > 0);//��֤���᲻Ϊ0

            277     if (j == 0)

                278     {

                279         system("cls");

                280         toxy(15, 6);

                281         printf("��֤���������꣬�����������˵�����");

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

                    296         printf("--------------1.�޸�ѧ��-------------");

                    297         toxy(15, 7);

                    298         printf("--------------2.�޸�����-------------");

                    299         toxy(15, 8);

                    300         printf("--------------3.�޸��Ա�-------------");

                    301         toxy(15, 9);

                    302         printf("--------------4.�޸�����-------------");

                    303         toxy(15, 10);

                    304         printf("--------------5.�޸ĳ�������---------");

                    305         toxy(15, 11);

                    306         printf("--------------6.�޸ı�ע ------------");

                    307         toxy(15, 12);

                    308         printf("--------------7. �˳� ---------------");

                    309         toxy(15, 13);

                    310         printf("������1~6����ѡ��:");

                    311         toxy(15, 14);

                    312         scanf("%d", &select);

                    313         FILE * fp1;

                    314         toxy(15, 15);

                    315      if ((fp1 = fopen("stu", "r+")) == NULL)//Ϊ�˶���д����r+��stu�ļ�

                        316      {

                        317          system("cls");//����

                        318          toxy(15, 6);

                        319         printf("cannot open file!");

                        320         toxy(15, 8);

                        321         exit(0);

                        322      }

                    323      for (i = 0; i < N; i++)

                        324     {

                        325         fread(&File[i], sizeof(struct file), 1, fp1);//���ļ��ж�ȡ���ݵ�File

                        326          if (feof(fp1))//�ж��ļ��Ƿ���������

                            327             break;

                        328         count++;//ÿ�γɹ���stu�ļ��ж�ȡ��Ϣ����ѧ�����ݸ�����1

                        329     }

                    330      int flag = 0;

                    331         switch (select)

                        332         {

                    333         case 1://�޸�ѧ��

                        334                 system("cls");//����

                        335                 toxy(15, 5);

                        336                 printf("������Ҫ�޸�ѧ����ѧ��:");

                        337                 toxy(15, 6);

                        338                 scanf("%s", number);

                        339                 for (i = 0; i < count; i++)

                            340                 {

                            341                     if ((strcmp(number, File[i].id)) == 0)

                                342                     {

                                343                         toxy(15, 7);

                                344                         printf("*********************ѧ��������Ϣ*********************");

                                345                         toxy(15, 8);

                                346                         printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

                                347                         toxy(15, 9);

                                348                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                349                         toxy(15, 10);

                                350                         printf("���������ѧ����ѧ�Ž����޸�:");

                                351                         toxy(15, 11);

                                352                         scanf("%s", File[i].id);

                                353                         flag = 1;

                                354                         break;

                                355                     }

                            356                 }

                        357                 fclose(fp1);

                        358                 if (flag == 1)

                            359                 {

                            360                     system("cls");//����

                            361                     toxy(15, 12);

                            362                     printf("�޸ĳɹ���ϵͳ���Զ����棡");

                            363                     toxy(15, 13);

                            364                     printf("�����Զ���ת�����˵�....");

                            365                     FILE * fp2;

                            366                     if ((fp2 = fopen("stu", "w+")) == NULL)//��w+��stu�ļ�ͬʱ����ļ�����

                                367                     {

                                368                         printf("cannot open file!");

                                369                         exit(0);

                                370                     }

                            371                     for (i = 0; i < count; i++)

                                372                         fwrite(&File[i], sizeof(file), 1, fp2);//��File����Ϣд��stu�ļ�

                            373                     fclose(fp2);

                            374                     Sleep(600);

                            375                     menu();

                            376

                                377                 }

                        378                 if (flag == 0)

                            379                 {

                            380                     toxy(15, 12);

                            381                     printf("��ѧ��������!");

                            382                     toxy(15, 13);

                            383                     char c;

                            384                     printf("1.������һ��  2.�������˵�");

                            385                     toxy(15, 14);

                            386                     c = getch();

                            387                     if (c == '1') break;

                            388                     if (c == '2') menu();

                            389                 }

                        390

                    391         case 2://�޸�����

                        392             system("cls");//����

                        393             toxy(15, 5);

                        394                 printf("������Ҫ�޸�ѧ����ѧ��:");

                        395                 toxy(15, 6);

                        396                 scanf("%s", number);

                        397                 for (i = 0; i < count; i++)

                            398                 {

                            399                     if ((strcmp(number, File[i].id)) == 0)

                                400                     {

                                401                         toxy(15, 7);

                                402                         printf("*********************ѧ��������Ϣ*********************");

                                403                         toxy(15, 8);

                                404                         printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

                                405                         toxy(15, 9);

                                406                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                407                         toxy(15, 10);

                                408                         printf("���������ѧ�������������޸�:");

                                409                         toxy(15, 11);

                                410                         scanf("%s", File[i].name);

                                411                         flag = 1;

                                412                         break;

                                413                     }

                            414                 }

                        415                 if (flag == 1)

                            416                 {

                            417                     system("cls");//����

                            418                     toxy(15, 12);

                            419                     printf("�޸ĳɹ���ϵͳ���Զ����棡");

                            420                     toxy(15, 13);

                            421                     printf("�����Զ���ת�����˵�....");

                            422                     FILE * fp2;

                            423                     if ((fp2 = fopen("stu", "w+")) == NULL)//��w+��stu�ļ�ͬʱ����ļ�����

                                424                     {

                                425                         printf("cannot open file!");

                                426                         exit(0);

                                427                     }

                            428                     for (i = 0; i < count; i++)

                                429                         fwrite(&File[i], sizeof(file), 1, fp2);//��File����Ϣд��stu�ļ�

                            430                     fclose(fp2);

                            431                     Sleep(600);

                            432                     menu();

                            433

                                434                 }

                        435                 if (flag == 0)

                            436                 {

                            437                     toxy(15, 12);

                            438                     printf("��ѧ��������!");

                            439                     toxy(15, 13);

                            440                     char c;

                            441                     printf("1.������һ��  2.�������˵�");

                            442                     toxy(15, 14);

                            443                     c = getch();

                            444                     if (c == '1') break;

                            445                     if (c == '2') menu();

                            446                 }

                        447

                    448         case 3://�޸��Ա�

                        449             system("cls");//����

                        450             toxy(15, 5);

                        451                 printf("������Ҫ�޸�ѧ����ѧ��:");

                        452                 toxy(15, 6);

                        453                 scanf("%s", number);

                        454                 for (i = 0; i < count; i++)

                            455                 {

                            456                     if ((strcmp(number, File[i].id)) == 0)

                                457                     {

                                458                         toxy(15, 7);

                                459                         printf("*********************ѧ��������Ϣ*********************");

                                460                         toxy(15, 8);

                                461                         printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

                                462                         toxy(15, 9);

                                463                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                464                         toxy(15, 10);

                                465                         printf("���������ѧ�����Ա�����޸�:");

                                466                         toxy(15, 11);

                                467                         scanf("%s", File[i].sex);

                                468                         flag = 1;

                                469                         break;

                                470                     }

                            471                 }

                        472                 if (flag == 1)

                            473                 {

                            474                     system("cls");//����

                            475                     toxy(15, 12);

                            476                     printf("�޸ĳɹ���ϵͳ���Զ����棡");

                            477                     toxy(15, 13);

                            478                     printf("�����Զ���ת�����˵�....");

                            479                     FILE * fp2;

                            480                     if ((fp2 = fopen("stu", "w+")) == NULL)//��w+��stu�ļ�ͬʱ����ļ�����

                                481                     {

                                482                         printf("cannot open file!");

                                483                         exit(0);

                                484                     }

                            485                     for (i = 0; i < count; i++)

                                486                         fwrite(&File[i], sizeof(file), 1, fp2);//��File����Ϣд��stu�ļ�

                            487                     fclose(fp2);

                            488                     Sleep(600);

                            489                     menu();

                            490

                                491                 }

                        492                 if (flag == 0)

                            493                 {

                            494                     toxy(15, 12);

                            495                     printf("��ѧ��������!");

                            496                     toxy(15, 13);

                            497                     char c;

                            498                     printf("1.������һ��  2.�������˵�");

                            499                     toxy(15, 14);

                            500                     c = getch();

                            501                     if (c == '1') break;

                            502                     if (c == '2') menu();

                            503                 }

                    504         case 4://�޸�����

                        505             system("cls");//����

                        506             toxy(15, 5);

                        507                 printf("������Ҫ�޸�ѧ����ѧ��:");

                        508                 toxy(15, 6);

                        509                 scanf("%s", number);

                        510                 for (i = 0; i < count; i++)

                            511                 {

                            512                     if ((strcmp(number, File[i].id)) == 0)

                                513                     {

                                514                         toxy(15, 7);

                                515                         printf("*********************ѧ��������Ϣ*********************");

                                516                         toxy(15, 8);

                                517                         printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

                                518                         toxy(15, 9);

                                519                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                520                         toxy(15, 10);

                                521                         printf("���������ѧ������������޸�:");

                                522                         toxy(15, 11);

                                523                         scanf("%d", &File[i].age);

                                524                         flag = 1;

                                525                     }

                            526                 }

                        527                 if (flag == 1)

                            528                 {

                            529                     system("cls");//����

                            530                     toxy(15, 12);

                            531                     printf("�޸ĳɹ���ϵͳ���Զ����棡");

                            532                     toxy(15, 13);

                            533                     printf("�����Զ���ת�����˵�....");

                            534                     FILE * fp2;

                            535                     if ((fp2 = fopen("stu", "w+")) == NULL)//��w+��stu�ļ�ͬʱ����ļ�����

                                536                     {

                                537                         printf("cannot open file!");

                                538                         exit(0);

                                539                     }

                            540                     for (i = 0; i < count; i++)

                                541                         fwrite(&File[i], sizeof(file), 1, fp2);//��File����Ϣд��stu�ļ�

                            542                     fclose(fp2);

                            543                     Sleep(600);

                            544                     menu();

                            545

                                546                 }

                        547                 if (flag == 0)

                            548                 {

                            549                     toxy(15, 12);

                            550                     printf("��ѧ��������!");

                            551                     toxy(15, 13);

                            552                     char c;

                            553                     printf("1.������һ��  2.�������˵�");

                            554                     toxy(15, 14);

                            555                     c = getch();

                            556                     if (c == '1') break;

                            557                     if (c == '2') menu();

                            558                 }

                        559

                    560         case 5://�޸ĳ�������

                        561             system("cls");//����

                        562             toxy(15, 5);

                        563             printf("������Ҫ�޸�ѧ����ѧ��:");

                        564             toxy(15, 6);

                        565                 scanf("%s", number);

                        566                 for (i = 0; i < count; i++)

                            567                 {

                            568                     if ((strcmp(number, File[i].id)) == 0)

                                569                     {

                                570                         toxy(15, 7);

                                571                         printf("*********************ѧ��������Ϣ*********************");

                                572                         toxy(15, 8);

                                573                         printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

                                574                         toxy(15, 9);

                                575                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                576                         toxy(15, 10);

                                577                         printf("���������ѧ���ĳ�������(�� �� ��)�����޸�:");

                                578                         toxy(15, 11);

                                579                         scanf("%d%d%d", &File[i].birthday.year, &File[i].birthday.month, &File[i].birthday.day);

                                580                         flag = 1;

                                581                     }

                            582                 }

                        583                 if (flag == 1)

                            584                 {

                            585                     system("cls");//����

                            586                     toxy(15, 12);

                            587                     printf("�޸ĳɹ���ϵͳ���Զ����棡");

                            588                     toxy(15, 13);

                            589                     printf("�����Զ���ת�����˵�....");

                            590                     FILE * fp2;

                            591                     if ((fp2 = fopen("stu", "w+")) == NULL)//��w+��stu�ļ�ͬʱ����ļ�����

                                592                     {

                                593                         printf("cannot open file!");

                                594                         exit(0);

                                595                     }

                            596                     for (i = 0; i < count; i++)

                                597                         fwrite(&File[i], sizeof(file), 1, fp2);//��File����Ϣд��stu�ļ�

                            598                     fclose(fp2);

                            599                     Sleep(600);

                            600                     menu();

                            601

                                602                 }

                        603                 if (flag == 0)

                            604                 {

                            605                     toxy(15, 12);

                            606                     printf("��ѧ��������!");

                            607                     toxy(15, 13);

                            608                     char c;

                            609                     printf("1.������һ��  2.�������˵�");

                            610                     toxy(15, 14);

                            611                     c = getch();

                            612                     if (c == '1') break;

                            613                     if (c == '2') menu();

                            614                 }

                        615

                    616         case 6://�޸ı�ע

                        617         system("cls");//����

                        618             toxy(15, 5);

                        619                 printf("������Ҫ�޸�ѧ����ѧ��:");

                        620                 toxy(15, 6);

                        621                 scanf("%s", number);

                        622                 for (i = 0; i < count; i++)

                            623                 {

                            624                     if ((strcmp(number, File[i].id)) == 0)

                                625                     {

                                626                         toxy(15, 7);

                                627                         printf("*********************ѧ��������Ϣ*********************");

                                628                         toxy(15, 8);

                                629                         printf(" ѧ��       ����     �Ա�     ����    ��������    ��ע");

                                630                         toxy(15, 9);

                                631                         printf("%-10s  %-10s%-s %7d    %d-%d-%d  %7s", File[i].id, File[i].name, File[i].sex, File[i].age, File[i].birthday.year, File[i].birthday.month, File[i].birthday.day, File[i].desc);

                                632                         toxy(15, 10);

                                633                         printf("���������ѧ���ı�ע�����޸�:");

                                634                         toxy(15, 11);

                                635                         scanf("%s", &File[i].desc);

                                636                         flag = 1;

                                637                     }

                            638                 }

                        639                 if (flag == 1)

                            640                 {

                            641                     system("cls");//����

                            642                     toxy(15, 12);

                            643                     printf("�޸ĳɹ���ϵͳ���Զ����棡");

                            644                     toxy(15, 13);

                            645                     printf("�����Զ���ת�����˵�....");

                            646                     FILE * fp2;

                            647                     if ((fp2 = fopen("stu", "w+")) == NULL)//��w+��stu�ļ�ͬʱ����ļ�����

                                648                     {

                                649                         printf("cannot open file!");

                                650                         exit(0);

                                651                     }

                            652                     for (i = 0; i < count; i++)

                                653                         fwrite(&File[i], sizeof(file), 1, fp2);//��File����Ϣд��stu�ļ�

                            654                     fclose(fp2);

                            655                     Sleep(600);

                            656                     menu();

                            657

                                658                 }

                        659                 if (flag == 0)

                            660                 {

                            661                     toxy(15, 12);

                            662                     printf("��ѧ��������!");

                            663                     toxy(15, 13);

                            664                     char c;

                            665                     printf("1.������һ��  2.�������˵�");

                            666                     toxy(15, 14);

                            667                     c = getch();

                            668                     if (c == '1') break;

                            669                     if (c == '2') menu();

                            670                 }

                        671

                    672         case 7:system("cls");//����

                    673         default:break;

                                       674         }

                    675         }

                676

                    677     }

            678 }

    679 void invest()//��ѯ��Ϣ���ɰ�ѧ�š��������Ա����䡢�������ڲ�ѯѧ���Ļ�����Ϣ

        680 {

        681     system("cls");//����

        682     system("color F");//������ɫΪ����ɫ

        683     int i, x, flag, year, month, day, age;

        684     char number[20];

        685     char name[20];

        686     char sex[5];

        687     while (x != 6)

            688     {

            689     system("cls");

            690     toxy(15, 6);

            691     printf("��ѡ���ѯ����:n");

            692     toxy(15, 7);

            693     printf("t1.��ѯѧ��n");

            694     toxy(15, 8);

            695     printf("t2.��ѯ����n");

            696     toxy(15, 9);

            697     printf("t3.��ѯ�Ա�n");

            698     toxy(15, 10);

            699     printf("t4.��ѯ��������n");

            700     toxy(15, 11);

            701     printf("t5.��ѯ����n");

            702     toxy(15, 12);

            703     printf("t6.�˳�n");

                 toxy(15, 13);

               printf("������ѡ��:");

                 scanf("%d", &x);

                 FILE * fp;

                if ((fp = fopen("stu", "r")) == NULL)//ֻ�ö�����r��stu�ļ�

                     {

                         system("cls");//����

                         toxy(15, 6);

                        printf("cannot open filen");

                         toxy(15, 8);

                        exit(0);

                    }

                int count = 0;//������¼�ļ���ѧ�����ݵĸ���

               for (i = 0; i < N; i++)

                         {

                        fread(&File[i], sizeof(struct file), 1, fp);//��stu�ļ���Ϣ����File��
        if (feof(fp))//�ж��ļ��Ƿ���������

                             break;
         count++;//ÿ�γɹ���stu�ļ��ж�ȡ��Ϣ����ѧ�����ݸ�����1
         }

                 fclose(fp);

             switch (x)

                    {
    case 1:

                         system("cls");//����

                      toxy(15, 6);

                       printf("������ѧ��:");

                         toxy(15, 8);

                       scanf("%s", number);

                       system("cls");//����

                       flag = 0;

                       toxy(15, 6);

                         printf("ѧ��Ϊ%s��ѧ����Ϣ����:", number);

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

                           printf("�޷��ҵ���Ҫ�ҵ�ѧ��!");

                           }

                         toxy(15, 11 + count);

                       printf("���������ɷ��ء���");

                                getch();

                       break;

                case 2:

                        system("cls");//����

                        toxy(15, 6);

                         printf("����������:");
        toxy(15, 8);
         scanf("%s", name);
          flag = 0;

                         system("cls");//����
          toxy(15, 6);

                          printf("����Ϊ%s��ѧ����Ϣ����:", name);

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

                                 printf("�޷��ҵ���Ҫ�ҵ�ѧ��!");

                             }

                      toxy(15, 11 + count);

                      printf("���������ɷ��ء���");

                         getch();

                         break;

               case 3:

                       system("cls");//����

                         toxy(15, 6);

                       printf("�������Ա�(��/Ů):");

                         toxy(15, 8);

                         scanf("%s", sex);

                        system("cls");//����

                      flag = 0;

                         toxy(15, 6);

                       printf("�Ա�Ϊ%s��ѧ����Ϣ����:", sex);

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

                               printf("�޷��ҵ���Ҫ�ҵ�ѧ��!");

                           }

                       toxy(15, 11 + count);

                       printf("���������ɷ��ء���");

                        getch();

                          break;

                 case 4:

                        system("cls");//����
       toxy(15, 6);
        printf("�������������(�� �� ��):");

                        toxy(15, 8);
       scanf("%d%d%d", &year, &month, &day);

                      system("cls");//����

                        flag = 0;

                         toxy(15, 6);

                       printf("��������Ϊ%d��%d��%d�յ�ѧ����Ϣ����:", year, month, day);

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
             printf("�޷��ҵ���Ҫ�ҵ�ѧ��!");
       }
        toxy(15, 11 + count);
      printf("���������ɷ��ء���");

                      getch();

                       break;

                case 5:

                        system("cls");//����

                        toxy(15, 6);

                        printf("����������:");
        toxy(15, 8);
         scanf("%d", &age);
       system("cls");//����

                       flag = 0;

                       toxy(15, 6);

                      printf("����Ϊ%d��ѧ����Ϣ����:", age);
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
           printf("�޷��ҵ���Ҫ�ҵ�ѧ��!");

                          }

                      toxy(15, 11 + count);

                       printf("���������ɷ��ء���");

                      getch();

                     break;

              case 6:system("cls");//����

                               toxy(15, 8);

                                  printf("�����������˵�����");

                                  Sleep(700);

                                break;
    }
    }

         }

     void over()//�˳����ܣ���ʾ�˳��������ʾ 

      {

           char t;

            system("color F");//������ɫΪ����ɫ

            toxy(15, 11);

            printf("--------------------------");

            toxy(15, 12);

            printf("|    ��ȷ��Ҫ�˳���    |");

            toxy(15, 14);

            printf("|  1.ȷ��      2.ȡ��    |");
     toxy(15, 15);
     printf("--------------------------");

           while (1)

               {

                   t = getch();         //����t

                    switch (t)

                        {

                         case '1':

                             system("cls");//����

                             system("color F");//������ɫΪ����ɫ

                             toxy(15, 10);
            printf("���ڰ�ȫ�˳�....");
            Sleep(1000);     //��ͣ1�� 
             system("cls");
             system("color F");//������ɫΪ����ɫ
             toxy(15, 10);
             printf("�Ѱ�ȫ�˳����");
            toxy(15, 12);
             printf("ллʹ�ã�");
           toxy(15, 14);
             printf("bye-bye^_^");
             toxy(15, 16);
           exit(0);  break; //��ֹ���� 
          case '2':

                            menu(); break;   //���ú���������˵� 

                        default:break;

                                            }
    }
 }

 void menu()//�˵����ܣ���ʾ���ֲ�������
{
    system("cls");//����
    fflush(stdin);//��ջ���
   char x;
    int n;
    while (x != 'h')
     {
        system("color F");//������ɫΪ����ɫ
         system("cls");
        toxy(15, 4);
        printf("-----�༶��������ϵͳ-----");
        toxy(15, 5);
         printf("|                        |");
        toxy(15, 6);
        printf("|    a.ѧ��������Ϣ¼��  |");
        toxy(15, 7);
       printf("|                        |");
        toxy(15, 8);
        printf("|    b.ѧ��������Ϣ��ʾ  |");
         toxy(15, 9);
        printf("|                        |");

                     toxy(15, 10);

                     printf("|    c.ѧ��������Ϣ����  |");

                     toxy(15, 11);

                    printf("|                        |");
        toxy(15, 12);
        printf("|    d.ѧ��������Ϣɾ��  |");

                    toxy(15, 13);
       printf("|                        |");
        toxy(15, 14);
        printf("|    e.ѧ��������Ϣ�޸�  |");
         toxy(15, 15);
        printf("|                        |");
        toxy(15, 16);
        printf("|    f.ѧ��������Ϣ��ѯ  |");
        toxy(15, 17);
        printf("|                        |");
         toxy(15, 18);
         printf("|    g.��  ��   ��   ��  |");

                     toxy(15, 19);
         printf("|                        |");
         toxy(15, 20);
        printf("|    h.��  ��   ϵ   ͳ  |");
         toxy(15, 21);
         printf("|                        |");
        toxy(15, 22);
         printf("--------------------------");
        toxy(15, 23);
        printf("������ѡ��:");
         x = getch();
         if (x < 'A' || x>'H' && x < 'a' || x>'h')//�������ķ�Χ������A-H��a-h
         {
             toxy(15, 25);
            printf("����ѡ������,����������");
             Sleep(700);
            continue;
        }
         if (x >= 'A' && x <= 'H')
            x = x + 32;//����дת��ΪСд

                     switch (x)
         {
        case 'a':
            system("cls");
             system("color F");//������ɫΪ����ɫ
            toxy(15, 8);
            printf("������¼��ѧ������:");
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

 void save_password(char str[])//�������뵽password�ı��ļ���
 {
     FILE * fp;
    fp = fopen("password", "w");//���ı��ļ�
   if (fp == NULL)
    {
         printf("cannot open file");
    }
    if (fputs(str, fp) != 0)//ʹ��fputs������д�������ļ����ɹ��򷵻�0�����򷵻ط�0ֵ
    {
       printf("write error!");

                 }

            fclose(fp);
 }

   

         void load()//�����½��ͨ����֤��ȡ�ļ����������û�����������Ƿ�һ�£��Ӷ�����ϵͳ

         {
     char _password[18];

            int p = 3;//��3����֤�������

         do

                 {

                     system("cls");//����

                    system("color F");//������ɫΪ����ɫ

                    int i = 0;

                     char password[18];
         char str[] = "hstc2018";//��һ�ε�½�ĳ�ʼ����
        char k;
        FILE * fp;
         if ((fp = fopen("password", "a+")) == NULL)
         {
             printf("cannot open file");
             exit(0);
        }
         fseek(fp, 0L, SEEK_END);//���ļ�ָ���Ƶ����
         int size = ftell(fp);//��ftell�����ⶨ�ļ�λ�ñ�ǵĵ�ǰλ��
         rewind(fp);//ʹ�ļ�λ�ñ�����·����ļ��Ŀ�ͷ
        if (size == 0)//����ļ��ĳ���Ϊ�գ���˵���ǵ�һ�ε�½ʹ��
         {
             strcpy(password, str);//����ʼ���븴�Ƶ�password����
             save_password(password);//�������뵽�ļ���
         }
        else
            fgets(password, 18, fp);//���ļ��ж�ȡ����
        toxy(15, 6);
        printf("----------ѧ����������ϵͳ---------n");
         toxy(15, 8);
       printf("���������������:");
       for (;;)//�˴�Ϊ�������벻���Բ��� 
        {
            k = getch();//����k
            if (k == 'r') //�������kΪ�س���������ѭ�� 
          {
                break;
            }
            if (k == 'b')//�������kΪɾ���� 
             {
               if (i > 0)//������뻹û��ȫɾ�� 
                 {
                   printf("b");
                    printf(" ");
                     printf("b");
                     i--;
                }
             }
            else  //��������k�Ȳ���ɾ������Ҳ���ǻس���
           {
                _password[i] = k;
                printf("*");
                i++;
            }
        }
        _password[i] = '';//���ַ�����β�����������
         if (strcmp(password, _password) == 0)//�ж������Ƿ�������ȷ
         {
             system("cls");//����
            toxy(15, 10);
             printf("���ڵ�½����");
             Sleep(500);
6             menu();
         }
         else
         {
            toxy(15, 10);
             p--;
             printf("�������!������%d�λ���", p);
             Sleep(600);

                         }

           
     }while (p > 0);//��֤���᲻Ϊ0
     if (p == 0)
     {
        system("cls");//����
        toxy(15, 6);
         printf("����������!");
         toxy(15, 8);
     }
 }
 void change_password()//�޸����룬��Ҫ���������������룬�����������֤��ȷ��ɳɹ��޸�
 {
7     system("cls");//����
     system("color F");//������ɫΪ����ɫ
     char str[18];
     FILE * fp;

             if ((fp = fopen("password", "r")) == NULL)//ֻ�ö�����r��stu�ļ�
     {
         printf("cannot open file");
         exit(0);
     }

             fgets(str, 18, fp);//��fpָ���password�ļ������ַ�������ŵ��ַ�����str��
    fclose(fp);

         do

                 {

                     system("cls");//����

                  char password[18], newpassword[18], c, t;

                    int i = 0;
        toxy(15, 6);
        printf("ѧ������ϵͳ");
        toxy(15, 8);

                    printf("�޸�����");

                     toxy(15, 10);

                     printf("�����������:");
         for (;;)//�˴�Ϊ���벻���Բ���

                    {

                             c = getch();

                            if (c == 'r')//�������Ϊ�س���
             {
                break;
            }
             else if (c == 'b')//�������cΪɾ����

                                {

                                    if (i > 0) //������뻹û��ȫɾ��

                                      {

                                          printf("b");

                                           printf(" ");

                                          printf("b");

                                           i--;

                                      }

                              }

                             else  //��������c�Ȳ���ɾ������Ҳ���ǻس���

                              {

                                    password[i] = c;

                                    printf("*");

                                     i++;
          }
         }
        password[i] = '';//���ַ�����β�����������

                     i = 0;

                    toxy(15, 12);

                    printf("������������:");
        for (;;)//�˴�Ϊ�������벻���Բ���

                         {

                           c = getch();

                            if (c == 'r') //�������cΪ�س���������ѭ��

                               {

                                   break;

                               }

                        else if (c == 'b')//�������cΪɾ����

                                {

                                   if (i > 0)//������뻹û��ȫɾ��

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

                  newpassword[i] = '';//���ַ�����β�����������

                 if (strcmp(str, password) == 0)//�����������ԭ��������֤�ɹ�

                   {

                       save_password(newpassword);//����������

                       system("cls");//����

                            toxy(15, 6);

                         printf("�޸ĳɹ�,�����������˵�����");

                            Sleep(600);

                         menu();

                      }

                  else

                   {

                        system("cls");//����

                      toxy(15, 8);

                              printf("-------------------------------------");

                               toxy(15, 9);

                                printf("|                                   |");

                                 toxy(15, 10);

                              printf("|        ��������Ƿ����?        |");

                           toxy(15, 11);

                                 printf("|                                   |");

                             toxy(15, 12);

                                 printf("| 1.��                      2.��    |");

                             toxy(15, 13);

                          printf("|                                   |");

                             toxy(15, 14);

                             printf("-------------------------------------");

                           while (1)

                                   {

                                   t = getch();

                                    if (t == '1')

                                          {

                                              system("cls");//����
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
	printf("*************    1.��������         *************\n");
	printf("*************    2.�������         *************\n");
	printf("*************    3.ɾ������         *************\n");
	printf("*************    4.��������         *************\n");
	printf("*************    5.���ɼ���������   *************\n");
	printf("*************    6.�˳�             *************\n");
	printf("*************************************************\n");
	printf("��ѡ��:>");
	scanf("%d", n);
}
void scanfstudent(struct Student* p, int len)//����ѧ������Ϣ ѧ�� ���� �Ա� ���� �÷�
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("�������%dѧ������Ϣ:\n", i + 1);
		printf("ѧ��:");
		scanf("%s", p[i].xuehao);
		printf("����:");
		scanf("%s", p[i].name);
		printf("�Ա�:");
		scanf("%s", p[i].sex);
		printf("����:");
		scanf("%d", &p[i].age);
		printf("�÷�:");
		scanf("%f", &p[i].score);
		printf("\n");
	}

}

void printfstudent(struct Student* p, int len)//��ѧ������Ϣ�������
{
	int i;
	printf("ѧ��\t\t����\t\t�Ա�\t\t����\t\t����\n\n");

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

	printf("������Ҫ��������ĳ��ȣ�");
	scanf("%d", &n);
	scanfstudent(p, n);
	*len = n;
	printfstudent(p, *len);

}
void add(struct Student* p, int* len)//����һ��ѧ������Ϣ�����Ұ���˳������
{
	// int i,j;

	//int pos = 0;
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		struct Student st;
		printf("������Ҫ���ѧ������Ϣ:\n");
		printf("ѧ��:");
		scanf("%s", st.xuehao);
		printf("����:");
		scanf("%s", st.name);
		printf("�Ա�:");
		scanf("%s", st.sex);
		printf("����:");
		scanf("%d", &st.age);
		printf("�÷�:");
		scanf("%f", &st.score);
		printf("\n");

		p[mylen] = st;
		*len = mylen + 1;
		printfstudent(p, *len);
		printf("\n");
		printf("�Ƿ������ӣ�����:\n1.����\n2.�˳�\n");
		scanf("%d", &c);
	}
}
void Sort(struct Student* p, int len)//���շ����Ӵ�С����ѡ������
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

void del(struct Student* p, int* len)//ɾ��ѧ������Ϣ
{
	int i, j;
	char p1[1024];
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		printf("������Ҫɾ��ѧ����ѧ��:");
		scanf("%s", p1);
		for (i = 0; i < *len; i++)
		{
			if (strcmp(p[i].xuehao, p1) == 0)
				break;
		}
		if (i == 0)//ɾ�����ǵ�һ��Ԫ��
		{
			for (j = 0; j < (*len) - 1; j++)
				p[j] = p[j + 1];
		}
		else if (i > 0 && i < (*len) - 1)//ɾ���м��Ԫ��
		{

			for (j = i; j < (*len) - 1; j++)
				p[j] = p[j + 1];

		}
		else if (i == (*len) - 1)
			;
		else
			printf("error,ѧ����������!\n");
		*len = mylen - 1;//���鳤�ȼ���һ��
		printfstudent(p, *len);
		printf("\n");
		printf("�Ƿ����ɾ��������:\n1.����\n2.�˳�\n");
		scanf("%d", &c);
	}
}

void serch(struct Student* p, int len)//��ѧ�Ż�����������ѧ����Ϣ
{

	int i, j;
	int flat = 0;
	char num[100];
	char name1[100];
	printf("������1��2,1��ѧ�Ų���,2����������:");
	scanf("%d", &i);

	if (i == 1)
	{
		printf("������Ҫ���ҵ�ѧ��:");
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
			printf("ѧ����������!\n");
		}
		else
		{
			printf("ѧ��:%s,����:%s,�Ա�:%s,����:%d,�÷�:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
		}
	}
	else if (i == 2)
	{
		flat = 0;
		printf("������Ҫ���ҵ�����:");
		scanf("%s", name1);
		for (j = 0; j < len; j++)
		{
			if (strcmp(p[j].name, name1) == 0)
			{
				flat++;
				printf("ѧ��:%s,����:%s,�Ա�:%s,����:%d,�÷�:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
				break;
			}

		}
		if (!flat)
		{
			printf("������������!\n");
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
		case 6:printf("лл����ʹ��!\n\n"); break;
		default:printf("����������������!\n\n"); break;
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
	printf("*************    1.��������         *************\n");
	printf("*************    2.�������         *************\n");
	printf("*************    3.ɾ������         *************\n");
	printf("*************    4.��������         *************\n");
	printf("*************    5.���ɼ���������   *************\n");
	printf("*************    6.�˳�             *************\n");
	printf("*************************************************\n");
	printf("����������1-6:");
	scanf("%d", n);
}
void scanfstudent(struct Student* p, int len)//����ѧ������Ϣ ѧ�� ���� �Ա� ���� �÷�
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("�������%dѧ������Ϣ:\n", i + 1);
		printf("ѧ��:");
		scanf("%s", p[i].xuehao);
		printf("����:");
		scanf("%s", p[i].name);
		printf("�Ա�:");
		scanf("%s", p[i].sex);
		printf("����:");
		scanf("%d", &p[i].age);
		printf("�÷�:");
		scanf("%f", &p[i].score);
		printf("\n");
	}

}

void printfstudent(struct Student* p, int len)//��ѧ������Ϣ�������
{
	int i;
	printf("ѧ��\t\t����\t\t�Ա�\t\t����\t\t����\n\n");

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
	printf("������Ҫ��������ĳ��ȣ�");
	scanf("%d", &n);
	scanfstudent(p, n);
	*len = n;
	printfstudent(p, *len);

}
void add(struct Student* p, int* len)//����һ��ѧ������Ϣ�����Ұ���˳������
{
	// int i,j;

	//int pos = 0;
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		struct Student st;
		printf("������Ҫ���ѧ������Ϣ:\n");
		printf("ѧ��:");
		scanf("%s", st.xuehao);
		printf("����:");
		scanf("%s", st.name);
		printf("�Ա�:");
		scanf("%s", st.sex);
		printf("����:");
		scanf("%d", &st.age);
		printf("�÷�:");
		scanf("%f", &st.score);
		printf("\n");

		p[mylen] = st;
		*len = mylen + 1;
		printfstudent(p, *len);
		printf("\n");
		printf("�Ƿ������ӣ�����:\n1.����\n2.�˳�\n");
		scanf("%d", &c);
	}
}
void Sort(struct Student* p, int len)//���շ����Ӵ�С����ѡ������
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
void del(struct Student* p, int* len)//ɾ��ѧ������Ϣ
{
	int i, j;
	char p1[1024];
	int c = 1;
	while (c == 1)
	{
		int mylen = *len;
		printf("������Ҫɾ��ѧ����ѧ��:");
		scanf("%s", p1);
		for (i = 0; i < *len; i++)
		{
			if (strcmp(p[i].xuehao, p1) == 0)
				break;
		}
		if (i == 0)//ɾ�����ǵ�һ��Ԫ��
		{
			for (j = 0; j < (*len) - 1; j++)
				p[j] = p[j + 1];
		}
		else if (i > 0 && i < (*len) - 1)//ɾ���м��Ԫ��
		{

			for (j = i; j < (*len) - 1; j++)
				p[j] = p[j + 1];

		}
		else if (i == (*len) - 1)
			;
		else
			printf("error,ѧ����������!\n");
		*len = mylen - 1;//���鳤�ȼ���һ��
		printfstudent(p, *len);
		printf("\n");
		printf("�Ƿ����ɾ��������:\n1.����\n2.�˳�\n");
		scanf("%d", &c);
	}
}

void serch(struct Student* p, int len)//��ѧ�Ż�����������ѧ����Ϣ
{

	int i, j;
	int flat = 0;
	char num[100];
	char name1[100];
	printf("������1��2,1��ѧ�Ų���,2����������:");
	scanf("%d", &i);

	if (i == 1)
	{
		printf("������Ҫ���ҵ�ѧ��:");
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
			printf("ѧ����������!\n");
		}
		else
		{
			printf("ѧ��:%s,����:%s,�Ա�:%s,����:%d,�÷�:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
		}
	}
	else if (i == 2)
	{
		flat = 0;
		printf("������Ҫ���ҵ�����:");
		scanf("%s", name1);
		for (j = 0; j < len; j++)
		{
			if (strcmp(p[j].name, name1) == 0)
			{
				flat++;
				printf("ѧ��:%s,����:%s,�Ա�:%s,����:%d,�÷�:%.2f\n", p[j].xuehao, p[j].name, p[j].sex, p[j].age, p[j].score);
				break;
			}

		}
		if (!flat)
		{
			printf("������������!\n");
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
//��̬����ṹ����
struct Student p[1024];

printf("������ѧ���ĸ�����");
scanf("%d",&len);

// p = (struct Student*)malloc(sizeof(struct Student)*len);��̬����һ���ṹ����

scanfstudent(p,len);
Sort(p,len);
printfstudent(p,len);
do
{
struct Student st;

printf("\n���������ӵ�ѧ������Ϣ��\n");
printf("ѧ��:");
scanf("%s",st.xuehao);
printf("����:");
scanf("%s",st.name);
printf("�Ա�:");
scanf("%s",st.sex);
printf("����:");
scanf("%d",&st.age);
printf("�÷�:");
scanf("%f",&st.score);

// serch(p,len);

printf("\n");
//printf("������Ҫɾ����ѧ����ѧ��:");
printf("\n");
//scanf("%s",xuehao11);
add(p,&st,&len);
// del(p,xuehao11,&len);ɾ��һ��ѧ������Ϣ
printfstudent(p,len);
printf("�Ƿ������ӣ�\n1:��\n2�����\n");
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
		case 6:printf("лл����ʹ��!\n\n"); break;
		default:printf("����������������!\n\n"); break;
		}
		if (n == 6)
			break;
	}
	return 0;
}
*/



















/*
#include<stdio.h>   //��׼�������������
#include<string.h>   //�ַ���������
#include<stdlib.h>
struct clothing
{
	int num;   //��װ���
	char Name[10];   //��Ʒ����
	int price;   //�۸�
	char type;   //�ͺ�
}clothing[100];   //����һ���ṹ��
int main()   //��������
{
	void welcomemenu()  //���˵�
	{
		{
			printf("��ѡ������Ҫ�Ĳ���<1-6>:\n");
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
					printf("������������������ѡ��!");
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
	void save(int m);   //�����ļ�����
	void inputmessage();  //¼���װ��Ϣ
	void inquiremessage();   //��ѯ��װ��Ϣ
	void addmessage();   //��ӷ�װ
	void delmessage();   //ɾ����װ
	void modifymessage();   //�޸ķ�װ��Ϣ
	void exit();   //�˳�
	int n, flag;
	char a;


	getchar();
	printf("�Ƿ�������в���?�ظ�y or n:\n");
	a = getchar();
	if (a == 'y')
	{
		flag = 1;
		system("cls");   //����
		welcomemenu();   //�������˵�����
		printf("���ٴ�ѡ�����Ĳ���<1-6>:\n");
		scanf("%d", &n);
	}
	else
		exit(0);
}*/