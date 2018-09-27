// Recursion.

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
            return NULL;

        Node *cur = head;

        if (head->child == NULL) {
            head->next = flatten(head->next);
            if (head->next != NULL)
                head->next->prev = head;
        }
        else {
            Node *rem = head->next;

            head->child->prev = head;
            head->next = flatten(head->child);
            head->child = NULL;

            if (rem != NULL) {
                rem = flatten(rem);
                
                Node *p = head->next;
                while (p->next != NULL)
                    p = p->next;

                p->next = rem;
                rem->prev = p;   
            }
        }
        
        return head;
    }
};