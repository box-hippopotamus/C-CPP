#include <iostream>
using namespace std;

class stack
{
public:
	stack()
	{
		_a = nullptr;
		_size = _capacity = 0;
	}

	stack(int n)
	{
		_a = (int*)malloc(sizeof(int) * n);
		if (_a == nullptr)
		{
			perror("malloc fail!");
			return;
		}

		_capacity = n;
		_size = 0;
	}

	~stack()
	{
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}

	stack(const stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail!");
			return;
		}

		memcpy(_a, st._a, sizeof(int) * st._size);
		_size = st._size;
		_capacity = st._capacity;
	}

	void Push()
	{
		cout << "ѹջ" << endl;
 	}

private:
	int* _a = nullptr;
	int _size = 0;
	int _capacity = 0;
};

class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}

	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

class A
{
public:
	void Print() const
	{
		cout << a << endl;
	}

	A* operator&()
	{
		return this;
	}

	const A* operator&() const
	{
		return this;
	}

private:
	int a = 1;
};

int main()
{
	const A a1;
	a1.Print();

	return 0;
}