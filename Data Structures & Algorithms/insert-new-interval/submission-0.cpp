class Solution {
public:
    

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0;

        // push all intervals that are before newInterval => condition: interval[1] < newIntercal[0]
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i++]);
        }

        // push merged interval => condition for merging max(left_sides) <= min(right_sides)
        // merged interval: [min(lefts), max(rights)]
        while(i<n && max(intervals[i][0], newInterval[0]) <= min(intervals[i][1], newInterval[1])){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        // rest
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};