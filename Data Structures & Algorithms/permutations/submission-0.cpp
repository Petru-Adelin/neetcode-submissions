class Solution {


public:


    void bkt(vector<int>& nums, vector<bool>& freq, vector<int>& partial, vector<vector<int>>& results){
        if(partial.size() == nums.size()){
            results.push_back(partial);
            return;
        }
        for(int i = 0 ; i < nums.size(); ++i){
            if(freq[i] == false){
                partial.push_back(nums[i]);
                freq[i] = true;
                bkt(nums, freq, partial, results);

                partial.pop_back();
                freq[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<bool> freq(7, false);
        vector<int> partial;
        bkt(nums, freq, partial, results);
        return results;
    }
};