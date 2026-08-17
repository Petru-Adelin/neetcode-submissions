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
    bool hasCycle(ListNode* head) {
        ListNode* fast, *slow;
		fast = head, slow = head;
		while(fast && slow){
			// loop thorugh 3 times with fast and check for each time 
			for(int i = 1; i <= 3; ++i){
				fast = fast->next;
                if(fast == nullptr)
                    break;
				if(fast == slow)
					return true;
			}
			slow = slow->next;
		}
		return false;
    }
};