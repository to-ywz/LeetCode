# 数组序号转换
除夕30件事(4/30)
## 1 题目
![alt](Q.PNG)

## 2 解题思路
除夕 30件事情
回顾 其他解

## 3 代码
``` c
int cmp(const void *a, const void *b) { return *(int *)a < *(int *)b ? 1 : -1; }

int lastStoneWeight(int *stones, int stonesSize)
{
    if (1 == stonesSize)
        return stones[0];
    qsort(stones, stonesSize, sizeof(int), cmp);
    while (stones[1] != -1)
    {
        if (stones[0] == stones[1])
        {
            stones[0] = stones[1] = -1;
        }
        else
        {
            stones[0] -= stones[1];
            stones[1] = -1;
        }
        qsort(stones, stonesSize, sizeof(int), cmp);
    }
    return stones[0] == -1 ? 0 : stones[0];
}
```