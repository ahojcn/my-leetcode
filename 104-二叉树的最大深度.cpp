// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

// 1. 递归
// 如果没有左、右孩子，那高度为 1
// 有左、右孩子，高度为 1 + max(左，右)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


// 2. 非递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_dept = 0;
        queue<pair<TreeNode*,int> >q;
        q.push({root, 1});
        while(!q.empty()) {
            TreeNode* curr_node = q.front().first;
            int curr_dept = q.front().second;
            q.pop();
            if(curr_node) {
                max_dept =  max(curr_dept, max_dept);
                q.push({curr_node->left, curr_dept+1});
                q.push({curr_node->right, curr_dept+1});
            }
        }
        return max_dept;
    }
};

