#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    if (x < 10)
    {
        return true;
    }

    char buf[33] = "";
    // 时间复杂度未知
    sprintf(buf, "%d", x);      // 将 数字转换为字符 双向查找
    int length = strlen(buf);

    for (int i = 0; i < length / 2; i++)
    { // 时间复杂度 对折O(n/2)
        if (buf[i] != buf[length - 1 - i])
        {
            return false;
        }
    }
    return true;
}

// @lc code=end
