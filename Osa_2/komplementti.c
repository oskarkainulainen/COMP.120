#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char *binary_str;
    int length;
    int value;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <binary_string>\n", argv[0]);
        return 1;
    }

    binary_str = argv[1];
    length = strlen(binary_str);
    value = 0;

    for (i = 1; i < length; i++) {
        if (binary_str[i] == '1') {
            value += (int)pow(2, length - i - 1);
        }
    }

    if (binary_str[0] == '1') {
        value -= (int)pow(2, length - 1);
    }

    printf("%d\n", value);
    return 0;
}

