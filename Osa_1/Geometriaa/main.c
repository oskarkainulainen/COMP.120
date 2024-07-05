#include <stdio.h>
#include <stdlib.h>
#include "geometria.h"

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Käyttö: %s <sade1> [<sade2> ...]\n", argv[0]);
        return 1;
    }

    printf("Piin arvo: %.19Lf\n", PII);

    for (i = 1; i < argc; i++) {
        double sade = atof(argv[i]);
        double ala = ympyranAla(sade);
        double tilavuus = pallonTilavuus(sade);
        double piiri = (double)(2.0L * PII * sade);

        printf("Säteen %.6f omaavan ympyrän ala ja pallon tilavuus: %.10f ja %.10f\n", sade, ala, tilavuus);
        printf("Säteen %.6f omaavan ympyrän piiri on %.10f\n", sade, piiri);
    }

    return 0;
}

