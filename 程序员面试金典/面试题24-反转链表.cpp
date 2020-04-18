// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

// 1. 原地
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

// 2. 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};