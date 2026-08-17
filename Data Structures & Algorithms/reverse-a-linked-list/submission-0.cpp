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
    ListNode* reverseList(ListNode* head) {
		if(head == nullptr || head->next == nullptr)
			return head;

		ListNode* current = head;
		ListNode* prev = nullptr;
		while(current != nullptr){
			// save the next one 
			ListNode* temp = current->next;
			// reverse the connection
			current->next = prev;
			// iterate
			prev = current;
			current = temp;
		}
		return prev;
    }
};