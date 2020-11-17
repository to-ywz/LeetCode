/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x)
        {
            if (INT_MAX / 10 < res || INT_MIN / 10 > res)
            {
                return 0;
            }
            res = res * 10 + (x % 10);
            x /= 10;
        }
        return res;
    }
};
// @lc code=end
