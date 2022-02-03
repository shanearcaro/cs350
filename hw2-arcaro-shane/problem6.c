#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>

int saturating_add(int x, int y);

int main(int argc, char* argv[]) {
    printf("Sum: %d\n", saturating_add(INT_MAX, 1));
    return 0;
}

int saturating_add(int x, int y) {
    // Get the sum of the two numbers
    int z = x + y;

    // o_x determines if the number is positive or negative
    // 1 means positive 0 means negative
    int o_1 = ((x & INT_MIN) >> 31) + 1;
    int o_2 = ((y & INT_MIN) >> 31) + 1;
    int o_3 = ((z & INT_MIN) >> 31) + 1;

    // 0 if both numbers have the same sign, 1 otherwise
    int sign = o_1 ^ o_2;

    // Overflow occurs when the sign of x and y are the same but the sign of z is different
    int overflow = !sign && o_1 != o_3;

    // Set conditional variables without using an if statement
    // If overflow happens it means that x and y had the same sign, so if x is positive it must be positive overflow otherwise its negative
    ((overflow && o_1) && (z = INT_MAX) || (overflow && !o_1) && (z = INT_MIN));
    return z;
}