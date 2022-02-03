#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char* compareU(signed long constant1, unsigned long constant2);
char* compare(long constant1, long constant2);

int main(int argc, char* argv[]) {
    printf("%13d %16dU%10s\n", 0, 0, compareU(0, 0));
    printf("%13d %17d%10s\n", 0, 0, compare(-1, 0));
    printf("%13d %16dU%10s\n", -1, 0, compareU(-1, 0));
    printf("%13d %17d%10s\n", INT_MAX, -INT_MAX-1, compare(INT_MAX, INT_MIN));
    printf("%12dU %17d%10s\n", INT_MAX, -INT_MAX-1, compareU(INT_MAX, INT_MIN));
    printf("%13d %17d%10s\n", -1, -2, compare(-1, -2));
    printf("(unsigned)%3d %17d%10s\n", -1, -2, compareU(-1, -2));
    printf("%13d %16dU%10s\n", INT_MAX, INT_MAX + 1, compareU(INT_MAX, INT_MAX + 1));
    printf("%13d (int)%9dU%10s\n", INT_MAX, INT_MAX + 1, compareU(INT_MAX, (int) (INT_MAX + 1)));

}

char* compareU(signed long constant1, unsigned long constant2) {
    if (constant1 == constant2)
        return "==";
    else if (constant1 > constant2)
        return ">";
    return "<";
}

char* compare(signed long constant1, signed long constant2) {
    if (constant1 == constant2)
        return "==";
    else if (constant1 > constant2)
        return ">";
    return "<";
}