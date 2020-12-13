/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

bool isValid(char *s)
{
    const int len = strlen(s);
    if (len % 2)
        return false;
    int index = -1;
    char *stack = (char *)calloc(len + 1, sizeof(char));

    for (int i = 0; i < len; i++)
    {
        if ('(' == s[i])
        {
            stack[++index] = ')';
        }
        else if ('[' == s[i])
        {
            stack[++index] = ']';
        }
        else if ('{' == s[i])
        {
            stack[++index] = '}';
        }
        else if (index == -1 || stack[index] != s[i])
        {
            return false;
        }
        else
        {
            index--;
        }
    }
    return (-1 == index);
}
// @lc code=end
