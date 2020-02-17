
#include<iostream>
#include<string>
using namespace std;
int main()
{

    string str;
    while (getline(cin, str))
    {
        unsigned int i;
        for (i = 0; i < str.size(); i++)
        {
            if (str.find(str[i]) == str.rfind(str[i]))
            {
                cout << str[i] << endl;
                break;
            }
        }
        if (i == str.size())
            cout << -1 << endl;
    }
    return 0;
}

/*#include<iostream>
#include<string>
using namespace std;

void main()
{
    string str;
    for (int i = 0; i < str.size(); ++i)
    {
        char index_1 = str.find("str[i]");
        char index_2 = str.rfind("str[i]");
        int ret = strcmp(index_1, index_2);
        if (ret == 1)
            printf("%c", str[i]);
        else
            printf("%d", -1);
    }
}*/