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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode *new_head = new ListNode(0);
    	new_head->next = head;

        ListNode *p = new_head;
        while (p->next != NULL)
        {
        	if (p->next->val == val)
        		p->next = p->next->next;
        	else
	        	p = p->next;
        }

        return new_head->next;
    }
};
