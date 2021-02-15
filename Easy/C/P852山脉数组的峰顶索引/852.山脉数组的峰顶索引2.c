/*
 * @lc app=leetcode.cn id=852 lang=c
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start

int peakIndexInMountainArray(int *arr, int arrSize)
{
    int hig = arrSize - 1;
    int low = 0;
    while (hig > low)
    {
        int mid = low + (hig - low) / 2;
        if (arr[mid] < arr[mid + 1])
        {// 还能向后就不是 山峰
            low = mid + 1;
        }
        else
        { // 不用 +1 因为需要判断当前处是否为峰值
            hig = mid;
        }
    }
    return low;
}
// @lc code=end
