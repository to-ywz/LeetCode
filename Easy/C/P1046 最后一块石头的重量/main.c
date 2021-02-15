#include <math.h>
#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 30

int cmp(const void *a, const void *b) { return *(int *)a < *(int *)b ? 1 : -1; }

int lastStoneWeight(int *stones, int stonesSize);

int stone[MAX_SIZE] = {2, 7, 4, 1, 8, 1};

int main(void)
{
    int seed = time(NULL);
    srand(seed);

    int n = rand() % 31;
    printf("%d\n", n);

    // 获取正确 样例
    putchar('[');
    for (int i = 0; i < n; i++)
    {
        stone[i] = rand() % 1001;
        printf("%d,", stone[i]);
    }
    putchar('\b');
    printf("]\n");

    // printf("%d\n", lastStoneWeight(stone, sizeof(stone) / sizeof(stone[0])));
    printf("%d\n", lastStoneWeight(stone, n));

    return 0;
}

int lastStoneWeight(int *stones, int stonesSize)
{
    if (1 == stonesSize)
        return stones[0];
    qsort(stones, stonesSize, sizeof(int), cmp);
    while (stones[1] != -1)
    {
        if (stones[0] == stones[1])
        {
            stones[0] = stones[1] = -1;
        }
        else
        {
            stones[0] -= stones[1];
            stones[1] = -1;
        }
        qsort(stones, stonesSize, sizeof(int), cmp);
    }
    return stones[0] == -1 ? 0 : stones[0];
}
