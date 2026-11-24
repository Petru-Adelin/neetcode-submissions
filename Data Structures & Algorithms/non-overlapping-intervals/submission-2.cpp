class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return 0;

        auto comp = [](const vector<int>& i1, const vector<int>& i2){
            return i1[0] < i2[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int prev_end = intervals[0][1];
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] >= prev_end){
                res.push_back(intervals[i]);
                prev_end = intervals[i][1];
            }else{

                // check the min end
                if(intervals[i][1] < prev_end){
                    res.pop_back();
                    res.push_back(intervals[i]);
                    prev_end = intervals[i][1];
                }
            }
        }
        return intervals.size() - res.size();
    }
};
