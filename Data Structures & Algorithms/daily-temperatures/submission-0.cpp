
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		// save only the indeces
		vector<int> res(temperatures.size(), 0);
		stack<int> st;
		st.push(0);
		for(int i = 1; i < temperatures.size(); ++i){
			while(!st.empty() && temperatures[i] > temperatures[st.top()]){
				int idx = st.top();
				res[idx] = i - idx;
				st.pop();
			}
			st.push(i);
		}
		return res;
    }
};
