//һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)��
//���һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
//���磺��������������ĺ����� {
//    1, 1, 2, 3
//}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��, ���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ�
//���������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�


/*
#include<iostream>
#include<algorithm>
using namespace std;
int n;int *x=NULL;
int count(int pos,int add,long long  mul)
{
    int num=0;  
    for(int i=pos;i<n;++i)  
    {  
        add+=x[i];      
        mul*=x[i];          
        if(add>mul)        
            num+=1+count(i+1,add,mul);      
        else if(x[i]==1)         
            num+=count(i+1,add,mul);     
        else         
            break;        
        add-=x[i];   
        mul/=x[i];        
        while(x[i+1]==x[i] && i+1<n)   
        {         
            ++i;    
        } 
    }  
    return num;
} 
int main()
{ 
        cin>>n;   
        x=new int [n];  
        int add=0;          
        //��    
        long long mul=1;      //��    
        for(int i=0;i<n;++i)   
        {       
            cin>>x[i]; 
        }        
        sort(x,x+n); 
        int num=count(0,add,mul);   
        cout<<num; 
        if(x!=NULL)    
        {        
            delete []x;    
            x=NULL;  
        }  
        return 0;
}

//������������ڣ���������һ��ĵڼ���

/*
#include<iostream>
using namespace std;
class Solution
{
public:
    int fun(int year, int month, int day)
    {
        int Month1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
        int Month2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int count = 0;
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        {
            if (year < 0 || month < 1 || day < 1 || month>12 || day<1 || day>Month1[month - 1])
            {
                return -1;
            }    
            for (int i = 0; i < month - 1; ++i)
            {//ѭ����Ӹ��������·�֮ǰ�������·�����֮��    	
                count += Month1[i];
            }
        }
        else
        {
            if (year < 0 || month < 1 || day < 1 || month>12 || day<1 || day>Month2[month - 1])
            {
                return -1;
            }
            for (int i = 0; i < month - 1; ++i)
            {//ѭ����Ӹ��������·�֮ǰ�������·�����֮��    	
                count += Month2[i];
            }
        }
        count += day;//���ϻ�������һ�µ�����   
        return count;
    }
};
int main()
{
    int year, month, day;
    Solution p;
    while (cin >> year >> month >> day)
    {
        cout << p.fun(year, month, day) << endl;
    }
    system("pause");
    return 0;
}

/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ccstring1[] = "is page fault??";
	char ccstring2[] = "no page fault??";
	strcpy(ccstring1, "no");
	if (strcmp(ccstring1, ccstring2) == 0)
		cout << ccstring2;
	else
		cout << ccstring1;
}*/