#include <stdio.h>
#include <string.h>
#include "kolmijako.h"

/* Apufunktio: vaihdetaan alkioita */
static void vaihda(unsigned char *a, unsigned char *b, size_t koko) {
    size_t i;
    for (i = 0; i < koko; i++) {
        unsigned char temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

/* Apufunktio vertailuun:
   Palauttaa -1 jos a < b,
               0 jos a == b,
               1 jos a > b
   käyttäen annetun vrt-funktion semantiikkaa. */
static int cmp(const void *aa, const void *bb, int (*vrt)(const void *, const void *)) {
    int ab = vrt(aa, bb);
    int ba = vrt(bb, aa);

    /* vrt(a,b) != 0 => a < b
       vrt(a,b) == 0 => a >= b
       vrt(b,a) != 0 => b < a => a > b
       vrt(b,a) == 0 => b >= a */
    if (ab != 0 && ba == 0) {
        /* a < b */
        return -1;
    } else if (ab == 0 && ba == 0) {
        /* a == b */
        return 0;
    } else {
        /* ab == 0 && ba != 0 => a > b */
        return 1;
    }
}

void kolmijako_gen(void *t, size_t n, size_t koko,
                   size_t vipu1, size_t vipu2,
                   int (*vrt)(const void *, const void *),
                   size_t *p1, size_t *p2)
{
    unsigned char *a;
    unsigned char *pv1;
    unsigned char *pv2;
    size_t temp;
    unsigned char *piv1;
    unsigned char *piv2;
    size_t lt, gt, i;
    int c1, c2;

    a = (unsigned char *)t;

    if (n < 2) {
        if (p1) *p1 = 0;
        if (p2) *p2 = (n > 0) ? 0 : 0;
        return;
    }

    pv1 = a + vipu1 * koko;
    pv2 = a + vipu2 * koko;

    /* Varmistetaan että pivot1 <= pivot2 */
    if (cmp(pv1, pv2, vrt) > 0) {
        /* Vaihdetaan pivotit */
        vaihda(pv1, pv2, koko);
        /* Vaihdetaan myös vipuindeksit */
        temp = vipu1;
        vipu1 = vipu2;
        vipu2 = temp;
    }

    /* Vaihdetaan pivot1 ensimmäiseen alkioon */
    if (vipu1 != 0) {
        vaihda(a, a + vipu1 * koko, koko);
    }

    /* Vaihdetaan pivot2 viimeiseen alkioon */
    if (vipu2 != n-1) {
        vaihda(a + (n-1)*koko, a + vipu2 * koko, koko);
    }

    /* Pivotit ovat nyt a[0] ja a[n-1] */
    piv1 = a;                 /* ensimmäinen pivot */
    piv2 = a + (n-1)*koko;    /* toinen pivot */

    lt = 1;
    gt = n - 2;
    i = lt;

    while (i <= gt && gt < n) {
        c1 = cmp(a + i*koko, piv1, vrt);
        if (c1 < 0) {
            /* a[i] < pivot1 */
            vaihda(a + i*koko, a + lt*koko, koko);
            lt++;
            i++;
        } else {
            c2 = cmp(a + i*koko, piv2, vrt);
            if (c2 > 0) {
                /* a[i] > pivot2 */
                while (i < gt && cmp(a + gt*koko, piv2, vrt) > 0) {
                    gt--;
                }
                vaihda(a + i*koko, a + gt*koko, koko);
                gt--;
                if (cmp(a + i*koko, piv1, vrt) < 0) {
                    vaihda(a + i*koko, a + lt*koko, koko);
                    lt++;
                }
                i++;
            } else {
                /* pivot1 <= a[i] <= pivot2 */
                i++;
            }
        }
    }

    lt--;
    gt++;

    vaihda(a, a + lt*koko, koko);
    vaihda(a + (n-1)*koko, a + gt*koko, koko);

    if (p1) *p1 = lt;
    if (p2) *p2 = gt;
}

