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

    bool isValidRec(TreeNode* root, int min = INT_MIN, int max = INT_MAX){
        if(root == nullptr)
            return true;
        if(!(root->val > min && root->val < max))
            return false;
        return isValidRec(root->left, min, root->val) &&  isValidRec(root->right, root->val, max);
        
    }

    bool isValidBST(TreeNode* root) {
        return isValidRec(root);
    }
};