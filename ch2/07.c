#include <stdio.h>

unsigned int invert(unsigned x, unsigned p, unsigned n) {
    unsigned int mask = ~(~0 << n) << (p - n + 1);
    return x ^ mask;
}

int main() {
    unsigned int x = 0b11111111;
    unsigned int p = 4;
    unsigned int n = 3;
    printf("%d\n", invert(x, p, n));
    return 0;
}
