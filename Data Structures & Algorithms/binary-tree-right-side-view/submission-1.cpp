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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            size_t s = q.size();
            // traverse and save the childer
            for(int i = 0; i < s - 1; i++){
                // add the next level children
                TreeNode* current = q.front();
                q.pop();
                if(current->left != nullptr)
                    q.push(current->left);
                if(current->right != nullptr)
                    q.push(current->right);
            }
            // treat the last node separately
            TreeNode* visible = q.front();
            q.pop();
            res.push_back(visible->val);
            if(visible->left != nullptr)
                q.push(visible->left);
            if(visible->right != nullptr)
                q.push(visible->right);
        }
        return res;
    }
};