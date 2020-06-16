// https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&&tqId=11189&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        set<ListNode*> s;
        ListNode* cur = pHead1;
        while (cur != nullptr) {
            s.insert(cur);
            cur = cur->next;
        }
        
        cur = pHead2;
        ListNode* ret = nullptr;
        while (cur != nullptr) {
            if (s.find(cur) != s.end()) {
                ret = cur;
                break;
            } else {
                cur = cur->next;
            }
        }
        return ret;
    }
};