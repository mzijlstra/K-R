#include <stdio.h>

unsigned int sestbits(unsigned int x, unsigned int p, unsigned int n,
                      unsigned int y) {
    unsigned int mask = 0;
    for (int i = 0; i < n; i++) {
        mask = mask << 1;
        mask = mask | 1;
    }
    unsigned int bits = y & mask;
    bits = bits << (p - n);
    mask = mask << (p - n);
    mask = ~mask;

    /* clear target bits */
    x = x & mask;
    return x | bits;
}

int main() {
    unsigned int x = 0x12345678;
    unsigned int y = 0xABCDEF00;
    unsigned int p = 8;
    unsigned int n = 4;
    unsigned int result = sestbits(x, p, n, y);
    printf("0x%X\n", result);
    return 0;
}
