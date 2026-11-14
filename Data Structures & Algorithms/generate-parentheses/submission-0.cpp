
class Solution {
public:
    void bkt_with_pruning(int n, int opened, int closed, vector<char>& choices, string& partial, vector<string>& results){
        if(partial.size() == 2*n){
            if(opened == closed)
                results.push_back(partial);
            return;
        }
        if(closed > opened)
            return;
        // add one of the parathesis
        for(char& c: choices){
            partial.push_back(c);
            if(c == '('){
                bkt_with_pruning(n, opened+1, closed, choices, partial, results);
            }else{
                bkt_with_pruning(n, opened, closed+1, choices, partial, results);
            }
            partial.pop_back();

        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string partial;
        vector<char> choices = {'(', ')'};
        bkt_with_pruning(n, 0, 0, choices, partial, results);
        return results;
    }
};