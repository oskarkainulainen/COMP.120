#ifndef PVM_H
#define PVM_H

/* Päivämäärä-tietue */
typedef struct {
    int pv;       /* Päivä */
    int kk;       /* Kuukausi */
    int vuosi;    /* Vuosi */
    char vk_pv[3]; /* Viikonpäivä lyhenteenä ("ma", "ti", jne.) */
} Pvm;

/* Funktiot */
Pvm* kasvataPvm(Pvm *pvm);
unsigned int pvmEro(const Pvm *a, const Pvm *b);
void tulostaPvm(Pvm *pvm);

#endif /* PVM_H */

