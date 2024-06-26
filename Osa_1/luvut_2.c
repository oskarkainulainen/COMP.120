#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a, b;
    int *divisors;
    int i, j;
    int found = 0;
    int divisible;

    if (argc < 4) {

        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);


    if (a >= b) {
        return 1;
    }


    divisors = (int *)malloc((argc - 3) * sizeof(int));
    if (divisors == NULL) {
        return 1;
    }

    for (i = 3; i < argc; i++) {
        divisors[i - 3] = atoi(argv[i]);
    }

    for (i = a; i <= b; i++) {
        divisible = 0;
        for (j = 0; j < argc - 3; j++) {
            if (i % divisors[j] == 0) {
                divisible = 1;
                break;
            }
        }
        if (!divisible) {
            if (found) {
                printf(" ");
            }
            printf("%d", i);
            found = 1;
        }
    }

    if (found) {
        printf("\n");
    }


    free(divisors);

    return 0;
}

