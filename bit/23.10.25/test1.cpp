#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//enum { SIZE = 5 };
//
//int main(void)
//{
//	double a[SIZE] = { 1.,2.,3.,4.,5. };
//	FILE* fp = fopen("test.bin", "wb"); // 必须用二进制模式
//	fwrite(a, sizeof * a, SIZE, fp); // 写 double 的数组
//	fclose(fp);
//	double b[SIZE];
//	fp = fopen("test.bin", "rb");
//	size_t ret_code = fread(b, sizeof * b, SIZE, fp); // 读 double 的数组
//	if (ret_code == SIZE) {
//		puts("Array read successfully, contents: ");
//		for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
//		putchar('\n');
//	}
//	else { // error handling
//		if (feof(fp))
//			printf("Error reading test.bin: unexpected end of file\n");
//		else if (ferror(fp)) {
//			perror("Error reading test.bin");
//		}
//	}
//	fclose(fp);
////}
//
//#include<stdio.h>

//int jiecheng(int i)
//{
//	if (i > 1)
//	return i * jiecheng(i - 1);
//
//	if (i <= 1)
//	return 1;
//}
//
//#define hongjiecheng(i) jiecheng(i)
//
//int main()
//{
//	int a = jiecheng(5);
//
//	//int a = hongjiecheng(5);
//
//	printf("%d", a);
//
//	return 0;
//}
//
//#include <stdio.h>
//
//#define print(formate,n) printf("The value of"#n"is"formate"/n",n)
//
//int main()
//{
//	float a = 5.0f;
//	print(%f,a);
//
//	printf("the value of a is" % f"/n", f);
//
//	return 0;
//}

#include <stdio.h>

int intmax(int x, int y)
{
	return (x > y) ? x : y;
}

float floatmax(float x, float y)
{
	return (x > y) ? x : y;
}

int main()
{


	return 0;
}