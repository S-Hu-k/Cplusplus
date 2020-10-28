#include<iostream>
using namespace std;

class A
{
public:
	A() :m_a(256) {}
private:
	int m_a;
};

void  main() {
	A a;
	int* b = static_cast<int*>((static_cast<void*>(&a)));
	//int* b = static_cast<int*>((static_cast<void*>(&a)));
	cout << *b<<endl;
}
/*class Base
{
	friend void PrintData(const Base& b, const D& d, const C& c);
public:
	Base(int a, int b) : m_a(a), m_b(b)
	{
#ifdef DISPLAY
		cout << "Base::Base()" << endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout << "Base::~Base()" << endl;
#endif
	}
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun(int, int)
	{
		cout << "Base::fun(int,int)" << endl;
	}
	void show()
	{
		cout << "Base::show()" << endl;
	}
public:
	int m_a = 0;
	int m_b = 0;
};
class D : public Base
{
	friend void PrintData(const Base& b, const D& d, const C& c);
public:
	D() : Base(1, 2)
	{
#ifdef DISPLAY
		cout << "D::D()" << endl;
#endif
	}
	~D()
	{
#ifdef DISPLAY
		cout << "D::~D()" << endl;
#endif
	}
public:
	void fun()
	{
		cout << "D::fun()" << endl;
	}
public:
	int m_x = 0;
	int m_y = 0;
};
class C
{
	friend void PrintData(const Base& b, const D& d, const C& c);
public:
private:
	int m_n = 0;
	int m_k = 0;
};
void PrintData(const Base& b, const D& d, const C& c)
{
	cout << b.m_a << " : " << b.m_b << endl;
	cout << d.m_x << " : " << d.m_y << endl;
	cout << c.m_n << " : " << c.m_k << endl;
}
//继承体系里面的友元函数不具备传递性  // 父类 <--> 子类 
void main()
{
	D d;
	//d.fun();
	//d.fun(0,0);
	//d.show();
	Base b(1, 2);
	C c;
	PrintData(b, d, c);
}
/*class Person
{
	friend void Print();
	
private:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
	int _age = 18;
};


class Student : public Person
{
protected:
	
		int _stuid; // 学号
};
class Teacher : public Person
{
protected:
	int _jobid; // 工号
};
int main()
{
	Person pre;
	pre.Print();
	Student s;
	Teacher t;
	//s.Print();
	//t.Print();
	return 0;
}*/

/*
class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
	//	m_a = m_b = 0;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
public:
	void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	void fun(int a)
	{
		cout << "This is Base::fun(int)" << endl;
	}
private:
	int m_a;
	int m_b;
};
class D : public Base
{
public:
	D()
	{
		cout << "D::D()" << endl;
		m_x = m_y = m_z = 0;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
public:
	//同名隐藏
	void fun()
	{
		cout << "This is D::fun()" << endl;
	}
	void show()
	{
		cout << "This is D::show()" << endl;
	}
private:
	int m_x;
	int m_y;
	int m_z;
};
void main()
{
	
	Base b;
	D d;
	//赋值兼容规则

	b = d;//1.子类对象给父类对象赋值
	Base* pb = &d;//2.子类对象的引用给父类对象的指针赋值
	Base &rb = d;//33.子类对象给父类对象的引用初始化

}
/*
void main()
{
	D d;
	Base *pb = &d;
	pb->fun();
}
/*
void main()
{
	D d;
	d.show();
	d.fun();
}

void main()
{
	Base b, *pb=nullptr;
	D    d;
	//1
	b = d;   //类型不同
	//2
	pb = &d;
	//3
	Base &rb = d; //初始化
}
/*
class Base
{
public:
	void fun1()
	{}
protected:
	void show ()
	{
	}
	void show1()
	{}
private:
	void list1()
	{}
private:
	int m_a;
};
class D : private Base
{
public:
	void fun()
	{
		fun1();
		show1();
		//list1();
	}
protected:
	void show()
	{
		fun1();
	}
private:
	int m_x;
};
class C : public D
{
public:
	void fun2()
	{
		//fun1();
	}
};
//能否访问的问题  //1 站在对象的角度  //2 站在子类内部的角度
int main()
{
	D d;
	d.fun(); //
	//d.fun1();
}

//class Base
//{
//public:
//	
//private:
//	int m_x = 0;
//	int m_y = 0;
//};*/