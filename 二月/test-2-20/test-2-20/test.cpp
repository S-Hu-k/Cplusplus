#include<iostream>
#include<vector>
//#include<vld.h>
using namespace std;











/*
void main()
{

	vector<int> v ;
	v.assign(10, 2);
	cout << v.size() << endl;
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
}


/*
void main()
{
	vector<int> v = { 1,2,3,4,5,6 };
	auto it = v.begin();
	cout << "it=" << *it << endl;

	v.resize(10);
 it = v.begin();
	cout << "it=" << *it << endl;

	
}


/*
void main()
{
	vector<int> v = { 1,2,3,4,5,6 };
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;

	auto it = find(v.begin(), v.end(), 5);
	cout << "it=" << *it << endl;


	v.push_back(19);
 it = find(v.begin(), v.end(), 5);
	cout << "it=" << *it << endl;

 
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
}


/*

void main()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v2 = { 155,22,53,24,535,62,17,28,92,1120 };

	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

	for (auto& e : v2)
		cout << e << " ";
	cout << endl;

	v1.swap(v2);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

	for (auto& e : v2)
		cout << e << " ";
	cout << endl;

}
/*
void main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(int);
	vector<int> v(a, a + 10);

	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = find(v1.begin(), v1.end(), 5);
	auto p1 = find(v1.begin(), v1.end(), 9);
	auto it = v1.erase(p,p1);

	for (auto& e : v1)
		cout << e << " ";
	cout << endl;
}
/*
void main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(int);
	vector<int> v(a, a + 10);

	vector<int> v1= { 1,2,3,4,5,6,7,8,9,10 };
	auto p = find(v1.begin(), v1.end(), 9);
	v1.insert(p, 100);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;

}
*/