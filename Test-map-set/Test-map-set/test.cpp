
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
*/