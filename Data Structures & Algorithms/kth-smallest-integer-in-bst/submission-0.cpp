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

    void inorder(vector<int>& vec, TreeNode* root) const{
        if(root == nullptr)
            return;

        inorder(vec, root->left);
        vec.push_back(root->val);
        inorder(vec, root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> in_order;
        inorder(in_order, root);
        // k is consider being in the range
        return in_order[k-1];
    }
};