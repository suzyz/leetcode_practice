// Implemented a min heap by myself.
// O(K) extra space. O(N*logK) time. N is the number of all numbers.

class PriorityQueue
{
public:
    vector<ListNode*> heap;

    PriorityQueue() {
        heap = std::vector<ListNode*>(1);
    }

    void push(ListNode* p);
    ListNode* pop();
};

void PriorityQueue::push(ListNode* p) {
    if (p == NULL)
        return;

    heap.push_back(p);

    int j = heap.size()-1;
    int i = j>>1;
    
    while (i >= 1) {
        if (heap[i]->val <= heap[j]->val)
            break;

        ListNode *tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;

        j = i;
        i = j>>1;
    }
}

ListNode* PriorityQueue::pop() {
    ListNode *res = heap[1];

    heap[1] = heap.back();
    heap.pop_back();

    int i = 1, j = 2;
    while (j < heap.size()) {
        int k = i;
        if (heap[j]->val < heap[k]->val) {
            k = j;
        }

        if (j+1 < heap.size() && heap[j+1]->val < heap[k]->val) {
            k = j+1;
        }

        if (k == i)
            break;

        ListNode *tmp = heap[i];
        heap[i] = heap[k];
        heap[k] = tmp;

        i = k;
        j = i<<1;
    }

    return res;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        PriorityQueue pq;

        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL)
                pq.push(lists[i]);
        
        ListNode* resHead = new ListNode(0);
        ListNode* cur = resHead;

        while (pq.heap.size()>1) {
            cur->next = pq.pop();
            pq.push(cur->next->next);

            cur = cur->next;
        }

        return resHead->next;
    }
};
