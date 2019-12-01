#include<iostream>
using namespace std;
class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void main()
{
	Date d;
	d.operator&();



}







/*
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
		//请思考下面的几个问题：
			//1. const对象可以调用非const成员函数吗？
			//2. 非const对象可以调用const成员函数吗？
			//3. const成员函数内可以调用其它的非const成员函数吗？
			//4. 非const成员函数内可以调用其它的const成员函数吗？
			//8.取地址及const取地址操作符重载
			//这两个默认成员函数一般不用重新定义 ，编译器默认会生成。
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void main()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
}
/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "Assign," << this << "=" << &d<< endl;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
void main()
{
	Date d1;
	Date d2 ( d1);
}
/*
////////////////////////////////////////////////
#include<assert.h>
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2(s1);
}
/////////////////////////////////////////////////////
/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	// 这里d2调用的默认拷贝构造完成拷贝，d2和d1的值也是一样的。
	cout<<"Date d2(d1)"<<endl;
}
/*
class Date
	//拷贝函数得传值 不传值会造成死循环
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date( const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		//3.若未显示定义，系统生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷
			//贝，这种拷贝我们叫做浅拷贝，或者值拷贝。
			
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);
	
}
/*
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()"<<this << endl;
		free(_str);
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Person p;
	return 0;
}
/*
typedef int DataType;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	//关于编译器自动生成的析构函数，是否会完成一些事情呢？下面的程序我们会看到，编译器生成的
		//默认析构函数，对会自定类型成员调用它的析构函数。
		~SeqList()
	{
			if (_pData)
			{
				free(_pData); // 释放堆上的空间
				_pData = NULL; // 将指针置为空
				_capacity = 0;
				_size = 0;
			}
		}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};
/*
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}

/*
class Date
{
public:
	//Date()
	//{
	//	_year = 1900;
	//	_month = 1;
	//	_day = 1;
	//}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void main()
{
	Date d;
}

/*class Date
{
private:
	int _year;
	int _month;
	int _day;
};
void main()
{
	Date d2;
}

/*
class Date
{
public:
	//1.无参构造函数
	Date()
	{}
	//2.带参构造函数
	Date(int year, int mouth, int day)
	{
		_year = year;
		_mouth = mouth;
		_day = day;
	}
private:
	int _year;
	int _mouth;
	int _day;

};
void main()
{
	Date d1;
	Date d2(2015, 5, 4);
	Date d3();
}
/*
class Date
{
	//构造函数主要是为了初始化对象。
public:
	void SetDate(int year, int mouth, int day)
	{
		_year = year;
		_mouth = mouth;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _mouth << "-" << _day << endl;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
int main()
{
	Date d1, d2;
	d1.SetDate(2016, 5, 56);
	d1.Display();
}
//#include"fun.h"
//构造 构造拷贝  拷贝 析构 
/*
class String
{
public:
	//String(const char *str = NULL);//空指针
	String(const char *str = "")//字符串
	{

	}
private:
	char *m_data;
};
void main()
{
	[]
}
/*
class Test
{
public:
	Test()
	{
		m_data = 0;
	}
private:
	int m_data;
};
void main()
{
	Test t;
	Test t1 = t;

}




//1.自我赋值检测
//2.释放当前对象空间
//3.重新开辟空间并赋值
//4返回当前对象





//Test& operator=(const Test &t)  可以连等
// 1 常方法的const 怎么了
//int GetData(Test *const this) const
//int GetData(const Test *const this) 
//常成员函数表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，
//任意修改它所在的类的成员的操作都是不允许的（因为隐含了对this指针的const引用），唯一的例外是对于mutable修饰的成员。
// 2 GetData() 与 GetData()const 能否共存   可以共存
//const int getData()
//函数的返回值被const修饰，不能作为左值。
//对于内置类型，返回值，这么使用好像没什么意义。
//因为返回的是临时变量，临时变量已经是const
//如果返回一个类对象的引用，加const可以确保，返回值不会被直接操作。
//int getData() const
//该函数是类的const成员函数
//即该函数不会修改类的数据成员
//当定义一个const对象时，只能调用const成员函数，
//以保证类的数据成员不会改变。
// 3 拷贝构造函数的const 
//若拷贝构造函数不加const，编译器会先调用Fun1(）返回一个临时对象，然后用该临时对象初始化test
// 4 赋值语句 
//   Test& operator=(const Test &t
//   void  operator=(Test t)
/*
class Test
{
public:
	//构造函数

	//Test t;
	Test(int data = 0)
	{
		cout << "Create Test Object:" << this << endl;
	m_data = data;
	}
	//拷贝构造函数
	//语法要求 语义要求
	Test(Test &t)
	{
		cout << "Copy Create Test Object:" << this << endl;
		m_data = t.m_data;
	}
	//赋值语句
	/*
	Test& operator=(const Test &t)
	{
	cout<<"Assign,"<<this<< "="<<&t<<endl;
	if(this != &t)
{
	m_data = t.m_data;
	}
	return *this;
	}
	
/*
	void operator=(Test t)
	{
		cout << "Assign," << this << "=" << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
	}
	//析构函数 
	//~t
    ~Test()
	{
		cout << "Free Test Object:" << this << endl;
	}
public:
	int GetData()const  //常方法
	{
		return m_data;
	}
	/*
	int GetData()
	{
	return m_data
	}
	
/*
private:
	int m_data;
};

void main()
{
	Test t(10);   //  t
	Test t1 = t;  //  t1
	Test t2;
	t2 = t1;
}
/*
class Test
{
public:
//构造函数  自动
Test() //默认构造函数
{
cout<<"Create Test() Object."<<endl;
}
Test(int data)
{
cout<<"Create Test(int) Object."<<endl;
m_data = data;
}
Test(int data, int value)
{
cout<<"Create Test(int,int) Object."<<endl;
m_data = data;
m_value = value;
}
public:
void fun()

{}
private:
int m_data; //
int m_value;
};
void main()
{
Test t; //
Test t1(10);
Test t2(10,20);
}
/*
class A
{
public:
void PrintA()
{
cout << _a << endl;
}
void Show()
{
cout << "Show()" << endl;
}
private:
int _a;
};

int main()

{

A a;

//A* p = NULL;

A *p = &a;

p->PrintA();

p->Show();

}
/*
class CGood
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(this->name, name);
		this->count = count;
		this->price = price;

	}
	void SetName(char *name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
public:
	char* GetName()
	{
		return name;
	}
	int GetCount()
	{
		return count;
	}
	float GetPrice()
	{
		return price;
	}
	float GetTotalPrice()
	{
		return price*count;
	}
private:
	char name[10];
	int count;
	float price;
	float total_price;
};
void main()
{
	CGood  c1;//实例化对象
	c1.RegisterGoods("sjh", 23, 6);
	cout << c1.GetName() << endl;

}

/*
class student
{
public:
	//什么都不写，默认为私有
	void Regester(char *n, char *s, int a, int h, int w);
private:
	char name[10];
	char sex[3];
	int age;
	int height;
	int weight;
};
class CGood
{
public:
	void Register(char *n, int c, float p);
private:
	char name[10];
	int count;
	float price;
	float total_prive;
};
void student::Regester(char *n, char *s, int a, int h, int w)
{
	strcpy(name, n);
	strcpy(sex, s);
	age = a;
	height = h;
	weight = w;
}
void main()
{
	student s;//实例化对象
	
}
*/