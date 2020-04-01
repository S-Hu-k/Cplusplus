
class Solution {
public:
    int jumpFloorII(int number)
    {
        if (number == 1 || number == 0)
            return 1;
        if (number == 2)
            return 2;
        int sum = 0;
        for (int i = 0; i < number; ++i)
        {
            sum += jumpFloorII(i);
        }
        return sum;

    }
};

/*#include<iostream>
using namespace std;
/*
int main()
{
    long CatLegth, r;
    cin >> CatLegth;
    cin>> r;
    long C = 2 * r * 3.14;
    if (CatLegth > C)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}


#include <iostream>
using namespace std;

//一个double就可以解决，不用考虑用字符串做大整数乘除法

int main()
{
    double n, r;
    while (cin >> n >> r)
    {
        if (n > 6.28 * r)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}*/