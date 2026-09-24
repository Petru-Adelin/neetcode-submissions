#include <cassert>
#define ASSERT_EQ(val1, val2) \
		do { \
			assert(((val1) == (val2)) && "Values are not equal: " #val1 " != " #val2); \
		}while(0)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> st;
        for(string& token: tokens){
			try {
				int value = stoi(token);
				st.push(value);
			}catch(const invalid_argument& ){
				// the token is a symbol so cumulate the result in the stack
				int x, y;
				x = st.top();
				st.pop();
				y = st.top();
				st.pop();
				int res;
				if(token == "+")
					res = y + x;
				if(token == "-")
					res = y - x;
				if(token == "/")
					res = y / x;
				if(token == "*")
					res = y * x;
				st.push(res);
			}
		}
		ASSERT_EQ(st.size(), 1);
		return st.top();
		
    }
};