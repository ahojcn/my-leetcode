// https://leetcode-cn.com/problems/range-sum-of-bst/

class Solution {
    void __func(TreeNode* node, int L, int R) {
        if (!node) return;
        if (node->val >= L && node->val <= R) {
            ans += node->val;
        }
        __func(node->left, L, R);
        __func(node->right, L, R);
    }
    
public:
    int ans;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        ans = 0;
        __func(root, L, R);
        return ans;
    }
};