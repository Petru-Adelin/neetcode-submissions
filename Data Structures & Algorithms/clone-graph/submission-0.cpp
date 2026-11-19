/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:

    Node* cloneGraph(Node* node) {

        if(node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> que;

        mp[node] = new Node(node->val);
        que.push(node);

        while(!que.empty()){
            Node* n = que.front();
            que.pop();

            for(Node* current: n->neighbors){
                if(mp.find(current) == mp.end()){
                    mp[current] = new Node(current->val);
                    que.push(current);
                }
                mp[n]->neighbors.push_back(mp[current]);
            }
        }
        return mp[node];
    }
};
