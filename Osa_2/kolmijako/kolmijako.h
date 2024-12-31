#ifndef KOLMIJAKO_H
#define KOLMIJAKO_H

/* IntPari-tietue */
typedef struct {
    int x; /* pienet1 */
    int y; /* pienet2 */
} IntPari;

/* Funktiomäärittely */
IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2);

#endif /* KOLMIJAKO_H */

