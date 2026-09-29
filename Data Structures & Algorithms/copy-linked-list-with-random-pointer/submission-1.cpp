/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



class Solution {
public:



    Node* copyRandomList(Node* head) {

		// !! ERROR: WHEN THE HEAD IS NULLPTR 
		// ?? SOLUTION: RETURN NULLPTR WHEN THE LIST IS EMPTY
		if(head == nullptr)
			return nullptr;

        unordered_map<Node*, Node*> mp;

		Node* new_head = new Node(head->val);
		
		Node* current = head->next;
		Node* copy = new_head;
		
		mp.insert({head, new_head});
		while(current != nullptr){
			Node* new_node = new Node(current->val);
			copy->next = new_node;

			mp.insert({current, new_node});
			
			current = current->next;
			copy = new_node;
		}

		current = head;
		copy = new_head;
		while(current != nullptr){
			if(current->random != NULL){
				copy->random = (*(mp.find(current->random))).second;
			}
			current = current->next;
			copy = copy->next;
		}

		return new_head;
    }

};