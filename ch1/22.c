#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define COLLIM 80    /* minimum length of a line to be printed */

/* getline: read a line into s, return length */
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

int main() {
    int len; /* current line length */
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (len >= COLLIM) {
            // look for a space to break the line
            int found = 0;
            for (int i = 80; i > 0; --i) {
                if (line[i] == ' ' || line[i] == '\t') {
                    line[i] = '\n';
                    found = 1;
                    break;
                }
            }
            if (!found) {
                for (int i = 80; i < MAXLINE && line[i] != '\0'; ++i) {
                    if (line[i] == ' ' || line[i] == '\t') {
                        line[i] = '\n';
                        break;
                    }
                }
            }
        }
        printf("%s", line);
    }
}
/* clang-format off */
/* this is a very long line with some text in it that should totally be broken up into multiple lines because it is way too long to be on a single line */
/* clang-format on */
