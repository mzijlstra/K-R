#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {
    int i, j, c;
    for (i = j = 0; i < strlen(s1); i++) {
        if (s1[i] == '-' && i > 0 && i < strlen(s1) - 1) {
            for (c = s1[i - 1] + 1; c < s1[i + 1]; c++) {
                s2[j++] = c;
            }
        } else {
            s2[j++] = s1[i];
        }
    }
}

int main() {
    char s1[] = "-a-z0-9-";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}
