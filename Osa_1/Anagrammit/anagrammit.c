#include "anagrammit.h"
#include <limits.h>
#include <string.h>

int anagrammeja(char mj1[], char mj2[]) {
    int lkmt[UCHAR_MAX + 1] = {0};
    int i;

    for (i = 0; mj1[i] != '\0'; ++i) {
        lkmt[(unsigned char) mj1[i]]++;
    }

    for (i = 0; mj2[i] != '\0'; ++i) {
        lkmt[(unsigned char) mj2[i]]--;
    }

    for (i = 0; i <= UCHAR_MAX; ++i) {
        if (lkmt[i] != 0) {
            return 0;
        }
    }

    return 1;
}

