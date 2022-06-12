#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //use binary search
        //初始化 l r蓝色与红色之外
        int l =-1, r=nums.size();
        int m=0;
        //结束条件蓝色红色相遇
        while(l+1 != r)
        {
            int m = (l+r)/2;
            // 如果为蓝色部分条件 isblue 为 < target
            if(nums[m] < target)
            {
               l =m; 
            }else
            {
               r =m;
            }
        }
        //第一个元素为 红色第一个元素，也就是r
        int first = r;
        //红色第一个也不是target 只是大于target
        if(first==nums.size() || nums[first] != target)
        {
            return {-1,-1};
        }
        l =-1;
        r= nums.size();
        while(l+1 != r)
        {
            m = (l+r)/2;
            if(nums[m] <= target)
            {
                l=m;
            }else
            {
                r =m;
            }
        }
        int last = l;
        // 蓝色最后一个也不是target 只是小于target
        if(last == -1  || nums[last]!= target)
        {
            return {-1,-1};
        }
        return {first,last};
        


    }
};
// @lc code=end

