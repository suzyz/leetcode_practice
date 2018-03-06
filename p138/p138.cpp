/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
       	unordered_map<RandomListNode*, RandomListNode*> newPtr;

       	RandomListNode *p, *newHead, *q;
       	newHead = new RandomListNode(0);
       	p = head;
       	q = newHead;

       	while (p != NULL)
       	{
       		q->next = new RandomListNode(p->label);
       		newPtr[p] = q->next;

       		q = q->next;
       		p = p->next;
       	}

       	p = head;
       	q = newHead->next;
       	while (p != NULL)
       	{
       		q->random = newPtr[p->random];

       		q = q->next;
       		p = p->next;
       	}

       	return newHead->next;
    }
};
