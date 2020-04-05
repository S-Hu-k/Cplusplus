
#include<iostream>
#include<string>
#include<vector>
#include"test.h"
using namespace std;

void JudgeScoreByLenth(string pPasswordStr)
{
	int ScoreByLenth = 0;
	int len = pPasswordStr.size();
	if (len <= 4)
		ScoreByLenth = 5;
	if (len > 5 && len <= 7)
		ScoreByLenth = 10;
	if (len >= 8)
		ScoreByLenth = 25;

}
void JudgeScoreByLetter(string pPasswordStr)
{
	int ScoreByLetter = 0;
	int SLetter = 0, BLetter = 0;
	for (int i = 0; i < pPasswordStr.size(); ++i)
	{
		if (pPasswordStr[i] >= 'a' && pPasswordStr[i] <= 'z')
			SLetter = 1;
		if (pPasswordStr[i] >= 'A' && pPasswordStr[i] <= 'Z')
			BLetter = 1;
	}
	if ((SLetter == 1 && BLetter == 0) || (SLetter == 0 && BLetter == 1))
	{
		ScoreByLetter = 10;
	}
	if (SLetter == 1 && BLetter == 1)
	{
		ScoreByLetter = 20;
	}
	
}

void JudgeScoreByNumber(string pPasswordStr)
{
	int count = 0;
	int ScoreByNumber = 0;
	for (int i = 0; i < pPasswordStr.size(); ++i)
	{
		if(isdigit(pPasswordStr[i]))
		{
			count++;
		}
	}
	if (count > 1)
		ScoreByNumber = 20;
	if (count == 1)
		ScoreByNumber = 10;

}
void JudgeScoreBySingle(string pPasswordStr)
{
	int count = 0;
	int ScoreBySingle = 0;
	for (int i = 0; i < pPasswordStr.size(); ++i)
	{
		if ((pPasswordStr[i] >= 33 && pPasswordStr[i] <= 47)
			|| pPasswordStr[i] >= 58 && pPasswordStr[i] <= 64)
		{
			count++;
		}
	}
	if (count >1)
		ScoreBySingle = 25;
	if (count == 1)
		ScoreBySingle = 10;
}
//void JudgeScoreByEncourage(string pPasswordStr)
//{
//	if ()
//	{
//
//	}
//}

int main()
{
	string pPasswordStr;
	while (getline(cin, pPasswordStr))
	{

	}
}



/*
#include <iostream>
#include <string>
using namespace std;
int main()
{   
	string password;   
	while(getline(cin,password))  
	{      
		int score=0;        //���볤�ȵ÷�   
		if(password.size()<=4)
		{    
			score+=5;    
		}
		else if(password.size()>=8)
		{   
			score+=25;      
		}
		else
		{      
			score+=10;      
		}       
		//��ĸ�����֡�����ͳ��  
		int Alpha=0,alpha=0,number=0,number_count=0,ch=0,ch_count=0;    
		for(int i=0;i<password.size();i++)    
		{      
			if(password[i]>='a' && password[i]<='z')
			{     
				alpha=1;        
			}
			else if(password[i]>='A' && password[i]<='Z')
			{            
				Alpha=1;         
			}
			else if(isdigit(password[i]))
			{   
					number=1;         
					number_count++;      
			}
			else
			{       
				ch=1;     
				ch_count++;      
			}                    
		}       
		//��ĸ�÷�       
		if((alpha==1&&Alpha==0) || (alpha==0&&Alpha==1))
		{          
			score+=10;      
		}
		else if(alpha==1 && Alpha==1)
		{          
			score+=20;     
		}     
		//���ֵ÷�    
		if(number_count>1)
		{       
			score+=20;        }
		else if(number)
		{    
				score+=10;      
		}       
		//���ŵ÷�     
		if(ch_count>1)
		{        
			score+=25; 
		}
		else if(ch)
		{   
			score+=10;   
		}       
		//�����÷�     
		if(Alpha && alpha && number && ch)
		{   
			score+=5;      
		}
		else if((Alpha||alpha)&& number && ch)
		{    
			score+=3;       
		}
		else if((Alpha||alpha)&& number)
		{    
			score+=2;    
		}     
		if(score>=90)
		{ 
			cout<<"VERY_SECURE"<<endl;     
		}
		else if(score>=80)
		{         
			cout<<"SECURE"<<endl;    
		}else if(score>=70)
		{     
			cout<<"VERY_STRONG"<<endl;    
		}else if(score>=60)
		{           
			cout<<"STRONG"<<endl;   
		}
		else if(score>=50)
		{  
			cout<<"AVERAGE"<<endl;      
		}
		else if(score>=25)
		{        
			cout<<"WEAK"<<endl;   
		}
else
		{     
			cout<<"VERY_WEAK"<<endl;    
		}   
	}   
	return 0;
}
*/


/*
#include<iostream>
#include<vector>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();//��ά���������(�����̵Ĵ�С)
		//����û����֮����row��
		for (int i = 0; i < row; i++)
		{
			int sum_row = 0;
			int sum_cow = 0;
			for (int j = 0; j < row; j++)
			{
				sum_row += board[i][j];
				sum_cow += board[j][i];
			}
			if (sum_row == row || sum_cow == row)//ֻҪ��һ�л�һ��֮����row,��˵�����Ӯ��
			{
				return true;
			}
		}
		int first = 0;
		int second = 0;
		for (int i = 0; i < row; i++)
		{
			first += board[i][i];
			second += board[i][row - 1 - i];
		}
		if (first == row || second == row)
		{
			return true;
		}
		//�����⣬˵��û��һ�����ܳɹ�����ʧ��
		return false;
	}
};
/*
bool is_win(const vector<vector<int>>& board)
{
	int row = board.size();//��ά���������(�����̵Ĵ�С)
	//����û����֮����row��
	for (int i = 0; i < row; i++)
	{
		int sum_row = 0;
		int sum_cow = 0;
		for (int j = 0; j < row; j++)
		{
			sum_row += board[i][j];
			sum_cow += board[j][i];
		}
		if (sum_row == row)//ֻҪ��һ��֮����row,��˵�����Ӯ��
		{
			return true;
		}
		if (sum_cow == row)//ֻҪ��һ��֮����row,��˵�����Ӯ��
		{
			return true;
		}
	}
	int first = 0;
	int second = 0;
	for (int i = 0; i < row; i++)
	{
		first += board[i][i];
		second += board[i][row - 1 - i];
	}
	if (first == row)
	{
		return true;
	}
	if (second == row)
	{
		return true;
	}
	//�����⣬˵��û��һ�����ܳɹ�����ʧ��
	return false;
}

/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}
*/