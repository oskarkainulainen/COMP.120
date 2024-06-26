#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int i;
    double num, root;

    if (argc < 3) {
        return 1;
    }

    for (i = 2; i < argc; i++) {
        num = atof(argv[i]);
        root = sqrt(num);
        printf("sqrt(%.4f) = %.4f\n", num, root);
    }

    return 0;
}

