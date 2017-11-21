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
    ListNode* oddEvenList(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;

    	ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
        ListNode *odd = dummy1, *even = dummy2, *p = head, *q = head->next;
        while (p)
        {
        	odd->next = p;
        	odd = p;
        	if (p->next != NULL)
        		p = p->next->next;
        	else
        		p = NULL;

        	even->next = q;
        	even = q;

            if (!q)
                break;
            
        	if (q->next != NULL)
        		q = q->next->next;
        	else
        		q = NULL;
        }

       	odd->next = dummy2->next;

        return dummy1->next;
    }
};
