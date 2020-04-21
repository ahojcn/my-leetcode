// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/

// 1. 递归
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

// 2. 使用栈
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> s;
        s.push(root);
        while (s.empty() != true) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur == nullptr) continue;
            swap(cur->left, cur->right);
            s.push(cur->left);
            s.push(cur->right);
        }
        return root;
    }
};

// 3. 使用队列
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;

        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == nullptr) continue;
            swap(cur->left, cur->right);
            q.push(cur->left);
            q.push(cur->right);
        }
        return root;
    }
};