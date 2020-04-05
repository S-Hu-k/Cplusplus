/*
class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i = 0, j = 1;
        while (i < len && j < len)
        {
            if (arr[len - 1] % 2 == 0)
            {
                swap(arr[len - 1], arr[i]);
                i += 2;
            }
            else
            {
                swap(arr[len - 1], arr[j]);
                j += 2;
            }
        }
    }
};

/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    void oddInOddEvenInEven(vector<int>& arr, int len)
    {
        long i = 0, j = 1;
        while (i < len && j < len)
        {
            if (arr[i] % 2 == 0)
            {
                i += 2;
               continue;
            }
            if (arr[j] % 2 != 0)
            {
                j += 2;
                continue;
            }
            swap(arr[i], arr[j]);
        }
    }
}


/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int oddInOddEvenInEven(vector<int>& arr, int len)
{
    vector<int> arr1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = 0; j < arr.size(); j += 2)
            {
                arr1[j] = arr[i];
            }
        }
        if (arr[i] % 2 == 1)
        {
            for (int j = 1; j < arr.size(); j += 2)
            {
                arr1[j] = arr[i];
            }
        }
     return arr1[i];
    }
}
   
int main()
{
    int oddInOddEvenInEven(vector<int> & arr, int len);
    
}*/