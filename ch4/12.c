#include <stdio.h>
/* printd: print n in decimal */
int printd(int n, char s[], int i) {
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10) {
        i = printd(n / 10, s, i);
    }

    s[i] = n % 10 + '0';

    if (!(n / 10)) {
        s[i + 1] = '\0';
    }
    return i + 1;
}

int main() {
    char s[100];
    printd(-123, s, 0);
    printf("%s\n", s);
}
