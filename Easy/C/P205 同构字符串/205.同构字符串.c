/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isIsomorphic(char *s, char *t)
{
    int len = strlen(s);
    unsigned char sHash[128] = {0}, tHash[128] = {0};

    if (!len)
        return true;

    for (int i = 0; i < len; i++)
    {
        if (!sHash[s[i]])
        {
            sHash[s[i]] = i + 1;
        }
        if (!tHash[t[i]])
        {
            tHash[t[i]] = i + 1;
        }
        if (tHash[t[i]] != sHash[s[i]])
            return false;
    }
    return true;
}
// @lc code=end
