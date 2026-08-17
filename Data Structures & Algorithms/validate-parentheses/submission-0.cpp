#include <cstring>
class Solution {
public:

	bool isopen(char c){
		return strchr("{[(", c) != nullptr;
	}

	bool isclosed(char c){
		return strchr("})]", c) != nullptr;
	}
	// the first char is always the one that is open and the second one is always the one closed
	bool same(char c1, char c2){
		char samp1[] = "{[(";
		char samp2[] = "}])";
		const char* pos = strchr(samp1, c1);
		const char* pos2 = strchr(samp2, c2);
		if(pos == nullptr || pos2 == nullptr)
			return false;
	 return (pos - samp1 + 1) == (pos2 - samp2 + 1);
	}

    bool isValid(string s) {
		stack<char> st;
		for(char& c: s){
			if(this->isopen(c)){
				st.push(c);
			}else if(this->isclosed(c)){
				if(st.empty())
					return false;
				if(this->same(st.top(), c))
					st.pop();
				else 
					return false;
			}
		}
        if(st.empty())
			return true;
		return false;
    }
};