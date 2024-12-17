/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smallHead = new ListNode(0);
        ListNode *largeHead = new ListNode(0);
        ListNode *sml = smallHead;
        ListNode *lag = largeHead;
        while (head) //顺序遍历链表
        {
            ListNode *head_next = head->next;
            if (head->val < x)
            {
                sml->next = head;
                sml = sml->next;
            }
            else
            {
                lag->next = head;
                lag = lag->next;
            }
            head = head->next;
        }
        // 链接两个链表
        lag->next = nullptr;
        sml->next = largeHead->next;
        ListNode* ans = smallHead->next;
        delete smallHead;
        delete largeHead;
        return ans;
    }
};
// 双指针解法
// 构造两个链表，分别链接<x 和 >=x的节点
// 连接两个链表
// @lc code=end
