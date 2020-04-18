// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1. 我刚开始想的，和 26 题很像，所以使用了类似的双指针法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* s = head;
        ListNode* f = head->next;
        while (f != nullptr) {
            if (s->val == f->val) {
                ListNode* tmp = f->next;
                s->next = tmp;
                delete f;
                f = tmp;
            } else {
                s = f;
                f = f->next;
            }
        }
        return head;
    }
};


// 2. 其实一个指针就可以了
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) { return head; }

        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};