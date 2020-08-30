#include<iostream>
#include<string>

using namespace std;
#include<iostream>
#include<string>
#include<vld.h>
#include<assert.h>
using namespace std;

namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string& s);
		friend istream& operator>>(istream& _cin, bit::string& s);
	public:
		typedef char* iterator;
	public:
		string(const char* str = "") :m_str(nullptr)
		{
			m_capacity = m_size = strlen(str);
			m_str = new char[m_capacity + 1];  // \0
			strcpy(m_str, str);
		}
		string(const string& s) : m_str(nullptr), m_capacity(0), m_size(0)
		{
			string tmp(s.m_str);
			_swap(*this, tmp);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				_swap(*this, tmp);
			}
			return *this;
		}
		~string()
		{
			if (m_str)
			{
				delete[]m_str;
				m_str = nullptr;
			}
			m_capacity = m_size = 0;
		}
	public:
		iterator begin()
		{
			return m_str;
		}
		iterator end()
		{
			return m_str + size();
		}
	public:
		size_t size()const
		{
			return m_size;
		}
		size_t capacity()const
		{
			return m_capacity;
		}
		bool empty()const
		{
			return m_size == 0;
		}
		void clear()
		{
			m_size = 0;
			m_str[0] = '\0';
		}
	public:
		const char* c_str()const
		{
			return m_str;
		}
	public:
		void push_back(char c)
		{
			if (m_size >= m_capacity)
				reserve(m_capacity * 2);
			m_str[m_size++] = c;
			m_str[m_size] = '\0';
		}
	public:
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void resize(size_t newSize, char c = '\0');
		const char& operator[](size_t index)const;
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);
		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const;
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const;
		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len);
	public:
		char& operator[](int i)
		{
			assert(i >= 0 && i < m_size);
			return m_str[i];
		}
	public:
		void reserve(size_t new_cpy)
		{
			if (new_cpy > m_capacity)
			{
				char* new_str = new char[new_cpy + 1];
				memcpy(new_str, m_str, m_size);
				m_capacity = new_cpy;
				delete[]m_str;
				m_str = new_str;
			}
		}
	protected:
		static void _swap(string& s1, string& s2)
		{
			std::swap(s1.m_str, s2.m_str);
			std::swap(s1.m_capacity, s2.m_capacity);
			std::swap(s1.m_size, s2.m_size);
		}
	private:
		char* m_str;
		size_t m_capacity;
		size_t m_size;
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		out << s.m_str;
		return out;
	}
};

