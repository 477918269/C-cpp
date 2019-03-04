#include<iostream>
#include<assert>

using namespace std;

template<class T>
class Vector
{
public:
	T* begin()
	{
		return _start;
	}
	T* end()
	{
		return _finish;
	}
	const T*Cbegin()
	{
		return _start;
	}
	const T* Cend()
	{
		return _finish;
	}
	size_t Size() const
	{
		return _finish - _start;
	}
	size_t Capacity() const
	{
		return _endOfstorage - _start;

	}
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfstorage(nullptr)
	{
	}
	Vector(const Vector<T>& v)
	{
		_start = new T[v.Capacity()];
		T* it = v.begin();
		while (*it != v.end())
		{
			*_start++ = *v._start++;
			it++;
		}
		_finish = _start + v.Size();
		_endOfstorage = _start + v.Capacity();
		
	}
	Vector<T>& operator=(const Vector<T>& v)
	{

	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = nullptr;
		}
	}
	void Reserve(size_t n)
	{
		size_t size = Size();
		if (n > Capacity())
		{
			T* tmp = new T[n];
			for (size_t i = 0; i < size(); i++)
			{
				*tmp++ = *_start;
			}
			delete[] _start;
			_start = tmp;
			_finish = _start + size;
			_endOfstorage = _start + n;
		}
	}
	void Resize(size_t n, const T&value = T())
	{
		if (n < Size())
		{
			_finish = _start + n;
			return;
		}

		else if (n >= Capacity())
		{
			Reserve(n);
			
		}
	}
	void PushBack(const T& x)
	{
		if (_finish == _endOfstorage)
		{
			size_t capacity = Capacity() = 0 ? 4 : capacity *= 2;
			Reserve(capacity);
		}
		_finish = x;
		_finish++;
	}
	void PopBack()
	{
		_finish--;
	}
	T* Insert(T* pos, const T& x)
	T*  Erase(T* pos)
	T& operator[](size_t pos)
	{
		return *(_start + pos);
	}
private:
	T* _start;
	T* _finish;
	T* _endOfstorage;

};

void Test1()
{

}

int main()
{

	system("pause");
	return 0;
}