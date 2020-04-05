#include<iostream>
using namespace std;
class A
{
public:
	void eat()
	{
		cout << "A::eat()" << endl;
	}
	void foot()
	{
		cout << "A::foot()" << endl;
	}
	void sleep()
	{
		cout << "A::sleep()" << endl;
	}
};
class dog :public A
{
	void eat()
	{
		cout << "dog::eat()" << endl;
	}
	void foot()
	{
		cout << "dog::foot()" << endl;
	}
	void sleep()
	{
		cout << "dog::sleep()" << endl;
	}
};
class pig :public A
{
	void eat()
	{
		cout << "pig::eat()" << endl;
	}
	void foot()
	{
		cout << "pig::foot()" << endl;
	}
	void sleep()
	{
		cout << "pig::sleep()" << endl;
	}
};
void active(A* pb)
{
	pb->eat();
	pb->foot();
	pb->sleep();
}
int main()
{
	A a;
	dog dog;
	pig pig;
}