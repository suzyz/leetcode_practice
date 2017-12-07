// Iterative.

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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL)
    		return NULL;

    	ListNode *new_head = new ListNode(0);
    	new_head->next = head;

       	ListNode *pre = new_head, *p = head, *q = head->next;
       	while (pre != NULL && pre->next != NULL && pre->next->next != NULL)
       	{
       		p = pre->next;
       		q = p->next;
       		if (p->val == q->val)
       		{
       			while (q != NULL && q->val == p->val)
       				q = q->next;
       			pre->next = q;
       		}
       		else
       			pre = pre->next;
       	}

       	return new_head->next;
    }
};
