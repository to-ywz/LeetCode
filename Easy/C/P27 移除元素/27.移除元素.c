/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start

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
// @lc code=end
