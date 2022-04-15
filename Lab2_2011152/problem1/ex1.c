#include <stdio.h>
#include <stdlib.h>

#include "ex1.h"

void *aligned_malloc(unsigned int size, unsigned int align)
{
    void *first, *res;
    size_t tmp = align - 1 + sizeof(void*);
    first = (void*)malloc(size + tmp);
    if (size == 0 || first == NULL) return NULL;
    size_t tmp_addr = (size_t)first + tmp;
    res = (void*)(tmp_addr & ~((size_t)(align - 1)));
    *((size_t*)res - 1) = (size_t)first;
    return res;
}

void *aligned_free(void* ptr)
{
    free((void*)(((size_t*)ptr))[-1]);
}