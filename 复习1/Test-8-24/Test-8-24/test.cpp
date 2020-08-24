#include<iostream>
#include<string>
using namespace std;
void main()
{
    string email = "2096136603@qq.com";
    string s = "jk9;";

   size_t pos = email.find_first_of(s);
   cout << "pos=" << pos << endl;

   pos = email.find_first_not_of(s);
   cout << "pos=" << pos << endl;

   pos = email.find_last_of(s);
   cout << "pos=" << pos << endl;

   pos = email.find_last_not_of(s);
   cout << "pos=" << pos << endl;
}
/*void main()
{
    string str = "dhjcksdcs;m sjkdk";
    string::iterator  it = str.begin();
    while (it != str.end())
    {
        cout << *it;
        ++it;
    }
    cout << endl;


    string::reverse_iterator  rit = str.rbegin();
    while (rit != str.rend())
    {
        cout << *rit;
        ++rit;
    }
}
/*void main()
{
    string email = "2096136603@qq.com";
    string email_type;

    size_t start_pos = email.find('@');
    size_t end_pos = email.find('.');

    email_type = email.substr(start_pos + 1, end_pos - start_pos - 1);
    cout << "email_type: " << email_type << endl;

}
// string::find
/*#include <iostream>       // std::cout
#include <string>         // std::string

int main()
{
    std::string str("There are two needles in this haystack with needles.");
    std::string str2("needle");

    // different member versions of find in the same order as above:
    std::size_t found = str.find(str2);
    if (found != std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';

    found = str.find("needles are small", found + 1, 6);
    if (found != std::string::npos)
        std::cout << "second 'needle' found at: " << found << '\n';

    found = str.find("haystack");
    if (found != std::string::npos)
        std::cout << "'haystack' also found at: " << found << '\n';

    found = str.find('.');
    if (found != std::string::npos)
        std::cout << "Period found at: " << found << '\n';

    // let's replace the first needle:
    str.replace(str.find(str2), str2.length(), "preposition");
    std::cout << str << '\n';

    return 0;
}*/
/*
void main()
{
	string email = "2096136603@qq.com";
	size_t pos = email.find('3');
	if (pos != string::npos)
	{
		cout << "pos=" << pos << endl;
	}
    pos = email.rfind('3');
    if (pos != string::npos)
    {
        cout << "pos=" << pos << endl;
    }
}
/*
void  main()
{
	string str1 = "qwe";
	string str2 = "qwe";

	 char s1[] = "qwe";
     char s2[] = "qwe";
}*/