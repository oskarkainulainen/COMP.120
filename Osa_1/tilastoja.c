#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    double pienin, suurin;
    int i, j;
    int max_count = 0;
    int ainutlaatuiset_lkm = 0;
    int useimmin_lkm = 0;

    if (argc < 2) {
        return 1;
    }

    pienin = atof(argv[1]);
    suurin = atof(argv[1]);

    for (i = 2; i < argc; i++) {
        double luku = atof(argv[i]);
        if (luku < pienin) pienin = luku;
        if (luku > suurin) suurin = luku;
    }

    printf("Pienin: %.6f\n", pienin);
    printf("Suurin: %.6f\n", suurin);

    for (i = 1; i < argc; i++) {
        int count = 0;
        double luku_i = atof(argv[i]);
        for (j = 1; j < argc; j++) {
            double luku_j = atof(argv[j]);
            if (luku_i == luku_j) {
                count++;
            }
        }
        if (count == 1) {
            ainutlaatuiset_lkm++;
        }
        if (count > max_count) {
            max_count = count;
        }
    }

    if (ainutlaatuiset_lkm > 0) {
        printf("Ainutlaatuiset:");
        for (i = 1; i < argc; i++) {
            int count = 0;
            double luku_i = atof(argv[i]);
            for (j = 1; j < argc; j++) {
                double luku_j = atof(argv[j]);
                if (luku_i == luku_j) {
                    count++;
                }
            }
            if (count == 1) {
                printf(" %.6f", luku_i);
            }
        }
        printf("\n");
    }

    if (max_count > 1) {
        printf("Useimmiten esiintyneet (%d kertaa):", max_count);
        for (i = 1; i < argc; i++) {
            int count = 0;
            double luku_i = atof(argv[i]);
            for (j = 1; j < argc; j++) {
                double luku_j = atof(argv[j]);
                if (luku_i == luku_j) {
                    count++;
                }
            }
            if (count == max_count) {
                int printed = 0;
                for (j = 1; j < i; j++) {
                    if (atof(argv[j]) == luku_i) {
                        printed = 1;
                        break;
                    }
                }
                if (!printed) {
                    printf(" %.6f", luku_i);
                    useimmin_lkm++;
                }
            }
        }
        printf("\n");
    }

    return 0;
}

