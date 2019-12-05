#include<iostream>
using namespace std;




class Test
{
	friend ostream& operator<<(ostream& out, const Test& t);
public:
	explicit Test(int data = 0) :m_data(data), m_count(0)//只能用在构造函数中
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