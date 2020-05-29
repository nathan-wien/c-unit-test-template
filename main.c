#include <stdio.h>
#include "add.h"
#include "concat.h"

int main() {
    printf("%s\n", concat("hello", "world"));
    return 0;
}
