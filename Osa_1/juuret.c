#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int i;
    int precision;
    char format[20];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <precision> <number1> [number2 ... numberN]\n", argv[0]);
        return 1;
    }

    precision = atoi(argv[1]);
    sprintf(format, "%%.%df\n", precision);

    for (i = 2; i < argc; i++) {
        double num = atof(argv[i]);
        double root = sqrt(num);
        printf("sqrt(%.*f) = ", precision, num);
        printf(format, root);
    }

    return 0;
}

