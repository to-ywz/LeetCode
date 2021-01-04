# 可被-5-整除的二进制前缀

## 1 题目
![alt](Q.PNG)

## 2 解题思路
> 其实这道题目的 解题思路很简单 就是每一次累乘之后 `%5`,这道题最大的问题是 `A.length < 30000`,这 连 long long 都装不下 ,这里就需要都用到一个定理 **余数定理**
> ```
> (a + b) % q= (a % q + b % q) %q
> (a * b) % p = (a % p * b % p) % p
> ```
>所以 可以每添加一位求一次余数，然后在余数的基础上继续求下一位，依次类推

## 3 代码
> ``` c
> bool *prefixesDivBy5(int *A, int ASize, int *returnSize)
> {
>     int temp = 0;
>     *returnSize = ASize;
>     bool *res = (bool *)calloc(ASize, sizeof(bool));
>     for (int i = 0; i < ASize; i++)
>     {
>         temp = ((temp << 1) + A[i]) % 10;
>         if (0 == temp || 5 == temp)
>         {
>             res[i] = true;
>         }
>     }
>     return res;
> }
> ```