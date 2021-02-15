/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (0 == strsSize)
        return "";

    // 横向扫描
    for (int i = 1; i < strsSize; i++)
    {
        for (int j = 0; strs[0][j]; j++)
        {
            if (strs[0][j] != strs[i][j])
            {
                strs[0][j] = '\0';
                break;
            }
        }
    }
    return strs[0];
}
// @lc code=end
