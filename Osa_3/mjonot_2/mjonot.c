#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mjonot.h"

char ** jarjesta_mjt(char **mjt, size_t lkm, int (*vrt)(const char*, const char*)) {
    char **kopio;
    size_t i, j;
    
    /* Varataan taulukko osoittimille */
    kopio = (char **)malloc(lkm * sizeof(char *));
    if (kopio == NULL) {
        return NULL; /* Muistivarauksen epäonnistuminen */
    }

    /* Kopioidaan merkkijonot */
    for (i = 0; i < lkm; i++) {
        size_t pituus = strlen(mjt[i]) + 1;
        kopio[i] = (char *)malloc(pituus * sizeof(char));
        if (kopio[i] == NULL) {
            /* Jos varaus epäonnistuu kesken kaiken, vapautetaan jo varatut */
            for (j = 0; j < i; j++) {
                free(kopio[j]);
            }
            free(kopio);
            return NULL;
        }
        strcpy(kopio[i], mjt[i]);
    }

    /* Lajitellaan taulukko vertailufunktion avulla */
    /* vrt(a, b) != 0 tarkoittaa, että a tulee ennen b */
    for (i = 0; i < lkm; i++) {
        for (j = i+1; j < lkm; j++) {
            /* Jos kopio[j] pitäisi olla ennen kopio[i], vaihdetaan ne */
            if (vrt(kopio[j], kopio[i]) != 0) {
                char *temp = kopio[i];
                kopio[i] = kopio[j];
                kopio[j] = temp;
            }
        }
    }

    return kopio;
}

