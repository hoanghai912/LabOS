#include <stdio.h>
#include "readline.h"
#include "factorial.h"

int power(int a, int b)
{
    if (b == 0) return 1;
    if (a == 0 || b == 1) return a;
    return a * power(a, b-1);
}

int sizeStr(char *str)
{
    int count = 0;
    while (str[count] != '\n' && str[count] != '\0')
    {
        ++count;
    }
    return count;
}

int strToInt(char *str)
{
    int res = 0;
    int size = sizeStr(str);
    int tmp = size;
    for (int i = 0; i<size; i++)
    {
        res += (str[i] - '0') * power(10, --tmp);
    }
    return res;
}


int main (int argc , char *argv []){
    while (1)
    {
        //string tmp;
        //fgets(tmp, sizeof(tmp), stdin);
        char tmp[1000];
        if (read_line(tmp) == 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("My factorial is: %d\n", factorial(strToInt(tmp)));
        }
    }
    return 0;
}