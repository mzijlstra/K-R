#include <stdio.h>
/* copy input to output; 1st version */
int main() {
    int c = getchar();
    int d = EOF;
    printf("EOF: %d\n", d);
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
