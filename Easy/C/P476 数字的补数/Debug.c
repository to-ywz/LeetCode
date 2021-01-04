#include <math.h>
#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief 本地运行正确
 * */
int findComplement1(int num)
{
    int a = (long)(~num);
    int b = (long)(1 << (int)(log2(num)) + 1);

    return a + b;
}

int findComplement(int num)
{
    int res = 0, index = 0;

    while (num)
    {
        if (!(num & 0x01))
        {
            res += pow(2, index);
        }
        index++;
        num >>= 1;
    }
    return res;
}

int main(void)
{
    int num;

    scanf("%d", &num);

    printf("%d\n", findComplement(num));

    return 0;
}