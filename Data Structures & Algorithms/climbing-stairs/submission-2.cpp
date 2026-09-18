
class Solution {
public:


	int climbing(int n, map<int, int>& mp){
		if(n < 0)
			return -1;

		if(mp.find(n) != mp.end())
			return (*(mp.find(n))).second;
		
		int result = climbing(n-1, mp) + climbing(n-2, mp);
		mp.insert({n, result});
		return result;
	}

    int climbStairs(int n) {
        map<int, int> mp;
		mp.insert({{0, 0}, {1, 1}, {2, 2}});

		// check for the value of n 
		if(n > 20){
			climbing(10, mp);
			climbing(17, mp);
		}	
		return climbing(n, mp);
    }
};