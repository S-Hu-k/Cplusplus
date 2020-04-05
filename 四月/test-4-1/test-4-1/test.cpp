class Solution {
public:
    int Add(int num1, int num2)
    {

        while (num2 != 0) {
            int temp = num1 ^ num2;// 两个二进制相加相当于异或，不算进位
            num2 = (num1 & num2) << 1;// 求进位相当于与操作，再左移一位
            num1 = temp;
        }
        return num1;
    }
};
/*
int main()
{
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;

    }
}*/