void main()
{
	bit::string str("Hello C++");
	cout << "str = " << str << endl;
	str.push_back('x');
	cout << "str = " << str << endl;
}
/*namespace bit
{
	class String
	{
	public:
		typedef char* iterator;
	public:
		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s);
			this->Swap(tmp);
		}
		String& operator=(String s)
		{
			this->Swap(s)
				return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		/////////////////////////////////////////////////////////////////
		// iterator
		iterator begin() { return _str; }
		iterator end() { return _str + _size; }
		/////////////////////////////////////////////////////////////////
		// modify
		void PushBack(char c)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		// ��ҵʵ��
		void Append(const char* str);
		String& operator+=(const char* str);
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* C_Str()const
		{
			return _str;
		}
		/////////////////////////////////////////////////////////////////
		// capacity
		size_t Size()const
			size_t Capacity()const
			bool Empty()const
			void Resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)
		{
			// ������������ھ��������򿪱ٿռ�
		if(newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);
				// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}
		////////////////////////////////////////////////////////////////////
		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		////////////////////////////////////////////////////////////////////
		// ��ҵ
		bool operator<(const String& s);
		bool operator<=(const String& s);
		bool operator>(const String& s);
		bool operator>=(const String& s);
		bool operator==(const String& s);
		bool operator!=(const String& s);
		// ����c��string�е�һ�γ��ֵ�λ��
		size_t Find(char c, size_t pos = 0) const;
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t Find(const char* s, size_t pos = 0) const;
		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		String& Insert(size_t pos, char c);
		String& Insert(size_t pos, const char* str);
		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		String& Erase(size_t pos, size_t len);
	private:
		friend ostream& operator<<(ostream& _cout, const bit::String& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
ostream& bit::operator<<(ostream& _cout, const bit::String& s)
{
	cout << s._str;
	return _cout;
}
///////���Զ����string����в���
void TestBitString()
{
	bit::String s1("hello");
	s1.PushBack(' ');
	s1.PushBack('b');
	s1.Append(1, 'i');
	s1 += 't';
	cout << s1 << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	// ���õ�������ӡstring�е�Ԫ��
	String::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// ������Կ���һ����ֻҪ֧�ֵĻ�����iterator����֧�ַ�Χfor
	for (auto ch : s1)
		cout << ch << " ";
	cout << endl;
}
/*
//�ַ������һ�����ʵĳ��ȡ�https://www.nowcoder.com/questionTerminal/8c949ea5f36f422594b306a2300315da��
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while(getline(cin,str))
	{
		size_t pos=str.rfind(" ");
		if(pos==string::npos)
			printf("%d",str.size());
		else
			printf("%d",str.size()-pos-1);
	}
	return 0;
}
//�ַ����е�һ��Ψһ�ַ���https://leetcode-cn.com/problems/first-unique-character-in-a-string/submissions/��
�ⷨһ
   int firstUniqChar(string s)
	{
		int count[256]={0};
		for(int i=0;i<s.size();++i)
		{
			count[s[i]]+=1;
		}
		for(int i=0;i<s.size();++i)
		{
			if(count[s[i]]==1)
			return i;
		}
		return -1;
	}
	//�ⷨ��
	int firstUniqChar(string s)
	{
		for(int i=0;i<s.size();++i)
		{
			int index1=s.find(s[i]);
			int index2=s.rfind(s[i]);
			if(index1==index2)
			return i;
		}
		return -1;

	}
//������ת��ĸ��https://leetcode-cn.com/problems/reverse-only-letters/��
string reverseOnlyLetters(string S)
{
	int start = 0;
	int end = S.size() - 1;
	while (start < end)
	{
		//������ߵ�һ����ĸ
		while (start < end)
		{
			if ((S[start] >= 'a' && S[start] <= 'z')
				|| (S[start] >= 'A' && S[start] <= 'Z'))
				break;
			start++;
		}
		//�����ұߵ�һ����ĸ
		while (start < end)
		{
			if ((S[end] >= 'a' && S[end] <= 'z')
				|| (S[end] >= 'A' && S[end] <= 'Z'))
				break;
			end--;
		}
		if (start < end)
		{
			char tmp = S[start];
			S[start] = S[end];
			S[end] = tmp;
			start++;
			end--;
		}
	}
	return S;
}*/
/*
int main()
{
	string str = "Hello Bit.";
	//ֱ�����
	cout << str << endl;

	//C++11
	for (auto& e : str)
		cout << e;
	cout << endl;

	//operator[]
	for (int i = 0; i < str.size(); ++i)
		cout << str[i] ;
	cout << endl;

	//string.at()
	for (int i = 0; i < str.size(); ++i)
		cout << str.at(i);
	cout << endl;

	//���������
	string::iterator  it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	//���������
	string::reverse_iterator  rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
	//����������������
	string::iterator it1 = str.end() - 1;
	while (it1 != str.begin())
	{
		cout << *it1;
		--it1;
	}
	cout << *it1;
	cout << endl;
}
/*int main()
{
	string str = "Hello Bit.";

	//ֱ�����
	cout << str << endl;
	//operator[]
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i];
	}
	cout << endl;
	//C++11
	for (auto& e : str)
	{
		//if(e == 'H')
		//	e = 'h';
		cout << e;
	}
	cout << endl;
	//at()
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i);
	}
	cout << endl;
	//iterator ++ --
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
	//
	string::iterator it1 = str.end() - 1;
	while (it1 != str.begin())
	{
		cout << *it1;
		--it1;
	}
	cout << *it1;
	cout << endl;
}
/*int main()
{
	/*size_t find(const string & str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;*/


	/*string email = "32@c5690203@qq.com";
	string substr("60.c");
	size_t pos = email.find_first_of(substr);
	cout << pos << endl;
}*/
/*
void main()
{
	string email = "36@5690203@qq.com";
	size_t pos = email.find('@', 3);
	cout<<"pos = "<<pos<<endl;
	pos = email.find("569", 4);
	if(pos == string::npos)
		cout<<"find not."<<endl;
	else
		cout<<"pos = "<<pos<<endl;
	string str = "qq";
	pos = email.find(str);
	cout<<"pos = "<<pos<<endl;
}
}*/