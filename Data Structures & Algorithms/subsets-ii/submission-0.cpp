using indeces = vector<int>;
using matrix = vector<vector<int>>;
using int_vect = vector<int>;

class Solution {
public:

    void bkt(int_vect& nums,int start, matrix& results, int_vect& partial){
        if(partial.size() >= nums.size()){
            return;
        }
        for(int i = start; i < nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1])
                continue;
            partial.push_back(nums[i]);
            if(partial.size() <= nums.size())
                results.push_back(partial);
            bkt(nums, i+1, results, partial);
            partial.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        matrix results;
        vector<int> partial;
        results.push_back({});
        bkt(nums, 0, results, partial);
        return results;
    }
};