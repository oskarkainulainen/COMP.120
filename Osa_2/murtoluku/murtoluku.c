#include <stdio.h>
#include "murtoluku.h"

/* Apufunktio suurimman yhteisen tekijän laskemiseen */
static int suurinYhteinenTekija(int a, int b) {
    a = a < 0 ? -a : a; /* Muutetaan positiiviseksi */
    b = b < 0 ? -b : b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Supistettu murtoluku */
Murtoluku supistettuML(int os, int nim) {
    Murtoluku tulos;
    int sytek;

    tulos.os = os;
    tulos.nim = nim;

    if (os == 0 || nim == 0) {
        return tulos; /* Ei supisteta, jos osoittaja tai nimittäjä on 0 */
    }
    if (nim < 0) {
        tulos.os = -os;
        tulos.nim = -nim; /* Muutetaan nimittäjä positiiviseksi */
    }

    sytek = suurinYhteinenTekija(tulos.os, tulos.nim);
    tulos.os /= sytek;
    tulos.nim /= sytek;
    return tulos;
}

/* Murtolukujen summa */
Murtoluku lisaaML(Murtoluku a, Murtoluku b) {
    int osoittaja = a.os * b.nim + b.os * a.nim;
    int nimittaja = a.nim * b.nim;
    return supistettuML(osoittaja, nimittaja);
}

/* Murtolukujen erotus */
Murtoluku vahennaML(Murtoluku a, Murtoluku b) {
    int osoittaja = a.os * b.nim - b.os * a.nim;
    int nimittaja = a.nim * b.nim;
    return supistettuML(osoittaja, nimittaja);
}

/* Murtolukujen tulo */
Murtoluku kerroML(Murtoluku a, Murtoluku b) {
    int osoittaja = a.os * b.os;
    int nimittaja = a.nim * b.nim;
    return supistettuML(osoittaja, nimittaja);
}

/* Murtolukujen osamäärä */
Murtoluku jaaML(Murtoluku a, Murtoluku b) {
    int osoittaja = a.os * b.nim;
    int nimittaja = a.nim * b.os;
    return supistettuML(osoittaja, nimittaja);
}

/* Murtoluvun tulostus */
void tulostaML(Murtoluku ml) {
    if (ml.os == 0) {
        printf("0");
    } else if (ml.nim == 1) {
        printf("%d", ml.os);
    } else {
        printf("%d/%d", ml.os, ml.nim);
    }
}

