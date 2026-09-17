
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> indeces;
		int left, right;
		left = 0;
		right = numbers.size()-1;
		bool target_missed = true;
		while(left < right && target_missed){
			auto it_right = numbers.begin() + right;
			auto it_left = numbers.begin() + left;
			int diff = target - *it_left;
			// check for the pair 
			if(diff == (*it_right)){
				indeces.push_back(left+1);
				indeces.push_back(right+1);
				target_missed = false;
			}else{
				// moving the targets 
				if(diff > (*it_right))
					// move left
					left++;
				if(diff < (*it_right))
					// move the right
					right--;
			}

		}
		return indeces;
    }
};
