/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct MyStruct
{
    int value;
    int index;
} NumArray;

int cmp(const void *a, const void *b)
{
    return ((NumArray *)a)->value - ((NumArray *)b)->value;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *resArray = (int *)malloc(2 * sizeof(int));
    *returnSize = 0;

    // 复制数组,存储下数组的值和其序号
    NumArray *numArray = (NumArray *)malloc(sizeof(NumArray) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        numArray[i].index = i;
        numArray[i].value = nums[i];
    }

    // 根据值大小 快速排序
    qsort(numArray, numsSize, sizeof(numArray[0]), cmp);

    for (int i = 0; i < numsSize; i++)
    {
        NumArray key = {.value = target - numArray[i].value};

        // 也是 循环 但采用二分查找 时间复杂度 (logn);
        NumArray *res = bsearch(&key, &numArray[i + 1], numsSize - i - 1, sizeof(numArray[0]), cmp);

        if (res)
        {
            resArray[0] = numArray[i].index;
            resArray[1] = res->index;
            *returnSize = 2;
        }
    }
    return resArray;
}
// 总 时间复杂度 nlogn
// @lc code=end
