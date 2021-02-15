/*
 * @lc app=leetcode.cn id=1046 lang=c
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start

int cmp(const void *a, const void *b) { return *(int *)a < *(int *)b ? 1 : -1; }

int lastStoneWeight(int *stones, int stonesSize)
{
    if (1 == stonesSize)
        return stones[0];
    qsort(stones, stonesSize, sizeof(int), cmp);
    while (stones[1] != -1)
    {
        if (stones[0] == stones[1])
        {
            stones[0] = stones[1] = -1;
        }
        else
        {
            stones[0] -= stones[1];
            stones[1] = -1;
        }
        qsort(stones, stonesSize, sizeof(int), cmp);
    }
    return stones[0] == -1 ? 0 : stones[0];
}

// @lc code=end
