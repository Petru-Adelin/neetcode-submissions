class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overflow = 1;
		vector<int> res(digits.size(), 0);
		for(int i = digits.size()-1; i >= 0; --i){
			res[i] = (digits[i] + overflow) % 10;
			overflow = (digits[i] + overflow) / 10;
		}
		if(overflow == 1)
			res.insert(res.begin(), 1);
		return res;
    }
};