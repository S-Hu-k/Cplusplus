

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
    vector<int> num;
    double GetMedian(vector<int> num)
    {
        sort(num.begin(), num.end());
        if (num.size() % 2 == 1)
            cout << num[num.size() / 2] << endl;
        else
        {
            cout << (num[num.size() / 2] + num[num.size() / 2 - 1]) / 2 << endl;
        }
    }
}


//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res;
        if (input.empty() || k > input.size())
            return res;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; ++i)
            res.push_back(input[i]);
        return res;
    }
};

/*
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> input = { 4, 5, 1, 6, 2, 7, 3, 8 };
    int k = 4;
    sort(input.begin(), input.end());
    for (int i = 0; i < k; ++i)
    {
        cout << input[i] << endl;
    }
}*/