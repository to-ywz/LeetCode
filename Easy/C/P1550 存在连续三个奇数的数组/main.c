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

int array[] = {1, 2, 34, 3, 4, 5, 7, 23, 12};

bool threeConsecutiveOdds(int *arr, int arrSize)
{
    if (arrSize < 3)
    {
        return false;
    }
    int cnt = 0;
    for (int i = 0; i < arrSize; i++)
    {
        cnt = (arr[i] & 1) * ((arr[i] & 1) + cnt);
        if (cnt == 3)
            return true;
    }

    return false;
}

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
    printf("%d\n", threeConsecutiveOdds(array, 9));

    return 0;
}

int peakIndexInMountainArray(int *arr, int arrSize)
{
    int hig = arrSize - 1;
    int low = 0;
    while (hig < low)
    {
        int mid = low + (hig - low) / 2;
        if (arr[mid] < arr[mid + 1])
        { // 还能向后就不是 山峰
            low = mid + 1;
        }
        else
        { // 不用 +1 因为需要判断当前处是否为峰值
            hig = mid;
        }
    }
    return low;
}
