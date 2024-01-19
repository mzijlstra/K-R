#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    int lengths[15];
    for (int i = 0; i < 15; i++) {
        lengths[i] = 0;
    }

    int size = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            lengths[size] += 1;
            size = -1;
        } else if (state == OUT) {
            state = IN;
        }
        ++size;
    }
    for (int i = 1; i < 15; i++) {
        printf("%d: ", i);
        for (int j = 0; j < lengths[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
