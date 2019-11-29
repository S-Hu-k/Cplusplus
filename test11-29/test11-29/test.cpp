#include<iostream>
using namespace std;
//常方法的const怎么 了
//getdate与getdate()const 能否共存
//拷贝构造函数的const 加与不加有啥区别

#include<iostream>

#include<stdio.h>

//#include"fun.h"

using namespace std;

// 1 常方法的const 怎么了
// 2 GetData() 与 GetData()const 能否共存
// 3 拷贝构造函数的const 
// 4 赋值语句 
//   Test& operator=(const Test &t
//   void  operator=(Test t)

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
	*/
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
	*/
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
	
}*/