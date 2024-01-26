#include <stdio.h>

int strrindex(char source[], char searchfor[]);
char pattern[] = "ould";

/* pattern to search for */
/* find all lines matching pattern */
int main() {
    char* test = "Could, should, would return 19";
    int idx = strrindex(test, pattern);
    printf("Found index: %d\n", idx);
    char* notFound = "There is no match";
    idx = strrindex(notFound, pattern);
    printf("Found index: %d\n", idx);
}


/* strindex: return right most index of t in s, −1 if none */
int strrindex(char s[], char t[]) {
    /* find idx of the last character inside s */
    int idxS, idxT;
    for (idxS = 0; s[idxS] != '\0'; idxS++);
    idxS--;

    /* find idx of the last character inside t */
    for (idxT = 0; t[idxT] != '\0'; idxT++);
    idxT--;

    // walk s in reverse comparing it to t
    int i, j, k;
    for (i = idxS; i >= 0; i--) {
        for (j = i, k = idxT; k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k < idxT && k == -1) {
            return i;
        }
    }
    return -1;
}
