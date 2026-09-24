class Solution {
public:
    int characterReplacement(string s, int k) {
		unordered_map<char, int> mp;
		int n = s.size();
		int left = 0;

		int max_freq = 0;
		int res = 0;
		for(int right = 0 ; right < n; ++right){
			mp[s[right]]++;
			// max_freq can be identify between the previous frequency and the frequency of the current char 
			// as the current char as the best chance to have the frequency higher
			max_freq = max(max_freq, mp[s[right]]);
			// check for the case of shrinking the window
			if(right - left + 1 - max_freq > k){
				mp[s[left]]--;
				left++;
			}

			res = max(res, right-left +1);

		}
		return res;
    }
};