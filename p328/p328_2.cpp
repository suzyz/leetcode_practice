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

        ListNode *odd = head, *even = head->next;
        ListNode *head_of_even = even, *cur = even->next;

        int i = 2;
        while (cur)
        {
            ++i;
        	if (i%2)
            {
                odd->next = cur;
                odd = cur;
            }
            else
            {
                even->next = cur;
                even = cur;
            }
            cur = cur->next;
        }

        even->next = NULL;
        odd->next = head_of_even;

       	return head;
    }
};
