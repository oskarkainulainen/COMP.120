#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void tarkista_rajat(int arvo) {
    int first = 1;
    
    printf("%d: ", arvo);

    if (arvo >= SCHAR_MIN && arvo <= SCHAR_MAX) {
        printf("signed char");
        first = 0;
    }

    if (arvo >= 0 && arvo <= UCHAR_MAX) {
        if (!first) printf(", ");
        printf("unsigned char");
        first = 0;
    }

    if (arvo >= SHRT_MIN && arvo <= SHRT_MAX) {
        if (!first) printf(", ");
        printf("short int");
        first = 0;
    }

    if (arvo >= 0 && arvo <= USHRT_MAX) {
        if (!first) printf(", ");
        printf("unsigned short int");
        first = 0;
    }

    if (arvo >= INT_MIN && arvo <= INT_MAX) {
        if (!first) printf(", ");
        printf("int");
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; ++i) {
        int arvo = atoi(argv[i]);
        tarkista_rajat(arvo);
    }

    return 0;
}

