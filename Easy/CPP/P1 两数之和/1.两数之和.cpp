// @before-stub-for-debug-begin
#include "commoncppproblem1.h"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
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
// @lc code=end
