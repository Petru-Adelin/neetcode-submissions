class Solution {
    

public:
    void bkt(vector<int>& terms, int target, int depth, vector<int> & partial_sol, vector<vector<int>>& results){
        if(target == 0){
            results.push_back(partial_sol);
            return;
        }
        
        for(int i = depth; i < terms.size(); ++i){
            if(i > depth && terms[i] == terms[i-1])
                continue;
            
            // do not go further since the array is ordered
            if(terms[i] > target)
                break;
            
            // call the backtracking 
            partial_sol.push_back(terms[i]);
            bkt(terms, target - terms[i], i+1, partial_sol, results);
            partial_sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> partial_sol;
        sort(candidates.begin(), candidates.end());
        bkt(candidates, target, 0, partial_sol, results);
        return results;
    }
};