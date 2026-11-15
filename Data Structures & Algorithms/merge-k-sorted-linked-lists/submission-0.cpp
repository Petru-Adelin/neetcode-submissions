/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* n1, ListNode* n2){return n1->val > n2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>pq(comp);
        for(auto list_root: lists){
            if(list_root != nullptr)
                pq.push(list_root);
        }
        // create the new List 
        ListNode dummy(0);
        ListNode* current = &dummy;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            current->next = node;
            current = node;

            if(node->next != nullptr)
                pq.push(node->next);

            
        }
        current->next = nullptr;
        return dummy.next;
    }
};
