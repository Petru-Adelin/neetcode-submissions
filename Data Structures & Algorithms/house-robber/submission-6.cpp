class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
       vector<int> results(nums.size(), 0);
       results[0] = nums[0];
       results[1] = max(nums[0], nums[1]);
       for(int i = 2; i < nums.size(); ++i){
            results[i] = max(results[i-1], results[i-2] + nums[i]);
       }
       return results[nums.size()-1];
    }
};
