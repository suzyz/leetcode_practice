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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        	return head;

        ListNode *former = new ListNode(0), *latter = head->next;
        former->next = head;
        head->next = NULL;

        while (latter != NULL)
        {
        	ListNode *q = latter;
        	latter = latter->next;
        	q->next = NULL;
        	
        	ListNode *p = former->next, *pre = former;
        	while (p != NULL && q->val > p->val)
        	{
        		pre = p;
        		p = p->next;
        	}

			q->next = pre->next;
        	pre->next = q;
        }

        return former->next;
    }
};
