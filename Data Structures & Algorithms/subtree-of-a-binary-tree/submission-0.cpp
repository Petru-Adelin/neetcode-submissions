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

    /**
	 * IF NODE == NULLPTR => ADD A #
	 * IF NODE != NULLPTR => ADD THE <VALUE>
	 */
	void tostr(TreeNode* root, string& form){
		if(root == nullptr){
			form += ",#";
			return;
		}
		
		form += format(",{}", root->val);
		tostr(root->left, form);
		tostr(root->right, form);
	} 

	/**
	 * BUILDING THE LPS VECTOR FOR MIRRORING MATHCING 
	 */
	vector<int> buildLPS(string& pattern){
		int len = 0;
		int size = pattern.size();
		vector<int> lps (size, 0);
		int i = 1;
		while(i < size){
			if(pattern[i] == pattern[len]){
				lps[i++] = ++len;
			}else{
				if(len != 0)
					len = lps[len-1];
				else
					i++;
			}
		}
		return lps;
	}

	/**
	 * KMP search based on the LPS vector of the serialized forms of the trees
	 */
	bool kmpsearch(string& source, string& patt){
		auto lps = this->buildLPS(patt);
		int i = 0, j = 0;
		while(i < source.size()){
			// move further on char match 
			if(source[i] == patt[j]){
				i++; 
				j++;
			}
			// full pattern match 
			if(j == patt.size())
				return true;

			// in case of mismathced the j jumps back to the lps of the last char (it tells us what portion fo the pattern can be safely jumped because we have it matched previously)
			// if the j == 0 (we have no beginning of the pattern safely matched, then we )
			else if (source[i] != patt[j]){
				if(j != 0){
					j = lps[j-1];
				}else{
					i++;
				}
			}
		}
		return false;
	}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		string s1, s2;
		this->tostr(root, s1);
		this->tostr(subRoot, s2);
		return kmpsearch(s1, s2);
	}
};
