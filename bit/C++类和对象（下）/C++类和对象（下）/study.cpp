#include <iostream>
using namespace std;  

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//
//private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//};
//
//class C
//{
//public:
//	C(int a)
//	{
//		cout << "int" << endl;
//	}
//
//	explicit C(double a)
//	{
//		cout << "double" << endl;
//	}
//
//	C(float a)
//	{
//		cout << "float" << endl;
//	}
//
//	C(int a, int b)
//	{
//		cout << "int int" << endl;
//	}
//
//private:
//	int c;
//};
//
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class A
{
private:
	static int k;
	int h;
public:
	class B // B天生就是A的友元
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	return 0;
}

//class sum
//{
//public:
//	sum()
//	{
//		_i++;
//		_sum += _i;
//	}
//
//	static int getSum()
//	{
//		return _sum;
//	}
//
//private:
//	static int _i;
//	static int _sum;
//};
//
//int sum::_i = 0;
//int sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		sum a[n];
//		return sum::getSum();
//	}
//};


//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//
//	int monthDay[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//
//	int ans = monthDay[month - 1];
//
//	ans += day;
//
//	if (month > 2 && ((year % 4 == 0 && year % 400 != 0) || year % 400 == 0))
//	{
//		ans += 1;
//	}
//	cout << ans << endl;
//	return 0;
//}
