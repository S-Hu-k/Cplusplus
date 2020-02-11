#include<iostream>
using namespace std;

class Date


	{
		friend ostream& operator<<(ostream& out, const Date& dt);
	public:
		Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
		Date& operator=(const Date& d);
		Date operator+(int days);

		Date operator-(int days);
		int operator-(const Date& d);
		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);
		bool operator>(const Date& d)const;
		bool operator>=(const Date& d)const;
		bool operator<(const Date& d)const;
		bool operator<=(const Date& d)const;
		bool operator==(const Date& d)const;
		bool operator!=(const Date& d)const;
	public:
		int GetWeek(int year, int month, int day);
	private:
		int _year;
		int _month;
		int _day;
	};

	///////////////////////////////////////////////////////////
	Date::Date(int year, int month, int day)
		:_year(year), _month(month), _day(day)
	{
		//_year = year;
		//_month = month;
		//_day = day;
	}
	Date::Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& Date::operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;

	}


	bool Date::operator==(const Date& d)const
	{
		return (_year == d._year && _month == d._month && _day == d._day);
	}
	bool Date::operator!=(const Date& d)const
	{
		//return _year!=d._year || _month!=d._month || _day=!d._day;
		return !(*this == d);
	}
	bool Date::operator>(const Date& d)const
	{
	if (_year > d._year)
			return true;
		else if (_year < d._year)
			return false;
		else if (_month > d._month)
		return true;
		else if (_month < d._month)
			return false;
		else if (_day > d._day)
			return true;
		return false;
	}
	bool Date::operator<=(const Date& d)const
	{
		return !(*this > d);
	}

	bool Date::operator<(const Date& d)const
	{
		if (_year < d._year)
			return true;
		else if (_year > d._year)
			return false;
		else if (_month < d._month)
		  return true;
		else if (_month > d._month)
			return false;
		else if (_day < d._day)
			return true;
		return false;
	}
	bool Date::operator>=(const Date& d)const
	{
		return !(*this < d);
	}
	ostream& operator<<(ostream& out, const Date& dt)
	{
		out << dt._year << "年" << dt._month << "月" << dt._day << "日";
		return out;
	}
	//////////////////////////////////////////////////////////
	bool IsLeap(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;
		return false;
	}
	int GetDayByYearMonth(int year, int month)
	{
		int days[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };//查表
		if (month == 2)
		{
			if (IsLeap(year))
				month = 0;
		}
		return days[month];
	}
	Date Date::operator+(int days)
	{
		Date tmp = *this;
		int mdays = GetDayByYearMonth(tmp._year, tmp._month);
		while (days + tmp._day > mdays)
		{
		tmp._month++;
			if (tmp._month > 12)
			{
				tmp._month = 1;
				tmp._year++;
			}
			days -= mdays;
			mdays = GetDayByYearMonth(tmp._year, tmp._month);
		}
		tmp._day += days;
		return tmp;
	}
	Date Date::operator-(int days)
	{
		//
	}
	//dt1 - dt2
	int Date::operator-(const Date& d)
	{
		//
	}
	int Date::GetWeek(int year, int month, int day)
	{
		//
	}

	Date& Date::operator++()
	{
		*this = *this + 1;
		return *this;
	}
	Date Date::operator++(int)
	{
		Date tmp = *this;
		++* this;
		return tmp;
	}





	///////////////////////////////////////////////////////////

	void main()
	{
		Date dt1(2019, 12, 9);
		cout << dt1 << endl;
		Date dt = dt1 - 20;
		cout << dt1 << endl;
	}
	/*
	void main()
	{
		Date dt1(2019,12,9);
		cout<<dt1<<endl;
		//Date dt = dt1 + 35;
		++dt1;  //dt1.operator++()
		dt1++;  //dt1.operator++(0)

		//dt = dt1 + dt2;  //dt1.operator+(dt2) //==> operator+(&dt1, dt2);
		cout<<dt1<<endl;
		cout<<tmp<<endl;
	}
	/*
	void main()
	{
		Date dt1(2011,12,29);

		Date dt2(2019,12,19);

		//dt1.operator!=(dt2);
		if(dt1 == dt2)
			cout<<"dt1 == dt2"<<endl;

		if(dt1 != dt2)
			cout<<"dt1 != dt2"<<endl;
		if(dt1 > dt2)
			cout<<"dt1 > dt2"<<endl;

		if(dt1 <= dt2)
			cout<<"dt1 <= dt2"<<endl;

		Date dt3 = dt2;
	}
};

*/