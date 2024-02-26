#include <stdio.h>

#define swap(t, x, y)                                                          \
    {                                                                          \
        t temp = x;                                                            \
        x = y;                                                                 \
        y = temp;                                                              \
    }

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;

    if (left >= right) { /* do nothing if array contains */
        return;          /* fewer than two elements */
    }
    swap(int, v[left], v[(left + right) / 2]); /* move partition elem */
    last = left;
    /* to v[0] */
    for (i = left + 1; i <= right; i++) {
        /* partition */
        if (v[i] < v[left]) {
            ++last;
            swap(int, v[last], v[i]);
        }
    }
    swap(int, v[left], v[last]); /* restore partition elem */

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int main(void) {
    int test[] = {3, 2, 1, 4, 5};
    qsort(test, 0, 4);
    for (int i = 0; i < 5; i++) {
        printf("%d ", test[i]);
    }
    printf("\n");
    return 0;
}
