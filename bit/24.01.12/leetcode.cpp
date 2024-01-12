#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, const char* key) {
    HashItem* pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, char* key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, char* key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    }
    else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, const char* key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem* curr = NULL, * tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int countWords(char** words1, int words1Size, char** words2, int words2Size) {
    HashItem* freq1 = NULL, * freq2 = NULL;
    for (int i = 0; i < words1Size; i++) {
        hashSetItem(&freq1, words1[i], hashGetItem(&freq1, words1[i], 0) + 1);
    }
    for (int i = 0; i < words2Size; i++) {
        hashSetItem(&freq2, words2[i], hashGetItem(&freq2, words2[i], 0) + 1);
    }

    int res = 0;
    for (HashItem* pEntry = freq1; pEntry; pEntry = pEntry->hh.next) {
        int cnt1 = pEntry->val;
        if (cnt1 == 1 && hashGetItem(&freq2, pEntry->key, 0) == 1) {
            ++res;
        }
    }
    hashFree(&freq1);
    hashFree(&freq2);
    return res;
}

int main()
{

	return 0;
}