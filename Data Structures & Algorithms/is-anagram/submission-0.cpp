class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(const auto chr: s){
            if(mp.find(chr) == mp.end())
                // insert into the map 
                mp.insert(pair<char, int>(chr, 1));
            else
                mp[chr]++;
        }

        // decrement and check for the others
        for(const auto& chr: t){
            if(mp.find(chr) == mp.end()){
                return false;
            }else{
                // if found either erase or decrease the value
                if(mp[chr] == 1)
                    mp.erase(chr);
                else
                    mp[chr]--;
            }
        }
        if(mp.size() != 0)
            return false;
        return true;
    }
};