//一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
//如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
//例如：如果袋子里面的球的号码是 {
//    1, 1, 2, 3
//}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//你可以适当从袋子里移除一些球(可以移除0个, 但是别移除完)，要使移除后的袋子是幸运的。
//现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。


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
        //和    
        long long mul=1;      //积    
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

//根据输入的日期，计算是这一年的第几天

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
            {//循环相加该天所在月份之前的所有月份天数之和    	
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
            {//循环相加该天所在月份之前的所有月份天数之和    	
                count += Month2[i];
            }
        }
        count += day;//加上还不到整一月的天数   
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