for (int i = 0; i < n; ++i)
{
    int sum += i;
}


/*
#include <iostream>
using namespace std;

#include <algorithm> 
int main()
{
    int a[5] = { 1,3,4,9,6 };
    sort(a, a + 5);
    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;
    return 0;
}

/*
#include <iostream>
using namespace std;
int fun(int x, int y)
{
    if (x == y)
        return (x);
    else
        return ((x + y) / 2);
}
int main()
{
    int a = 4, b = 5, c = 6;
    printf("%d\n", fun(2 * a, fun(b, c)));
}

/*#include<iostream>
using namespace std;

/*





void main()
{
    int* p1 = new int[10];//中括号用数组的方式申请
    cout << *p1 << endl;
    delete [10]p1;//释放也要用中括号
}
/*
void main()
{
    int* p1 = new int(10);//小括号是赋初值
    cout << *p1 << endl;
    delete p1;
 }
 */