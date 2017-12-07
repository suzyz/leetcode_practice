// Recursive.

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
    	if (head == NULL || head->next == NULL)
    		return head;

    	int v = head->val;
        ListNode *p = head->next;
        if (p->val != v)
        {
            head->next = deleteDuplicates(p);
            return head;
        }
        else
        {
            while (p != NULL && p->val == v)
                p = p->next;

            return deleteDuplicates(p);            
        }
    }
};
