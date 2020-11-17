# 两数之和

### 关于 unorderedmap
> unordered map,内部含一个hash表,查找速度会上升 但是 Hash 生成速度慢

### 解题思路
> 利用内置 unordered_map 直接 O(1) 查找
> ```c++
>    HashTable.find(target-num[i]);
>```

### 代码
```c++
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto addend = hashMap.find(target - nums[i]);
            if (addend != hashMap.end())
            {
                return {addend->second, i};
            }
            hashMap[nums[i]] = i;
        }
        return {};
    }
};
```