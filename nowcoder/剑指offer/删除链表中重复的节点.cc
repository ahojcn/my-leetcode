/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;

        ListNode *node = new ListNode(0);
        node->next = pHead;
        pHead = node;

        ListNode *pre = pHead;
        ListNode *cur = pHead->next;
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->val == cur->next->val) {
                ListNode *tmp = cur;
                while (cur->next != nullptr && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                while (tmp != cur) {
                    ListNode *del = tmp;
                    tmp = tmp->next;
                    delete del;
                }
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        node = pHead;
        pHead = pHead->next;
        delete node;
        return pHead;
    }
};

