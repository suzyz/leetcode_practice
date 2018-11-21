class KthLargest {
public:
	int K;
	bool isFull = false;
	map<int, int, greater<int>> freq;
    KthLargest(int k, vector<int> nums) {
    	K = k;
    	isFull = nums.size() >= K;

    	int i = 0;
        while (i < nums.size() && i < K) {
        	++freq[nums[i]];
        	++i;
        }
        
        while (i < nums.size()) {
        	add(nums[i]);
        	++i;
        }
    }
    
    int add(int val) {

    	if (!isFull) {
    		isFull = true;
    		++freq[val];
    		return freq.rbegin()->first;
    	}

		int cur = freq.rbegin()->first;

        if (val <= cur)
        	return cur;
        
        ++freq[val];
        if (freq[cur] == 1)
        	freq.erase(cur);
        else
        	--freq[cur];

        return freq.rbegin()->first;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */