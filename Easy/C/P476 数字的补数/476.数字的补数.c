/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 */

// @lc code=start

int findComplement(int num)
{
    int res = 0, index = 0;

    while (num)
    {
        if (!(num % 2))
        {
            res += pow(2, index);
        }
        index++;
        num >>= 1;
    }
    return res;
}

// @lc code=end
