#include<iostream>

using namespace std;

template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_Pdate(new T[capacity])
		, _size = 0
		, _capacity = capacity
	{
	}

	~Vector();

	void PushBack(const T& data)
	{
		_Pdate[_size] = data;
		_size++;
	}

	T& operator[](size_t index)
	{
		return _Pdate[index];
	}

private:
	T* _Pdate;
	size_t _size;
	size_t _capacity
};

template <class T>

Vector<T>::~Vector()
{
	if (_Pdate)
	{
		delete[] _Pdate;
	}
}














//template<typename T>
//void Swap(T&left, T&right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//
//
//int main()
//{
//	int a = 0;
//	double b = 2.5;
//	Swap(a, b);
//}