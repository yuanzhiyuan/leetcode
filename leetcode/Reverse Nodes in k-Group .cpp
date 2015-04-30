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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k<2) return head;
        
        ListNode* next_group = head;
        int i=0;
        for(;i<k;i++){
            if(next_group){
                next_group = next_group->next;
            }else{
                return head;
            }
           
        }
        
        
        //new_group 指向下一组的头
        ListNode* new_reversed_group = reverseKGroup(next_group,k);
        ListNode* cur = head;
        ListNode dummy(-1);
        ListNode* reverse_head = &dummy;
        
        //头插法
        while(cur!=next_group){
            ListNode* next = cur->next;
            
            cur->next = reverse_head->next?reverse_head->next:new_reversed_group;
            reverse_head->next = cur;
            cur = next;
            
        }
        return dummy.next;
        
    }
};
