/*
 * @lc app=leetcode.cn id=1502 lang=c
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start

int cmp(const void *a, const void *b)
{
    return (*(int *)a) < (*(int *)b) ? -1 : 1;
}

bool canMakeArithmeticProgression(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), cmp);
    int diff = arr[1] - arr[0];
    for (int i = 0; i < arrSize - 1; i++)
    {
        if (diff != arr[i + 1] - arr[i])
        {
            return false;
        }
    }
    return true;
}
// @lc code=end
