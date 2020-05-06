// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/

// 1. queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() != true) {
            int size = q.size();
            vector<int> cur_lv;
            
            while (size-- != 0) {
                TreeNode* cur_node = q.front();
                q.pop();
                cur_lv.push_back(cur_node->val);
                if (cur_node->left != nullptr) q.push(cur_node->left);
                if (cur_node->right != nullptr) q.push(cur_node->right);
            }

            res.push_back(cur_lv);
        }

        return res;
    }
};

// 2. 递归
class Solution {
    vector<vector<int>> res;

    void __levelOrder(TreeNode* root, int lv) {
        if (root == nullptr) return;

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