#ifndef ASTEET_H
#define ASTEET_H

/* Enum-määrittely */
typedef enum {
    Celsius,
    Fahrenheit,
    Kelvin
} Asteikko;

/* Struct-määrittely */
typedef struct {
    float lampotila; /* Lämpötilan arvo */
    Asteikko asteikko; /* Asteikon tyyppi */
} Lampotila;

/* Funktioiden esittelyt */
float muunna(Lampotila a, Asteikko b);
float erotus(Lampotila a, Lampotila b, Asteikko c);

#endif /* ASTEET_H */

