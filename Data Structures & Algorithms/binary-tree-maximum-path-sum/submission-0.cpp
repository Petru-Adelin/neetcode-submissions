/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    private:
        int res = INT_MIN;

public:

    int pathRec(TreeNode* node){
        if(node == nullptr)
            return 0;
        
        // if the path itself is negative we can go without considering it <=> +0
        int left = max(pathRec(node->left), 0);
        int right = max(pathRec(node->right), 0);

        // bending through the node
        res = max(res, node->val+left+right);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        pathRec(root);
        return res;
    }
};