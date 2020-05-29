#include "mergeSort.h"

#include <stdlib.h>

void merge(int* a, int l, int m, int r) {
    int* tmp = malloc(r + 1 * sizeof(int));

    for (int i = l; i <= r; i++) {
        tmp[i] = a[i];
    }

    int p1 = l;
    int p2 = m + 1;

    for (int i = l; i <= r; i++) {
        if (p1 == m + 1) {
            a[i] = tmp[p2++];
        } else if (p2 == r + 1) {
            a[i] = tmp[p1++];
        } else if (tmp[p1] < tmp[p2]) {
            a[i] = tmp[p1++];
        } else {
            a[i] = tmp[p2++];
        }
    }

    free(tmp);
}

void mergeSort(int* a, int l, int r) {
    if (l >= r) {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}