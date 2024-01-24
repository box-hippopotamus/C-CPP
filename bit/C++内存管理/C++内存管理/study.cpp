#include <iostream>
using namespace std;

void Test()
{
    // 动态申请一个int类型的空间
    int* ptr4 = new int;

    // 动态申请一个int类型的空间并初始化为10
    int* ptr5 = new int(10);

    // 动态申请10个int类型的空间
    int* ptr6 = new int[10];

    // 动态申请10个int类型的空间,并初始化，不完全初始化时，多出的位置初始化为0
    int* ptr7 = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    delete ptr4;
    delete ptr5;
    delete[] ptr6;
    delete[] ptr7;
}
//
//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int[10];
//
//	delete p1;
//	delete[] p2;
//
//	return 0;
//}


class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A():" << this << endl;
    }

    ~A()
    {
        cout << "~A():" << this << endl;
    }
private:
    int _a;
};


int main()
{
    A* p1 = (A*)malloc(sizeof(A));
    A* p2 = new A(1);
    free(p1);
    delete p2;

    return 0;
}