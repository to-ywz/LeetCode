/*
 * @lc app=leetcode.cn id=1518 lang=c
 *
 * [1518] 换酒问题
 */

// @lc code=start

int numWaterBottles(int numBottles, int numExchange)
{
    return numBottles >= numExchange ? (numBottles + (numBottles - numExchange) / (numExchange - 1) + 1)
                                     : numBottles;
}
// @lc code=end
