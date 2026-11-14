class PrefixTree {


private:
    struct Node{
        vector<Node*> nodes;
        bool leaf;

        Node(): nodes(26, nullptr), leaf(false){}
    };

    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* current = root;
        for(char& c: word){
            int i = c - 'a';
            if(current->nodes[i] == nullptr){
                current->nodes[i] = new Node();
            }
            current = current->nodes[i];
        }
        current->leaf = true;
    }
    
    bool search(string word) {
        Node* current = root;
        for(char& c: word){
            int i = c - 'a';
            if(current->nodes[i] == nullptr)
                return false;
            current = current->nodes[i];
        }
        if(current->leaf)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        for(char& c: prefix){
            int i = c - 'a';
            if(current->nodes[i] == nullptr)
                return false;
            current = current->nodes[i];
        }
        if(current->leaf == true)
            return true;
        for(int i = 0; i < 26; ++i){
            if(current->nodes[i] != nullptr)
                return true;
        }
        return false;
    }
};