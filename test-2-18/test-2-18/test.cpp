#include<string>
#include<iostream>
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

	//�����ַ�����ʼλ�õĿո���߻���
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
			//���¶�λbuf��λ��
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