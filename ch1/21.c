/* clang-format off */
#include <stdio.h>

#define TABINC 4

int main() {
    int c;
    int count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++count;
            if (count == TABINC) {
                putchar('\t');
                count = 0;
            }
        } else {
            if (count > 0) {
                for (int i = 0; i < count; ++i) {
                    putchar(' ');
                }
            }
            count = 0;
              putchar(c);
        }
    }
}
