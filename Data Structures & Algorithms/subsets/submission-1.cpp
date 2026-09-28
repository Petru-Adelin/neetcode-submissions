#define state pair<int, vector<int>>
#define vect vector<int>()

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

	vector<vector<int>> non_recursive(vector<int>& nums){
		int n = nums.size();
		stack<state>st;
		vector<vector<int>> res;
		st.push({0, vect});
		while(!st.empty()){
			state s = st.top();
			st.pop();
			res.push_back(s.second);
			// add all the numbers inside 
			for(int i = n-1; i > s.first -1; --i){
				auto v = vect;
				v.push_back(nums[i]);
				v.insert(v.end(), s.second.begin(), s.second.end());
				st.push({i+1, v});
			}
		}
		return res;
	}

    vector<vector<int>> subsets(vector<int>& nums) {
		
		return non_recursive(nums);
	}
};