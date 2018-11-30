class MyLinkedList {
public:
    int size;

    struct Node
    {
        int val;
        Node* next;

        Node() { val = 0; next = NULL; }
        Node(int v) { val = v; next = NULL; }
        Node(int v, Node *p) { val = v; next = p; }
    };

    Node *head, *tail;

    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;

        Node *p = head;
        for (int i = 0; i < index; ++i)
            p = p->next;

        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head = new Node(val, head);
        
        ++size;
        if (size == 1)
            tail = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ++size;

        if (size == 1)
            head = tail = new Node(val);
        else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        ++size;

        Node *p = head;
        for (int i = 0; i < index-1; ++i)
            p = p->next;

        p->next = new Node(val, p->next);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size)
            return;

        --size;
        if (size == 0) {
            head = tail = NULL;
            return;
        }

        if (index == 0) {
            Node *tmp = head;
            head = head->next;
            delete(tmp);
        }

        Node *p = head;
        for (int i = 0; i < index-1; ++i)
            p = p->next;

        Node *tmp = p->next;
        p->next = tmp->next;
        delete(tmp);

        if (index == size)
            tail = p;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */