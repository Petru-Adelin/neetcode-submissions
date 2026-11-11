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

    void gen_list(ListNode* root1, ListNode* root2, ListNode* rez, int overflow = 0){
        if(root1 == nullptr && root2 == nullptr && overflow == 0)
            return;
        
        int val1 = root1 != nullptr? root1->val : 0;
        int val2 = root2 != nullptr ? root2->val : 0;

        int summing = val1 + val2 + overflow;
        int over = summing > 9 ? 1 : 0;
        
        int digit = summing % 10;
        rez->next = new ListNode(digit); ;
        gen_list(root1 != nullptr? root1->next : nullptr, root2 != nullptr ? root2->next : nullptr, rez->next, over);
        
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_list_head = new ListNode();
        ListNode* head_index = new_list_head;
        gen_list(l1, l2, head_index);
        head_index = new_list_head->next;
        delete new_list_head;
        return head_index;
    }
};