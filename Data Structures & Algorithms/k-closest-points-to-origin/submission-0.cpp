class Solution {

private:
    struct DistPoint{
        int x, y;
        double dist;

        DistPoint(int x, int y): x(x), y(y), dist(sqrt(x*x+y*y)){}
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //function<bool(const DistPoint& a, const DistPoint& b)>
        auto comp = [](const DistPoint& a, const DistPoint& b) -> bool{
            return a.dist > b.dist;
        };
        priority_queue<DistPoint, vector<DistPoint>,decltype(comp)> pq(comp);
        for(auto& point: points){
            auto x = point[0], y = point[1];
            DistPoint dp(x, y);
            pq.push(dp);
        }
        vector<vector<int>> results;
        for(int i = 1; i <= k; ++i){
            auto point = pq.top();
            pq.pop();
            vector<int> v = {point.x, point.y};
            results.push_back(v);
        }
        return results;
    }
};