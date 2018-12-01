// Hash.
// Solve conflits with linked list.
class MyHashSet {
public:
    struct Node {
        int k;
        Node *next;
        
        Node() { next = NULL; }
        Node(int k2) { k = k2; next = NULL; }
        Node(int k2, Node *p) { k = k2; next = p; }
    };
    
    const int maxSize = 10000;
    vector<Node*> data;
    
    /** Initialize your data structure here. */
    MyHashSet() {
        data = vector<Node*>(maxSize);
    }
    
    void add(int key) {
        int pos = findPos(key);
        
        if (data[pos] == NULL)
            data[pos] = new Node(key);
        else {
            Node *p = data[pos];
            while (p != NULL) {
                if (p->k == key)
                    return;
                
                if (p->next == NULL) {
                    p->next = new Node(key);
                    return;
                }
                p = p->next;
            }
        }
    }
    
    void remove(int key) {
        int pos = findPos(key);
        
        if (data[pos] == NULL)
            return;
        
        if (data[pos]->k == key) {
            Node *tmp = data[pos]->next;
            delete(data[pos]);
            
            data[pos] = tmp;
            return;
        }
        
        Node *p = data[pos]->next, *pre = data[pos];
        while (p != NULL) {
            if (p->k == key) {
                pre->next = p->next;
                delete(p);
                
                return;
            }
            
            pre = p;
            p = p->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = findPos(key);
        
        Node *p = data[pos];
        while (p != NULL) {
            if (p->k == key)
                return true;
            
            p = p->next;
        }
        
        return false;
    }
    
    int findPos(int key) {
        return key % maxSize;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */