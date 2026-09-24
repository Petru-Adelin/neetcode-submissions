class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i, j, maxA;
		i = 0; j = heights.size()-1;
		maxA = 0;
		// area =  min(h_i, h_j) * (j-i)
		while(i < j){
			int area = min(heights[i], heights[j]) * (j -i);
			maxA = max(maxA, area);
			if(heights[i] < heights[j])
				i++;
			else 
				j--;
		}
		return maxA;
    }
};
