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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head; //一般技巧：创建一个节点，作为头结点之前的节点。免得设置q的时候超出 
        ListNode *p = &dummy, *q = &dummy;
        for (int i = 0; i < n; i++) // q 先走n 步
        q = q->next;
        while(q->next) { // 一起走
            p = p->next;
            q = q->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
        
        
        
    }
};
