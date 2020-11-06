
#include<iostream>
#include<list>
#include<vector>
#include<functional>
#include<algorithm>
#include<unordered_set>
#include<bitset>
using namespace std;
void main()
{
	pair<int, string> v1 = { 1, "abc" };  //值对 
	pair<int, string> v2 = { 2, "xyz" };
	cout << v1.first << " : " << v1.second << endl;
	pair<string, string> v3 = make_pair("1-1", "元旦节");
	cout << v3.first << " : " << v3.second << endl;
}
/*
void main()
{
	forward_list<int> mylist;
	for(int i=1; i<=10; ++i)
		mylist.push_front(i);
	mylist.reverse();
	for(const auto &e : mylist)
		cout<<e<<"->";
	cout<<endl;
}
/*
int	_Count_if(int* _First, int* _Last, _Pr _Pred)
{
	int  _Count = 0;
	for (; _First != _Last; ++_First)
		if (_Pred(*_First))  //if(IsOdd(*_First))
			++_Count;
	return (_Count);
}
bool IsOdd(int i)
{
	return ((i % 2) == 0);
}
int main()
{
	// 统计v2中有多少个偶数
	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << _Count_if(v2.begin(), v2.end(), IsOdd) << endl;
	return 0;
}

//void main()
//{
//	map<int, string> s = { {1,"ks"},{2,"skjks"},{3,"jdl"} };
//	for (auto& e : s)
//	{
//		cout << e.first << ":" << e.second;
//		cout << endl;
//	}
//}
//		*/