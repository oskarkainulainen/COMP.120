#include "muunto.h"
#include <ctype.h>
#include <string.h>

void muunna(char mj[]) {
    int length = strlen(mj);
    int i;
    for (i = 0; i < length / 2; ++i) {
        /* Swap characters at position i and length-i-1 */
        char temp = mj[i];
        mj[i] = mj[length - i - 1];
        mj[length - i - 1] = temp;
    }

    for (i = 0; i < length; ++i) {
        if (islower(mj[i])) {
            mj[i] = toupper(mj[i]);
        } else if (isupper(mj[i])) {
            mj[i] = tolower(mj[i]);
        }
    }
}

