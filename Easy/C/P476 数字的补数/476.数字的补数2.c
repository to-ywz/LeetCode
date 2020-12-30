/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 */

// @lc code=start

int findComplement(int num)
{
    int res = 0, count = 0;

    while (num)
    {
        res |= (num & 1 ? 0 : 1 << count);
        ++count;
        num >>= 1;
    }

    return res;
}
// @lc code=end
