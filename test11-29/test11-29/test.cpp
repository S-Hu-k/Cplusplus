#include<iostream>
using namespace std;
#include<iostream>
#include<stdio.h>
//#include"fun.h"
using namespace std;
//���� ���쿽��  ���� ���� 
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

*/


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
	*/
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
	*/
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
	
}*/