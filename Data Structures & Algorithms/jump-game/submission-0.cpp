class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() -1;
        int i = goal - 1;
        while(goal != 0 && i >= 0){
            if(nums[i] + i >= goal)
                goal = i;
            i--;
        }
        return goal == 0;
    }
};