/*
 * @lc app=leetcode.cn id=520 lang=c
 *
 * [520] 检测大写字母
 */

// @lc code=start

bool detectCapitalUse(char *word)
{
    int len = strlen(word);
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            cnt++;
    }
    if (cnt == len || cnt == 0 || cnt == 1 && word[0] >= 'A' && word[0] <= 'Z')
        return true;
    return false;
}

// @lc code=end
