#include "pikalaj.h"
#include "kolmijako.h"
#include <stdlib.h>

/* Pikalajittele-funktio */
void pikalajittele(int alku, int loppu, int t[]) {
    int a, b, pienet1, pienet2; /* Siirretty muuttujien määrittely alkuun */

    if (alku >= loppu) {
        return; /* Jos osataulukon koko on 0 tai 1, palataan. */
    }

    /* Valitaan satunnaiset indeksit jakoalkioiksi */
    a = alku + rand() % (loppu - alku + 1);
    b = alku + rand() % (loppu - alku + 1);

    /* Varmistetaan, että indeksit a ja b eivät ole samat */
    while (a == b) {
        b = alku + rand() % (loppu - alku + 1);
    }

    /* Kutsutaan kolmijako-funktiota */
    kolmijako(loppu - alku + 1, t + alku, a - alku, b - alku, &pienet1, &pienet2);

    /* Muunnetaan osataulukon indeksit koko taulukon indekseiksi */
    pienet1 += alku;
    pienet2 += alku;

    /* Rekursiivinen kutsu vasemmalle, keskelle ja oikealle osalle */
    pikalajittele(alku, pienet1 - 1, t);
    pikalajittele(pienet1 + 1, pienet2 - 1, t);
    pikalajittele(pienet2 + 1, loppu, t);
}

