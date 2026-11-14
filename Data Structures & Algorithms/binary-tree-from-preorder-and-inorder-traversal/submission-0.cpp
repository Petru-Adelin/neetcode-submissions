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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inord_hash;
        for(int i = 0; i < inorder.size(); ++i){
            inord_hash.insert({inorder[i], i});
        }

        stack<tuple<reference_wrapper<TreeNode*>, int, int>> st;
        TreeNode* root;
        int preord_idx = 0;
        st.push({ref(root), 0, preorder.size()-1});
        while(!st.empty()){
    
            auto [node_ref, left, right] = st.top();
            st.pop();
            // Nullptr case 
            if(left > right)
                node_ref.get() = nullptr;
            else{
                int node_val = preorder[preord_idx];
                preord_idx++;
                node_ref.get() = new TreeNode(node_val);
                // find the index of the ndoe in the inorder
                int mid = inord_hash[node_val];
                st.push({node_ref.get()->right, mid+1, right});
                st.push({node_ref.get()->left, left, mid-1});
                
            }
            
        }
        return root;
    }
};
