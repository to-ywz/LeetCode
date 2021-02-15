/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start

int removeDuplicates(int *nums, int numsSize)
{
    if (0 == numsSize)
        return 0;
    int index = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i - 1] != nums[i])
        {
            nums[++index] = nums[i];
        }
    }
    return index + 1;
}
// @lc code=end
