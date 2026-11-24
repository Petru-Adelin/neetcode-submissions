class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> que_idx(queries.size());
        // init 
        for(int i = 0; i < queries.size(); ++i){
            que_idx[i] = {i, queries[i]};
        }
        auto que_comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        };
        auto inter_comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        };

        sort(intervals.begin(), intervals.end(), inter_comp);
        sort(que_idx.begin(), que_idx.end(), que_comp);
        vector<int> res(queries.size());
        auto less = [](const vector<int>& v1, const vector<int>& v2){
            return (v1[1] - v1[0] + 1) > (v2[1] - v2[0] +1);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(less)> pq(less);
        int j = 0;
        for(int i = 0; i < que_idx.size(); ++i){
            while(j < intervals.size() && intervals[j][0] <= que_idx[i].second){
                pq.push(intervals[j++]);
            }
            while(!pq.empty() && pq.top()[1] < que_idx[i].second)
                pq.pop();
            if(!pq.empty())
                res[que_idx[i].first] = (pq.top()[1] - pq.top()[0] +1);
            else 
                res[que_idx[i].first] = -1;
        }
        return res;
    }
};