/*
#include<iostream>
#include<vector>
using namespace std;
int reOrderArray(vector<int>& array)
{
    vector<int> v;
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] % 2 == 1)
        {
            v.push_back(array[i]);
        }
    }
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] % 2 == 0)
        {
            v.push_back(array[i]);
        }
    }
    array = v;
}
int main()
{
    vector<int> array = { 2,5,6,3 };
    cout << reOrderArray(array) << endl;
}
/*
#include<iostream>
#include<vector>
using namespace std;
int reOrderArray(vector<int>& array)
{
    vector<int> v;
    vector<int> v1;
    int j = 0;
    int count = 0;
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] % 2 == 1)
        {
            count++;
            v[i] = array[i];
        }
        for (int j = 0; j < array.size(); j++)
        {
            v1[j] = v[i];
        }
        if (array[i] % 2 == 0)
        {
            v[i] = array[i];
        }
        for (int j = count; j < array.size(); j++)
        {
            v1[j] = v[i];
        }
        return v1[j];
    }
}
int main()
{
    vector<int> array = { 2,5,6,3 };
    cout << reOrderArray(array) << endl;
}
/*
#include<iostream>
using namespace std;
double Power(double base, int exponent)
{ 
    if (exponent == 0) 
{ 
        return 1;
}     
if (exponent == 1)
{ 
    return base;
}        
double sum = 1.0;  
int exp = abs(exponent); 
while (exp)
{ 
    sum *= base;    
--exp;
}      
double result = 0.0;   
if (exponent > 0) 
{ 
    result = sum;
} 
else
{ 
    result = 1 / sum; 
}     
return result; 
}
int main()
{
    cout << Power(2, 6) << endl;
}


#include<iostream>
using namespace std;
double Power(double base, int exponent)
{
    if (base == 0.0)
    {
        return 0;
    }
    if (exponent == 1)
    {
        return base;
    }
    double cun = 1.0;
    int exp = abs(exponent);
    double result = 0.0;
    while (exp)
    {
        cun *= base;
       --exp;
    }
    if (exponent > 0)
    {
        result = cun;
    }
    else
    {
        result = 1 / cun;
    }
    return result;
  
}
int main()
{
    cout << Power(2,3) << endl;

}*/