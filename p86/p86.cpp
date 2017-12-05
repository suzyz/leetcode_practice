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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
		ListNode *great = new ListNode(0);
		ListNode *p = small, *q = great, *cur = head;

		while  (cur != NULL)
		{
			ListNode *tmp = cur->next;
			cur->next = NULL;
			if (cur->val < x)
			{
				p->next = cur;
				p = cur;
			}
			else
			{
				q->next = cur;
				q = cur;
			}
			cur = tmp;
		}

		p->next = great->next;

		return small->next;
    }
};

