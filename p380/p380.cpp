class RandomizedSet {
public:
    int n;
    vector<int> l;
    unordered_map<int,int> pos;
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pos.count(val))
            return false;
        ++n;
        l.push_back(val);
        pos[val] = l.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (pos.count(val) == 0)
            return false;

        l[pos[val]] = l[n-1];
        pos[l[n-1]] = pos[val];
        l.pop_back();
        pos.erase(val);

        --n;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return l[rand()%pos.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
