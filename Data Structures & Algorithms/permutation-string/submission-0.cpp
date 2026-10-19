using indeces = vector<int>;
using frequence = vector<int>;

class Solution {
public:

    bool check_freq(frequence& f1, frequence& f2){
        size_t n = f1.size();
        if(n != f2.size())
            return false;
        for(int i = 0; i < n; ++i){
            if(f1[i] != f2[i])
                return false;
        }
        return true;
    }

    void get_freq(string& s, frequence& f){
        for(char& c: s){
            f[c - 'a']++;
        }
    }

    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        size_t window_s = s1.size();
        size_t pattern_s = s2.size();
        frequence f1(26, 0), f2(26, 0);
        // get the frequency of the string s1
        get_freq(s1, f1);
        // check the frequence of the first window
        for(int i = 0; i < window_s; ++i){
            char c = s2[i];
            f2[c - 'a']++;
        }
        // check the frequencies
        if(check_freq(f1, f2))
            return true;
        
        for(int i = 1; i <= pattern_s - window_s; ++i){
            // we lose the letter from i-1 
            char lost = s2[i-1];    
            char gained = s2[window_s + i-1];
            f2[lost - 'a']--;
            f2[gained - 'a']++;
            // check the freq
            if(check_freq(f1, f2))
                return true;
        }
        return false;
    }
};