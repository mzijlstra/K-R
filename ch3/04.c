#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign, largest_negative;
    if ((sign = n) < 0) { /* record sign */
        if ((n - 1) == -n - 1) {
            largest_negative = 1;
            n = n + 1;
        } else {
            largest_negative = 0;
        }
        n = -n; /* make n positive */
    }

    i = 0;
    do { /* generate digits in reverse order */
        if (largest_negative && i == 0) {
            s[i++] = n % 10 + 1 + '0'; /* get next digit */
        } else {
            s[i++] = n % 10 + '0'; /* get next digit */
        }
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = -2147483648;
    char s[100];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}
