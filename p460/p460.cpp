class LFUCache {
public:
	int cap = 0;
	map<int, int> mapKeyToValue;
	map<int, int> freq;
	map<int, list<int>> mapFreqToKeys;
	map<int, list::iterator> pos;

    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!mapKeyToValue.count(key))
        	return -1;
        
        int v = mapKeyToValue[key];
        updateFreq(key);

        return v;
    }
    
    void put(int key, int value) {
        if (!mapFreqToKeys.count(key)) {

        	// 先 erase ??
        	if (mapKeyToValue.size() >= cap) {
        		int targetKey = mapFreqToKeys.begin()->front();

        		mapFreqToKeys.begin().pop_front();
        		mapKeyToValue.erase(targetKey);
        		pos.erase(targetKey);
        	}

        	mapKeyToValue[key] = value;

        	mapFreqToKeys[1].push_back(key);
        	pos[key] = mapFreqToKeys[1].end()-1;
        	
        } else {
        	mapKeyToValue[key] = value;
        	updateFreq(key);
        }
    }

    void updateFreq(int key) {
    	int oldFreq = freq[key];
        freq[key]++;

        mapFreqToKeys[oldFreq].erase(pos[key]);
        // if (mapFreqToKeys.count(oldFreq+1)) {
        	mapFreqToKeys[oldFreq+1].push_back(key);
        // }
        pos[key] = mapFreqToKeys[oldFreq+1].end()-1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */