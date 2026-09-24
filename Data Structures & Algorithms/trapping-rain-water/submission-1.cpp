class Solution {
public:
    

	int trap(vector<int>& height){
		int n = height.size();
		int left, right, max_left, max_right;
		max_left = height[0];
		max_right = height[n-1];
		left = 1 ;
		right = n-2;
		int max_water = 0;
		int water = 0;
		while(left <= right){
			int i = max_left < max_right ? left : right;
			water = min(max_left, max_right) - height[i];
			if(max_left < max_right){
				max_left = max(max_left, height[i]);
				left++;
			}else{
				max_right = max(max_right, height[i]);
				right--;
			}
			if(water > 0)
				max_water += water;
		}
		return max_water;
	}
};