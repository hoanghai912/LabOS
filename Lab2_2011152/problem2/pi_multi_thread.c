#include <stdio.h>
#include "pthread.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUMTHREADS 32

void* in_point(void *arg)
{
    double *count = (double*)malloc(sizeof(double));
    *count = 0;
    unsigned int t = time(NULL);
    long long points = (long long)arg;
    for (long i = 0; i<points; i++)
    {
        double x = (double)rand_r(&t)/RAND_MAX;
        double y = (double)rand_r(&t)/RAND_MAX;
        if (x*x + y*y <= 1) *count += 1;
    }

    pthread_exit((void*)count);
}

int main()
{
    double nPoints;
    scanf("%lf", &nPoints);
    long limit = nPoints / NUMTHREADS;
    double total = 0;

    pthread_t threads[NUMTHREADS];

    clock_t start = clock();
    for (int i = 0; i<NUMTHREADS; i++)
    {
        pthread_create(&threads[i], NULL, in_point, (void*)limit);
    }

    for (int i = 0; i<NUMTHREADS; i++)
    {
        void* status;
        pthread_join(threads[i], (void*)&status);
        total += *(double*)status;
    }

    clock_t finish = clock();
    double res = 4 * total / nPoints;

    double time_used = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Pi is %lf\n", res);
    printf("Time is %lf\n", time_used);
    return 0;
}