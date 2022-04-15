#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

int main()
{
    int *p1 = (int*)aligned_malloc(40, 64);
    printf("%p\n", p1);
    printf("%lu\n", (size_t)p1);

    aligned_free(p1);
    return 0;
}