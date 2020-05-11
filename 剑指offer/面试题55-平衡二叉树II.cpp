// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }
    int recur(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = recur(root->left);
        if (l == -1) return -1;
        int r = recur(root->right);
        if (r == -1) return -1;
        return abs(l - r) < 2 ? max(l, r) + 1 : -1;
    }
};