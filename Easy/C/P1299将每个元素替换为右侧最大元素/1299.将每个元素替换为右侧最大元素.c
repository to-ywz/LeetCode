/*
 * @lc app=leetcode.cn id=1299 lang=c
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int *replaceElements(int *arr, int arrSize, int *returnSize)
{
    int *res = (int *)calloc(arrSize, sizeof(int));

    int maxVal = -1;
    *returnSize = arrSize;
    for (int i = arrSize - 1; i >= 0; i--)
    {// 模拟快慢指针, maxVal 永远比 arr[i] 快
        res[i] = maxVal;
        maxVal = MAX(maxVal, arr[i]);
    }

    return res;
}
// @lc code=end
