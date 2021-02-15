#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

    int org_num = x;
    int res_num = 0;
    while (org_num)
    {
        if (res_num > INT_MAX / 10)
        {
            return false;
        }
        res_num = res_num * 10 + (org_num % 10);
        org_num /= 10;
    }
    if (res_num == x)
    {
        return true;
    }
    return false;
}

// @lc code=end
