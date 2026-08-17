
class Solution {
public:
    bool isPalindrome(string s) {
		int left, right;
		transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return tolower(c);});
		left = 0;
		right = s.size()-1;
		while(left <= right){
			// check for the different characters 
			if(! iswalnum(s[left])){
				left++;
				continue;
			}
			if(! iswalnum(s[right])){
				right--;
				continue;
			}
			if(s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
    }
};