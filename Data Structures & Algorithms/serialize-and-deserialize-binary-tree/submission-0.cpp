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




int init = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
 
class Codec{
private:
    void serialize(TreeNode* root, string& ser){
        if(root == nullptr){
            ser += "#,";
            return;
        }
        ser += to_string(root->val) + ",";
        serialize(root->left, ser);
        serialize(root->right, ser);
    }

    TreeNode* des(stringstream& ss){
        string token;
        if(!getline(ss, token, ','))
            return nullptr;
        if(token == "#")
            return nullptr;
        
        TreeNode* current = new TreeNode(stoi(token));
        current->left = des(ss);
        current->right = des(ss);
        return current;
    }



public:

    string serialize(TreeNode* root) {
        string ser;
        serialize(root, ser);
        return ser;    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return des(ss);
    }


};