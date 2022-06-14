/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low =-1, high=-1;
        unordered_map<char,int> um;
        while(high<s.size())
        {
            ++high;
            auto it = um.find(s[high]);
            if(it == um.end())
            { 
            // no repeat yet add char and index to um
                um[s[high]] = high;
            }else
            {
                //find repeat char move low to that index
            }
        }
        return high-low;
    }
};
// @lc code=end
int main()
{
    Solution s;
    int res =s.lengthOfLongestSubstring("abcabcbb");

    cout<<res<<endl;
    
}

