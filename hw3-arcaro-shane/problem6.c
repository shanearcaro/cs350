#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printValue(char* input);

int main(int argc, char* argv[]) {
    char* string = "0 01111110 10000000000000000000000";
    printValue(string);

    return 0;
}

void printValue(char* input) {
    printf("b=%s\n", input);
    int sign = strncmp(input, "0", 1) == 0 ? 1 : -1;

    input = input + 9;
    int exponent = 0;
    for (int i = 9; i >= 2; i--) {
        if (strncmp(input, "1", 1) == 0)
            exponent += 1 << (9 - i);
        input = input - 1;
    }
    exponent -= 127;

    int numerators[23];
    int denominators[23];

    // Have to add one for signed bit here

    input = input + 10;
    for (int i = 0; i < 23; i++) {
        if (strncmp(input, "1", 1) == 0) {
            numerators[i] = 1;
            denominators[i] = 2 << i;
        }
        else {
            numerators[i] = 0;
            denominators[i] = 0;
        }
        input = input + 1;
    }

    // Do some fraction math
    int f_num = 0;
    int f_denom = 0;
    for (int i = 0; i < 23 - 1; i++) {
        if (f_denom == 0) {
            f_num = numerators[i];
            f_denom = denominators[i];
        }
        else {
            if (denominators[i] != 0) {
                int offset = denominators[i] / f_denom;
                f_num = f_num * offset + 1;
                f_denom = denominators[i];
            }
        }
    }
    // Add the first bit
    f_num += f_denom;

    if (f_num == 0 && f_denom == 0) {
        f_num = f_denom = 1;
    }

    // Bit shift doesn't work for fractional numbers
    // When the exponent was greater than 0 bit shifting is fine
    // When the exponent is less than 0 bit shift causes overflow
    // Just have to use a double to calculate the exponent unfortunately.

    double power = 1;
    int length = exponent;
    if (exponent < 0)
        length *= -1;

    for (int i = 0; i < length; i++) {
        if (exponent > 0)
            power = power * 2;
        else
            power = power / 2;
    }

    printf("f=%f\n", sign * ((double) f_num / f_denom) * power);
}