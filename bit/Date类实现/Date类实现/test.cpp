#include "Date.h"

void TestDate1()
{
	Date d1(2024, 2, 4);
	Date d2(2024, 2, 29);

	d1 += 10000;
	cout << d2;

	d2 = d1 + 1000;
	cout << d2;
	d2 -= 100;
	cout << d2;
	d2 -= -100;
	cout << d2;
	d2 += -1000;
	cout << d2 << d1;

	cin >> d2;
	cout << d2;
}

int main()
{
	TestDate1();

	return 0;
}