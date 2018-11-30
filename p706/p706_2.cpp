// Use linked list to solve collision..
class MyHashMap {
public:

    struct Node
    {
        int k, v;
        Node *next;

        Node(int key, int value) { k = key; v = value; next = NULL; }
    };

    const int maxSize = 10000;
    vector<Node*> data;

    /** Initialize your data structure here. */
    MyHashMap() {
        data = vector<Node*>(maxSize);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = findPos(key);

        if (data[pos] == NULL)
            data[pos] = new Node(key, value);
        else {
            Node *p = data[pos];

            while (p != NULL && p->next != NULL && p->k != key)
                p = p->next;

            if (p->k == key)
                p->v = value;
            else
                p->next = new Node(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = findPos(key);
        
        Node *p = data[pos];
        while (p != NULL) {
            if (p->k == key)
                return p->v;
            p = p->next;
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = findPos(key);
        if (data[pos] == NULL)
            return;

        Node *p = data[pos];
        if (p->k == key)
            data[pos] = p->next;
        else {
            while (p != NULL && p->next != NULL && p->next->k != key)
                p = p->next;

            if (p->next == NULL)
                return;

            Node *tmp = p->next;
            p->next = tmp->next;
            delete(tmp);
        } 
    }

    int findPos(int key) {
        return key % maxSize;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */