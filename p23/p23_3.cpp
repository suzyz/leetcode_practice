// Recursion.
// O(N * logK) time.

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];

        vector<ListNode*> newList;

        for (int i = 0; i+1 < n; i+=2)
            newList.push_back(mergeTwoLists(lists[i], lists[i+1]));
        
        if (n%2)
            newList.push_back(lists[n-1]);

        return mergeKLists(newList);
    }

    ListNode* mergeTwoLists(ListNode *p1, ListNode *p2) {
        ListNode *res = new ListNode(0);
        ListNode *cur = res;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if (p1 != NULL) {
            cur->next = p1;
        } else if (p2 != NULL) {
            cur->next = p2;
        }

        return res->next;
    }
};
