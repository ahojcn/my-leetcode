// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

// 1.
class Solution {
    bool helper(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        if (l->val != r->val) return false;

        return helper(l->left, r->right) && helper(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        return helper(root->left, root->right);
    }
};