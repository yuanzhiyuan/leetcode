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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1)  return lists[0];
        if(lists.size()==2) {
            ListNode dummy(-1);
            ListNode* cur = &dummy;
            ListNode* a = lists[0];
            ListNode* b = lists[1];
            while(a!=nullptr&&b!=nullptr){
                if(a->val<b->val){
                    cur->next = a;
                    cur = cur->next;
                    a = a->next;
                }else{
                    cur->next = b;
                    cur = cur->next;
                    b = b->next;
                }
            }
            if(a==nullptr)  cur->next = b;
            else    cur->next = a;
            return dummy.next;
            
        }
        vector<ListNode*> lists_former(lists.begin(),lists.begin()+lists.size()/2);
        vector<ListNode*> lists_latter(lists.begin()+lists.size()/2,lists.end());
        ListNode* former = mergeKLists(lists_former);
        ListNode* latter = mergeKLists(lists_latter);
        vector<ListNode*> comb{former,latter};
        return mergeKLists(comb);
    }
};
