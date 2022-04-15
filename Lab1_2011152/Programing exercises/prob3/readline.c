#include <stdio.h>

void strCopy(char *src, char *des)
{
    int i = 0;
    while (src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
}

int read_line(char *str)
{
    char line[512];
    fgets(line, 512, stdin);
    strCopy(line, str);
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9' || str[i] == '\0') return 0;
        ++i;
    }
    return 1;
}