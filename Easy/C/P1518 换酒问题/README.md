# 换酒问题
除夕30件事(10/30)
## 1 题目
![alt](Q.PNG)

## 2 解题思路
> 看到这个题目,就知道了,八成就是数学题,而且很基础的那种,唯一可惜的就是不能向老板借酒.  
>这道题目的思路其实很简单,有两种解法,第一种就是简单的模拟,交换的过程,第二种就是 归纳法 .  
### 2.1 模拟法  
假设有 **7瓶酒, 换一次需要 3个空瓶**, 则有   
>|交换次数|交换空瓶数|空瓶数|获得酒数|总共酒数|
>|--|--|--|--|--|
>|0|0|7|0|7
>|1|6|1|2|9
>|2|3|0|1|10
> 转化为计算过程  
第一次: 可获得酒数量: 7/3 = 2 剩余空瓶数量: 7%3+2 = 3  
第二次: 可获得酒数量: 3/3 = 1 剩余空瓶数量: 3%3+1 = 1  
第三次: 无法交换结束  
转为代数 设:  
> *    **初始酒数:n**  
> *    **交换一次需要的酒瓶数:m**  
> *    **总酒数: count = n;**
>```c
>    while (n/m)
>    {
>        count += n/m;
>        n = n / m + n % m;
>    }
>```

### 2.2 数学法
**设: 有 x 瓶酒,每次交换需要 m 个空瓶, 交换次数为 n**  
> 得 每次交换减少 空瓶数为 m-1, 满足交换条件则有
> x - n(m-1) < m
> 当 条件不成立时 可以得出 n 的最小值, 即
> x - n(m-1) > m => n > (x-n)/(m-1),相等时去最小值
> 故 表达式通式为 x+min((x-n)/(m-1)+1),  
**当然这里有一个前提 x 必须大于等于 m 所以需要额外加一次判断**


## 3 代码
### 3.1 模拟法
```c
int numWaterBottles(int numBottles, int numExchange)
{
    int count = numBottles;
    while (numBottles / numExchange)
    {
        count += numBottles / numExchange;
        // 下次的瓶子
        numBottles = numBottles / numExchange + (numBottles % numExchange);
    }
    return count;
}
```
### 3.2 数学法
```c
int numWaterBottles(int numBottles, int numExchange)
{
    return numBottles >= numExchange ? (numBottles + (numBottles - numExchange) / (numExchange - 1) + 1)
                                     : numBottles;
}
```