// using STL's list container.

class LRUCache {
public:
	int cap = 0;
	list<pair<int,int>> l;
	unordered_map<int,list<pair<int,int>>::iterator> pos;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!pos.count(key))
        	return -1;
        else
        {
        	int v = pos[key]->second;
        	put(key,v);
        	return v;
        }
    }
    
    void put(int key, int value) {
        if (pos.count(key))
        	l.erase(pos[key]);
        else
	        if (l.size() == cap)
	        {
	        	int last = l.back().first;
	        	l.pop_back();
	        	pos.erase(last);
	        }

        l.insert(l.begin(),make_pair(key,value));
        pos[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
