#include<iostream>
#include<vector>
#include<map>
#include <string>
#include <initializer_list>
using namespace std;
int g_a = 10;
// �����ķ���ֵ���Ϊ����
int& GetG_A()
{
	return g_a;
}
int main()
{
	int a = 10;
	int b = 20;
	// a��b������ֵ��b�ȿ�����=����࣬Ҳ�����Ҳ࣬
	// ˵������ֵ�ȿɷ���=����࣬Ҳ�ɷ���=���Ҳ�
	a = b;
	b = a;
	const int c = 30;
	// ����ʧ�ܣ�cΪconst������ֻ���������޸�
	//c = a;
	// ��Ϊ���Զ�cȡ��ַ�����c�ϸ���˵��������ֵ
	cout << &c << endl;
	// ����ʧ�ܣ���Ϊb+1�Ľ����һ����ʱ������û�о������ƣ�Ҳ����ȡ��ַ�����Ϊ��ֵ
	//b + 1 = 20;
	GetG_A() = 100;
	return 0;
}

/*
class A
{
public:
	A(int a) : _a(a)
	{}
	// ��ʽȱʡ���캯�����ɱ���������
	A() = default;
	// �����������������ⶨ��ʱ�ñ���������Ĭ�ϸ�ֵ���������
	A& operator=(const A& a);
private:
	int _a;
};
A& A::operator=(const A& a) = default;
int main()
{
	A a1(10);
	A a2;
	a2 = a1;
	return 0;
}
int main()
{
	short a = 32670;
	short b = 32670;
	// c�������short����������ݶ�ʧ������ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ����������
		short c = a + b;
	std::map<std::string, std::string> m{ {"apple", "ƻ��"}, {"banana","�㽶"} };
		// ʹ�õ�������������, ����������̫����
		std::map<std::string, std::string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	return 0;
}
/*

template<class T>
class Vector {
public:
	// ...
	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0)
	{
		_array = new T[_capacity];
		for (auto e : l)
			_array[_size++] = e;
	}
	Vector<T>& operator=(initializer_list<T> l) {
		delete[] _array;
		size_t i = 0;
		for (auto e : l)
			_array[i++] = e;
		return *this;
	}
	// ...
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
int main()
{

}
/*
int main()
{
	int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	// ����
	int arr1[5]{ 1,2,3,4,5 };
	int arr2[]{ 1,2,3,4,5 };
	// ��̬���飬��C++98�в�֧��
	int* arr3 = new int[5]{ 1,2,3,4,5 };
	// ��׼����
	vector<int> v{ 1,2,3,4,5 };
	map<int, int> m{ {1,1}, {2,2,},{3,3},{4,4} };
	cout << x1 << endl;
	cout << x2 << endl;
	cout << x3 << endl;
	cout << x4 << endl;
	cout << x5 << endl;


	return 0;
}*/