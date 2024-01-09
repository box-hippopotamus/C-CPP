#define _CRT_SECURE_NO_WARNINGS 1


int min_num(int a, int b) {
    return a < b ? a : b;
}

int minExtraChar(char* s, char** dictionary, int dictionarySize) {
    int dp[200];
    for (int i = 0; i < 200; i++) {
        dp[i] = 52;
    }
    dp[0] = 0;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < dictionarySize; j++) {
            if (s[i] == dictionary[j][0]) {
                if (i + strlen(dictionary[j]) <= strlen(s)) {
                    for (int sk = 0; sk < strlen(dictionary[j]); sk++) {
                        if (dictionary[j][sk] == s[i + sk]) {
                            if (sk == strlen(dictionary[j]) - 1)
                                dp[i + sk + 1] = min_num(dp[i + sk + 1], dp[i]);
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else {
                dp[i + 1] = min_num(dp[i] + 1, dp[i + 1]);
                continue;
            }
            dp[i + 1] = min_num(dp[i] + 1, dp[i + 1]);
        }
        printf("i=%d =%c==%d\n", i, s[i], dp[i + 1]);
    }
    return dp[strlen(s)];
}
