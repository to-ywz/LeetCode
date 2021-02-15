/*
 * @lc app=leetcode.cn id=374 lang=c
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
    int lo = 0;
    int hi = n;
    while (lo <= hi)
    {
        int mi = lo + (hi - lo) / 2;
        int status = guess(mi);
        if (-1 == status)
        {
            hi = mi - 1;
        } 
        else if (1 == status)
        {
            lo = mi + 1;
        }
        else
            return mi;
    }
    return -1;
}
// @lc code=end
