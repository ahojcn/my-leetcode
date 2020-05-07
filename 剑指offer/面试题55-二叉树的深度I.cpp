// https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/

// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int d = 0;
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            d++;
        }

        return d;
    }
};