class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
		int sol = 0;
		for(int i = 1; i <= n; i++)
			sol ^= i;
		
		for(int num: nums)
			sol ^= num;
		
		return sol;
    }
};
