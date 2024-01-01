#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int binary_search(int arr[], int k, int len) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < k) {
			left = mid + 1;
		}
		else if (arr[mid] > k) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;

}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	scanf("%d", &k);
	int len = sizeof(arr) / sizeof(arr[0]);
	int pos = binary_search(arr, k, len);
	if (-1 == pos) {
		printf("找不到");
	}
	else {
		printf("找到了，下标为:%d", pos);
	}
	return 0;
}