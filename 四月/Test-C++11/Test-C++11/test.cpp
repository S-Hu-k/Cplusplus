#include<iostream>
#include<vector>
#include<map>
#include <string>
#include <initializer_list>
using namespace std;
int g_a = 10;
// 函数的返回值结果为引用
int& GetG_A()
{
	return g_a;
}
int main()
{
	int a = 10;
	int b = 20;
	// a和b都是左值，b既可以在=的左侧，也可在右侧，
	// 说明：左值既可放在=的左侧，也可放在=的右侧
	a = b;
	b = a;
	const int c = 30;
	// 编译失败，c为const常量，只读不允许被修改
	//c = a;
	// 因为可以对c取地址，因此c严格来说不算是左值
	cout << &c << endl;
	// 编译失败：因为b+1的结果是一个临时变量，没有具体名称，也不能取地址，因此为右值
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
	// 显式缺省构造函数，由编译器生成
	A() = default;
	// 在类中声明，在类外定义时让编译器生成默认赋值运算符重载
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
	// c如果给成short，会造成数据丢失，如果能够让编译器根据a+b的结果推导c的实际类型，就不会存在问题
		short c = a + b;
	std::map<std::string, std::string> m{ {"apple", "苹果"}, {"banana","香蕉"} };
		// 使用迭代器遍历容器, 迭代器类型太繁琐
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
	// 数组
	int arr1[5]{ 1,2,3,4,5 };
	int arr2[]{ 1,2,3,4,5 };
	// 动态数组，在C++98中不支持
	int* arr3 = new int[5]{ 1,2,3,4,5 };
	// 标准容器
	vector<int> v{ 1,2,3,4,5 };
	map<int, int> m{ {1,1}, {2,2,},{3,3},{4,4} };
	cout << x1 << endl;
	cout << x2 << endl;
	cout << x3 << endl;
	cout << x4 << endl;
	cout << x5 << endl;


	return 0;
}*/