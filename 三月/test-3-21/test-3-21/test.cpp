
#include<iostream>
#include<string>
using namespace std;
bool Judge_str(const string& str1, const string& str2)
{
    int i = 0;
    int j = 0;
    bool flag = false;
    while (str1[i] || str2[j])
    {
        if ((str1[i] == str2[j]) || str1[i] == '?')
        {
            i++;
            j++;
        }
        else if (str1[i] == '*')
        {
            i++;
            flag = true;
        }
        else if (flag)
        {
            while (str2[j] != str1[i])
                j++;
            flag = false;
        }
        else
            return false;
    }
    if (str1[i] == '\0' && str2[j] == '\0')
        return true;
    else
        return false;
}
int main()
{
    string str1;
    string str2;
    while (getline(cin, str1))
    {
        getline(cin, str2);
        if (Judge_str(str1, str2))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}


/*
#include<iostream>
using namespace std;
 int getTotalCount(int mouthCount)
{
	 if (mouthCount < 3)
		 return 1;
	 else
		 return getTotalCount(mouthCount - 1) + getTotalCount(mouthCount - 2);

}
int main()
{
	int mouth;
	cin >> mouth;
	cout << getTotalCount(mouth) << endl;
}


/*
#include<iostream>
using namespace std;
class A
{
public:
	void print()
	{
		cout << "A:print()";
	}
};
class B :private A
{
public:
	void print()
	{
		cout << "B:print()";
	}

};
class C :public B
{
public:
	void print()
	{
		cout << A:print();
	}
};
int main()
{
	C b;
	b.print();
}
/*
int main()
{
	char a[] = "programming", b[] = "language";
	char* p1, * p2;
	int i;
	p1 = a, p2 = b;
	for (i = 0; i < 7; i++)
		if (*(p1 + i) == *(p2 + i))
			printf("%c", *(p1 + i));
}*/