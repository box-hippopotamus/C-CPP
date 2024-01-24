#include <iostream>
using namespace std;

//int main() 
//{
//	int A_B, B_C, AB, BC;
//
//	cin >> A_B >> B_C >> AB >> BC;
//
//	int A = A_B + AB;
//
//	int B = B_C + BC;
//
//	if (A % 2 == 0 && B % 2 == 0)
//	{
//		A = A / 2;
//		B = B / 2;
//
//		int C = -(A_B + B_C - A);
//
//		printf("%d %d %d", A, B, C);
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//
//	return 0;
//}

int main()
{
	long long M;
	int N;

	cin >> M >> N;

	char numArr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	long long num = M;
	int count = 0;

	while (num != 0)
	{
		count++;
		num = num / N;
	}

	char* ptr = new char [count];

	num = M;
	int i = 0;

	while (num != 0)
	{
		ptr[i++] = numArr[num % N];
		num = num / N;
	}

	while (i > 0)
	{
		cout << ptr[i - 1];
		i--;
	}

	delete[] ptr;

	return 0;
}
