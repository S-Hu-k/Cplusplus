
#include<iostream>
#include<stdio.h>
#include<time.h>
#include"datetime.h"
using namespace std;

void main()
{
	CDateTime dt;
	//cout<<dt<<endl;
	dt.DShowDateTime();
	//dt1 = dt + 100
}
 


/*
class List;
class ListNode
{
	class List;
public:
	ListNode():m_data(0),next(nullptr)
	{}
	ListNode(int data ,ListNode *n=nullptr)
	{}
	~ListNode()
	{}
private:
	int m_data;
	ListNode* next;
};
class List
{
public:
	List():head(nullptr)
	{}
private:
	ListNode* head;
};
void main()
{
	List mylist;
}
/*
class Test
{
	friend ostream& operator<<(ostream& out, const Test& t);
public:
	explicit Test(int data = 0) :m_data(data)//只能用在构造函数中
	{
		m_count++;
	}
	Test& operator=(const Test& t)
	{
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		 m_count--;
	}
public:
	void Increment_Count()
	{
		m_count++;
	}
public://让对象强转
	operator int()
	{
		return m_data;
	}
public:
	 int GetUseCount()const
	{
		return m_count;
	}
private:
//public:
	int m_data;
	static int m_count;//静态 大家共享的 
};
///////////////////////////////////////////////
int Test::m_count = 0;
////////////////////////////////////////////
ostream& operator<<(ostream& out, const Test& t)
{
	out << t.m_data;
	return out;
}
void main()
{

}
/*
void main()
{

	
	Test t1;
	Test t2;

	cout << t1.GetUseCount() << endl;
	{
		Test t3;
		cout << t1.GetUseCount() << endl;
	}
		

	
	cout << t1.GetUseCount() << endl;

	//cout << t2.GetUseCount() << endl;

	//t1.Increment_Count();
	//t2.Increment_Count();
}
/*
void main()
{
	Test t1;
	Test t2;
	t1.Increment_Count();
	t2.Increment_Count();
}

//explicit  显式  不允许发生隐式转换 //只能用在构造函数中

/*
class Test
{
	friend ostream& operator<<(ostream& out, const Test& t);
public:
	explicit Test(int data = 0) :m_data(data)//只能用在构造函数中
	{
		
	}
	Test & operator=(const Test & t)
	{
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{}
public:
	void Increment_Count()
	{
		m_count++;
	}
public://让对象强转
	operator int()
	{
		return m_data;
	}
private:
	int m_data;
	static int m_count;
};
///////////////////////////////////////////////
int Test::m_count = 0;
////////////////////////////////////////////
ostream& operator<<(ostream& out, const Test& t)
{
	out << t.m_data;
	return out;
}

void main()
{
	Test t1;
	Test t2;
	t1.Increment_Count();
	t2.Increment_Count();
}



/*
class Test
{
	friend ostream& operator<<(ostream& out, const Test& t);
public:
explicit Test(int data=0):m_data(data) /   /只能用在构造函数中
	{

	}
	Test& operator=(const Test& t)
	{
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{}
public://让对象强转
	operator int ()
	{
		return m_data;
	}
private:
	int m_data;

};
ostream& operator<<(ostream& out, const Test& t)
{
	out << t.m_data;
	return out;
}
void main()
{
	Test t;
	cout << "t=" << t << endl;
	t =(Test)100;
	cout << "t=" << t << endl;
	int value = (int)t;
	cout << t << endl;
}




/*
class Test
{
public:
	Test(int value,int count,int data):m_value(value),m_count(count),m_data(data)
	{}
	~Test()
	{}
private:
	int m_value;
	int m_count;
	int m_data;

};
void main()
{
	Test t(0, 0, 00);
}
/*
class Base
{
public:
	Base(int x,int y):a(x),b(y)
	{}

private:
	int a;
	int b;
	
};
class Test
{
public:
	Test(int data) :m_data(1),ref(data),count(0),base(1,2)
	{}
private:
	int m_data;
	const int& ref;
	const int count;
	Base base;
};
void main()
{
	Test t(10);
	
}


/*
void main()
{
	cout << "skjasnlC" << endl;
}

/*



class Int

{

	//friend ostream& operator<<(ostream& out, const Complex& c)

	//friend  void Print (const Int& c);

	friend ostream& operator<<(ostream& out, const Int& x);

	friend istream& operator>>(istream& in, Int& x);

public:

	Int(int i = 0) : m_i(i)

	{}

	~Int()

	{}

public:

	int Getvalue()const

	{

		return m_i;

	}

public:

	bool operator==(const Int& x);

	bool operator!=(const Int& x);

	bool operator>(const Int& x);

	bool operator<=(const Int& x);

	bool operator<(const Int& x);

	bool operator>=(const Int& x);



private:

	int m_i;

};
ostream& operator<<(ostream& out, const Int& x)
{
	out << x.m_i;
	return out;
}
istream& operator>>(istream& in, Int& x)
{
	in >> x.m_i;
	return in;
}
void main()
{
	Int i = 0;
}
*/