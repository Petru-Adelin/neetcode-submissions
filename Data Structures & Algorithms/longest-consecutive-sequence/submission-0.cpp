class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s;
		for(int& n: nums){
			s.insert(n);
		}

		int cnt = 0;
		int max_cnt = 0;
		for(auto num = s.begin(); num != s.end(); num++){
			if(s.find((*num)-1) != s.end())
				continue;
			else{
				cnt = 1;
				int current_val = (*num)+1;
				while(s.find(current_val) != s.end()){
					cnt++;
					current_val++;
				}
				max_cnt = max(max_cnt, cnt);
			}
		}
		return max_cnt;
    }
};
