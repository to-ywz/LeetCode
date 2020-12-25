#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SAMP_NUM 10

int removeElement(int *nums, int numsSize, int val)
{
    int cnt = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[cnt++] = nums[i];
        }
    }

    return cnt;
}

int cmp(const void *a, const void *b) { return (*(int *)a) > (*(int *)b) ? 1 : -1; }

int main(void)
{
    int target;
    scanf("%d", &target);
    int sampleArray[SAMP_NUM];
    int seed = (int)time(NULL);
    srand(seed);

    for (int i = 0; i < SAMP_NUM; i++)
    {
        sampleArray[i] = rand() % 10;
    }

    for (int i = 0; i < SAMP_NUM; i++)
    {
        printf("%d ", sampleArray[i]);
    }
    printf("\n");

    int arrszie = removeElement(sampleArray, SAMP_NUM, target);

    for (int i = 0; i < arrszie; i++)
    {
        printf("%d ", sampleArray[i]);
    }

    return 0;
}