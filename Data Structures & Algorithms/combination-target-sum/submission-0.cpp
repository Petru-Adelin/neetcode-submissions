using vect = vector<int>;
using solution = vector<vector<int>>;
using map_int_vect = map<int, vector<int>>;
using umap_int_vect = unordered_map<int, vector<int>>;


class Solution {
public:

	int sum(vect& v){
		return accumulate(v.begin(), v.end(), 0);
	}

	void backt(vect& nums, int target, vect& partial, solution& sol){
		if(sum(partial) == target)
			sol.push_back(partial);
		// loop all the elements into a combination 
		for(auto it = nums.begin(); it != nums.end(); it++){
			// check the posibility of partial solution and then recur
			if((*it) + sum(partial) <= target){
				partial.push_back(*it);
				backt(nums, target, partial, sol);
			}
			// pop the element to search other possible solutions
			partial.pop_back();
		}
	}

	/**
	 * ERRORS corrected: 1. O(n) sum computation overhead 
	 * 					 2. Pop_back() outside the if() logic so that the infinite recursion will not occur 
	 * 					 3. Duplicate combiantion solutions
	 */
	void backt2(int start, vect& nums, int remaining, vect& partial, solution& sol) {
        if (remaining == 0) {
            sol.push_back(partial);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] <= remaining) {
                partial.push_back(nums[i]);
				// i passed to use the same element -> i+1 would force us to use the next element as the for loop starts from i
                backt2(i, nums, remaining - nums[i], partial, sol);
                partial.pop_back(); 
            }
		}
	}

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solution sol;
        vect partial;
        backt2(0, nums, target, partial, sol);
        return sol;
    }
};
