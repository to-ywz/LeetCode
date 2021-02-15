/*
 * @lc app=leetcode.cn id=1518 lang=c
 *
 * [1518] 换酒问题
 */

// @lc code=start

int numWaterBottles(int numBottles, int numExchange)
{
    int count = numBottles;
    while (numBottles / numExchange)
    {
        count += numBottles / numExchange;
        // 下次的瓶子
        numBottles = numBottles / numExchange + (numBottles % numExchange);
    }
    return count;
}
// @lc code=end
