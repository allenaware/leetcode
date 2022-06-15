/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low =0, high=0;
        unordered_set<char> us;
        int maxLength=0;
        while(high<s.size())
        {
            // no repeat yet add char and index to um
            //在窗口中找到了与右边界重复的字符串，然后不断缩小左边界，直至无重复(此情形被去除的左边界不可能为最长字符串)
             while(us.find(s[high])!=us.end())
             {
                us.erase(s[low]);
                low++;
             }
            maxLength = max(maxLength,high-low+1);
            us.insert(s[high]);
             ++high;
        }
        return maxLength;
    }
};
// @lc code=end
int main()
{
    Solution s;
    int res =s.lengthOfLongestSubstring("dvdf");

    cout<<res<<endl;
    
}

