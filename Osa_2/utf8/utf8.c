#include "utf8.h"

void utf8_koodaa(unsigned int merkki, unsigned char utf8[]) {
    if (merkki <= 0x7F) {
        /* 1-tavuinen koodi */
        utf8[0] = merkki;
        utf8[1] = '\0';
    } else if (merkki <= 0x7FF) {
        /* 2-tavuinen koodi */
        utf8[0] = 0xC0 | (merkki >> 6);
        utf8[1] = 0x80 | (merkki & 0x3F);
        utf8[2] = '\0';
    } else if (merkki <= 0xFFFF) {
        /* 3-tavuinen koodi */
        utf8[0] = 0xE0 | (merkki >> 12);
        utf8[1] = 0x80 | ((merkki >> 6) & 0x3F);
        utf8[2] = 0x80 | (merkki & 0x3F);
        utf8[3] = '\0';
    } else if (merkki <= 0x10FFFF) {
        /* 4-tavuinen koodi */
        utf8[0] = 0xF0 | (merkki >> 18);
        utf8[1] = 0x80 | ((merkki >> 12) & 0x3F);
        utf8[2] = 0x80 | ((merkki >> 6) & 0x3F);
        utf8[3] = 0x80 | (merkki & 0x3F);
        utf8[4] = '\0';
    }
}

