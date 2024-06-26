#include <stdio.h>
#include <stdlib.h>

int laske_leveys(int luku) {
    int leveys = 0;
    while (luku > 0) {
        luku /= 10;
        leveys++;
    }
    return leveys;
}

int main(int argc, char *argv[]) {
    int a, b, c, d;
    int maksimi_arvo, sarake_leveys;
    int i, j;

    if (argc != 5) {
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    d = atoi(argv[4]);

    maksimi_arvo = b * d;
    sarake_leveys = laske_leveys(maksimi_arvo) + 1;

    printf("%*s", sarake_leveys, "");
    for (i = a; i <= b; i++) {
        printf("%*d", sarake_leveys, i);
    }
    printf("\n");

    for (i = c; i <= d; i++) {
        printf("%*d", sarake_leveys, i);
        for (j = a; j <= b; j++) {
            printf("%*d", sarake_leveys, i * j);
        }
        printf("\n");
    }

    return 0;
}

