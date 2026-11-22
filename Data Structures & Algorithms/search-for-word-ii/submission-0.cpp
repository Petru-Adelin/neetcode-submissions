int init = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {

private:
    struct Node{
        vector<Node*> letters;
        Node* parent;
        bool word;
        bool dead;

        Node(Node* parent = nullptr): letters(vector<Node*>(26, nullptr)),parent(parent), word(false), dead(false) {}

        int size_null(){
            return accumulate(letters.begin(), letters.end(), 0, [](int acc, Node* item){return acc + (item != nullptr? 1 : 0);});
        }
        int size_dead(){
            return accumulate(letters.begin(), letters.end(), 0, [](int acc, Node* child){
                if(child != nullptr)
                    return acc + (child->dead == false? 1 : 0);
                return acc;
            });
        }
    };

    struct Trie{

        Node* root;
        Trie(vector<string>& words){
            root = new Node();
            for(auto& word: words){
                // add in the Trie
                add(word);
            }
        }

        void add(string& word){
            Node* current = root;
            for(char& c: word){
                int index = c - 'a';
                if(current->letters[index] == nullptr){
                    // create the node
                    current->letters[index] = new Node(current);
                }
                current = current->letters[index];
            }
            // mark as word
            current->word = true;
        }

        bool should_be_dead(Node* current){
            if(current == nullptr)
                return false;

            if(current->word == false){
                int not_nulls = current->size_null();
                if(not_nulls == 0)
                    return true;
                else {
                    int not_deads = current->size_dead();
                    if(not_deads == 0)
                        return true;
                }
            }
            return false;
        }

        
        Node* next(Node* current, char c){
            if(current == nullptr) return nullptr;
            int index = c - 'a';
            Node* next = current->letters[index];
            return next == nullptr || next->dead ? nullptr : next;
        }

        void found(Node* node){
            if(node == nullptr || node->word == false) return;

            node->word = false;
            node->dead = should_be_dead(node);
            if(node->dead){
                Node* parent = node->parent;
                while(parent){
                    parent->dead = should_be_dead(parent);
                    if(parent->dead == false)
                        break;
                    parent = parent->parent;
                }
            }
        }

        ~Trie(){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* current = q.front(); q.pop();
                // add the children
                for(auto letter: current->letters)
                    if(letter != nullptr)
                        q.push(letter);
                delete current;
            }
        }
    };

    // FUNTION FOR THE BKT  
    bool valid_index(int i, int j, int rows, int cols){
        return ((i >= 0 && i < rows) && (j >= 0 && j < cols));
    }

    // FIELDS FOR THE MOVES
    vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;

public:



    void bkt(Trie& trie, Node* current, vector<vector<char>>& board,int i, int j, string& word, vector<string>& res){
        // make the current move, add the char and verify for word
        // if word save it but don t stop untill a nullptr is reached 
        char c = board[i][j];
        word.push_back(c);
        board[i][j] = '#';

        // check word
        if(current->word){
            res.push_back(word);
            current->word = false;
            trie.found(current);
        }

        // explore 
        for(auto move: moves){
            int x = i+move.first, y = j+move.second;
            if(valid_index(x, y, rows, cols) && board[x][y]!='#'){
                Node* next = trie.next(current, board[x][y]);
                if(next)
                    bkt(trie, next,  board, x, y, word, res);
            }
        }

        board[i][j] = c;
        word.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie(words);
        vector<string> res;
        rows = board.size();
        cols = board[0].size();
        string word;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                Node* current = trie.next(trie.root, board[i][j]);
                if(current != nullptr){
                    bkt(trie, current, board, i, j, word, res);
                }
            }
        }
        return res;
    }
};
