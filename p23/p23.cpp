
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
///

class PriorityQueue
{
public:
	
	std::vector<ListNode*> heap;

	PriorityQueue(int k) {
		heap = std::vector<ListNode*>(k);
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       	int k = lists.size();

       	PriorityQueue pq = new PriorityQueue();

       	for (int i = 0; i < k; ++i)
       	{
       		
       	}
    }
};
