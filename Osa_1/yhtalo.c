#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    double a, b, c;
    double discriminant, root1, root2, root;

    if (argc != 4) {
        printf("Käyttö: %s <a> <b> <c>\n", argv[0]);
        return 1;
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("Ei ratkaisua\n");
    } else if (discriminant == 0) {
        root = -b / (2 * a);
        printf("%.3f\n", root);
    } else {
        root1 = (-b - sqrt(discriminant)) / (2 * a);
        root2 = (-b + sqrt(discriminant)) / (2 * a);
        if (root1 < root2) {
            printf("%.3f %.3f\n", root1, root2);
        } else {
            printf("%.3f %.3f\n", root2, root1);
        }
    }

    return 0;
}

