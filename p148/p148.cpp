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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        	return head;

        ListNode *fast = head, *slow = head, *pre;
        while (fast && fast->next)
        {
        	pre = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }

        pre->next = NULL;

        ListNode *l = sortList(head);
        ListNode *r = sortList(slow);

        return merge(l,r);
    }

    ListNode* merge(ListNode *p, ListNode *q)
    {
    	ListNode *res = new ListNode(0);
    	ListNode *backup = res;

    	while (p && q)
    	{
    		if (p->val < q->val)
    		{
    			res->next = p;
    			p = p->next;
    		}
    		else
    		{
    			res->next = q;
    			q = q->next;
    		}
    		res = res->next;
    	}

    	if (p)
    		res->next = p;
    	else
    		res->next = q;

    	return backup->next;
    }
};
