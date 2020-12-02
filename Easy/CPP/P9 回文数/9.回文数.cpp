/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (0 == x % 10 && x != 0))
        {
            return false;
        }

        int resx = x;
        int num = 0;
        try
        {
            while (x)
            {
                if (num > INT_MAX / 10)
                {
                    throw - 1;
                }
                num *= 10;
                num += (x % 10);
                x /= 10;
            }
        }
        catch (...)
        {
            return false;
        }
        if (resx == num)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
