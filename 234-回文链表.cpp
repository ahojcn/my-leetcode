// https://leetcode-cn.com/problems/palindrome-linked-list/

// 另外还有数组解法

// 1. 找到中间节点、翻转、遍历比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 快慢指针找到中间节点
        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        // 翻转 s 之后的链表
        ListNode* prev = nullptr;
        while (s) {
            ListNode* tmp = s->next;
            s->next = prev;
            prev = s;
            s = tmp;
        }

        // 到这里已经逆序
        while (head && prev) {
            if (head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};