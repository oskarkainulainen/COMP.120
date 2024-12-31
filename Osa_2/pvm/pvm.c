#include <stdio.h>
#include <string.h>
#include "pvm.h"

/* Kuukauden päivät (indeksit 1-12) */
static const int KUUKAUDEN_PAIVAT[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/* Viikonpäivien nimet */
static const char *VIIKONPAIVAT[] = {
    "ma", "ti", "ke", "to", "pe", "la", "su"
};

/* Tarkistaa, onko vuosi karkausvuosi */
static int onKarkausvuosi(int vuosi) {
    return (vuosi % 4 == 0 && vuosi % 100 != 0) || (vuosi % 400 == 0);
}

/* Kasvattaa päivämäärää yhdellä päivällä */
Pvm* kasvataPvm(Pvm *pvm) {
    int kuukaudenPaivat;
    int i;

    kuukaudenPaivat = KUUKAUDEN_PAIVAT[pvm->kk];
    if (pvm->kk == 2 && onKarkausvuosi(pvm->vuosi)) {
        kuukaudenPaivat++; /* Helmikuussa on 29 päivää karkausvuonna */
    }

    /* Päivämäärän kasvatus */
    pvm->pv++;
    if (pvm->pv > kuukaudenPaivat) {
        pvm->pv = 1;
        pvm->kk++;
        if (pvm->kk > 12) {
            pvm->kk = 1;
            pvm->vuosi++;
        }
    }

    /* Viikonpäivän päivitys */
    for (i = 0; i < 7; i++) {
        if (strcmp(pvm->vk_pv, VIIKONPAIVAT[i]) == 0) {
            strcpy(pvm->vk_pv, VIIKONPAIVAT[(i + 1) % 7]);
            break;
        }
    }

    return pvm;
}

/* Laskee päivämäärien erot päivinä */
unsigned int pvmEro(const Pvm *a, const Pvm *b) {
    Pvm aiempi;
    Pvm myohempi;
    unsigned int ero = 0;

    /* Kopioidaan aiempi ja myohempi päivämäärä */
    aiempi = *a;
    myohempi = *b;

    /* Varmistetaan, että aiempi on todellisuudessa aikaisempi */
    if ((a->vuosi > b->vuosi) || 
        (a->vuosi == b->vuosi && a->kk > b->kk) || 
        (a->vuosi == b->vuosi && a->kk == b->kk && a->pv > b->pv)) {
        aiempi = *b;
        myohempi = *a;
    }

    /* Kasvatetaan aiempaa päivämäärää, kunnes se saavuttaa myöhemmän */
    while (aiempi.vuosi != myohempi.vuosi || 
           aiempi.kk != myohempi.kk || 
           aiempi.pv != myohempi.pv) {
        kasvataPvm(&aiempi);
        ero++;
    }

    return ero;
}

/* Tulostaa päivämäärän */
void tulostaPvm(Pvm *pvm) {
    printf("%s %d.%d.%d", pvm->vk_pv, pvm->pv, pvm->kk, pvm->vuosi);
}

