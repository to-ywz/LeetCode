#include <string.h>
/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

int romanToInt(char *s)
{
    int sum = 0;
    for (int i = 0; s[i]; i++)
    {
        switch (s[i])
        {
        case 'M': sum += 1000;  break;
        case 'D': sum += 500;   break;
        case 'L': sum += 50;    break;
        case 'V': sum += 5;     break;
        case 'C':
            ('D' == s[i + 1] || 'M' == s[i + 1]) ? (sum -= 100) : (sum += 100);
            break;
        case 'X':
            ('L' == s[i + 1] || 'C' == s[i + 1]) ? (sum -= 10) : (sum += 10);
            break;
        case 'I':
            ('V' == s[i + 1] || 'X' == s[i + 1]) ? (sum -= 1) : (sum += 1);
            break;
        default:
            break;
        }
    }
    return sum;
}


// @lc code=end
