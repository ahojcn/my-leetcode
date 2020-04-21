// https://leetcode-cn.com/problems/partition-list-lcci/

// 1. 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* s = small;
        ListNode* l = large;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                s->next = cur;
                s = cur;
            } else {
                l->next = cur;
                l = cur;
            }
            cur = cur->next;
        }

        l->next = nullptr;
        s->next = large->next;
        s = small->next;
        delete small;
        delete large;
        return s;
    }
};

// 2.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre = head;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                swap(pre->val, cur->val);
                pre = pre->next;
            }
            cur = cur->next;
        }
        return head;
    }
};