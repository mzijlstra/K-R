#include <stdio.h>

#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itob(int n, char s[], unsigned int b) {
    int i, sign, digit;
    if ((sign = n) < 0) { /* record sign */
        n = -n;           /* make n positive */
    }

    i = 0;
    do { /* generate digits in reverse order */
        digit = n % b;
        if (digit < 10) {
            s[i++] = digit + '0';
        } else {
            digit -= 10;
            s[i++] = digit + 'A';
        }
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    itob(255, s, 16);
    printf("%s\n", s);
    return 0;
}
