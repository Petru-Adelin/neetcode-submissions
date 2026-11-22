int init = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {

unordered_map<char, string> mp = {
        {'2', "abc"}, 
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
};

public:

    void bkt(string& digits, int index, string& partial, vector<string>& sol){
        if(index == digits.size()){
            sol.push_back(partial);
            return;
        }
        char digit = digits[index];
        for(char& c: mp[digit]){
            partial.push_back(c);
            bkt(digits, index+1, partial, sol);
            partial.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {  
        if(digits == "")
            return {};
        string partial;
        vector<string> sol;
        bkt(digits, 0, partial, sol);
        return sol;
    }
};
