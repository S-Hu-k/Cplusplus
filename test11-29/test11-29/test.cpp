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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
		//��˼������ļ������⣺
			//1. const������Ե��÷�const��Ա������
			//2. ��const������Ե���const��Ա������
			//3. const��Ա�����ڿ��Ե��������ķ�const��Ա������
			//4. ��const��Ա�����ڿ��Ե���������const��Ա������
			//8.ȡ��ַ��constȡ��ַ����������
			//������Ĭ�ϳ�Ա����һ�㲻�����¶��� ��������Ĭ�ϻ����ɡ�
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
	// ����d2���õ�Ĭ�Ͽ���������ɿ�����d2��d1��ֵҲ��һ���ġ�
	cout<<"Date d2(d1)"<<endl;
}
/*
class Date
	//���������ô�ֵ ����ֵ�������ѭ��
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
		//3.��δ��ʾ���壬ϵͳ����Ĭ�ϵĿ������캯���� Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ�
			//�������ֿ������ǽ���ǳ����������ֵ������
			
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
	//���ڱ������Զ����ɵ������������Ƿ�����һЩ�����أ�����ĳ������ǻῴ�������������ɵ�
		//Ĭ�������������Ի��Զ����ͳ�Ա������������������
		~SeqList()
	{
			if (_pData)
			{
				free(_pData); // �ͷŶ��ϵĿռ�
				_pData = NULL; // ��ָ����Ϊ��
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
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
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
	//1.�޲ι��캯��
	Date()
	{}
	//2.���ι��캯��
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
	//���캯����Ҫ��Ϊ�˳�ʼ������
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
//���� ���쿽��  ���� ���� 
/*
class String
{
public:
	//String(const char *str = NULL);//��ָ��
	String(const char *str = "")//�ַ���
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




//1.���Ҹ�ֵ���
//2.�ͷŵ�ǰ����ռ�
//3.���¿��ٿռ䲢��ֵ
//4���ص�ǰ����





//Test& operator=(const Test &t)  ��������
// 1 ��������const ��ô��
//int GetData(Test *const this) const
//int GetData(const Test *const this) 
//����Ա������ʾ��Ա�������������thisָ��Ϊconstָ�룬�������ڸó�Ա�����У�
//�����޸������ڵ���ĳ�Ա�Ĳ������ǲ�����ģ���Ϊ�����˶�thisָ���const���ã���Ψһ�������Ƕ���mutable���εĳ�Ա��
// 2 GetData() �� GetData()const �ܷ񹲴�   ���Թ���
//const int getData()
//�����ķ���ֵ��const���Σ�������Ϊ��ֵ��
//�����������ͣ�����ֵ����ôʹ�ú���ûʲô���塣
//��Ϊ���ص�����ʱ��������ʱ�����Ѿ���const
//�������һ�����������ã���const����ȷ��������ֵ���ᱻֱ�Ӳ�����
//int getData() const
//�ú��������const��Ա����
//���ú��������޸�������ݳ�Ա
//������һ��const����ʱ��ֻ�ܵ���const��Ա������
//�Ա�֤������ݳ�Ա����ı䡣
// 3 �������캯����const 
//���������캯������const�����������ȵ���Fun1(������һ����ʱ����Ȼ���ø���ʱ�����ʼ��test
// 4 ��ֵ��� 
//   Test& operator=(const Test &t
//   void  operator=(Test t)
/*
class Test
{
public:
	//���캯��

	//Test t;
	Test(int data = 0)
	{
		cout << "Create Test Object:" << this << endl;
	m_data = data;
	}
	//�������캯��
	//�﷨Ҫ�� ����Ҫ��
	Test(Test &t)
	{
		cout << "Copy Create Test Object:" << this << endl;
		m_data = t.m_data;
	}
	//��ֵ���
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
	//�������� 
	//~t
    ~Test()
	{
		cout << "Free Test Object:" << this << endl;
	}
public:
	int GetData()const  //������
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
//���캯��  �Զ�
Test() //Ĭ�Ϲ��캯��
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
	CGood  c1;//ʵ��������
	c1.RegisterGoods("sjh", 23, 6);
	cout << c1.GetName() << endl;

}

/*
class student
{
public:
	//ʲô����д��Ĭ��Ϊ˽��
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
	student s;//ʵ��������
	
}
*/