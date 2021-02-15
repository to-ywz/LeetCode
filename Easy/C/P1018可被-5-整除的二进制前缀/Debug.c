#include <math.h>
#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool *prefixesDivBy5(int *A, int ASize, int *returnSize)
{
    int temp = 0;
    *returnSize = ASize;
    bool *res = (bool *)calloc(ASize, sizeof(bool));
    for (int i = 0; i < ASize; i++)
    {
        temp = ((temp << 1) + A[i]) % 10;
        if (0 == temp || 5 == temp)
        {
            res[i] = true;
        }
    }
    return res;
}

#define MAXSIZE 30000

void getSample(int n, int *A)
{
    int seed = time(NULL);
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 2;
        printf("%d,", A[i]);
    }
}

int main(void)
{
    int num;
    bool *res;
    int resultSize = 0;
    scanf("%d", &num);
    int A[MAXSIZE] = {0, 1, 1, 1, 1, 1};
    // int A[ ] = {0, 1, 1, 1, 1, 1};

    // const int num = (sizeof(A) / sizeof(A[0]));
    getSample(num, A);
    res = prefixesDivBy5(A, num, &resultSize);

    putchar('[');
    // for (int i = 0; i < resultSize; i++)
    // {
    //     if (res[i])
    //         printf("true%s", (resultSize == i - 1 ? "" : ","));
    //     else
    //         printf("false%s", (resultSize == i - 1 ? "" : ","));
    // }
    // putchar(']');

    return 0;
}

