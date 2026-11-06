
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        // first = left. second = size;
        pair<int, int> wind;
        wind.first = -1;
        wind.second = INT_MAX;
        vector<int> freq_t(128, 0);
        vector<int> freq_w(128, 0);

        // freq of the t
        // we can check later if the freqs are equal an incrementer is compared to the unique to see if all chars are checked
        int unique = 0;
        for(char &c: t){
            if(freq_t[c] == 0)
                unique++;
            freq_t[c]++;
        }

        int unique_matched = 0;
        size_t n = s.size();
        while(right < n){
            char c = s[right];
            freq_w[c]++;
            // if the frequence match increment the unique_match
            if(freq_t[c] > 0 && freq_w[c] == freq_t[c])
                unique_matched++;
            
            while(left <= right && unique == unique_matched){

                // save the window
                if(right - left + 1 < wind.second){
                    wind.first = left;
                    wind.second = right-left +1;
                }

                char left_char = s[left];
                left++;
                freq_w[left_char]--;
                // recompare the freq_w with the freq_t
                if(freq_t[left_char] > 0 && freq_t[left_char] > freq_w[left_char])
                    unique_matched--;
            }
            right++;
        }
        return wind.second == INT_MAX ? "" : s.substr(wind.first, wind.second);
    }
};