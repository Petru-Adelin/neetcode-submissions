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
public:

    int goodrec(TreeNode* root, int prev_max){
        if(root == nullptr)
            return 0;
        short addition = root->val >= prev_max ? 1 : 0;
        return goodrec(root->left, addition == 1 ? root->val : prev_max) + goodrec(root->right, addition == 1 ? root->val : prev_max) + addition;
        
    }

    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        // + 1 for the root 
        return goodrec(root, root->val);
    }
};