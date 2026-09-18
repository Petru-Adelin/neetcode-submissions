class Solution {
public:

	set<int> known_uncycle = {10, 100, 68, 86, 608, 806, 860, 680, 13, 31, 103, 130, 310, 301, 28, 82, 208, 280, 802, 820, 23, 32, 203, 230, 302, 320, 19, 91, 109, 901, 910, 190, 139, 193};

	int getSquares(int n){
		int sum = 0;
		if(n == 0)
			return sum;

		while(n != 0){
			sum += ((n%10) * (n%10));
			n /= 10;
		}
		return sum;
	}

	bool isCycled(int n, set<int>& unknown_encountered){
		if(known_uncycle.contains(n))
			return true;
		
		int sum = this->getSquares(n);
		if(sum == 1)
			return true;
		if(unknown_encountered.contains(sum))
			return false;
		unknown_encountered.insert(sum);
		return isCycled(sum, unknown_encountered);
		
	}

    bool isHappy(int n) {
        set<int> unknown_encountered;
		return this->isCycled(n, unknown_encountered);
    }
};