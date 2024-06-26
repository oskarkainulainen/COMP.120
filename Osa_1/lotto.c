#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int voittorivi[7];
    int lottorivi[7];
    int oikein[7];
    int osumat = 0;
    int i, j;

    for (i = 0; i < 7; i++) {
        voittorivi[i] = atoi(argv[i + 1]);
    }


    for (i = 0; i < 7; i++) {
        lottorivi[i] = atoi(argv[i + 8]);
    }


    printf("Voittorivi: ");
    for (i = 0; i < 7; i++) {
        printf("%d", voittorivi[i]);
        if (i < 6) {
            printf(" ");
        }
    }
    printf("\n");

    printf("Lottorivi: ");
    for (i = 0; i < 7; i++) {
        printf("%d", lottorivi[i]);
        if (i < 6) {
            printf(" ");
        }
    }
    printf("\n");


    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (lottorivi[i] == voittorivi[j]) {
                oikein[osumat] = lottorivi[i];
                osumat++;
                break;
            }
        }
    }


    if (osumat == 0) {
        printf("Ei yhtään oikein!\n");
    } else {
        printf("%d oikein: ", osumat);
        for (i = 0; i < osumat; i++) {
            printf("%d", oikein[i]);
            if (i < osumat - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

