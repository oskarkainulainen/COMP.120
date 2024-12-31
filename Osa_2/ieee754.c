#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    /* Variable declarations */
    char *bitstr;
    int i;
    int sign_bit;
    int exponent_bits;
    int exponent;
    double fraction;
    double weight;
    double significand;
    double value;

    /* Check for correct number of command-line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s 32-bit-binary-string\n", argv[0]);
        return 1;
    }

    bitstr = argv[1];

    /* Check if the input string has exactly 32 characters */
    if (strlen(bitstr) != 32) {
        fprintf(stderr, "Error: Input must be a 32-bit binary string.\n");
        return 1;
    }

    /* Validate that all characters are '0' or '1' */
    for (i = 0; i < 32; i++) {
        if (bitstr[i] != '0' && bitstr[i] != '1') {
            fprintf(stderr, "Error: Input must consist of '0' and '1' characters only.\n");
            return 1;
        }
    }

    /* Extract the sign bit */
    sign_bit = bitstr[0] - '0';

    /* Extract and calculate the exponent */
    exponent_bits = 0;
    for (i = 1; i <= 8; i++) {
        exponent_bits <<= 1;
        exponent_bits |= bitstr[i] - '0';
    }
    exponent = exponent_bits - 127; /* Subtract the bias (127) */

    /* Calculate the fraction (mantissa) */
    fraction = 0.0;
    weight = 0.5;
    for (i = 9; i < 32; i++) {
        if (bitstr[i] == '1') {
            fraction += weight;
        }
        weight /= 2.0;
    }

    /* Calculate the significand (1 + fraction) */
    significand = 1.0 + fraction;

    /* Calculate the final floating-point value */
    value = significand * pow(2.0, (double)exponent);

    /* Apply the sign */
    if (sign_bit == 1) {
        value = -value;
    }

    /* Print the outputs with the specified precision */
    printf("%.15f\n", significand);
    printf("%d\n", exponent);
    printf("%c\n", sign_bit == 0 ? '+' : '-');
    printf("%.15f\n", value);

    return 0;
}

