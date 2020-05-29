#include "concat.h"

#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    int len = strlen(a) + strlen(b) + 1;
    char* res = malloc(len * sizeof(char));
    int j = 0;

    for (size_t i = 0; i < strlen(a) - 1; i++) {
        res[j++] = a[i];
    }

    for (size_t i = 0; i < strlen(b) - 1; i++) {
        res[j++] = b[i];
    }

    res[j] = '\0';

    return res;
}
