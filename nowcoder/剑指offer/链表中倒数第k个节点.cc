// https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking


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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p1 = pListHead;
        while (p1 && k--) {
            p1 = p1->next;
        }

        if (!p1 && k != 0) return nullptr;

        ListNode *p2 = pListHead;
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};

