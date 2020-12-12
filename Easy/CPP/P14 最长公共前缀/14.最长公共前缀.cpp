/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size())
        {
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i)
        {
            char temp = strs[0][i];
            for (int j = 1; j < count; ++j)
            {
                if (i == strs[j].size() || strs[j][i] != temp)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end
