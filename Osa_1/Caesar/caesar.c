#include "caesar.h"
#include <limits.h>

void caesarKoodaa(char mj[], char aakkosto[], char korvaavat[]) {
    char korvaus[UCHAR_MAX + 1];
    int i;

    for (i = 0; i <= UCHAR_MAX; ++i) {
        korvaus[i] = (char) i;
    }
    
    for (i = 0; aakkosto[i] != '\0'; ++i) {
        korvaus[(unsigned char) aakkosto[i]] = korvaavat[i];
    }
    
    for (i = 0; mj[i] != '\0'; ++i) {
        mj[i] = korvaus[(unsigned char) mj[i]];
    }
}

