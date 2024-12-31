#include "kuukaudet.h"
#include <string.h>
#include <ctype.h>

const char *KK_NIMET[KK_LKM] = {
    "tammikuu", "helmikuu", "maaliskuu", "huhtikuu", 
    "toukokuu", "kesäkuu", "heinäkuu", "elokuu", 
    "syyskuu", "lokakuu", "marraskuu", "joulukuu"
};

const char KK_PAIVAT[2][KK_LKM] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int karkausvuosi(int vuosiluku) {
    if ((vuosiluku % 4 == 0 && vuosiluku % 100 != 0) || (vuosiluku % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

char kkPituus(const char *kkNimi, int vuosiluku) {
    int i, j;
    char nimi[10];
    
    for (i = 0; kkNimi[i] != '\0' && i < sizeof(nimi) - 1; i++) {
        nimi[i] = tolower((unsigned char)kkNimi[i]);
    }
    nimi[i] = '\0';
    
    for (i = 0; i < KK_LKM; i++) {
        for (j = 0; KK_NIMET[i][j] != '\0' && nimi[j] != '\0'; j++) {
            if (tolower((unsigned char)KK_NIMET[i][j]) != tolower((unsigned char)nimi[j])) {
                break;
            }
        }
        if (KK_NIMET[i][j] == '\0' && nimi[j] == '\0') {
            return KK_PAIVAT[karkausvuosi(vuosiluku)][i];
        }
    }
    
    return -1;
}

