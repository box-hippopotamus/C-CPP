#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1);
	void Print() const;
	bool operator==(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;
	Date& operator=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	int operator-(const Date& d) const;

	Date& operator++();
	Date& operator++(int);
	Date& operator--();
	Date& operator--(int);
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);


private:
	int _year;
	int _month;
	int _day;
};

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;

	return out;
}

inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}