class Solution {
public:

    int rob_lin(vector<int>& nums){
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        vector<int> res(n);
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i){
            res[i] = max(res[i-1], res[i-2] + nums[i]);
        }
        return res[n-1];
        
    }

    int rob(vector<int>& nums) {
        // if the first and last house are neighb. then we can just split into 2 problems where either consider the first or the last one 
        if(nums.size() == 1)
            return nums[0];
        vector<int> copy1 = nums, copy2 = nums;
        copy1.pop_back();
        copy2.erase(copy2.begin());
        return max(rob_lin(copy1), rob_lin(copy2));
    }
};
