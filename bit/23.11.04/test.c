#include "test.h"

int x = 5;
//int y = 6;
//
//
//int main()
//{
//	printf("%d\n", (x + y));
//	int x = 3;
//	int y = 4;
//	printf("%d\n", (x + y));
//}




void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
	int i1 = m - 1;
	int i2 = n - 1;
	int i3 = m + n - 1;

	while ((i1 >= 0) && (i2 >= 0))
	{
		if (nums1[i1] >= nums2[i2])
		{
			nums1[i3] = nums1[i1];
			i3--;
			i1--;
		}
		else
		{
			nums1[i3] = nums2[i2];
			i2--;
			i3--;
		}
	}
}