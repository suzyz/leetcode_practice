class Solution {
public:
	int n;
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        if (n < 2)
        	return false;

        vector<int> nxt(n);

        for (int i = 0; i < n; ++i)
        	nxt[i] = getNext(i, nums);

        for (int i = 0; i < n; ++i)
        	if (nxt[i] != i) {
        		bool ok = true, pos;
        		int slow = i, fast = nxt[i];
                
        		while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[nxt[slow]] > 0) {
        			
        			if (slow == fast) {
                        if (nxt[fast] == fast)
        				    break;
                        
                        return true;
                    }

        			slow = nxt[slow];
        			fast = nxt[nxt[fast]];
        		}
        	}
        

        return false;
    }

    int getNext(int p, vector<int>& nums) {
    	int nxt = (p + nums[p]) % n;
    	while (nxt < 0)
    		nxt += n;

    	return nxt;
    }
};