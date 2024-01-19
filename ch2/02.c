#include <stdio.h>

int main() {
    /* Write a loop equivalent to the for loop above without using && or ||.
     *
     * for (i=0; i<lim−1 && (c=getchar()) != ′\n′ && c != EOF; ++i)
     *     s[i] = c;
     * */
    char c;
    int lim = 1000;
    char s[lim];

    for (int i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        s[i] = c;
    }
}
