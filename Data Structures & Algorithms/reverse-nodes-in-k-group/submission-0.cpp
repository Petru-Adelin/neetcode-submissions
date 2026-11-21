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

    bool exist_group(ListNode* head, int k, ListNode*& tailGroup){
        int count = 0;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current != nullptr && count < k){
            count++;
            prev = current;
            current = current->next;
        }
        if(count == k){
            tailGroup = prev;
            return true;
        }
        return false;
    }

    void reverse_group(ListNode* head, ListNode* nextGroup, int k){
        ListNode* prev = nextGroup;
        ListNode* current = head;
        for(int i = 1; i <= k; ++i){
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
    }

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* prevGroup = nullptr;
        ListNode* nextGroup = nullptr;
        ListNode* tailGroupUnrevesed = nullptr;
        ListNode* newHead = nullptr;

        while(exist_group(current, k, tailGroupUnrevesed)){
            nextGroup = tailGroupUnrevesed->next;
            reverse_group(current, nextGroup, k);

            if(prevGroup == nullptr){
                newHead = tailGroupUnrevesed;
            }else{
                prevGroup->next = tailGroupUnrevesed;
            }
            prevGroup = current;
            current = nextGroup;

        }
        return newHead;
    }
};