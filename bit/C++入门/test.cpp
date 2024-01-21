#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}


//
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//void f(int a, int b)
//{
//	cout << "f(int a, int b)" << endl;
//}
//
//int main()
//{
//	f();
//	f(1);
//	f(1, 2);
//	return 0;
//}



//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//int main()
//{
//	int a = 0;
//	char b = '0';
//
//	f(a, b);
//	f(b, a);
//
//	return 0;
//}

//引用
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
////引用做返回值
//int Count()
//{
//	int n = 0;
//	n++;
//
//	return n;
//}
//
//int TestAuto()
//{
//	return 10;
//}
//
//int main()
//{
//	int arr[] = { 1,3,5,7,9 };
//
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//
//	for (auto& e : arr)
//	{
//		cout << e << " ";
//	}
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

//namespace user1
//{
//	int a = 0;
//	int b = 1;
//
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//using user1::Add;
//using user1::a;
//
//int main()
//{
//	printf("%d",a);
//	Add(3, 5);
//	return 0;
//}
//
//namespace user2
//{
//	int a = 1;
//	int b = 0;
//
//	float Add(float x, float y)
//	{
//		return x + y;
//	}
//}

#include <iostream>
using namespace std;
//
//int Add(int x, int y = 10, int z = 20)
//{
//	return x + y + z;
//}
//
//int main()
//{
//	Add(1);
//	return 0;
//}

//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}

inline int Add(int x, int y)
{
	int z = x + y;
	return z;
}

int main()
{
	int x = 1, y = 2;
	auto a = 3, b = 4;
	auto c = 5, d = 6.0;


	return 0;
}