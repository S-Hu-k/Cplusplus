/*
1月1日：元旦
1月的第三个星期一：马丁·路德·金纪念日
2月的第三个星期一：总统节
5月的最后一个星期一：阵亡将士纪念日
7月4日：美国国庆
9月的第一个星期一：劳动节
11月的第四个星期四：感恩节
12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期。
输入描述 :
输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。
输出描述 :
对应每一组数据，以“YYYY - MM - DD”格式输出当年所有的节日日期，每个日期占一行。
每组数据之后输出一个空行作为分隔。
示例1
输入
2014
2013
输出
2014 - 01 - 01
2014 - 01 - 20
2014 - 02 - 17
2014 - 05 - 26
2014 - 07 - 04
2014 - 09 - 01
2014 - 11 - 27
2014 - 12 - 25
2013 - 01 - 01
2013 - 01 - 21
2013 - 02 - 18
2013 - 05 - 27
2013 - 07 - 04
2013 - 09 - 02
2013 - 11 - 28
2013 - 12 - 25

重点：使用蔡勒公式
蔡勒公式：
字母意义：
w：星期； w对7取模得：0 - 星期日，1 - 星期一，2 - 星期二，3 - 星期三，4 - 星期四，5 - 星期五，6 - 星期六   
c：世纪（前两位数）    y：年（后两位数）
m：月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算
d : 日
公式：W  = [C / 4] - 2C  + y  + [y / 4] + [13 * (M + 1) / 5] + d  - 1 
（或 : w = y + [y / 4] + [c / 4] - 2c + [26(m + 1) / 10] + d -1

#include <iostream>
using namespace std;
int day_of_week(int year, int month, int day)
{
    //月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }
    int c = year / 100;
    year = year % 100;
    int week = year + (year / 4) + (c / 4) - 2 * c + 26 * (month + 1) / 10 + day - 1;  //公式：w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
    week = (week % 7 + 7) % 7;

    if (week == 0) {
        week = 7;
    }

    return week;
}

int day_of_demand(int year, int month, int count, int d_of_week)
{
    //count 第几个星期     d_of_week周几
    int week = day_of_week(year, month, 1);
    // 第几个星期 * 7天 + 这个星期到星期 d_of_week 还剩几天
    int day = 1 + (count - 1) * 7 + ((7 - week) + d_of_week) % 7;
    return day;
}
//输出格式为yyyy-mm-dd
// 元旦
void new_year_day(int year) {
    printf("%d-01-01\n", year);
}

// 马丁·路德·金纪念日
void martin_luther_king_day(int year) {
    printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}

// 总统日
void president_day(int year) {
    printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}

// 阵亡将士纪念日
void memorial_day(int year) {
    // 从 6 月往前数
    int week = day_of_week(year, 6, 1);
    int d = (week == 1) ? 6 : (week - 2);
    int day = 31 - d;
    printf("%d-05-%02d\n", year, day);
}

// 国庆
void independence_day(int year) {
    printf("%d-07-04\n", year);
}

// 劳动节
void labor_day(int year) {
    printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}

// 感恩节
void thanks_giving_day(int year) {
    printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}

// 圣诞节
void christmas(int year) {
    printf("%d-12-25\n", year);
}

// 美国节日
void festival(int year) {
    new_year_day(year);
    martin_luther_king_day(year);
    president_day(year);
    memorial_day(year);
    independence_day(year);
    labor_day(year);
    thanks_giving_day(year);
    christmas(year);
}

int main() {
    int year;
    while (cin >> year) {
        festival(year);
        cout << endl;
    }
}




/*
所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an, 
并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。

    输入描述 :

输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。
输出描述 :

对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
示例1

输入

10
18
输出

10 = 2 * 5

18 = 2 * 3 * 3

思路：1.循环从2开始找到第一个可以整除的素数，找到后跳出循环

2.在该数大于等于2的条件下，从2开始循环找到剩余可以整除的素数

#include<iostream>
using namespace std;
int main()
{
    int a;
    int i = 0;
    while (cin >> a)
    {
        cout << a << " = ";
        //找到第一个可以整除的素数，i从2开始
        i = 2;
        while (1)
        {
            if (a % i == 0)
            {
                cout << i;
                a /= i;
                break;
            }
            ++i;
        }
        //找到剩余可以整除的素数
        while (a >= 2)
        {
            i = 2;
            while (1)
            {
                if (a % i == 0)
                {
                    cout << " * " << i;
                    a /= i;
                    break;
                }
                ++i;
            }
        }
        cout << endl;
    }

}
*/ 