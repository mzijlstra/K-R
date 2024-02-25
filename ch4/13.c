#include <stdio.h>

int reverse(char s[], int pos) {
    char temp = s[pos];
    if (temp == '\0') {
        return 0;
    }
    int rev = reverse(s, pos + 1);
    s[rev] = temp;
    return rev + 1;
}

int main(void) {
    char test[] = "abc123";
    reverse(test, 0);
    puts(test);
}
