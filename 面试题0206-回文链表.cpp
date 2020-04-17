// https://leetcode-cn.com/problems/palindrome-linked-list-lcci/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 快慢指针，找到中间节点
        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
        }

        // 翻转 [s, f) 之间的链表
        ListNode* pre = nullptr;
        while (s) {
            ListNode* tmp = s->next;
            s->next = pre;
            pre = s;
            s = tmp;
        }

        // 遍历比较
        while (head && pre) {
            if (head->val != pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};