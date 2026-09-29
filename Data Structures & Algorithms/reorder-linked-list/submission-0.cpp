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
	void reorderList(ListNode* head){
		ListNode* slow = head, *faster = head;
		while(faster != nullptr && faster->next != nullptr){
			faster = faster->next->next;
			slow = slow->next;
		}
		// slow == middle (now)
		ListNode* after = slow->next;
		// brake the connection
		slow->next = nullptr;
		// reverse the second list;
		ListNode* current, *prev;
		current = after;
		prev = nullptr;
		while(current != nullptr){
			ListNode* temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		// prev has now the head of the second list
		after = prev;

		// interclass the 2 lists
		ListNode* before = head;
		while(after != nullptr){
			// make copies of the nexts
			ListNode* temp_after = after->next;
			ListNode* temp_before = before->next;
			// link from l1 -> l2 and from l2 -> l1
			before->next = after;
			after->next = temp_before;
			// move the list weiter
			after = temp_after;
			before=  temp_before;
		}

	}

};


