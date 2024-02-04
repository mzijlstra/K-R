#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power, e;
    int i, j, sign, eneg, exp;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e') {
        i++;
        e = 10;
        if (s[i] == '-') {
            e = 0.1;
            i++;
        }
        for (exp = 0; isdigit(s[i]); i++) {
            exp = 10.0 * exp + (s[i] - '0');
        }
        for (j = 0; j < exp; j++) {
            val *= e;
        }
    }

    return sign * val / power;
}

int mgetline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* rudimentary calculator */
int main() {
    double sum, atof(char[]);
    char line[MAXLINE];
    int mgetline(char line[], int max);
    sum = 0;
    while (mgetline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
