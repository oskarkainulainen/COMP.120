#include <stdio.h>
#include <string.h>
#include <ctype.h>

int on_palindromi(const char *s) {
    int vasen = 0;
    int oikea = strlen(s) - 1;

    while (vasen < oikea) {
        if (tolower(s[vasen]) != tolower(s[oikea])) {
            return 0;
        }
        vasen++;
        oikea--;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Käyttö: %s <merkkijono> [<merkkijono> ...]\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        if (on_palindromi(argv[i])) {
            printf("\"%s\": on palindromi\n", argv[i]);
        } else {
            printf("\"%s\": ei ole palindromi\n", argv[i]);
        }
    }

    return 0;
}

