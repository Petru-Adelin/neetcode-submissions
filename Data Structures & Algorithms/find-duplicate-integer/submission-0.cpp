
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

        }while(slow != fast);

        // they are at the same index 
        slow = 0;
        // move with both again but one step at a time
        do{

            slow = nums[slow];
            fast = nums[fast];
        }while(slow != fast);
        return slow;
    }
};