// https://leetcode-cn.com/problems/reverse-linked-list

// 1. 原地反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
};

// 2. 其实不用判断 head
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};