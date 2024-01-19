#include <stdio.h>

int rightrot(unsigned int x, int n);

int main() {
    printf("%d\n", rightrot(0b10101010, 3));
    return 0;
}

int rightrot(unsigned int x, int n) {
    unsigned int last_bit = ~0;
    last_bit = ~(last_bit >> 1);
    for (int i = 0; i < n; ++i) {
        printf("x = %u\n", x);
        if (x & 1) {
            x >>= 1;
            x |= last_bit;
        } else {
            x >>= 1;
        }
    }
    return x;
}
