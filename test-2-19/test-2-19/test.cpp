#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;

void main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

 // vector<int>::iterator it = v.begin();
    auto it=v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    v.pop_back();
    for (auto& e : v)
        cout << e << " ";
    cout << endl;

}


//vector 没有头插是因为效率  STL 以效率著称
/*
void main()
{
    vector<int> v;
    v.reserve(100);
    for (int i = 0; i < 100; ++i)
    {
        cout << "capacity=" << v.capacity() << endl;
        v.push_back(i);
    }
}
/*
void Print(vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}
void main()
{

    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v(a, a + 10);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    Print(v);
    v.resize(5, 3);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    Print(v);
}
/*
void main()
{

    int a[3] = { 1,2,3 };
    vector<int> v(a, a + 3);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    Print(v);
    v.reserve(10);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    Print(v);
   // v.resize(10);
   // cout << "size=" << v.size() << endl;
   // cout << "capacity=" << v.capacity() << endl;
   // Print(v);
    v.resize(10,3);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    Print(v);
}


    /*
    vector<int> v;
    cout << "size=" << v.size() << endl; 
    cout << "capacity=" << v.capacity() << endl;
    v.push_back(1);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    v.push_back(2);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    v.push_back(3);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    v.push_back(4);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    v.push_back(5);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
    v.push_back(8);
    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;
     

}
/*
void main()
{
    int  a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v4(a, a + 10);
    //利用下标进行访问 重载了operator[]
    for (int i = 0; i < v4.size(); i++)
        cout << v4[i] << " ";
    cout << endl;

    //利用at()  检测下标是否越界
     
    for (int i = 0; i < v4.size(); ++i)
        cout << v4.at(i) << " ";
    cout << endl;


    //利用迭代器
    vector<int>::iterator it = v4.begin();
    while (it != v4.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

     //利用反向迭代器
    vector<int>::reverse_iterator rit = v4.rbegin();
    while (rit != v4.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;



}
/*
void main()
{
    vector<int> v1;
    vector<int> v2(10, 1);
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;


    //向量的拷贝构造
    vector<int> v3(v2);
    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " ";
    cout << endl;

    int  a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v4(a, a + 10);
    for (int i = 0; i < v4.size(); i++)
        cout << v4[i] << " ";
    cout << endl;

    vector<int> v5 (v4.begin(), v4.end());
    for (int i = 0; i < v5.size(); i++)
        cout << v5[i] << " ";
    cout << endl;
}
/*
void main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
 }
*/