/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 */

// @lc code=start

int findComplement(int num)
{
    long temp = 1;
    while (num >= temp)
    {
        temp <<= 1;
    }
    return (temp - 1 - num);
}
// return (int)((long long)(~num) + (long long)(1 << (int)(log2(num)) + 1));
// 原数         取反码(题目期望)  取补码
// 1010(10)     0 101(5)          1 011(-3)
// 1001(09)     0 110(6)          1 010(-2)
// 1011(11)     0 100(4)          1 101(-5)
// 1100(12)     0 011(5)          1 100(-4)
// 取反去掉最高位
// @lc code=end
