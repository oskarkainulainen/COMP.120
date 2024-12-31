#include "mjonot.h"
#include <stdlib.h>  /* For malloc, free, NULL */
#include <string.h>  /* For strlen, strcpy */

char ** kopioi_mjt(char **mjt, size_t lkm) {
    size_t i;
    char **kopiot = (char **)malloc(lkm * sizeof(char *));
    if (kopiot == NULL) {
        return NULL;  /* Memory allocation failed */
    }

    for (i = 0; i < lkm; ++i) {
        size_t len = strlen(mjt[i]) + 1;  /* +1 for the null terminator */
        kopiot[i] = (char *)malloc(len * sizeof(char));
        if (kopiot[i] == NULL) {
            /* Memory allocation failed, free previously allocated memory */
            size_t j;
            for (j = 0; j < i; ++j) {
                free(kopiot[j]);
            }
            free(kopiot);
            return NULL;
        }
        strcpy(kopiot[i], mjt[i]);  /* Copy the string */
    }
    return kopiot;
}

