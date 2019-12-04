#include<iostream>
using namespace std;

class Int
{
	//friend ostream& operator<<(ostream& out, const Complex& c)
	friend  void Print (const Int& c);
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
	Int operator+(const Int& x)
	{
		return Int(m_i + x.m_i);
	}
	Int operator-(const Int& x)
	{
		return Int(m_i - x.m_i);
	}
	Int operator*(const Int& x)
	{
		return Int(m_i * x.m_i);
	}
	Int operator/(const Int& x)
	{
		return Int(m_i / x.m_i);
	}
	Int operator%(const Int& x)
	{
		return Int(m_i % x.m_i);
	}
public:
	//a+=b
	Int& operator+=(const Int& x)
	{
		Int tmp(m_i + x.m_i);
		return tmp;
	}
	Int& operator-=(const Int& x)
	{
		Int tmp(m_i - x.m_i);
		return tmp;
	}
	Int& operator*=(const Int& x)
	{
		Int tmp(m_i * x.m_i);
		return tmp;
	}
	Int& operator/=(const Int& x)
	{
		Int tmp(m_i / x.m_i);
		return tmp;
	}
	Int& operator%=(const Int& x)
	{
		Int tmp(m_i % x.m_i);
		return tmp;
	}
public:
	Int& operator++()
	{
		m_i++;
		return *this;
	}
	Int operator++(int)
	{
		/*Int tmp(m_i);
		m_i++;
		return tmp;*/
		Int tmp(*this);
		++* this;
		return tmp;
	}
	Int& operator--()
	{
		m_i--;
		return *this;
	}
	Int operator--(int)
	{
		Int tmp(m_i);
		m_i--;
		return tmp;
	}
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
	Int v = i++;


	cout << "v=" << v << endl;
	cout << "i=" << i << endl;
}
/*
void main()
{
	Int i3;
	Int i1 = 5;
	Int i2 = 2;
	i3 = i1 %=i2;
	cout << "i3="<<i3 << endl;
	//Int v = i++;
	//cout << i << endl;
	//Int i;
	//cin >> i;
	//cout << i << endl;
}
/*
class Complex
{
	//friend void Print(const Complex& c);//友元函数 ： 希望函数的参数对象可以直接访问类的私有数据
	friend ostream& operator<<(ostream& out, const Complex& c);//有元不是成员  没有this指针
	friend Complex operator+ (int x, const Complex & c);
public:
	Complex(int real = 0, int imag = 0) :m_real(real), m_imag(imag)
	{}
	~Complex()
	{}
public:
	int Getreal()const
	{
		return m_real;
	}
	int Getimag()const
	{
		return m_imag;
	}
public:
	Complex operator+(const Complex& c)
	{
		Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		return tmp;
		//无名临时对象的语法
		//return Complex(m_real + c.m_real, m_imag + c.m_imag);
	}
	Complex operator-(const Complex& c)
	{
		Complex tmp(m_real - c.m_real, m_imag - c.m_imag);
		return tmp;
		//无名临时对象的语法
		//return Complex(m_real + c.m_real, m_imag + c.m_imag);
	}
	Complex operator+(int x)
	{
		Complex tmp(m_real + x, m_imag);
		return tmp;
	}
	Complex& operator+=(const Complex& c)
	{
		m_real += c.m_real;
		m_imag += c.m_imag;
		return *this;
	}
	
private:
	int m_real;
	int m_imag;
};
//ostream& operator<<(ostream& out, const Complex& c)
//{
//	out << "(" << c.Getreal() << ":" << c.Getimag() << ")"<<endl;
//	return out;
//}
ostream& operator<<(ostream& out, const Complex& c)
{
	out << "(" << c.Getreal() << ":" << c.Getimag() << ")" << endl;
	return out;
}
Complex operator+ (int x, const Complex& c)
{
	Complex tmp(c.m_real + x, c.m_imag);
	return tmp;

}
void main()
{
	Complex c1(1, 2);
	Complex c2(2, 3);
	//Print(c1);
	Complex c;
	c = c1 + c2;
	cout << c << endl;
	c1 += c2;
	cout << c1 << endl;
	Complex c3;
	c3 = c1 - c2;
	cout << c3 << endl;

	//+ 是一个函数  不能通过整数调动函数 必须通过对象调动
	Complex c4;
	c4 =  5+c1;
	cout << c4<< endl;
}
/*
void Print(const Complex& c)
{
	cout << "(" << c.Getreal() << ":" << c.Getimag() << ")" << endl;
}
void main()
{
	//Complex c1(1, 2);
	//Complex c2(2, 3);
	//Print(c1);
	int a = 10;
	char ch = 'F';
	cout << a << endl;
	cout << ch << endl;
}

/*
class Complex;
	void Print(const Complex& c);

class Complex
{
	friend void Print(const Complex &c);//友元函数 ： 希望函数的参数对象可以直接访问类的私有数据
public:
	Complex(int real=0,int imag=0):m_real(real),m_imag(imag)
	{}
	~Complex()
	{}
public:
	int Getreal()const
	{return m_real;}
	int Getimag()const
	{return m_imag;}
private:
	int m_real;
	int m_imag;
};
void Print(const Complex& c)
{
	cout << "("<<c.Getreal() << ":" << c.Getimag() <<")"<< endl;
}
void main()
{
	Complex c1(1, 2);
	Complex c2(2, 3);
	Print(c1);
}


/*
void main()
{
	cout << "sjhcjksa" << endl;
}
*/