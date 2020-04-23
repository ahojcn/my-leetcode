// https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;

        int depth = 0;
        for (size_t i = 0; i < root->children.size(); ++i) {
            int tmp = maxDepth(root->children[i]);
            depth = max(depth, tmp);
        }

        return depth + 1;  // add root
    }
};