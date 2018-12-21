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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode *p = root;
        while (p != NULL) {
            ++n;
            p = p->next;
        }
        
        int base = n/k, rem = n%k;
        vector<ListNode*> res(k);
        
        p = root;
        for (int i = 0; i < k; ++i) {
            res[i] = p;
            
            int len = base + (i < rem);
            
            for (int j = 0; j < len-1; ++j)
                p = p->next;
            
            if (p == NULL)
                break;
            
            ListNode *tmp = p->next;
            p->next = NULL;
            p = tmp;
        }
        
        return res;
    }
};