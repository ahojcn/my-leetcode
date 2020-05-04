// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/

// 1. 平衡二叉树的中序遍历是有序的，
// 所以取遍历后的结果
class Solution {
    vector<int> v;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        dfs(node->left);
        v.push_back(node->val);
        dfs(node->right);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return v[v.size() - k];
    }
};


// 2. 在解法1中做了一些不必要的遍历
// 中序遍历的倒序: 右 左 根
// 当遍历到第 k 大的时候直接返回
class Solution {
    int res, k;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        dfs(node->right);
        if (k == 0) return;
        if (--k == 0) res = node->val;
        dfs(node->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }
};