/*
 * @lc app=leetcode.cn id=1550 lang=c
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start

bool threeConsecutiveOdds(int *arr, int arrSize)
{
    int cnt = 0;
    for (int i = 0; i < arrSize && cnt < 3; i++)
    {
        if (arr[i] & 0x01)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
    }
    if (cnt < 3)
        return false;
    return true;
}

// @lc code=end
