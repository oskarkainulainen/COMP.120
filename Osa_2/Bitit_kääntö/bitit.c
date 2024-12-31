#include <limits.h>
#include "bitit.h"

void kaannaScharBitit(signed char *x) {
    signed char result = 0;
    int i;
    for (i = 0; i < CHAR_BIT; i++) {
        result |= ((*x >> i) & 1) << (CHAR_BIT - 1 - i);
    }
    *x = result;
}

void kaannaShortBitit(short *x) {
    short result = 0;
    int i;
    for (i = 0; i < sizeof(short) * CHAR_BIT; i++) {
        result |= ((*x >> i) & 1) << (sizeof(short) * CHAR_BIT - 1 - i);
    }
    *x = result;
}

void kaannaIntBitit(int *x) {
    int result = 0;
    int i;
    for (i = 0; i < sizeof(int) * CHAR_BIT; i++) {
        result |= ((*x >> i) & 1) << (sizeof(int) * CHAR_BIT - 1 - i);
    }
    *x = result;
}

void kaannaLongBitit(long *x) {
    long result = 0;
    int i;
    for (i = 0; i < sizeof(long) * CHAR_BIT; i++) {
        result |= ((*x >> i) & 1) << (sizeof(long) * CHAR_BIT - 1 - i);
    }
    *x = result;
}

