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