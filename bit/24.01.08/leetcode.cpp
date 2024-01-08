#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int comp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
    int i, j;
    if (pointsSize < 3) {
        return 0;
    }
    int** arr = (int**)malloc(pointsSize * sizeof(int*));
    for (i = 0; i < pointsSize; i++) {
        arr[i] = (int*)malloc((pointsSize) * sizeof(int));
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i == j) {
                arr[i][j] = -1;
                continue;
            }
            arr[i][j] = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
                (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        }
    }
    for (i = 0; i < pointsSize; i++) {
        qsort(arr[i], pointsSize, sizeof(int), comp);
    }
    int count;
    int num = 0;
    for (i = 0; i < pointsSize; i++) {
        count = 1;
        for (j = 1; j < pointsSize; j++) {
            if (arr[i][j] == arr[i][j - 1]) {
                count++;
            }
            else {
                num += count * (count - 1);
                count = 1;
            }
        }
        num += count * (count - 1);
    }
    return num;
}

int main()
{

	return 0;
}