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


// ע������namespace�����ȥ�Ͳ�Ҫȡ��Ϊbit�ˣ������ȥ���׷�����^^
/*
namespace bit
{
	template<class T>
	class vector
	{
	public:
		// Vector�ĵ�������һ��ԭ��ָ��
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
		// ���ʹ��iterator�����������ᵼ�³�ʼ���ĵ���������[first,last)ֻ����vector�ĵ�����
		// ��������������������������[first,last]���������������ĵ�����
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
				// ����ֱ��ʹ��memcpy���������
				// �Ժ����ǻ��ø��õķ������
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
			// 1.���nС�ڵ�ǰ��size�������ݸ�����С��n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.�ռ䲻��������
			if (n > capacity())
				reserve(n);
			// 3.��size����n
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
			// �ռ䲻���Ƚ�������
			if (_finish == _endOfStorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);
				// ������������ݣ���Ҫ����pos
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
		// ����ɾ�����ݵ���һ������
		// ������:һ�߱���һ��ɾ���ĵ�����ʧЧ����
		//iterator erase(Iterator pos)
		//{
			// Ų�����ݽ���ɾ��
		//	iterator begin = pos + 1;
		//	while (begin != _finish) {
		//		*(begin - 1) = *begin;
		//		++begin;
		//	}
		//	--_finish;
		//	return pos;
	//	}
	private:
		iterator _start; // ָ�����ݿ�Ŀ�ʼ
		iterator _finish; // ָ����Ч���ݵ�β
		iterator _endOfStorage; // ָ��洢������β
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