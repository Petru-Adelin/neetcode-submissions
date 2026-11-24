class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // use tabulation 
        int s = cost.size();
        vector<int> results(s, 0);
        results[0] = cost [0];
        results[1] = cost[1];
        for(int i = 2; i < s; ++i){
            results[i] = min(results[i-1], results[i-2]) + cost[i];
        }
        return min(results[s-1], results[s-2]);
    }
};
