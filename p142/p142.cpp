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
    ListNode *detectCycle(ListNode *head) {
    	if (head == NULL || head->next == NULL)
    		return NULL;

        ListNode *fast = head, *slow = head;
        bool isCircle = false;

        while (fast != NULL)
        {
        	if (fast->next == NULL)
        		return NULL;

        	fast = fast->next->next;
        	slow = slow->next;

        	if (fast == slow)
        	{
        		isCircle = true;
        		break;
        	}
        }

        if (!isCircle)
        	return NULL;

        slow = head;
        while (fast != slow)
        {
        	fast = fast->next;
        	slow = slow->next;
        }

        return fast;
    }
};