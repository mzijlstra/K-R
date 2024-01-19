#include <stdio.h>
#define MAXLINE 10
/* maximum input line size */
int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;
    int total;
    /* current line length */
    int max;
    int maxLine;
    int lineNum;
    /* maximum length seen so far */
    char line[MAXLINE];
    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    lineNum = 0;
    maxLine = 0;
    total = 0;
    while ((len = mgetline(line, MAXLINE)) > 0) {
        total += len;
        while (line[len - 1] != '\n') {
            len = mgetline(line, MAXLINE);
            total += len;
        }
        lineNum++;
        if (total > max) {
            max = total;
            maxLine = lineNum;
            copy(longest, line);
        }
        total = 0;
    }
    if (max > 0) {
        /* there was a line */
        printf("Line: %d Length: %d ends with: %s\n", maxLine, max, longest);
    }
    return 0;
}

/* getline: read a line into s, return length */
int mgetline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    if (i == MAXLINE) {
        printf("Error: line is too long\n");
    }
    s[i] = '\0';
    return i;
}

/* copy: copy ′from′ into ′to′; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
