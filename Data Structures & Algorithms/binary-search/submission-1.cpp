class Solution {
public:
    int search(vector<int>& nums, int target) {
		int left, right, mij;
		left = 0, right = nums.size()-1;
		while(left <= right){
			mij = (left + right) / 2;
			if(nums[mij] == target)
				return mij;
			else if(nums[mij] < target)
				left = mij + 1;
			else 
				right = mij - 1;
		}
		return -1;
    }
};