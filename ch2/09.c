#include <stdio.h>

int bitcount(unsigned int x) {
    int b = 0;
    while (x != 0) {
        x &= (x - 1);
        b++;
    }
    return b;
}

int main() {
    unsigned int x = 21;
    printf("%d\n", bitcount(x));
}
