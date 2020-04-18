// https://leetcode-cn.com/problems/same-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1. 递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        return (p->val == q->val)
            && (isSameTree(p->left, q->left))
            && (isSameTree(p->right, q->right));
    }
};

// 2. 非递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        stack<map<char, TreeNode*>> s;
        map<char, TreeNode*> m1;
        m1['p'] = p;  m1['q'] = q;
        s.push(m1);

        while (!s.empty()) {
            auto m = s.top();  s.pop();
            if (m['p'] == nullptr && m['q']==nullptr) continue;
            if ((m['p'] != nullptr && m['q'] == nullptr)
                || (m['p'] == nullptr && m['q'] != nullptr)) 
                return false;
            if (m['p']->val != m['q']->val) return false;
            
            map<char, TreeNode*> tmp;
            tmp['p'] = m['p']->left;  tmp['q'] = m['q']->left;
            s.push(tmp);
            tmp['p'] = m['p']->right;  tmp['q'] = m['q']->right;
            s.push(tmp);
        }
        return true;
    }
};