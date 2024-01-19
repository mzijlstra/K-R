#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_LENGTH 16
/* count lines, words, and characters in input */
int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    int lengths[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++) {
        lengths[i] = 0;
    }

    int size = 0;
    int max = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (size >= MAX_LENGTH) {
                size = MAX_LENGTH - 1;
            }
            lengths[size] += 1;
            if (size != 0 && lengths[size] > max) {
                max = lengths[size];
            }
            size = -1;
        } else if (state == OUT) {
            state = IN;
        }
        ++size;
    }
    printf("\n");
    for (int i = max; i > 0; i--) {
        for (int j = 1; j < MAX_LENGTH; j++) {
            if (lengths[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i < MAX_LENGTH - 1; i++) {
        printf("%2d ", i);
    }
    printf("15+\n");
}
