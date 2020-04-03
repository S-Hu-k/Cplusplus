
#include<iostream>
using namespace std;
class A
{
public:
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual void foot() = 0;
};
class dog :public A
{
	virtual void eat()
	{
		cout << "dog::eat()" << endl;
	}
	virtual void foot()
	{
		cout << "dog::foot()" << endl;
	}
	virtual void sleep()
	{
		cout << "dog::sleep()" << endl;
	}

};
void active(A* pa)
{
	pa->eat();
	pa->foot();
	pa->sleep();
}
void main()
{
	dog d;
	active(&d);
}
/*
class A
{
public:
	virtual void Eat(int a, double b)
	{
		cout << "A::Eat()" << endl;
	}
	virtual void Foot()
	{
		cout << "A::Foot()" << endl;
	}
	virtual void Sleep()
	{
		cout << "A::Sleep()" << endl;
	}
};
class Dog : public A
{
public:
	void Eat(int x, double y)
	{
		cout << "Dog::Eat()" << endl;
	}
	void Foot()
	{
		cout << "Dog::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "Dog::Sleep()" << endl;
	}
};
class Pig : public A
{
public:
	void Eat()
	{
		cout << "Pig::Eat()" << endl;
	}
	void Foot()
	{
		cout << "Pig::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "Pig::Sleep()" << endl;
	}
};
class Person : public A
{
public:
	void Eat()
	{
		cout << "Person::Eat()" << endl;
	}
	void Foot()
	{
		cout << "Person::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "Person::Sleep()" << endl;
	}
};
class Bird : public A
{
public:
	virtual void Eat()
	{
		cout << "Bird::Eat()" << endl;
	}
	virtual void Foot()
	{
		cout << "Bird::Foot()" << endl;
	}
	virtual void Sleep()
	{
		cout << "Bird::Sleep()" << endl;
	}
};
//////////////////////////////////////////////////////
//通用方法 -->
void Active(A* pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}
void main()
{
	Dog dog;
	Pig pig;
	Person per;
	Bird bird;
	Active(&dog);
	Active(&pig);
	Active(&per);
	Active(&bird);
}*/