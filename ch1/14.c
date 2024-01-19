#include <stdio.h>

int main() {
    int c;
    int chars[128];
    for (int i = 0; i < 128; i++) {
        chars[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < 128) {
            if (c >= 'a' && c <= 'z') {
                c -= 32;
            }
            chars[c]++;
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        printf("%c: ", i);
        for (int j = 0; j < chars[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
