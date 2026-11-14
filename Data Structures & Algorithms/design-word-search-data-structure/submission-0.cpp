
class WordDictionary {

private:
    struct TrieN{
        bool is_leaf;
        vector<TrieN*> nodes;

        TrieN(): is_leaf(false), nodes(26, nullptr){
            
        }
    };

    TrieN* root;


public:



    WordDictionary() {
        root = new TrieN();
    }
    
    void addWord(string word) {
        TrieN* current = root;
        for(const char& c: word){
            int val = c - 'a';
            if(current->nodes[val] == nullptr){
                // create the node
                current->nodes[val] = new TrieN();
            }
            
            current = current->nodes[val];
        }
        current->is_leaf = true;
    }
    
    bool search(string word) {
        TrieN* current;
        size_t n = word.size();
        stack<pair<TrieN*, int>> st;
        st.push({root, 0});
        while(!st.empty()){
            auto [current, idx] = st.top();
            st.pop();

            if(idx == n){
                if(current->is_leaf)return true;
                continue;
            }

            char c = word[idx];

            if(c == '.'){
                // add all the available children in the stack for future work.
                for_each(current->nodes.begin(), current->nodes.end(), [&](TrieN* t){if(t != nullptr)  st.push({t, idx+1});});
            }else{
                if(current->nodes[c - 'a'] != nullptr)
                    st.push({current->nodes[c - 'a'], idx+1});
            }

        }
        
        return false;
    }
};