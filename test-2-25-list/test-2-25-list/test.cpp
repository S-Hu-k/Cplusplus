#include<iostream>
#include<list>
#include<vector>
using namespace std;



/*
int main()
{
	list<int> mylist1{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v{ 1,2,3,4,5 };

	for (auto& e : mylist1)
		cout << e << "-->";
	cout << "over" << endl;

	for (auto& e : v)
		cout << e <<" ";
	cout  << endl;


	list<int>::iterator it = mylist1.begin();
	while (it != mylist1.end())
	{
		cout << *it << " ";
		*it++;
	}
	cout << endl;

	vector<int>::iterator vit =v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		*vit++;
	}
	cout << endl;
}


/*
int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(int);
	//list<int> mylist;
	list<int> mylist1(10);
	list<int> mylist2(mylist1);
	list<int> mylist(ar, ar + n);
	list<int> mylist3(mylist.begin(), mylist.end());

	for (auto& e : mylist1)
		cout << e << "-->";
	cout << "over"<<endl;

	for (auto& e : mylist2)
		cout << e << "-->";
	cout << "over" << endl;

	for (auto& e : mylist3)
		cout << e << "-->";
	cout << "over" << endl;
}
*/