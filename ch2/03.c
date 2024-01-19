#include <stdio.h>

int htoi(char s[]);

int main() {
    char s[] = "0x1F";
    printf("%d\n", htoi(s));
    return 0;
}

int htoi(char s[]) {
    int i = 0;
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
        i += 2;
    int n = 0;
    for (; s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F' ||
           s[i] >= 'a' && s[i] <= 'f';
         ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a' + 10);
        }
    }
    return n;
}
