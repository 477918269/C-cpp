#include<iostream>

using namespace std;


template<class T>
class Vector
{
public:
	typedef T* iterator;

	size_t Size() const { return _finish - _start; }
	size_t Capacity() const { return _endOfStorage - _start; }

	Vector()
		:_start(nullptr),
		_finish(nullptr)
		_endOfStorage(nullptr)
	{}

	Vector(const Vector<T>& v)
	{
		_start = new T[v.size()];
		for (int i = 0; i < v.size(); i++)
		{
			_start[i] = v[i];
		}

		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}

	Vector<T>& operator=(Vector<T> v)
	{
		swap(v);
		return *this;
	}

	void swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}

	~Vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}


	void Reverse(size_t n)
	{
		if (n > Capacity())
		{
			size_t size = Size();
			T* tmp = new T[n];
			if (size > 0)
			{
				for (int i = 0; i < size; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + size;
			_endOfStorage = _start + n;
		}

		void PushBack(const T& n)
		{
			Insert(_finish, x);
		}

		void Insert(iterator pos, const T& x)
		{
			size_t n = pos - _start;
			if (_finish == _endOfStorage)
			{
				size_t capacity = Capacity == 0 ? 15 : Capacity * 2;
				Reverse(capacity);
			}
			pos = _start + n;

			iterator end = _finish + 1;
			while (end >= finish)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
		}
	}

private:
	iterator _start;
	iterator _finish;
	iterator _endOfStorage;
};


int main()
{

	system("pause");
	return 0;
}