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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode head = ListNode(0);
        ListNode* new_cur = &head;
        int carry = 0;
        int sum, x, y;
        while(p || q){
            x = (p!=NULL) ? p->val : 0;
            y = (q!=NULL) ? q->val : 0;
            sum = x + y + carry;
            new_cur->next = new ListNode(sum % 10);
            new_cur = new_cur->next;
            carry =  sum / 10;
            if(p!=NULL) p = p->next;
            if(q!=NULL) q = q->next;
        }
        
        if(carry>0){
            new_cur->next = new ListNode(carry);
        }
        return head.next;
    }
};
