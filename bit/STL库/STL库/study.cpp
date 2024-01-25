#include <iostream>
#include <assert.h>
using namespace std;
//
//template<class T>
//int Add(T x, T y)
//{
//	cout << "T" << endl;
//	return x + y;
//}
//
//template<class T1, class T2>
//int Add(T1 x, T2 y)
//{
//	cout << "T1 T2" << endl;
//	return x + y;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Add(1, 2);
//	Add(1.0, 3);
//
//	return 0;
//}

// ��̬˳���
template<class T>
class Stack
{
public:
	Stack(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{
	}

	// ʹ������������ʾ�������������������ⶨ�塣
	~Stack();

	size_t Size() 
	{ 
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Stack<T>::~Stack()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

int main()
{
	Stack<int> s1;
	Stack<double> s2;

	return 0;
}