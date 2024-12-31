#include <stddef.h>
#include "genhaku.h"

size_t etsi(void *mista, size_t n, void *mita, size_t m, size_t koko) {
    unsigned char *A = (unsigned char *)mista;
    unsigned char *B = (unsigned char *)mita;
    size_t i, j, k;

    /* Jos mita-taulukko on tyhjä tai sen pituus on 0, se löytyy triviaalisti indeksistä 0.
       Tässä oletamme, että m > 0. Jos m = 0, halutaan todennäköisesti palauttaa 0 
       (tällainen erikoistapaus ei ole tehtävässä mainittu, olettaen m > 0). */
    if (m > n) {
        /* mita on pidempi kuin mista, ei löydy */
        return n;
    }

    for (i = 0; i <= n - m; i++) {
        /* Tarkista jokaiselle i:lle, löytyykö mita tästä kohdasta. */
        /* Käydään läpi m alkioita, jokainen alkio koostuu 'koko' tavusta. */
        int found = 1; /* Oletetaan löytyneeksi, kunnes todistetaan toisin */
        for (j = 0; j < m; j++) {
            for (k = 0; k < koko; k++) {
                if (A[(i + j)*koko + k] != B[j*koko + k]) {
                    found = 0;
                    break;
                }
            }
            if (!found) break;
        }

        if (found) return i;
    }

    return n; /* Ei löydetty */
}

