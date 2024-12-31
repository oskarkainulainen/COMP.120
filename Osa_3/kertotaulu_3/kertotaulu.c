#include <stdlib.h>
#include "kertotaulu.h"

Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d) {
    uint rivit;
    uint sarakkeet;
    Kertotaulu *kt;
    uint i, j;

    if (a > b || c > d) {
        return NULL;
    }

    /* Lasketaan rivien ja sarakkeiden määrä */
    rivit = d - c + 2; /* Sisältää otsikkorivin */
    sarakkeet = b - a + 2; /* Sisältää otsikkosarakkeen */

    /* Varataan muistia Kertotaulu-oliolle */
    kt = (Kertotaulu *)malloc(sizeof(Kertotaulu));
    if (kt == NULL) {
        return NULL;
    }

    kt->a = a;
    kt->b = b;
    kt->c = c;
    kt->d = d;

    /* Varataan muistia rivien osoittimille */
    kt->kertotaulu = (uint **)malloc(rivit * sizeof(uint *));
    if (kt->kertotaulu == NULL) {
        free(kt);
        return NULL;
    }

    /* Varataan muistia jokaiselle riville */
    for (i = 0; i < rivit; i++) {
        kt->kertotaulu[i] = (uint *)malloc(sarakkeet * sizeof(uint));
        if (kt->kertotaulu[i] == NULL) {
            /* Vapautetaan aiemmin varatut rivit ja olio */
            for (j = 0; j < i; j++) {
                free(kt->kertotaulu[j]);
            }
            free(kt->kertotaulu);
            free(kt);
            return NULL;
        }
    }

    /* Täytetään kertotaulu */
    for (i = 0; i < rivit; i++) {
        for (j = 0; j < sarakkeet; j++) {
            if (i == 0 && j == 0) {
                /* Vasemman yläkulman tyhjä kohta */
                kt->kertotaulu[i][j] = 0;
            } else if (i == 0 && j > 0) {
                /* Ensimmäinen rivi (sarakkeiden otsikot) */
                kt->kertotaulu[i][j] = a + j - 1;
            } else if (i > 0 && j == 0) {
                /* Ensimmäinen sarake (rivien otsikot) */
                kt->kertotaulu[i][j] = c + i - 1;
            } else {
                /* Kertolaskun tulos */
                kt->kertotaulu[i][j] = (c + i - 1) * (a + j - 1);
            }
        }
    }

    return kt;
}

void tuhoaKertotaulu(Kertotaulu *kt) {
    uint rivit;
    uint i;

    if (kt == NULL) {
        return;
    }

    rivit = kt->d - kt->c + 2;

    /* Vapautetaan jokainen rivi */
    for (i = 0; i < rivit; i++) {
        free(kt->kertotaulu[i]);
    }

    /* Vapautetaan rivien osoittimien taulukko */
    free(kt->kertotaulu);

    /* Vapautetaan Kertotaulu-olio */
    free(kt);
}

