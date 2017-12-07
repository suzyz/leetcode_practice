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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *new_head1 = new ListNode(0);
        new_head1->next = head;

        ListNode *new_head2 = new ListNode(0);
        ListNode *new_tail2 = new_head2 , *new_head3 = new ListNode(0);

        if (m > 1)
        {
	        ListNode *p = head;
	        for (int i = 1; i < m; ++i)
	        	p = p->next;

	        new_tail2 = p;
	        new_head2->next = p;
        }
        
        // new_tail2->next = p;

        return new_head1->next;
    }
};
