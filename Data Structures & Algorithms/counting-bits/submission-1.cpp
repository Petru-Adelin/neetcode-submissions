
class Solution {
public:
    vector<int> countBits(int n) {
		int offset = 2;
        if(n == 0)
            return {0};
		vector<int> bits(n+1, 0);
		bits[1] = 1;
		for(int i = 2; i < bits.size(); ++i){
            if(offset * 2 == i)
				offset = i;
			bits[i] = bits[i-offset] + 1;
			
		}
        return bits;
    }
};