#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

//int main()
//{
//	int i;
//
//	for (i = 0; i <= 100000; i++)
//	{
//		int num,count,sum,x;
//
//		num = i;
//		//��i�Ǽ�λ��
//		while (num)
//		{
//			num = num / 10;
//			count++;
//		}
//		//���
//		num = i;
//		while (num)
//		{
//		    x = num % 10;
//			num = num / 10;
//			sum += pow((double)x, (double)count);
//		}
//		//�ж��Ƿ����
//
//		if (i == sum)
//			printf("%d ", i);
//
//	}
//	return 0;
//}
//
//int main()
//{
//	int i;
//
//	for (i = 0; i <= 100000; i++)
//	{
//		int sum;
//		int num = 0;
//		int count = 1;
//		num = i;
//		//��i�Ǽ�λ��
//		while (num/10)
//		{
//			num = num / 10;
//			count++;
//		}
//		//���
//		num = i;
//		while (num)
//		{
//			sum += pow(num%10, count);
//			num = num / 10;
//		}
//		//�ж��Ƿ����
//
//		if (i == sum)
//			printf("%d ", i);
//
//	}
//	return 0;
//}

////
//
////int main()
////{
////	int i,j;
////	int arr[6];//�������ÿһλ���ִ�����
////	for (i = 1; i <= 100000;i++)//�о�ÿһ������
////	{
////		int num = i;
////		int x;
////		if (num < 10)//ȷ��i�Ǽ�λ��
////			x = 1;
////		else if (10 <= num < 100)
////			x = 2;
////		else if (100 <= num < 1000)
////			x = 3;
////		else if (1000 <= num < 10000)
////			x = 4;
////		else if (10000 <= num < 100000)
////			x = 5;
////		else if (100000 <= num < 1000000)
////			x = 6;
////
////		for(j=0;j<6;j++)//��i��ÿλ���ִ�������
////			{
////				arr[j] = num % 10;
////				num = num / 10;
////			}
////
////		int sum = pow((double)arr[0], (double)x) +
////			pow((double)arr[1], (double)x) +
////			pow((double)arr[2], (double)x) +
////			pow((double)arr[3], (double)x) +
////			pow((double)arr[4], (double)x) +
////			pow((double)arr[5], (double)x) +
////			pow((double)arr[6], (double)x);//��ÿһλ���ִη������
////
////		if (i == sum)//�ж��Ƿ����
////			printf("%d ",i);
////
////	}
////
////	return 0;
////}
//
//int main()
//{
//	double x = 2.0;
//	double num = pow(x, 3.0);
//	printf("%f",num);
////
////	return 0;
//}

//
//int main()
//{
//	int a,i,num;
//
//	scanf("%d", &a);//����a��ֵ
//
//	for (i = 0; i < 5; i++)
//	{
//		int x = pow((double)10, (double)i);
//
//		while (x)
//		{
//			num += a * x;
//			x = x / 10;
//		}
//
//	}
//
//	printf("%d", num);
//
//	return 0;
//}

//int main() {
//	int a;
//	printf("������һ������a��");
//	scanf("%d", &a);
//
//	int term = a;  // ��һ��Ϊa
//	int Sn = term; // ��ʼ��SnΪ��һ��
//
//	for (int i = 1; i < 5; i++) {
//		term = term * 10 + a; // ������һ��
//		Sn += term;          // ����һ��ӵ�Sn��
//	}
//
//	printf("%d\n", Sn);
//
//	return 0;
//}


//
//void f(int num) 
//{
//	while (num)
//	{
//		int x = 1;
//		int count = 1;
//		int copy = num;
//		while (num / 10)
//		{
//			count++;
//			num = num / 10;
//		}
//
//		num = copy;
//
//		for (int i = 1; i < count; i++)
//		{
//			x = x * 10;
//		}
//
//		int sum = num / x;
//		printf("%d ", sum);
//		num = num % x;
//		f(num);
//	}
//}
//
//
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	f(num);
//
//	return 0;
//}
//
//
//void print(int a)
//{
//	if (a > 9)
//	{
//		int num = a / 10;
//		print(num);
//	}
//		int p = a % 10;
//		printf("%d ", p);
//
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//
//	print(a);
//
//	return 0;
////}
//
//
//
//int Fib(int a)
//{
//	if (a <= 2)
//		return 1;
//	if (a > 2)
//		return Fib(a - 1) + Fib(a - 2);
//}
//
//int main()
//{
//	int a;
//	while (scanf("%d", &a) != EOF)
//	{
//		int num = Fib(a);
//		printf("%d ", num);
//	}
//	return 0;
//}
int main()
{


	return 0;
}