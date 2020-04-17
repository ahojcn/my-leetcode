// https://leetcode-cn.com/problems/delete-middle-node-lcci/

// 不是中间的那个中间，是(head, tail)之间的任何一个节点
// 1 -> 5 -> 9 -> 12  删除 9 这个节点
// 1 -> 5 -> 12

// emm
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* t = node->next;
        node->next = t->next;
        delete t;
    }
};