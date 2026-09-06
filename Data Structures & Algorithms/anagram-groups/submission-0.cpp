/**
 * SOLUTION: for each word create a 26 vector of frequences of the letters 
 * 			 use a @param hashmap to same the frequence vector and the index of the list 
 * 			 of the anagrams in the result array
 */

#define anagrams vector<vector<string>>

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t seed = v.size();
        for (int i : v) {
            // Standard hash combination technique (Boost-style)
            seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:

	vector<int> anagram_vector(string& str){
		vector<int> freq(26, 0);
		for(const char& c: str){
			int ascii_val = c - 'a';
			freq[ascii_val]++;
		}
		return freq;
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		anagrams v;
		unordered_map<vector<int>, int, VectorHash> mp;
		for(auto str: strs){
			auto freq = this->anagram_vector(str);
			if(mp.count(freq) == 0){
				// add the freq key to the map and the string to a new array inside the result array
				v.push_back(vector<string>());
				auto idx = v.end() - 1;
				idx->push_back(str);
				mp.insert(pair<vector<int>, int>(freq, v.size()-1));
			}else{
				// there is already an array with anagrams like this one
				int index = mp.at(freq);
				auto idx = v.begin() + index;
				idx->push_back(str);
			}
		}
		return v;
    }
};