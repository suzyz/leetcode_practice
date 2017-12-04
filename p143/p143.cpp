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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        	return;

        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        }

        ListNode *latter_half = slow->next;
        slow->next = NULL;

        latter_half = reverse_list(latter_half);

        ListNode *p = head;
        while (p != NULL && latter_half != NULL)
        {
        	ListNode *tmp1 = p->next, *tmp2 = latter_half->next;
        	p->next = latter_half;
        	latter_half->next = tmp1;

        	p = tmp1;
        	latter_half = tmp2;
        }
    }

    ListNode* reverse_list(ListNode *l)
    {
    	ListNode *new_head = NULL, *p = l;
    	while (p != NULL)
    	{
    		ListNode *tmp = p->next;
    		p->next = new_head;
    		new_head = p;
    		p = tmp;
    	}
    	return new_head;
    }
};
