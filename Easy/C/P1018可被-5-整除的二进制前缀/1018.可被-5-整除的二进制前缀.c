/*
 * @lc app=leetcode.cn id=1018 lang=c
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *prefixesDivBy5(int *A, int ASize, int *returnSize)
{
    int temp = 0;
    *returnSize = ASize;
    bool *res = (bool *)calloc(ASize, sizeof(bool));
    for (int i = 0; i < ASize; i++)
    {
        temp = ((temp << 1) + A[i]) % 10;
        if (0 == temp || 5 == temp)
        {
            res[i] = true;
        }
    }
    return res;
}

// @lc code=end
