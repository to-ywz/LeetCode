/*
 * @lc app=leetcode.cn id=1331 lang=c
 *
 * [1331] 数组序号转换
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct ST
{
    int val;
    int index;
} ST_Typedef;

int cmp(const void *a, const void *b)
{ // 防止溢出
    return ((ST_Typedef *)a)->val < ((ST_Typedef *)b)->val ? -1 : 1;
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

// @lc code=end
