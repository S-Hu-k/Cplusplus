
#include <iostream> 
#include <string> 
using namespace std;
int main() {
    //��������    
    int n;
    //����    
    string order;
    while (cin >> n >> order) {
        //��n�׸������1��n , numΪ��굱ǰ���ڸ����ı��,firstΪ��ǰ��Ļ��ʾ
        //ҳ�ĵ�һ�׸����ı��        
        int num = 1, first = 1;
        //��������������4ʱ�����и���һҳ������ʾ�꣬���跭ҳ��firstʼ�ղ���		
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
        //������������4ʱ����ʾ��ȫ���и�����Ҫ��ҳ����Ļ������ʾ4�׸���
        else {
            for (int i = 0; i < order.size(); i++) {
                if (first == 1 && num == 1 && order[i] == 'U') {
                    first = n - 3;
                    num = n;
                }
                //���ⷭҳ1                
                else if (first == n - 3 && num == n && order[i] == 'D') {
                    first = 1; num = 1;
                }
                //���ⷭҳ2               
                else if (first != 1 && num == first && order[i] == 'U') {
                    first--; num--;
                }
                //һ�㷭ҳ1                
                else if (first != n - 3 && num == first + 3 && order[i] == 'D') {
                    first++; num++;
                }
                //һ�㷭ҳ2                
                else if (order[i] == 'U') {
                    num--;
                }
                //�������1                
                else {
                    num++;
                }
                //�������2            
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

//ϴ��
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    int T;//��ʾ���ݵ�����
    cin >> T;//����T


    for (int i = 0; i < T; ++i)
    {
        int N;//�������Ƶ�����������Ϊ2n��
        int K;//��Щ�Ʊ�ϴ������

        cin >> N;
        cin >> K;

        vector<int> InputData;
        vector<int> LeftHand;
        vector<int> RightHand;

        //������ݵ�����
        InputData.clear();
        int temp;
        for (int j = 0; j < 2 * N; ++j)
        {
            cin >> temp;
            InputData.push_back(temp);
        }

        //��ʼϴ��
        for (int k = 0; k < K; ++k)
        {//��ʼ��k��ϴ��

            LeftHand.clear();
            RightHand.clear();

            for (int j = 0; j < N; ++j)
            {//�����ַַ���
                LeftHand.push_back(InputData[j]);
            }

            for (int j = 0; j < N; ++j)
            {//�����ַַ���
                RightHand.push_back(InputData[j + N]);
            }

            //��ʼϴ��
            //�ȷ����ֵ��ƣ��ٷ����ֵ���
            for (int m = N - 1, n = 0; m >= 0; --m, ++n)
            {
                InputData[2 * n] = RightHand[m];
                InputData[2 * n + 1] = LeftHand[m];
            }

            reverse(InputData.begin(), InputData.end());
        }

        //ϴ�ƽ���
        //������
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
    cout << "������������" << endl;
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