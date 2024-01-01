#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//typedef struct {
//    int key;
//    int val;
//    UT_hash_handle hh;
//} HashItem;
//
//HashItem* hashFindItem(HashItem** obj, int key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(*obj, &key, pEntry);
//    return pEntry;
//}
//
//bool hashAddItem(HashItem** obj, int key, int val) {
//    if (hashFindItem(obj, key)) {
//        return false;
//    }
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    pEntry->val = val;
//    HASH_ADD_INT(*obj, key, pEntry);
//    return true;
//}
//
//bool hashSetItem(HashItem** obj, int key, int val) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (!pEntry) {
//        hashAddItem(obj, key, val);
//    }
//    else {
//        pEntry->val = val;
//    }
//    return true;
//}
//
//int hashGetItem(HashItem** obj, int key, int defaultVal) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (!pEntry) {
//        return defaultVal;
//    }
//    return pEntry->val;
//}
//
//void hashFree(HashItem** obj) {
//    HashItem* curr = NULL, * tmp = NULL;
//    HASH_ITER(hh, *obj, curr, tmp) {
//        HASH_DEL(*obj, curr);
//        free(curr);
//    }
//}
//
//bool isSingleRowCompliant(char** seats, int status, int row, int n) {
//    for (int j = 0; j < n; j++) {
//
//        if ((status >> j) & 1) {
//            if (seats[row][j] == '#') {
//                return false;
//            }
//            if (j > 0 && ((status >> (j - 1)) & 1)) {
//                return false;
//            }
//        }
//    }
//    return true;
//};
//
//bool isCrossRowsCompliant(int status, int upperRowStatus, int n) {
//    for (int j = 0; j < n; j++) {
//        if ((status >> j) & 1) {
//            if (j > 0 && ((upperRowStatus >> (j - 1)) & 1)) {
//                return false;
//            }
//            if (j < n - 1 && ((upperRowStatus >> (j + 1)) & 1)) {
//                return false;
//            }
//        }
//    }
//    return true;
//};
//
//int dp(char** seats, HashItem** memo, int row, int status, int n) {
//    int key = (row << n) + status;
//    if (!hashFindItem(memo, key)) {
//        if (!isSingleRowCompliant(seats, status, row, n)) {
//            hashAddItem(memo, key, INT_MIN);
//            return INT_MIN;
//        }
//        int students = __builtin_popcount(status);
//        if (row == 0) {
//            hashAddItem(memo, key, students);
//            return students;
//        }
//        int mx = 0;
//        for (int upperRowStatus = 0; upperRowStatus < 1 << n; upperRowStatus++) {
//            if (isCrossRowsCompliant(status, upperRowStatus, n)) {
//                mx = fmax(mx, dp(seats, memo, row - 1, upperRowStatus, n));
//            }
//        }
//        hashAddItem(memo, key, students + mx);
//    }
//    return hashGetItem(memo, key, 0);
//};
//
//int maxStudents(char** seats, int seatsSize, int* seatsColSize) {
//    int m = seatsSize, n = seatsColSize[0];
//    HashItem* memo = NULL;
//    int mx = 0;
//    for (int i = 0; i < (1 << n); i++) {
//        mx = fmax(mx, dp(seats, &memo, m - 1, i, n));
//    }
//    hashFree(&memo);
//    return mx;
//}

int main()
{

    int k[4][4] = { 0 };

    printf("%p\n", k);
    printf("%p\n", k + 1);

    printf("%p\n", k[0]);
    printf("%p\n", k[0] + 1);

    printf("%p\n", &k);
    printf("%p\n", &k + 1);




    return 0;
}