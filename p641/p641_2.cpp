// Using vector. (circular array).
class MyCircularDeque {
public:
    int size, cap, head, tail; // [)
    vector<int> nums;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = 0;
        cap = k;
        nums = vector<int>(k);

        head = tail = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cap == size)
            return false;
        
        ++size;

        head = (head-1+cap)%cap;
        nums[head] = value;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cap == size)
            return false;
        
        ++size;

        nums[tail] = value;
        tail = (tail+1)%cap;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0)
            return false;

        --size;
        head = (head+1)%cap;

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0)
            return false;

        --size;
        tail = (tail-1+cap)%cap;

        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0)
            return -1;
        else
            return nums[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0)
            return -1;
        else
            return nums[(tail-1+cap)%cap];
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