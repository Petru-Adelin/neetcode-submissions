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


	// OPTIMIZED VERSION 
	int balanced(TreeNode* root){
		if(!root)
			return 0;

		int left = balanced(root->left);
		if (left == -1)return -1; 

		int right = balanced(root->right);
		if(right == -1) return -1;

		if(abs(left-right) > 1) return -1;
		return 1 + max(left, right);
	}

	bool isBalanced(TreeNode* root){
		return balanced(root) != -1;
	}
};
