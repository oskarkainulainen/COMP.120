#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the number of digits in a number */
static int number_length(unsigned long num) {
    int len = 0;
    if (num == 0) return 1;
    while (num != 0) {
        num /= 10;
        len++;
    }
    return len;
}

char *fib_jono_mj(unsigned int n)
{
    /* Variable declarations at the beginning */
    size_t kap = 1;          /* Initial capacity */
    char *mj = NULL;         /* Pointer to the string */
    size_t pit = 0;          /* Number of characters used */
    unsigned long Fi_minus_2 = 0; /* Fibonacci variables */
    unsigned long Fi_minus_1 = 1;
    unsigned long Fi = 0;
    unsigned int i;
    int len_number;
    int m;
    int written;
    char *new_mj;

    /* Allocate initial memory */
    mj = malloc(kap);
    if (!mj) {
        /* Allocation failed */
        return NULL;
    }
    mj[0] = '\0'; /* Initialize as empty string */

    if (n == 0) {
        /* Return empty string */
        return mj;
    }

    for (i = 0; i < n; i++) {
        /* Calculate Fi */
        if (i == 0) {
            Fi = 0;
        } else if (i == 1) {
            Fi = 1;
        } else {
            Fi = Fi_minus_1 + Fi_minus_2;
        }

        /* Compute the length needed for the next number */
        if (i == 0) {
            len_number = number_length(Fi);
        } else {
            len_number = 2 + number_length(Fi); /* Include ", " prefix */
        }

        m = len_number + 1; /* Include space for null terminator */

        /* Check if we need to increase capacity */
        if (pit + m > kap) {
            do {
                kap *= 2; /* Double the capacity */
            } while (pit + m > kap);

            new_mj = realloc(mj, kap);
            if (!new_mj) {
                /* Reallocation failed */
                free(mj);
                return NULL;
            }
            mj = new_mj;
        }

        /* Append the number to the string */
        if (i == 0) {
            written = sprintf(&mj[pit], "%lu", Fi);
        } else {
            written = sprintf(&mj[pit], ", %lu", Fi);
        }

        pit += written; /* Update the position */

        /* Update Fibonacci variables */
        if (i >= 1) {
            Fi_minus_2 = Fi_minus_1;
        }
        Fi_minus_1 = Fi;
    }

    /* Resize the memory to the exact size needed */
    new_mj = realloc(mj, pit + 1);
    if (!new_mj) {
        /* Reallocation failed */
        free(mj);
        return NULL;
    }
    mj = new_mj;

    return mj;
}

