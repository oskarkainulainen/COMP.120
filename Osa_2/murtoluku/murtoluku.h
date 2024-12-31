#ifndef MURTOLUKU_H
#define MURTOLUKU_H

/* Murtoluku-tietue */
typedef struct {
    int os;  /* Osoittaja */
    int nim; /* Nimittäjä */
} Murtoluku;

/* Funktiomäärittelyt */
Murtoluku supistettuML(int os, int nim);
Murtoluku lisaaML(Murtoluku a, Murtoluku b);
Murtoluku vahennaML(Murtoluku a, Murtoluku b);
Murtoluku kerroML(Murtoluku a, Murtoluku b);
Murtoluku jaaML(Murtoluku a, Murtoluku b);
void tulostaML(Murtoluku ml);

#endif /* MURTOLUKU_H */

