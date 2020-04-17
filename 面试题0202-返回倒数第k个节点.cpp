// https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/

// 1. 计数，遍历两边
// 时间 O(n) 空间 O(1)
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        
        ListNode* cur = head;
        int count = 1;
        while (cur->next != nullptr) {
            cur = cur->next;
            count++;
        }

        cur = head;
        while (count-- != k) {
            cur = cur->next;
        }

        return cur->val;
    }
};

// 2. 前后指针，遍历一遍
// 时间 O(n) 空间 O(1)
class Solution {
public:
    int kthToLast(ListNode* head, int k) {

        ListNode* s = head;
        ListNode* f = head;
        while (k-- != 0) {
            f = f->next;
        }

        while (f != nullptr) {
            s = s->next;
            f = f->next;
        }

        return s->val;
    }
};