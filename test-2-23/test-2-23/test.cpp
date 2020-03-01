#include<iostream>
#include<assert.h>
#include<string>
//#include<vld.h>
#include<vector>
using namespace std;
#include <assert.h>

namespace Cool
{
	//template<class T>
	template<typename T>

	class vector
	{
	public:
		typedef T* iterator;
		vector()
			: start(nullptr)
			, finish(nullptr)
			, end_of_storage(nullptr)
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
			return finish == start;
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
		void resize(size_t n, const T& value = T())
		{
			if (n <=size())
			{
				finish = start + n;
				return;
			}
			if (n > capacity())
				reserve(n * 2);
			iterator p = finish;
			finish = start + n;
			while (p != finish)
			{
				*p = value;
				p++;
			}

		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};

};
int main()
{
	Cool::vector<int> v;
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	v.reserve(10);
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	v.resize(5, 6);
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	for (auto& e : v)
		cout << e << " ";
	cout << endl;

}
/*
int main()
{
	Cool::vector<int> v;
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	v.reserve(2);
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
}


// 注意这里namespace大家下去就不要取名为bit了，否则出去容易翻车。^^
/*
namespace bit
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator cbegin() const { return _start; }
		const_iterator cend() const { return _finish; }
		// construct and destroy
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		vector(int n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		// 如果使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
		// 重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v): _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}
		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		// capacity
		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endOfStorage - _start; }
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				// 这里直接使用memcpy是有问题的
				// 以后我们会用更好的方法解决
				//if (_start)
				// memcpy(tmp, _start, sizeof(T)*size);
				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}

		}
		void resize(size_t n, const T& value = T())
		{
			// 1.如果n小于当前的size，则数据个数缩小到n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.空间不够则增容
			if (n > capacity())
				reserve(n);
			// 3.将size扩大到n
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		///////////////access///////////////////////////////
		T& operator[](size_t pos) { return _start[pos]; }
		const T& operator[](size_t pos)const { return _start[pos]; }
		///////////////modify/////////////////////////////
		void push_back(const T& x) { insert(end(), x); }
		void pop_back() { erase(--end()); }
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			// 空间不够先进行增容
			if (_finish == _endOfStorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);
				// 如果发生了增容，需要重置pos
				pos = _start + size;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		// 返回删除数据的下一个数据
		// 方便解决:一边遍历一边删除的迭代器失效问题
		//iterator erase(Iterator pos)
		//{
			// 挪动数据进行删除
		//	iterator begin = pos + 1;
		//	while (begin != _finish) {
		//		*(begin - 1) = *begin;
		//		++begin;
		//	}
		//	--_finish;
		//	return pos;
	//	}
	private:
		iterator _start; // 指向数据块的开始
		iterator _finish; // 指向有效数据的尾
		iterator _endOfStorage; // 指向存储容量的尾
	};
}
int main()
{
	bit::vector<int> v;
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	v.reserve(2);
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
}*/