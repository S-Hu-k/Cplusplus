#include<string>
#include<iostream>
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp);
	}
	// 对比下和上面的赋值那个实现比较好？
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	/*
	String& operator=(const String& s)
	{
	if(this != &s)
	{
	String strTmp(s);
	swap(_str, strTmp._str);
	}
	return *this;
	}
	*/
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
namespace bit
{
	class String
}
/*
istream& operator>>(istream& is, String& s1)
{
	char* str1 = new char[10];
	int count = 1;
	int cpity = 10;
	char* temp = str1;
	while (((*temp = getchar()) == ' ') || (*temp == '\n'));
	while (1)
	{

		if (count >= cpity)
		{
			str1 = (char*)realloc(str1, cpity *= 2);
			temp = str1 + count - 1;
		}
		else if ((*temp == ' ') || *temp == '\n')
		{
			*temp = '\0';
			break;
		}
		*++temp = getchar();
		count++;
	}
	s1.str = str1;
	s1.capacity = cpity;
	s1.len = count;
	return is;





/*
istream& operator>>(istream& _cin, bit::string& s)
{
	static const size_t default_buf_size = 10;
	int capacity = default_buf_size;
	char* str = (char*)malloc(sizeof(char) * default_buf_size);
	char* buf = str;

	size_t count = 0;

	//跳过字符串起始位置的空格或者换行
	while ((*buf = getchar()) == ' ' || (*buf == '\n'));

	for (;;)
	{
		if (*buf == '\n' || *buf == ' ')
		{
			*buf = '\0';
			break;
		}
		else if (count >= capacity)
		{
			capacity *= 2;
			str = (char*)realloc(str, capacity);
			//重新定位buf的位置
			buf = str + count;
		}
		*++buf = getchar();
		count++;
	}

	s.m_str = str;
	s.m_capacity = capacity;
	s.m_size = count;
	return _cin;
}
*/