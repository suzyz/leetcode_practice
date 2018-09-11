// Using priority_queue of STL.
// O(K) extra space. O(N*logK) time. N is the number of all numbers.

class Solution {
public:
    struct myCompare {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myCompare> pq;

        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL)
                pq.push(lists[i]);
        
        ListNode* resHead = new ListNode(0);
        ListNode* cur = resHead;

        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();

            if (cur->next->next != NULL)
                pq.push(cur->next->next);

            cur = cur->next;
        }

        return resHead->next;
    }
};
