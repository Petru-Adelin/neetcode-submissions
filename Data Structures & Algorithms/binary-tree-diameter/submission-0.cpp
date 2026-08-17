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

	int getHeight(TreeNode* node, int& rez){
		if(node == nullptr)
			return 0;
		int left = getHeight(node->left, rez);
		int right = getHeight(node->right, rez);
		rez = max(rez, left+right);
		return 1 + max(left, right);
	}

    int diameterOfBinaryTree(TreeNode* root) {
		int rez = 0;
		this->getHeight(root, rez);
		return rez;
    }
};