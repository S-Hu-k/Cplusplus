/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        if (str1.empty() || str2.empty()) {
            cout << max(str1.size(), str2.size()) << endl;
            continue;
        }

        size_t len1 = str1.size();
        size_t len2 = str2.size();
        vector<vector<int>> F(len1 + 1, vector<int>(len2 + 1, 0));
        //处理第一行和第一列，str1或者str2为空串的情况
        for (int j = 1; j < len2 + 1; ++j) {
            F[0][j] = j;
        }
        for (int i = 1; i < len1 + 1; ++i) {
            F[i][0] = i;
        }

        for (int i = 1; i < len1 + 1; ++i) {
            for (int j = 1; j < len2 + 1; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    F[i][j] = 1 + min(F[i][j - 1], F[i - 1][j]);
                    F[i][j] = min(F[i][j], F[i - 1][j - 1]);
                }
                else {
                    F[i][j] = 1 + min(F[i][j - 1], F[i - 1][j]);
                    F[i][j] = min(F[i][j], F[i - 1][j - 1] + 1);
                }
            }
        }
        cout << F[len1][len2] << endl;
    }
    return 0;
}

/*
public class Main {



    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        while (input.hasNext()) {

            String str1 = input.nextLine();

            String str2 = input.nextLine();

            System.out.println(distance(str1, str2));

        }

    }



    public static int distance(String string1, String string2) {

        char[] str1 = string1.toCharArray();

        char[] str2 = string2.toCharArray();

        int[][] dp = new int[str1.length + 1][str2.length + 1];



        for (int i = 0; i <= str1.length; i++)

            dp[i][0] = i;

        for (int i = 0; i <= str2.length; i++)

            dp[0][i] = i;



        for (int i = 1; i <= str1.length; i++) {

            for (int j = 1; j <= str2.length; j++) {

                if (str1[i - 1] == str2[j - 1]) {

                    dp[i][j] = dp[i - 1][j - 1];

                }
                else {

                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;

                }

            }

        }

        return dp[str1.length][str2.length];

    }

    private static int min(int a, int b, int c) {

        return Math.min(Math.min(a, b), c);

    }

}


/*
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
//1.判断两个字符串的长度
//2.判断两个字符串有多少个字符不一样

int stringdistance( string v1, string v2)
{
    int a = 0;
    int dif = v1.size() - v2.size(); 
    int min=v1.size()>v2.size()?v1.size():v2.size();
    if (v1.size() == v2.size())
    {
        for (int i = 0; i < v1.size(); ++i)
        {
            int count = 0;
            if (v1[i] != v2[i])
            {
                count++;
            }
        }
    }
    else
    {
        for (int i = 0; i < min; ++i)
        {
            if (v1[i] == v2[i])
            {
                a++;
            }
        }
        return abs(dif);
    }
}
int main()
{
    string v1;
    string v2;
    cin >> v1;
    cin >> v2;
    cout << stringdistance(v1, v2) << endl;

}

/*
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//比较函数，这里的元素类型要与vector存储的类型一致
//bool compare(int a, int b)
//{
 //   return a < b; //升序排列
//}
//std::sort(vec.begin(), vec.end(), compare);
int getValue(vector<int> gifts, int n)
{  
        int size = n / 2;
        int count = 0;
        sort(gifts.begin(), gifts.end());
     
        for (int i = 0; i < n; i++) 
        {
            if (gifts[i] == gifts[n / 2])
                count++;
        }
        if (count > n / 2)
            return gifts[n / 2];
        return 0;
}

int main()
{
    vector<int> gifts = { 1,44,3,56,4,63,2,2 ,8,9,89,89,89,89,89};
    cout << getValue(gifts, gifts.size()) << endl;
}*/