#include<iostream>
#include<algorithm>
using namespace std;
class A
{
public:
    A(int a)
        :_a1(a)
        , _a2(_a1)
    {}

    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }

private:
    int _a2;
    int _a1;
};

int main()
{
    A aa(1);
    aa.Print();
}
/*
class Solution
{
public:
    int thirdMax(<int>& nums)
    {
        int len = nums.size() - 1;
        if (nums.size() < 3)
        {
            sort(nums.begin(), nums.end());
            return nums[len];
        }
        if (nums.size() > 3)
        {
            sort(nums.begin(), nums.end());
            if (nums[1] != nums[2])
                return nums[2];
            else
            {
                int k = 3;
                while (nums[2] == nums[k])
                    k++;
                return nums[k + 1];
            }
        }
        return 0;
    }
};
/*
int main()
{
	int a[10] = { 1,5,6,4,5,5,45,8,9,7 };
	sort(a,a+10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
		
	}

}
/*
int main()
{
	int a[] = { 2, 4, 6, 8, 10 }, * p, ** k;
	p = a;
	k = &p;
	printf(" % d", *(p++));
	printf(" % d\n", **k);
	return 0;
}



/*#include<iostream>
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
	return 0;
}*/