class Solution {
public:

	void backtracking(int i, vector<int>& nums, vector<int>& sol, vector<vector<int>>& res){
		if(i == nums.size()){
			res.push_back(sol);
			return;
		}
		sol.push_back(nums[i]);
		backtracking(i+1, nums, sol, res);
		// return from recursion replace the 
		sol.pop_back();
		backtracking(i+1, nums, sol, res);
	}

    vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> sol;
		vector<vector<int>> res;
		backtracking(0, nums, sol, res);
		return res;
	}
};