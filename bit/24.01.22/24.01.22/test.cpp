#include <iostream>
using namespace std;



//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (int*)malloc(capacity * sizeof(int));
//		if (nullptr == _array)
//		{
//			perror("malloc…Í«Îø’º‰ ß∞‹");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const int& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	int* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class A
//{
//public:
//	A()
//	{
//		_a1 = 0;
//	}
//
//	A(int a)
//	{
//		_a1 = a;
//	}
//
//private:
//	int _a1;
//};

//int main()
//{
//	A abc;
//
//	abc = 1;
//	abc = 5.0;
//
//	return 0;
//}




class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		_array = (int*)malloc(capacity * sizeof(int));
		if (nullptr == _array)
		{
			perror("malloc…Í«Îø’º‰ ß∞‹");
			return;
		}

		_size = 0;
		_capacity = capacity;
	}
	void Push(const int& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	Stack(const Stack& s)
	{
		cout << "øΩ±¥ππ‘Ï" << endl;
	}

	Stack& operator=(const Stack& s)
	{
		cout << "∏≥÷µ÷ÿ‘ÿ" << endl;
		return *this;
	}


private:
	int* _array;
	size_t _size;
	size_t _capacity;
};


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d2)
	{
		return _year == d2._year
		&& _month == d2._month
			&& _day == d2._day;
	}

	Date& operator++()
	{
		//¥˙¬Î
	}

	Date& operator++(int)
	{
		//¥˙¬Î
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Stack s1;
	Stack s2;

	Stack s4 = s1;
	s4 = s2;

	return 0;
}