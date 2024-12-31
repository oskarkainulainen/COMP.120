#include "kolmijako.h"
#include <stdio.h>

/* Vaihtaa kahden muuttujan arvot */
static void vaihda(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2) {
    IntPari tulos;
    int pienet1 = 0, pienet2;
    unsigned int i;  /* Muuttujan määrittely funktion alussa */

    /* Varmistetaan, että t[vipu1] <= t[vipu2], vaihdetaan tarvittaessa */
    if (t[vipu1] > t[vipu2]) {
        vaihda(&vipu1, &vipu2);
    }

    /* Ensimmäinen läpikäynti: pienemmät kuin t[vipu1] */
    for (i = 0; i < n; i++) {
        if (t[i] < t[vipu1]) {
            vaihda(&t[i], &t[pienet1]);
            if (vipu1 == pienet1) vipu1 = i;
            else if (vipu1 == i) vipu1 = pienet1;
            pienet1++;
        }
    }

    /* Asetetaan t[vipu1] oikeaan kohtaan */
    vaihda(&t[pienet1], &t[vipu1]);
    if (vipu1 == pienet1) vipu1 = pienet1;

    /* Toinen läpikäynti: pienemmät kuin t[vipu2] */
    pienet2 = pienet1 + 1;
    for (i = pienet2; i < n; i++) {
        if (t[i] < t[vipu2]) {
            vaihda(&t[i], &t[pienet2]);
            if (vipu2 == pienet2) vipu2 = i;
            else if (vipu2 == i) vipu2 = pienet2;
            pienet2++;
        }
    }

    /* Asetetaan t[vipu2] oikeaan kohtaan */
    vaihda(&t[pienet2], &t[vipu2]);

    /* Tallennetaan tulokset */
    *p1 = pienet1;
    *p2 = pienet2;
    tulos.x = pienet1;
    tulos.y = pienet2;

    return tulos;
}

