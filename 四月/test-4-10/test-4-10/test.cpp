/*
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> v;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		return v;
	}

};
/*
#include<iostream>
using namespace std;
class Person
{
public:    
	void Print() 
	{ 
		cout << _name << endl; 
	} 
protected: 
	string _name; // ���� 
private :    
	int _age ;   // ����
};

//class Student : protected Person 
//class Student : private Person 
class Student :public Person 
{ 
protected :  
	int _stunum ; // ѧ�� 
};

/*
#include<iostream>
using namespace std;
class Person 
{
public:
	void Print()
	{
	cout << "name:" << _name << endl;   
	cout << "age:" << _age << endl;
	} 
protected:  
	string _name = "peter"; // ����   
	int _age = 18;  // ���� 
};

// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡�
//�������ֳ���Student�� Teacher������Person�ĳ�Ա��
//��������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
//����Print���Կ�����Ա�����ĸ��á�
class Student : public Person 
{
protected:
	// Student�����࣬Ҳ���������ࡣ
		//  1.2.2�̳й�ϵ�ͷ����޶���
		//  1.2.3�̳л����Ա���ʷ�ʽ�ı仯
   int _stuid; // ѧ��
};
class Teacher : public Person 
{
	protected:    int _jobid; // ���� 
};
int main() 
{
	Student s;   
	Teacher t;  
	s.Print();  
	t.Print();
	return 0;
}



/*
#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A::A()"<<endl;
	}
	~A()
	{
		cout << "A::~A()" << endl;
	}

private:
	int m_a;
};
class B :public A
{
public:
	B()
	{
		cout << "B::B()" << endl;
	}
	~B()
	{
		cout << "B::~B()" << endl;
	}

private:
	int m_x;
};
int main()
{
	A a;
	B b;
	//��ֵ���ݹ���
	a = b;//������Ը����ำֵ
	A* p = &b;//����������ĵ�ַ������� ָ�븳ֵ
	A& rp = b;//����ʹ���������Ϊ��������ý��г�ʼ��

}*/