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
//		//求i是几位数
//		while (num)
//		{
//			num = num / 10;
//			count++;
//		}
//		//求和
//		num = i;
//		while (num)
//		{
//		    x = num % 10;
//			num = num / 10;
//			sum += pow((double)x, (double)count);
//		}
//		//判断是否输出
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
//		//求i是几位数
//		while (num/10)
//		{
//			num = num / 10;
//			count++;
//		}
//		//求和
//		num = i;
//		while (num)
//		{
//			sum += pow(num%10, count);
//			num = num / 10;
//		}
//		//判断是否输出
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
////	int arr[6];//用数组把每一位数字存下来
////	for (i = 1; i <= 100000;i++)//列举每一个数字
////	{
////		int num = i;
////		int x;
////		if (num < 10)//确定i是几位数
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
////		for(j=0;j<6;j++)//把i的每位数字存入数组
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
////			pow((double)arr[6], (double)x);//把每一位数字次方后求和
////
////		if (i == sum)//判断是否输出
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
//	scanf("%d", &a);//输入a的值
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
//	printf("请输入一个数字a：");
//	scanf("%d", &a);
//
//	int term = a;  // 第一项为a
//	int Sn = term; // 初始化Sn为第一项
//
//	for (int i = 1; i < 5; i++) {
//		term = term * 10 + a; // 计算下一项
//		Sn += term;          // 将下一项加到Sn中
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