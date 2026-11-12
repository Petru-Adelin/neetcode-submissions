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

    void levelOrderIndexed(TreeNode* root,vector<vector<int>>& res, int level = 0){
        if(root == nullptr)
            return;
        // add the node in the vector
        if(res.size() == level)
            res.push_back({});
        res[level].push_back(root->val);
        levelOrderIndexed(root->left, res, level+1);
        levelOrderIndexed(root->right, res, level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderIndexed(root, res);
        return res;
    }
};
