
class Solution {
public:

    string encode(vector<string>& strs) {
		string result = ""s;
		for(const string& str: strs){
			int length = str.size();
			result += format("{}#{}", length, str);
		}
		return result;
    }

    vector<string> decode(string s) {
		vector<string> res;
		int i = 0;
		while(i < s.size()){
			string length = "";
			while(i < s.size() && s[i] != '#'){
				length += s[i++];
			}
			// skip the '#'
			i++;
			int len = stoi(length);
			string word = s.substr(i, len);
			res.push_back(word);
			i+= len;
		}
		return res;
    }
};

