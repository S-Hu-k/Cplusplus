
#include<iostream>
using namespace std;
class Base
{
public:
	int m_n;
};

//虚拟继承
class A : virtual public Base   //A 有自己的虚基表
{
public:
	int m_a;
};
class B : virtual public Base  //B 有自己的虚基表
{
public:
	int m_b;
};
class D : public A, public B
{
public:
	int m_d;
};

void main()
{
	D d;
	d.m_d = 0;
	d.m_a = 1;
	d.m_b = 2;

	d.A::m_n = 3;

}
/*
#define DISPLAY
class Base
{
public:
	Base(int a) :m_a(a), m_b(a)
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
class Base1
{
public:
	Base1(int a, int b) :m_a1(a), m_b1(b)
	{
#ifdef DISPLAY
		cout << "Base1::Base1()" << endl;
#endif
	}
	~Base1()
	{
#ifdef DISPLAY
		cout << "Base1::~Base1()" << endl;
#endif
	}
public:
	void fun()
	{
		cout << "Base1::fun()" << endl;
	}
	void fun(int, int)
	{
		cout << "Base1::fun(int,int)" << endl;
	}
	void show()
	{
		cout << "Base1::show()" << endl;
	}
public:
	int m_a1 = 0;
	int m_b1 = 0;
};
//多继承
class D : public Base1, virtual public Base
{
public:
	D() : bs(0), Base(1), bs1(1, 2), Base1(1, 2)
	{
		cout << "D::D()" << endl;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
private:
	int m_x;
	int m_y;
	Base bs;
	Base1 bs1;
};
void main()
{
	//1 先按照继承的顺序构造父类
	//2 按照对象的顺序实例化对象成员
	//3 在构造子类
	D d;
}
/*
#include<iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		++m_count;
	}
	~Base()
	{
		--m_count;
	}
public:
	int GetCount()const
	{
		return m_count;
	}
public:
	void Increment()
	{
		m_count++;
	}
private:
	static int m_count; //用于统计对象的个数
};
int Base::m_count = 0;
class D : public Base
{
public:
	D()
	{}
public:

};
void main()
{
	D d;
	cout<<"object count = "<<d.GetCount()<<endl;
	{
		D d1;
		cout<<"object count = "<<d.GetCount()<<endl;
	}
	cout<<"object count = "<<d.GetCount()<<endl;
}
/*void main()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(D) << endl;   //1  //1  默认值
	D d; //开辟空间 1   8
}


/*
class Base
{
public:
	Base()
	{};
public:
	int Getcount()
	{
		return ++count;
	}
private:
	static int count;
};
int Base::count = 0;
class D :public Base
{
	D()
	{};
public:
	int getcount()const
	{
		return Base::Getcount();
	}
};
int main()
{
	D d;
	cout << "count =" << d.getcount << endl;

}
/*
//#define DISPLAY
class D;
class Base
{
	friend void PrintData(const Base& b, const D& d);
public:
#ifdef DISPLAY
	Base()
	{
		cout << "Base::Base()" << endl;
	}

	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
#endif
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
private:
	int m_a = 0;
	int m_b = 0;
};
class D :public Base//默认为私有继承
{
	friend void PrintData(const Base& b, const D& d);
#ifdef DISPLAY
public:
	D()
	{
		cout << "D::D()" << endl;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
#endif
public:
	void show()
	{
		cout << "D::show()" << endl;
	}
private:
	int m_x=0;
	int m_y=0;
};
void PrintData(const Base &b,const D &d)
{
	cout << b.m_a << ":" << b.m_b << endl;
	cout << d.m_x << ":" << d.m_y << endl;
}
void main() 
{
	D d;
	Base b;
	PrintData(b,d);

}*/
/*
class Person
{
public :
	Person(const char* name = "peter"): _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p): _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num): Person(name), _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s): Person(s), _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			
				_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
void main()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
/*
class Base 
{
public:
	Base() 
	{
		cout << "Base::Base()" << endl;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
private:
	int m_a=0;
	int m_b=0;
};
class D:public Base//默认为私有继承
{
public:
	D()
	{
		cout << "D::D()" << endl;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
private:
	int m_x;
	int m_y;
};
int main()
{
	Base b;
	D d;

	b = d;

	Base* pb = &d;
	Base& rb = d;
}*/