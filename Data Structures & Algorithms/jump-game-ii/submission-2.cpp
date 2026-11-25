class Solution {
public:
    int jump(vector<int>& nums) {
        int reach, max_reach, jump;
        jump = 0;
        reach = 0;
        max_reach = 0;
        if(nums.size() == 1)  
            return 0;
        for(int i = 0; i < nums.size(); i++){
            max_reach = max(max_reach, i + nums[i]);

            // check if the max_reach already to the end
            if(max_reach >= nums.size() -1)
                return jump+1;
        
            if(i == reach){
                jump++;
                reach = max_reach;
            }
        }
        return jump;
    }
};