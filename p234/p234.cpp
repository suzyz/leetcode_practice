// Reverse the first half of the list, and compare it with the latter half.
// This method modifies the input list.

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
    bool isPalindrome(ListNode* head) {

    	if (head == NULL || head->next == NULL)
    		return true;

        ListNode *rev = NULL, *fast = head, *slow = head, *tmp;
        while (fast && fast->next)
        {
        	fast = fast->next->next;

        	tmp = slow->next;
        	slow->next = rev;
        	rev = slow;
        	slow = tmp;
        }

        if (fast)
            slow = slow->next;

        while (rev && slow)
        {
        	if (rev->val != slow->val)
        		return false;
        	rev = rev->next;
        	slow = slow->next;
        }

        return true;
    }
};
