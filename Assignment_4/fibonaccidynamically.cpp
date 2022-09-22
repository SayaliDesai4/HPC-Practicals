// //Fibonacci Series using Dynamic Programming 
// #include<stdio.h>
// int fib(int n)
// {
//     /* Declare an array to store Fibonacci numbers. */ 
//     int f[n+2]; // 1 extra to handle case, n = 0
//     int i;
//     /* 0th and 1st number of the series are 0 and 1*/ 
//     f[0] = 0;
//     f[1] = 1;
//     for (i = 2; i <= n; i++)
//     {
//         /* Add the previous 2 numbers in the series and store it */
//         f[i] = f[i-1] + f[i-2];
//     }
//     return f[n];
// }
// int main ()
// {
//     int n = 9; printf("%d", fib(n)); getchar();
//     return 0;
// }




#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int fib(int n) 
{
    int i, j;
    if (n<2)
        return n;
    else 
    {
        #pragma omp task shared(i)
        i=fib(n-1);
        #pragma omp task shared(j)
        j=fib(n-2);
        #pragma omp taskwait
        return i+j;
    }
}
int main(int argc, char **argv)
{
    int n, result;
    char *a = argv[1];
    n = atoi(a);
    #pragma omp parallel
    {
        #pragma omp single
        result = fib(n);
    }
    printf("Result is %d\n", result);
}