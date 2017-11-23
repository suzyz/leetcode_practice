// recursively

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
    ListNode* reverseList(ListNode* head) {
        return reverse_list(head,NULL);       
    }

    ListNode* reverse_list(ListNode *head1, ListNode *head2)
    {
        if (head1 == NULL)
            return head2;

        ListNode *newhead = head1->next;
        head1->next = head2;
        return reverse_list(newhead, head1);
    }
};
