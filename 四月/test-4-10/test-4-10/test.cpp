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
	string _name; // 姓名 
private :    
	int _age ;   // 年龄
};

//class Student : protected Person 
//class Student : private Person 
class Student :public Person 
{ 
protected :  
	int _stunum ; // 学号 
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
	string _name = "peter"; // 姓名   
	int _age = 18;  // 年龄 
};

// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。
//这里体现出了Student和 Teacher复用了Person的成员。
//下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
//调用Print可以看到成员函数的复用。
class Student : public Person 
{
protected:
	// Student是子类，也称作派生类。
		//  1.2.2继承关系和访问限定符
		//  1.2.3继承基类成员访问方式的变化
   int _stuid; // 学号
};
class Teacher : public Person 
{
	protected:    int _jobid; // 工号 
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
	//赋值兼容规则
	a = b;//子类可以给父类赋值
	A* p = &b;//可以用子类的地址给父类的 指针赋值
	A& rp = b;//可以使用子类对象为父类的引用进行初始化

}*/