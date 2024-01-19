#include <stdio.h>

int main() {
    int c;
    int string = 0;
    int character = 0;
    int comment = 0;
    while ((c = getchar()) != EOF) {
        if (!comment) {
            if (c == '\'' && !string) {
                character = !character;
                putchar(c);
            } else if (c == '"' && !character) {
                string = !string;
                putchar(c);
            } else if (c == '/') {
                int next = getchar();
                if (next == '*') {
                    comment = 1;
                } else {
                    putchar(c);
                    putchar(next);
                }
            } else {
                putchar(c);
            }
        } else {
            if (c == '*' && (c = getchar()) == '/') {
                comment = 0;
            }
        }
    }
}
