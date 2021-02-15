/*
 * @lc app=leetcode.cn id=852 lang=c
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start

int peakIndexInMountainArray(int *arr, int arrSize)
{
    int i = 0;
    while (arr[i] < arr[i + 1])
    {
        i++;
    }
    return i;
}
// @lc code=end
