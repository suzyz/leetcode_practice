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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *t1 = NULL, *reversed_h2 = NULL, *reversed_t2 = NULL; 
        ListNode *h2 = new ListNode(0);
        ListNode *h3 = new ListNode(0);

        ListNode *p = head, *pre = NULL;
        for (int i = 1; i < m; ++i)
        {
            pre = p;
            p = p->next;
        }

        t1 = pre;
        if (pre != NULL)
            pre->next = NULL;

        h2->next = p;

        for (int i = 0; i < n-m+1; ++i)
        {
            pre = p;
            p = p->next;
        }
        
        if (pre != NULL)
            pre->next = NULL;

        h3->next = p;

        /// reverse

        p = reversed_t2 = h2->next;
        while (p != NULL)
        {
            ListNode *tmp = p->next;

            p->next = reversed_h2;
            reversed_h2 = p;
            p = tmp;
        }

        ///

        if (m > 1)
        {
            t1->next = reversed_h2;
            reversed_t2->next = h3->next;

            return head;
        }
        else
        {
            reversed_t2->next = h3->next;

            return reversed_h2;
        }
    }
};
