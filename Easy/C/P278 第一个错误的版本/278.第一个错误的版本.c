/*
 * @lc app=leetcode.cn id=278 lang=c
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int hig = n;
    int low = 1;

    while (hig < low)
    {
        int mid = low + (hig - low) / 2;
        if (isBadVersion(mid))
        {
            hig = mid;
        }
        else
        {
            hig = mid - 1;
        }
    }
    return hig;
}
// @lc code=end
