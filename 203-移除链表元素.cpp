// https://leetcode-cn.com/problems/remove-linked-list-elements

// 1. 注意判断 head->val == val 的情况
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;

        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        if (head->val == val) {
            cur = head;
            head = head->next;
            delete cur;
        }

        return head;
    }
};

// 2. 哨兵节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 不需要再做判断
        // if (!head) return nullptr;

        ListNode* node = new ListNode(-1);
        node->next = head;
        ListNode* prev = node;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        head = node->next;
        delete node;
        return head;
    }
};

// 3. 递归实现
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;

        head->next = removeElements(head->next, val);

        return head->val == val ? head->next : head;
    }
};