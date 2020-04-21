// 原题的意思是在O(1)时间内删除一个确定在链表中的节点

// 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) return head;

        if (head->val == val) return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};