/*
 * @lc app=leetcode.cn id=1550 lang=c
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start

bool threeConsecutiveOdds(int *arr, int arrSize)
{
    if (arrSize < 3)
    {
        return false;
    }
    int cnt = 0;
    for (int i = 0; i < arrSize; i++)
    {
        cnt = (arr[i] & 1) * ((arr[i] & 1) + cnt);
        if (cnt == 3)
            return true;
    }

    return false;
}

// @lc code=end
