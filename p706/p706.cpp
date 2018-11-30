// Very brutal.
class MyHashMap {
public:
    const int maxSize = 10000;
    vector<pair<int, int>> data;
    /** Initialize your data structure here. */
    MyHashMap() {
        pair<int, int> tmp = make_pair(-1, -1);
        data = vector<pair<int, int>>(maxSize, tmp);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = findPutPos(key);

        data[pos].first = key;
        data[pos].second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = findPos(key);
        
        if (pos != -1)
            return data[pos].second;
        else
            return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = findPos(key);
        if (pos != -1)
            data[pos].first = data[pos].second = -1;
    }

    int findPos(int key) {
        int pos = key % maxSize, count = 0;

        while (data[pos].first != key && count < maxSize) {
            ++count;
            ++pos;
            if (pos == maxSize)
                pos = 0;
        }
        
        if (count == maxSize)
            return -1;
        else
            return pos;
    }
    
    int findPutPos(int key) {
        bool isFirstEmpty = true;
        int pos = key % maxSize, count = 0, backup = -1;

        while (data[pos].first != key && count < maxSize) {
            if (isFirstEmpty && data[pos].first == -1) {
                isFirstEmpty = false;
                backup = pos;
            }
            ++count;
            ++pos;
            if (pos == maxSize)
                pos = 0;
        }
        
        if (count == maxSize)
            return backup;
        else
            return pos;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */