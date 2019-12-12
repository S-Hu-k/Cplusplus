#include"datetime.h"
void HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO  cursor_info = { 1, 0 };
	SetConsoleCursorInfo(handle, &cursor_info);
}
CDateTime::CDateTime(int year, int month, int day)
{
	time_t te;
	time(&te); // long 
	struct tm* ptm = localtime(&te);
	_year = ptm->tm_year + 1900;
	_month = ptm->tm_mon + 1;
	_day = ptm->tm_mday;
	_hour = ptm->tm_hour;
	_minute = ptm->tm_min;
	_second = ptm->tm_sec;
}
ostream& operator<<(ostream& out, const CDateTime& dt)
{
	out << dt._year << "?¨º" << dt._month << "??" << dt._day << "??" << dt._hour << "?¡À" << dt._minute << "¡¤?" << dt._second << "??";

	return out;
}
void CDateTime::GetCurDateTime()
{
	time_t te;
	time(&te); // long 
	struct tm* ptm = localtime(&te);
	_year = ptm->tm_year + 1900;
	_month = ptm->tm_mon + 1;
	_day = ptm->tm_mday;
	_hour = ptm->tm_hour;
	_minute = ptm->tm_min;
	_second = ptm->tm_sec;
}
void CDateTime::DShowDateTime()
{
	system("color 0F");
	HideCursor();
	while (1)
	{
		GetCurDateTime();
		cout << *this << endl;
		Sleep(1000);
		system("cls");
	}
}