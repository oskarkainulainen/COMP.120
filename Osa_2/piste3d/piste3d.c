#include "piste3d.h"
#include <math.h>
#include <stdio.h>

double etaisyys(Piste3D p1, Piste3D p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y) +
                (p1.z - p2.z) * (p1.z - p2.z));
}

void tulosta(Piste3D p, int tarkkuus) {
    char format[20];
    sprintf(format, "(%%.%df, %%.%df, %%.%df)", tarkkuus, tarkkuus, tarkkuus);
    printf(format, p.x, p.y, p.z);
}

