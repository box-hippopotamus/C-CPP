#include <iostream>
using namespace std;

////����C�Ľṹ��
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTN;
//
////��C�Ľṹ������Ϊ����
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};

#include "stack.h"

//void stack::Init()
//{
//	cout << "��ʼ��ջ" << endl;
//}
//
//void stack::Push(int x)
//{
//	cout << x << "��ѹջ��" << endl;
//}
//
//void stack::Destroy()
//{
//	cout << "����ջ" << endl;
//}



class className
{
	// ���壺�ɳ�Ա�����ͳ�Ա�������
};

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

struct ListNode
{
	int val;
	struct ListNode* next;
};

class stack
{
public:
	void Init()
	{
		cout << "��ʼ��ջ" << endl;
	}

	void Push(int x)
	{
		cout << x << "��ѹջ��" << endl;
	}

	void Destroy()
	{
		cout << "����ջ" << endl;
	}

	int stackSize()
	{
		return size;
	}
private:
	int* a;
	int size;
	int capacity;
};

class myclass
{
public:
	void Init(int x, int y, int z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	void Add()
	{
		cout << _x + _y + _z << endl;
	}

	void tellMeThis()
	{
		cout << this << endl;
	}

private:
	int _x;
	int _y;
	int _z;
};

int main()
{
	myclass c1;
	myclass c2;

	c1.Init(1, 2, 3);
	c2.Init(4, 5, 6);

	c1.Add();
	c2.Add();

	return 0;
}