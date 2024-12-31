#ifndef PISTE3D_H
#define PISTE3D_H

typedef struct {
    double x;
    double y;
    double z;
} Piste3D;

double etaisyys(Piste3D p1, Piste3D p2);
void tulosta(Piste3D p, int tarkkuus);

#endif

