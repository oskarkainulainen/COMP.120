#include "asteet.h"

/* Muunnosfunktio lämpötilan muuntamiseksi eri asteikkojen välillä */
float muunna(Lampotila a, Asteikko b) {
    float celsius; /* Siirretty muuttujan määrittely alkuun */

    if (a.asteikko == b) {
        return a.lampotila; /* Ei muunnosta tarpeen */
    }

    /* Muunna ensin Celsius-asteikolle */
    if (a.asteikko == Celsius) {
        celsius = a.lampotila;
    } else if (a.asteikko == Fahrenheit) {
        celsius = (a.lampotila - 32) / 1.8;
    } else if (a.asteikko == Kelvin) {
        celsius = a.lampotila - 273.15;
    }

    /* Muunna Celsius-asteikolta halutulle asteikolle */
    if (b == Celsius) {
        return celsius;
    } else if (b == Fahrenheit) {
        return celsius * 1.8 + 32;
    } else if (b == Kelvin) {
        return celsius + 273.15;
    }

    return 0.0; /* Paluuarvo virhetilanteessa */
}

/* Funktio kahden lämpötilan erotuksen laskemiseksi */
float erotus(Lampotila a, Lampotila b, Asteikko c) {
    float tempA, tempB; /* Siirretty muuttujien määrittely alkuun */

    /* Muunna molemmat lämpötilat haluttuun asteikkoon */
    tempA = muunna(a, c);
    tempB = muunna(b, c);

    /* Palauta erotus */
    return tempA - tempB;
}

