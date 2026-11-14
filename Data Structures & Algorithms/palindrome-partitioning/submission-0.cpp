
class Solution {

private:

    bool is_pali(string& s){
        int i = 0, j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:

    void bkt(string& source,int start, vector<string>& partial, vector<vector<string>>& results){
        if(start == source.size()){
            results.push_back(partial);
        }
        for(int i = start; i < source.size();++i){
            string ss = source.substr(start, i-start+1);
            if(is_pali(ss)){
                partial.push_back(ss);
                bkt(source, i+1, partial, results);
                partial.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> partial;
        bkt(s, 0, partial, results);
        return results;
    }
};