/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0; // 默认设置为 0
    int *resArray = (int *)malloc(sizeof(int) * 2);
    /** 
     * 两重 for 每一次 i 访问的值都被当做一个加数
     * 暴力, 会死在 相同大量数值重复的数组上,无法排序,排序后找不到原序
     */
    for (int i = 0; i < numsSize; i++)
    { // 确定一个数
        int temp = target - nums[i];
        for (int j = i + 1; j < numsSize; j++)
        { // 寻找另一个数
            if (temp == nums[j])
            {
                resArray[0] = i;
                resArray[1] = j;
                *returnSize = 2;
                return resArray;
            }
        }
    }
    return resArray;
}

// @lc code=end
