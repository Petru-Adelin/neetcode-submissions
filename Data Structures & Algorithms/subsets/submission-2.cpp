// Modern C++ Type Aliases (Recommended)
using state = std::pair<int, std::vector<int>>;
using vect = std::vector<int>;
using solution = std::vector<std::vector<int>>;

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
		st.push({0, vect()});
		while(!st.empty()){
			state s = st.top();
			st.pop();
			res.push_back(s.second);
			// add all the numbers inside 
			for(int i = n-1; i > s.first -1; --i){
				auto v = vect();
				v.push_back(nums[i]);
				v.insert(v.end(), s.second.begin(), s.second.end());
				st.push({i+1, v});
			}
		}
		return res;
	}

	solution bit_mapping(vect& nums){
		solution res;
		int n = nums.size();
		int range = 1 << n;
		for(int i = 0; i < range; ++i){
			vect partial_sol;
			for(int j = 0; j < n; ++j){
				if((i & (1 << j))!= 0)
					partial_sol.push_back(nums[j]);
			}
			res.push_back(partial_sol);
		}
		return res;
	}

    vector<vector<int>> subsets(vector<int>& nums) {
		
		return bit_mapping(nums);
	}
};