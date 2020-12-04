/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

int romanToInt(char *s)
{
    int romanHash[26] = {0};
    romanHash['I' - 'A'] = 1;
    romanHash['V' - 'A'] = 5;
    romanHash['X' - 'A'] = 10;
    romanHash['L' - 'A'] = 50;
    romanHash['C' - 'A'] = 100;
    romanHash['D' - 'A'] = 500;
    romanHash['M' - 'A'] = 1000;

    int res = 0, preNum = 0;
    for (int i = 0; s[i]; i++)
    {
        if (preNum < romanHash[s[i] - 'A'])
        {
            res -= preNum * 2;
        }
        preNum = romanHash[s[i] - 'A'];
        res += preNum;
    }
    return res;
}

// @lc code=end
