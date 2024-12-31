#include <stdio.h>
#include <limits.h>
#include "bitit.h"

void printBits(unsigned long x, int num_bits) {
    int i;
    int zero_count = 0;
    int one_count = 0;

    for (i = num_bits - 1; i >= 0; i--) {
        if ((x >> i) & 1) {
            printf("1");
            one_count++;
        } else {
            printf("0");
            zero_count++;
        }
    }
    printf("\n%d\n%d\n", zero_count, one_count);
}

void scharBitit(signed char x) {
    printf("%d\n", x);
    printBits((unsigned char)x, CHAR_BIT);
}

void shortBitit(short int x) {
    printf("%d\n", x);
    printBits((unsigned short)x, sizeof(short int) * CHAR_BIT);
}

void intBitit(int x) {
    printf("%d\n", x);
    printBits((unsigned int)x, sizeof(int) * CHAR_BIT);
}

void longBitit(long int x) {
    printf("%ld\n", x);
    printBits((unsigned long)x, sizeof(long int) * CHAR_BIT);
}

