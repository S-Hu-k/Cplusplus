#include<iostream>
using namespace std;//�����ռ�

/*

class Test
{
public:
	Test(int data)
	{
		cout << "Create Test Object:" << this << endl;
		m_data = data;
	}
	//��������
	Test(const Test &t)//����&  �������ѭ��
	{
		cout << "Copy Creat Test Object:" << this << endl;
	}
	//��ֵ���
	Test& operator=(const Test &t)
	{
		cout << "Assign," << this << "=" << &t << endl;
	}
	//��������  �������� �������з���ֵ
	~Test()
	{
		cout << "Free Test Object  :" << this<<endl;
	}
private:
	int m_data;
};
void main()
{
	Test t(19);
	Test t1=t;
	//Test t2(t1);
	//Test t2;
	//t2 = t1;
}



/*
class Test
	//1.���캯�� ���ֱ���������ͬ
	//2.���캯���������з���ֵ
	//3.���캯����������
{
public:
	Test()//Ĭ�Ϲ��캯��
	{
		cout << "Create Test Object." << endl;
	}
	Test(int data)
	{
		cout << "Create Test(int) Object." << endl;
		m_data = data;
	}
	Test(int data, int value)
	{
		cout << "Create Test(int ,int) Object." << endl;
		m_data = data;
		m_value = value;
	}
private:
	int m_data;
	int m_value;

};
void main()
{
	Test t;

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
	//A* p = NULL;
	A a;
	A *p = &a;
	p->PrintA();
	p->Show();
}
/*
class CGood
{
	//this ��Ա�����Ĳ��� ���˺��� this��������
public:
	void RegsterGoods(char *name, int count, float price)
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
	char *GetName()
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
	CGood c1;
	//RegsterGoods��&c1,"cbsah", 23, 666666)
	c1.RegsterGoods("cbsah", 23, 666666);
	cout << c1.GetName() << endl;//���������ʱ ����thisָ��//
	c1.SetName("skjka");
	cout << c1.GetName() << endl;


}

class Test
{
public:
	//void SetData(Test *const this)
	void SetData(int data = 0)
	{
		this->m_data = data;
	}
	int Getdata(int data)
	{
		return this->m_data;
	}
	void Setvalue(int value = 0)
	{
	 this->m_value = value;
	}

	int Getvalue()
	{
		return this->m_value;
	}
public:
	void ShowData()
	{
		//cout << "data=" << m_data << endl;
		//cout << "data=" << m_value << endl;
		//printf("m_data=%d m_value=%d", m_data, m_value);
	}
public:
	int m_data;
	int m_value;
};
void main()
{
	cout << sizeof(Test) << endl;//��Сֻ�����ݳ�Ա�й�ϵ
}

void main()
{
Test t1, t2;
t1.SetData(1);
t1.Setvalue(2);
t2.SetData(10);
t2.Setvalue(20);
cout << "t1 data=" << t1.ShowData() << endl;
cout << "t2 data=" << t2.ShowData() << endl;
}

void main()
{
Test t;//ʵ��������
t.m_data = 10;
t.SetData(10);
//int value = t.Getdata(10);
cout << "t=" <<value<< endl;//
t.ShowData();
}*/



/*
class Test
{
public:

//���캯�� �Զ�
Test(int data=0)
{
cout << "Creat online." << this<<endl;
m_data = data;
}
//��������
Test(const Test &t)




{
cout << "sdhjfshoisd." << this << endl;
m_data = t.m_data;
}
//��������  �����з���ֵ һ������ֻ��һ����������(ջ��
~Test()
{
cout << "free test object." << this << endl;
}
private:
int m_data;
};

void main()
{
Test t(10);
Test t1(100);
Test t2(1000);
Test t9= t;
Test t10(t9);
}
/*
class Test
{
public:

//���캯�� �Զ�
Test()//Ĭ�Ϲ��캯��
{
cout << "Creat online." << endl;
}
};

void main()
{
Test f1;
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
cout << c1.GetName()<< endl;

}

/*
//����Ӧ�ñ�¶����
class CGood
{
public:
void Register(char *n, int c, float p);
private:
char name[10];
};

void main()
{

}

/*
class Student
{
public://ʲô����д Ĭ��Ϊ˽��
char name[10];//���ݳ�Ա  ��Ա����
private:
char sex[3];
int age;
protected:
int height;
int weight;
};
void main()
{
Student s;//ʵ��������

}
/*
void main()
{
int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int n = sizeof(ar) / sizeof(int);
for (int i = 0; i < n; ++i)
cout << ar[i] << " ";
cout << endl;

for (auto &ele : ar)
{

//ele = 11;
cout << ele << " ";
}
cout<< endl;
}
/*
class Base {};
class Derived : public Base {};

void main()
{
Base b, *pb;
pb = NULL;
Derived d;

cout << typeid(int).name() << endl
<< typeid(unsigned).name() << endl
<< typeid(long).name() << endl
<< typeid(unsigned long).name() << endl
<< typeid(char).name() << endl
<< typeid(unsigned char).name() << endl
<< typeid(float).name() << endl
<< typeid(double).name() << endl
<< typeid(string).name() << endl
<< typeid(Base).name() << endl
<< typeid(b).name() << endl
<< typeid(pb).name() << endl
<< typeid(Derived).name() << endl
<< typeid(d).name() << endl
<< typeid(type_info).name() << endl;
}
/*
inline int  fun(int a, int b)
{
return a + b;
}
void main()
{
int value = fun(10, 20);
cout << value<< endl;
}
/*
int fun(int a = 0, int b = 0)
{
return a + b;
}
void main()


{
cout << "hello bit." << endl;




cout << fun(12,586565) << endl;
}*/