#include "factorial.h"

int factorial(const int aNumber)
{
    if (aNumber == 0) return 1;
    int tmp = aNumber - 1;
    return aNumber * factorial(tmp); //De quy
}