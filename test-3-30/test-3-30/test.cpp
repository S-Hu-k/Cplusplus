/*
#include <iostream>
using namespace std;
int main()
{
    int f[10001];
    for (int i = 2; i < 10001; i++)
    {
        f[0] = 1;
        f[1] = 1;
        f[i] = (f[i - 1] % 10000 + f[i - 2] % 10000) % 10000;
    }
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            int x;
            cin >> x;
            printf("%04d", f[x]);
        }
        cout << endl;
    }

    return 0;
}


/*
#include<iostream>
using namespace std;
int judgenum(int a)
{
    if (a < 10)
        return a;
    else
    {
        int lastnum = a % 10;
        int prevnum = a / 10;
        if (lastnum + prevnum < 10)
            return lastnum + prevnum;
        else
        {
            judgenum(lastnum + prevnum);
        }
    }
}
int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    //判断 a b 是几位数
     cout << judgenum(a) << endl;
     cout << judgenum(b) << endl;
}*/