// Using stack.

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

        stack<Node*> st;

        Node *cur = head;

        while (cur != NULL) {
            if (cur->child == NULL) {
                if (cur->next == NULL && !st.empty()) {
                    cur->next = st.top();
                    st.pop();

                    cur->next->prev = cur;
                }
            } else {
                if (cur->next != NULL)
                    st.push(cur->next);

                cur->next = cur->child;
                cur->child = NULL;
                cur->next->prev = cur;
            }

            cur = cur->next;
        }

        return head;
    }
};