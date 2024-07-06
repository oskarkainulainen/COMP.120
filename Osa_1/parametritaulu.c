#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_length(int num) {
    int length = 0;
    if (num == 0) return 1;
    while (num > 0) {
        num /= 10;
        length++;
    }
    return length;
}

int main(int argc, char *argv[]) {
    int i, j;
    int max_index_width = 0;
    int max_param_width = 0;
    int table_width;
    int index_length, param_length;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <param1> [param2 ... paramN]\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        index_length = num_length(i);
        if (index_length > max_index_width) {
            max_index_width = index_length;
        }

        param_length = strlen(argv[i]);
        if (param_length > max_param_width) {
            max_param_width = param_length;
        }
    }

    max_index_width += 2;
    max_param_width += 2;
    table_width = 1 + max_index_width + 1 + max_param_width + 1;

    for (i = 0; i < table_width; i++) {
        printf("#");
    }
    printf("\n");

    for (i = 1; i < argc; i++) {
        printf("# %*d | %-*s #\n", max_index_width - 2, i, max_param_width - 2, argv[i]);

        if (i < argc - 1) {
            printf("#");
            for (j = 0; j < max_index_width; j++) {
                printf("-");
            }
            printf("+");
            for (j = 0; j < max_param_width; j++) {
                printf("-");
            }
            printf("#\n");
        }
    }

    for (i = 0; i < table_width; i++) {
        printf("#");
    }
    printf("\n");

    return 0;
}

