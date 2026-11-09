class Solution {
public:

    int binary_search(vector<int>& v, int st, int dr, int target){
        if(st > dr)
            return -1;
        int mij = st + (dr - st) / 2;
        if(v[mij] == target)
            return mij;
        if(v[mij] < target)
            return binary_search(v, mij+1, dr, target);
        else 
            return binary_search(v, st, mij-1, target);
    }

    int search(vector<int>& nums, int target) {
        int st = 0, dr = nums.size()-1;
        // finding the cut point of the array 
        while(st < dr){
            int mij = (st + dr) /2 ;
            if(nums[mij] > nums[dr])
                st = mij + 1;
            else 
                dr = mij;
        }
        int res1 = binary_search(nums, 0, st-1, target);
        int res2 = binary_search(nums, st, nums.size()-1, target);
        if(res1 != -1)
            return res1;
        if(res2 != -1)
            return res2;
        return -1;
    }
};