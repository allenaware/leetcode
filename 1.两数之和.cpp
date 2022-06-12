// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> um;
        for(int i =0; i < nums.size(); i++)
        {
            auto foundIt = um.find(nums[i]);
            if( foundIt != um.end())
            {
                return {i,foundIt->second};

            }else
            {
                int remain = target - nums[i];
                um[remain]=i;
            }
        }

        return {-1,-1};

    }
};
// @lc code=end

