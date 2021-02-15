#include <limits.h>
/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */
// @lc code=start

int reverse(int x)
{
    if (x < 10 && x > -10)
    {
        return x;
    }
    /**
     * 反向构造 每次取余 出来的数 加上 res*10 ,计算前先判断
     */
    int res = 0;
    while (x)
    {
        if (res > INT_MAX / 10 || res < INT_MIN / 10)
        { // 边界判断 当 res
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
// @lc code=end
