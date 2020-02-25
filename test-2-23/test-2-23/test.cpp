#include<iostream>
#include<assert.h>
#include<string>
//#include<vld.h>
#include<vector>
using namespace std;

namespace bit
{
	template<class T>
	//template<typename T>

	class vector
	{
	public:
		typedef T* iterator;
		vector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{}
		~vector()
		{
			delete[]start;
			start = finish = end_of_storage = nullptr;
		}
	public:
		size_t size()const
		{
			return finish - start;
		}
		size_t capacity()const
		{
			return end_of_storage - start;
		}
		bool empty()const
		{
			return finsh == start;
		}
	public:
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
	public:
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T* new_start = new T[n];
				if (start)
				{
					for (int i = 0; i < oldsize; ++i)
					{
						new_start[i] = start[i];
					}
				}
				start = new_start;
				finish = start + oldsize;
				end_of_storage = start + n;
			}
		}
	};
};
void main()
{
	bit::vector<int> v;
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	v.reserve(2);
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
}