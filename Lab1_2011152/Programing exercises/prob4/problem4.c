#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE *in;
    char line[512];
    int arr[1000];
    in = fopen("numbers.txt", "r");
    int size = 0;
    while (fgets(line, sizeof(line), in) != NULL)
    {
        int val = atoi(line);
        arr[size++] = val;
    }

    int count = 0;

    pid_t pid = fork();

    if (pid == 0)
    {
        int i = 0;
        for (int i = 0; i<size; i++)
        {
            if (arr[i] % 3 == 0) count++;
        }
    }

    else if (pid > 0)
    {
        int i = 0;
        for (int i = 0; i<size; i++)
        {
            if (arr[i] % 2 == 0) count++;
        }
    }
    else printf("Error to create child proccess\n");

    printf("%d\n", count);

    return 0;
}