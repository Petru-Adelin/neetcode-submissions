class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2){
            return i1[0] < i2[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        vector<int> base_interval = intervals[0];
        int i = 1;
        int n = intervals.size();
        while(i < n){
            // check the merging property
            if(max(base_interval[0], intervals[i][0]) <= min(base_interval[1], intervals[i][1])){
                base_interval[0] = min(base_interval[0], intervals[i][0]);
                base_interval[1] = max(base_interval[1], intervals[i][1]);
                i++;
                continue;
            }
            res.push_back(base_interval);
            base_interval = intervals[i];
            i++;
        }
        res.push_back(base_interval);
        return res;
    }
};