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

	void reverse(ListNode*& head){
		ListNode* prev, *current;
		current = head;
		prev = nullptr;
		while(current != nullptr){
			ListNode* temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		head = prev;
	}


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the list and count the n^th element
		this->reverse(head);
		ListNode* current = head;
		ListNode* prev = nullptr;
		int i = 1;
		while(i < n){
			prev = current;
			current = current->next;
			i++;
		}
		if(prev == nullptr){
			head = head->next;
		}else{
			prev->next = current->next;
			current->next = nullptr;
		}
		delete current;
		this->reverse(head);
		return head;
    }
};