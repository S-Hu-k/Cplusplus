
#include <iostream> 
#include <string> 
using namespace std;
int main() {
    //歌曲数量    
    int n;
    //命令    
    string order;
    while (cin >> n >> order) {
        //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示
        //页的第一首歌曲的编号        
        int num = 1, first = 1;
        //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变		
        if (n <= 4) {
            for (int i = 0; i < order.size(); i++) {
                if (num == 1 && order[i] == 'U') {
                    num = n;
                }
                else if (num == n && order[i] == 'D') {
                    num = 1;
                }
                else if (order[i] == 'U') {
                    num--;
                }
                else {
                    num++;
                }
            }
            for (int i = 1; i <= n - 1; i++) {
                cout << i << ' ';
            }
            cout << n << endl;
            cout << num << endl;
        }
        //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
        else {
            for (int i = 0; i < order.size(); i++) {
                if (first == 1 && num == 1 && order[i] == 'U') {
                    first = n - 3;
                    num = n;
                }
                //特殊翻页1                
                else if (first == n - 3 && num == n && order[i] == 'D') {
                    first = 1; num = 1;
                }
                //特殊翻页2               
                else if (first != 1 && num == first && order[i] == 'U') {
                    first--; num--;
                }
                //一般翻页1                
                else if (first != n - 3 && num == first + 3 && order[i] == 'D') {
                    first++; num++;
                }
                //一般翻页2                
                else if (order[i] == 'U') {
                    num--;
                }
                //其他情况1                
                else {
                    num++;
                }
                //其他情况2            
            }
            for (int i = first; i < first + 3; i++) {
                cout << i << ' ';
            }
            cout << first + 3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}

//洗牌
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    int T;//表示数据的组数
    cin >> T;//输入T


    for (int i = 0; i < T; ++i)
    {
        int N;//左右手牌的数量（总量为2n）
        int K;//这些牌被洗的轮数

        cin >> N;
        cin >> K;

        vector<int> InputData;
        vector<int> LeftHand;
        vector<int> RightHand;

        //完成数据的输入
        InputData.clear();
        int temp;
        for (int j = 0; j < 2 * N; ++j)
        {
            cin >> temp;
            InputData.push_back(temp);
        }

        //开始洗牌
        for (int k = 0; k < K; ++k)
        {//开始第k次洗牌

            LeftHand.clear();
            RightHand.clear();

            for (int j = 0; j < N; ++j)
            {//给左手分发牌
                LeftHand.push_back(InputData[j]);
            }

            for (int j = 0; j < N; ++j)
            {//给右手分发牌
                RightHand.push_back(InputData[j + N]);
            }

            //开始洗牌
            //先放右手的牌，再放左手的牌
            for (int m = N - 1, n = 0; m >= 0; --m, ++n)
            {
                InputData[2 * n] = RightHand[m];
                InputData[2 * n + 1] = LeftHand[m];
            }

            reverse(InputData.begin(), InputData.end());
        }

        //洗牌结束
        //输出结果
        for (int l = 0; l < 2 * N; ++l)
        {
            cout << InputData[l] << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
#include<iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
vector<int> func(int n, int m)
{
    vector<int>iVec;
    for (int i = 0; i < 2 * n; i++)
    {
        int iNum;
        cin >> iNum;
        iVec.push_back(iNum);
    }
    for (int j = 0; j < m; j++)
    {
        vector<int>iVecSubLeft(iVec.begin(), iVec.begin() + n);
        vector<int>iVecSubRight(iVec.begin() + n, iVec.end());
        for (int i = 0; i < n; i++)
        {
            iVec.push_back(iVecSubLeft[i]);
            iVec.push_back(iVecSubRight[i]);
        }
    }
    return iVec;
    // copy(iVec.begin(),iVec.end(),ostream_iterator<int>(cout," "));
     //cout<<endl;

}
int main()
{
    cout << "请输入组数：" << endl;
    int groupNum = 0;
    cin >> groupNum;
    vector<vector<int>>iVecvec;
    for (int num = 0; num < groupNum; num++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> iVec = func(n, m);
        iVecvec.push_back(iVec);
    }
    for (int i = 0; i < iVecvec.size(); i++)
    {
        copy(iVecvec[i].begin(), iVecvec[i].end(); ostream_iterator<int>(cout, "  "));
        cout << endl;
    }
    return 0;
}
*/