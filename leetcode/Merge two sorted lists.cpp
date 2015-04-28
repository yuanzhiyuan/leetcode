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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr)   return l2;
        if(l2 == nullptr)   return l1;
        ListNode dummy(-1);//����һ���ڵ㣬����nextָ��ͷ��㣬��Ϊ���Ȳ�֪���µ������ͷ�����ʲô 
        ListNode* p  = &dummy;
        for(;l1!=nullptr&&l2!=nullptr;p = p->next){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        p->next = l1!=nullptr?l1:l2;
        return dummy.next;
    }
};
