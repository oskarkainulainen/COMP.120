#ifndef KERTOTAULU_H
#define KERTOTAULU_H

/* Määritellään uint alias tyyppille unsigned int */
typedef unsigned int uint;

/* Tietue Kertotaulu */
typedef struct {
    uint a;
    uint b;
    uint c;
    uint d;
    uint **kertotaulu; /* Kaksiulotteinen taulukko kertotaulua varten */
} Kertotaulu;

/* Funktioiden esittelyt */
Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d);
void tuhoaKertotaulu(Kertotaulu *kt);

#endif /* KERTOTAULU_H */

