// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

// 1. BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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

                if (cur_node->left != nullptr) {
                    q.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    q.push(cur_node->right);
                }
            }
            res.push_back(cur_level);
        }

        return res;
    }
};

// 2. DFS
class Solution {
    vector<vector<int>> res;
    void __levelOrder(TreeNode* root, int lv) {
        if (!root) return;
        if (res.size() == lv) res.resize(lv + 1);
        res[lv].push_back(root->val);
        __levelOrder(root->left, lv+1);
        __levelOrder(root->right, lv+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        __levelOrder(root, 0);
        return res;
    }
};