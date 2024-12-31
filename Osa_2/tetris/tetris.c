#include "tetris.h"
#include <string.h>

void paivita(char ruudukko[20][10]) {
    int i, j, k;
    char uusi_ruudukko[20][10];
    int uusi_rivi;
    int rivi_taynna;

    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 10; ++j) {
            uusi_ruudukko[i][j] = ' ';
        }
    }

    uusi_rivi = 19;
    for (i = 19; i >= 0; --i) {
        rivi_taynna = 1;
        for (j = 0; j < 10; ++j) {
            if (ruudukko[i][j] == ' ') {
                rivi_taynna = 0;
                break;
            }
        }

        if (!rivi_taynna) {
            for (k = 0; k < 10; ++k) {
                uusi_ruudukko[uusi_rivi][k] = ruudukko[i][k];
            }
            uusi_rivi--;
        }
    }

    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 10; ++j) {
            ruudukko[i][j] = uusi_ruudukko[i][j];
        }
    }
}

