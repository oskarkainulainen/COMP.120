#include <stdlib.h>
#include "fibonacci.h"

unsigned int * fib_jono(unsigned int n) {
    unsigned int *fib_array;
    unsigned int i;

    /* If n is 0, return NULL as there are no Fibonacci numbers to generate */
    if (n == 0) {
        return NULL;
    }

    /* Allocate memory for n unsigned integers */
    fib_array = (unsigned int *)malloc(n * sizeof(unsigned int));
    if (fib_array == NULL) {
        return NULL; /* Memory allocation failed */
    }

    /* Initialize the first two Fibonacci numbers */
    fib_array[0] = 0;
    if (n > 1) {
        fib_array[1] = 1;
    }

    /* Calculate the remaining Fibonacci numbers */
    for (i = 2; i < n; i++) {
        fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    }

    return fib_array;
}

