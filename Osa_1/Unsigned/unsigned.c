#include <stdio.h>
#include <limits.h>
#include "unsigned.h"

void ucharIntervalli(unsigned char sade, unsigned char askel) {
    unsigned char u, prev_u;
    printf("unsigned char:");
    u = (unsigned char)(-sade);

    /* Negative side */
    while (1) {
        printf(" %u", (unsigned int)u);
        if (u == 0) {
            break; /* Reached zero */
        }
        prev_u = u;
        u += askel;
        if (u < prev_u) {
            /* Check if the wrapped-around value is within the interval */
            if (u <= sade) {
                printf(" %u", (unsigned int)u);
            }
            break; /* Wrapped around */
        }
    }
    printf("\n");
}

void ushortIntervalli(unsigned short sade, unsigned short askel) {
    unsigned short u, prev_u;
    printf("unsigned short:");
    u = (unsigned short)(-sade);

    /* Negative side */
    while (1) {
        printf(" %u", (unsigned int)u);
        if (u == 0 || u == sade) {
            break; /* Reached zero or upper limit */
        }
        prev_u = u;
        u += askel;
        if (u < prev_u) {
            /* Check if the wrapped-around value is within the interval */
            if (u <= sade) {
                printf(" %u", (unsigned int)u);
            }
            break; /* Wrapped around */
        }
    }
    printf("\n");
}

void uintIntervalli(unsigned int sade, unsigned int askel) {
    unsigned int u, prev_u;
    printf("unsigned int:");
    u = (unsigned int)(-sade);

    /* Negative side */
    while (1) {
        printf(" %u", u);
        if (u == 0 || u == sade) {
            break; /* Reached zero or upper limit */
        }
        prev_u = u;
        u += askel;
        if (u < prev_u) {
            /* Check if the wrapped-around value is within the interval */
            if (u <= sade) {
                printf(" %u", u);
            }
            break; /* Wrapped around */
        }
    }
    printf("\n");
}

void ulongIntervalli(unsigned long sade, unsigned long askel) {
    unsigned long u, prev_u;
    printf("unsigned long:");
    u = (unsigned long)(-sade);

    /* Negative side */
    while (1) {
        printf(" %lu", u);
        if (u == 0 || u == sade) {
            break; /* Reached zero or upper limit */
        }
        prev_u = u;
        u += askel;
        if (u < prev_u) {
            /* Check if the wrapped-around value is within the interval */
            if (u <= sade) {
                printf(" %lu", u);
            }
            break; /* Wrapped around */
        }
    }
    printf("\n");
}

