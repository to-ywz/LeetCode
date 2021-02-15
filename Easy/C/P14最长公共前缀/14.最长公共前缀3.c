/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start

char *getPrefix(char *lStr, char *rStr)
{
    for (int i = 0; '\0' != lStr[i]; i++)
    {
        if (lStr[i] != rStr[i])
        {
            lStr[i] = '\0';
            return lStr;
        }
    }
    return lStr;
}

char *getLongestCommonPrefix(char **strs, int start, int end)
{
    if (end == start)
        return strs[start];

    // 二分防溢出
    int mid = (end - start) / 2 + start;

    // 递归分治
    char *lcpL = getLongestCommonPrefix(strs, start, mid);
    char *lcpR = getLongestCommonPrefix(strs, mid + 1, end);

    // 获取最终子序列
    return getPrefix(lcpL, lcpR);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (0 == strsSize)
        return "";

    return getLongestCommonPrefix(strs, 0, strsSize - 1);
}
// @lc code=end
