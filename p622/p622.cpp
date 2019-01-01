class MyCircularQueue {
public:
    int h, t, cap, size;
    vector<int> data;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cap = k;
        size = h = t = 0;
        
        data = vector<int>(cap);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (size == cap)
            return false;
        
        data[t] = value;
        ++t;
        if (t == cap)
            t = 0;
        
        ++size;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (size == 0)
            return false;
        
        ++h;
        if (h == cap)
            h = 0;
        
        --size;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (size == 0)
            return -1;
        return data[h];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (size == 0)
            return -1;
        return data[(t-1+cap)%cap];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */