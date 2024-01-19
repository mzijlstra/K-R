/* clang-format off */
#include <stdio.h>    
#define MAXLINE 1000

/* maximum input line size */
int mgetline(char line[], int maxline);

/* print longest input line */
int main() {
    int len;
    /* current line length */
    char line[MAXLINE];
    while ((len = mgetline(line, MAXLINE)) > 0) {
        /* remove blank lines */
        if (len == 1 && line[0] == '\n') {
            continue;
        }
        /* remove trailing blanks on non-blank lines */
        while (line[len - 1] == ' ' || line[len - 1] == '\t' ||
               line[len - 1] == '\n') {
            line[len - 1] = '\0';
            --len;
        }
        printf("%s\n", line);
    }
    return 0;
}

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

/* This is a very long line, longer than 80 chars, will the formatter not mess it up? */         
/* This is a very long line, longer than 80 chars, No, I can turn it off using these nifty comments! */
/* clang-format on */
