// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

class Solution {
    bool func(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr || A->val != B->val) return false;
        return func(A->left, B->left) && func(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        return func(A, B) 
            || isSubStructure(A->left, B) 
            || isSubStructure(A->right, B);
    }
};