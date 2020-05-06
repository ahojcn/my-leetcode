// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

// 1. 二叉树的层序遍历
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return res;
    }
};