class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<int> last_seen_idx(256, -1);

		int left = 0;
		int max_length = 0;
		for(int right = 0; right < s.size(); ++right){
			unsigned char c = s[right];

			if(last_seen_idx[c] >= left)
				left = last_seen_idx[c]+1;
			last_seen_idx[c] = right;

			max_length = max(max_length, right-left+1);
		}
		return max_length;
    }
};