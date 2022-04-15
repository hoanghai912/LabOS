#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

int main()
{
    while (1)
    {
        char str[1000];
        //fgets(str, sizeof(str), stdin);
        printf("%d\n", read_line(str));
    }
    return 0;
}