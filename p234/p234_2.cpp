// Recursively compare the "reversed" list with the input list,
// without modifying the input.

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
    ListNode *rev = NULL;

    bool isPalindrome(ListNode* head) {

    	if (head == NULL || head->next == NULL)
    		return true;

        rev = head;
        return compare(head);
    }

    bool compare(ListNode *cur)
    {
        if (cur == NULL)
            return true;

        bool is_identical = compare(cur->next) && (cur->val == rev->val);

        rev = rev->next;
        return is_identical;
    }
};
