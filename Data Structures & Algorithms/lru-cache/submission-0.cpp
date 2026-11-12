class LRUCache {

private:
    struct Node{
        int val, key;
        Node* next, *prev;
        Node():val(-1), next(nullptr), prev(nullptr){}
        Node(int val, int key , Node* next, Node* prev):val(val), key(key), next(next), prev(prev){} 
        Node(int val, int key): val(val), key(key), next(nullptr), prev(nullptr){}
        ~Node() = default;
    };

    Node* root, *tail;
    int capacity;
    unordered_map<int, Node*> mp;

    void relink(Node* current){
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    void move_to_front(Node* current){
        current->next = root->next;
        root->next->prev = current;
        current->prev = root;
        root->next = current;  
    }
public:

   

    LRUCache(int capacity){
        root = new Node(0, 0);
        tail = new Node(0, 0);
        root->next = tail;
        tail->prev = root;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        // Else case
        Node* current = mp[key];
        relink(current);
        move_to_front(current);
        return current->val;
     
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* current = mp[key];
            current->val = value;
            relink(current);
            move_to_front(current);
            return;
        }
        // Else case
        Node *n = new Node(value, key);
        if(capacity == mp.size()){
            // free a node from the list and mp
            Node* gone = tail->prev;
            relink(gone);
            mp.erase(gone->key);
            delete gone;
        }
        mp.insert({key, n});
        move_to_front(n);
    }
    ~LRUCache(){
        Node* current = root;
        while(current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
