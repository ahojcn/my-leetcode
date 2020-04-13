// https://leetcode-cn.com/problems/symmetric-tree

// 1. 递归
// 左子树的左边孩子 == 右子树的右边孩子 
// && 左子树的右孩子 == 右子树的左孩子
class Solution {
    bool __isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        return __isSymmetric(left->left, right->right)
            && __isSymmetric(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return __isSymmetric(root->left, root->right);
    }
};

// 2. 非递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        stack<map<char, TreeNode*>> s;
        map<char, TreeNode*> m;
        m['l'] = root->left;
        m['r'] = root->right;
        s.push(m);

        while (!s.empty()) {
            auto cur = s.top(); s.pop();
            if (cur['l'] == nullptr && cur['r'] == nullptr) continue;
            if (cur['l'] == nullptr || cur['r'] == nullptr) return false;
            if (cur['l']->val != cur['r']->val) return false;

            map<char, TreeNode*> next;
            next['l'] = cur['l']->left;
            next['r'] = cur['r']->right;
            s.push(next);
            next['l'] = cur['l']->right;
            next['r'] = cur['r']->left;
            s.push(next);
        }
        return true;
    }
};