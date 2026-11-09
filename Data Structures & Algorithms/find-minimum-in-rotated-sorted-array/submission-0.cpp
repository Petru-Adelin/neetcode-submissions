class Solution {
public:
    int findMin(vector<int> &nums) {
        int st, dr;
        st= 0;
        dr = nums.size()-1;
        while(st < dr){
            int mij = st + (dr - st) / 2;
            if(nums[mij] > nums[dr]){
                st = mij+1;
            }else{
                dr = mij;
            }
        }
        return nums[st];
    }
};