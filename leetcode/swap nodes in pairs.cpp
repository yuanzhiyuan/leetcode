/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)   return nullptr;
        ListNode dummy(-1);
        
        ListNode* new_list = &dummy;
        ListNode* cur = head;
        ListNode* former=0;
        ListNode* latter=0;
        while(cur!=nullptr&&cur->next!=nullptr){
            former = cur;
            latter = cur->next;
            cur = latter->next;
            new_list->next = latter;
            latter->next = former;
            new_list = former;
            
        }
        new_list->next = cur;
        return dummy.next;
    }
};
