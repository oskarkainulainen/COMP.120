#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a, b, i;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <int a> <int b>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    

    if (a > b) {
        fprintf(stderr, "Error: a should be less than or equal to b\n");
        return 1;
    }

    for (i = a; i <= b; i++) {
        printf("%d: %c\n", i, (char)i);
    }

    return 0;
}



