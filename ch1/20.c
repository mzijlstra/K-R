/* clang-format off */
#include <stdio.h>

#define TABINC 4

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (int i = 0; i < TABINC; ++i) {
				putchar(' ');
			}
		} else {
			putchar(c);
		}
	}
}
/* clang-format on */
