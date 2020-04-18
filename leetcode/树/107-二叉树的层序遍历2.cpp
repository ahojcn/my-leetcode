// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

// 1. BFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur_level;
            while (size--) {
                TreeNode* cur_node = q.front();  q.pop();
                cur_level.push_back(cur_node->val);
                if (cur_node->left) q.push(cur_node->left);
                if (cur_node->right) q.push(cur_node->right);
            }
            res.push_back(cur_level);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};