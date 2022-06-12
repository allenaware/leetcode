/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include<vector>
#include<iostream>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * result= nullptr, * current = nullptr;
        int carry = 0;
        while(p1!=nullptr || p2 !=nullptr)
        {
            ListNode* newNode = new ListNode();
            if(result == nullptr)
            {
                result = newNode;
                current = newNode;
            }else
            {
                current->next = newNode;
                current = newNode;
            }
            int value =0;
            if(p1 !=nullptr && p2 != nullptr)
            {
                value = p1->val + p2->val + carry;
                carry = value/10;
                value = value - carry * 10;
                p1= p1->next;
                p2= p2->next;
            }else
            if(p1 == nullptr && p2 != nullptr)
            {
                value = p2->val + carry;
                carry = value /10;
                value = value - carry * 10;
                p2 = p2->next;
            }else
            if(p1 != nullptr && p2 == nullptr)
            {
                value = p1->val + carry;
                carry = value / 10;
                value = value - carry * 10;
                p1 = p1->next;
            }
            current->val = value;

        }
        if(carry !=0)
        {
            ListNode * newNode = new ListNode(carry);
            current->next = newNode;
        }
        return result;

    }
};
// @lc code=end
ListNode * buildList(const vector<int>& v)
{
    ListNode * head =nullptr, *current = nullptr;
    for(int i : v)
    {
        ListNode * newNode = new ListNode(i);
        if(head == nullptr)
        {
            head = newNode;
            current = newNode;
        }else
        {
            current->next = newNode;
            current = newNode;
        }

    }
    return head;

}
int main()
{
    auto p1 = buildList({9,9,9,9,9,9,9});
    auto p2 = buildList({9,9,9,9});
    Solution s;
    auto result = s.addTwoNumbers(p1,p2);
    while(result!=nullptr)
    {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;


}
