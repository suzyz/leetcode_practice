// Using self-defined linked list.
class MyCircularDeque {
public:
    int size, cap;

    struct Node
    {
        int val;
        Node *pre, *next;

        Node(int v) { val = v; pre = next = NULL; }
    };

    Node *head, *tail;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
        size = 0;

        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->pre = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cap == size)
            return false;
        
        ++size;

        Node *p = new Node(value);
        p->next = head->next;
        head->next->pre = p;
        head->next = p;
        p->pre = head;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cap == size)
            return false;
        
        ++size;

        Node *p = new Node(value);
        p->pre = tail->pre;
        tail->pre->next = p;
        p->next = tail;
        tail->pre = p;

        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0)
            return false;

        --size;

        Node *p = head->next;
        head->next = p->next;
        p->next->pre = head;

        delete(p);

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0)
            return false;

        --size;

        Node *p = tail->pre;
        tail->pre = p->pre;
        p->pre->next = tail;

        delete(p);

        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0)
            return -1;
        else
            return head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0)
            return -1;
        else
            return tail->pre->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */