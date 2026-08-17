class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i <= nums.size(); ++i){
            // compute the diff
            int diff = target - nums[i];
            auto found_iter = mp.find(diff);
            if(found_iter != mp.end()){
                return {found_iter->second, i};
            }else{
                mp.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};
