#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}

int main() {
    char s1[] = "hello, world!";
    char s2[] = "hello, world!";
    squeeze(s1, "l");
    printf("%s\n", s1);
    squeeze(s2, "lo");
    printf("%s\n", s2);
    return 0;
}
