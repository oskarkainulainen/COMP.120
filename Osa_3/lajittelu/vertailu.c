#include <string.h>
#include "rectangle.h"
#include "vertailu.h"

int rectAlaVrt(const void *a, const void *b) {
    Rectangle * const *r1 = (Rectangle * const *)a;
    Rectangle * const *r2 = (Rectangle * const *)b;
    int ala1 = (*r1)->width * (*r1)->height;
    int ala2 = (*r2)->width * (*r2)->height;

    if (ala1 < ala2) return -1;
    else if (ala1 > ala2) return 1;
    return 0;
}

int rectXyVrt(const void *a, const void *b) {
    Rectangle * const *r1 = (Rectangle * const *)a;
    Rectangle * const *r2 = (Rectangle * const *)b;
    int x1 = (*r1)->origin.x;
    int x2 = (*r2)->origin.x;
    int y1, y2;

    if (x1 < x2) return -1;
    else if (x1 > x2) return 1;

    /* x:t samat, verrataan y:tä */
    y1 = (*r1)->origin.y;
    y2 = (*r2)->origin.y;

    if (y1 < y2) return -1;
    else if (y1 > y2) return 1;
    return 0;
}

int rectLeveysVrt(const void *a, const void *b) {
    Rectangle * const *r1 = (Rectangle * const *)a;
    Rectangle * const *r2 = (Rectangle * const *)b;
    int w1 = (*r1)->width;
    int w2 = (*r2)->width;

    if (w1 > w2) return -1; 
    else if (w1 < w2) return 1;
    return 0;
}

int mjPitAakkosVrt(const void *a, const void *b) {
    char * const *x = (char * const *)a;
    char * const *y = (char * const *)b;
    size_t lenx = strlen(*x);
    size_t leny = strlen(*y);
    int cmp;

    if (lenx > leny) return -1;  
    else if (lenx < leny) return 1;
    /* yhtä pitkät, verrataan aakkosjärjestyksessä nousevasti */
    cmp = strcmp(*x, *y);
    if (cmp < 0) return -1;
    else if (cmp > 0) return 1;
    return 0;
}

