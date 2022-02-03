#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    printf("\t\t\t     Word Size\n");
    printf("Value\t\t8\t\t16\t\t32\t\t64\n\n");

    printf("\t\t0x%x\t\t0x%x\t\t0x%x\t0x%lx\n", UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);
    printf("UMax\t\t%d\t\t%d\t\t%ud\t%lu\n\n", UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);

    printf("\t\t0x%x\t0x%x\t0x%x\t0x%lx\n", SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
    printf("TMin\t\t%d\t\t%d\t\t%d\t%ld\n\n", SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

    printf("\t\t0x%x\t\t0x%x\t\t0x%x\t0x%lx\n", SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX);
    printf("TMax\t\t%d\t\t%d\t\t%d\t%ld\n\n", SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX);

    printf("-1\t\t0x%x\t0x%x\t0x%x\t0x%lx\n\n", (char) -1, (short) -1, (int) -1, (long) -1);

    printf("0\t\t0x%x\t\t0x%x\t\t0x%x\t\t0x%lx\n\n", (char) 0, (short) 0, (int) 0, (long) 0);

    return 0;
}