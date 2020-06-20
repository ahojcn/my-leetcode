// https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

        ListNode *tail = nullptr, *cur = pHead;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = tail;
            tail = cur;
            cur = tmp;
        }

        return tail;
    }
};
