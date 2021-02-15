#include <math.h>
#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 100000

typedef struct ST
{
    int val;
    int index;
} ST_Typedef;

int cmp(const void *a, const void *b)
{ // 防止溢出
    return ((ST_Typedef *)a)->val < ((ST_Typedef *)b)->val ? -1 : 1;
}
int arr[MAX_SIZE] = {40, 10, 20, 30};
int *arrayRankTransform(int *arr, int arrSize, int *returnSize);

int main(void)
{
    int seed = time(NULL);
    srand(seed);

    // int n = rand() % 31;
    // printf("%d\n", n);
    int returnSize;
    // 获取正确 样例
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = rand();
    // }
    // int *res = arrayRankTransform(arr, &n, &n);
    int *res = arrayRankTransform(arr, 4, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", res[i]);
    }
    puts("\n");
    return 0;
}

int *arrayRankTransform(int *arr, int arrSize, int *returnSize)
{
    if (0 == arrSize)
    {
        *returnSize = 0;
        return arr;
    }
    ST_Typedef *numbers = (ST_Typedef *)malloc(arrSize * sizeof(ST_Typedef));
    for (int i = 0; i < arrSize; i++)
    {
        numbers[i].index = i;
        numbers[i].val = arr[i];
    }

    qsort(numbers, arrSize, sizeof(ST_Typedef), cmp);
    int j = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (0 == i || numbers[i].val != numbers[i - 1].val)
        {
            j++;
        }
        arr[numbers[i].index] = j;
    }

    *returnSize = arrSize;
    return arr;
}
