//https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/


// 输入 [3,9,20,null,null,15,7]
// 输出 [[3],[20,9],[],[7,15],[]]
// 预期 [[3],[20,9],[15,7]]
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         stack<TreeNode*> s;
//         s.push(root);
//         vector<vector<int>> vv;

//         while (!q.empty()) {
//             vector<int> v;
//             while (!s.empty()) {
//                 v.push_back(s.top()->val);
//                 s.pop();
//             }
//             vv.push_back(v);
//             TreeNode* cur_node = q.front();
//             q.pop();
//             if (cur_node->left) {
//                 q.push(cur_node->left);
//                 s.push(cur_node->left);
//             }
//             if (cur_node->right) {
//                 q.push(cur_node->right);
//                 s.push(cur_node->right);
//             }
//         }
        
//         return vv;
//     }
// };


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        bool is_left = false;
        while (!q.empty()) {
            int row_len = q.size();
            vector<int> v;
            for (int i = 0; i < row_len; ++i) {
                TreeNode* cur_node = q.front();
                q.pop();
                
                v.push_back(cur_node->val);
                if (cur_node->left) q.push(cur_node->left);
                if (cur_node->right) q.push(cur_node->right);
            }

            is_left = !is_left;
            if (is_left) {
                res.push_back(v);
            } else {
                res.push_back(vector<int>(v.rbegin(), v.rend()));
            }
        }

        return res;
    }
};