class Solution {
public:
    int Add(int num1, int num2)
    {

        while (num2 != 0) {
            int temp = num1 ^ num2;// ��������������൱����򣬲����λ
            num2 = (num1 & num2) << 1;// ���λ�൱���������������һλ
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