class Solution {
public:
	long long n, len, ans, mind;
	vector<int> digits;

    string nearestPalindromic(string s) {
        n = 0;
        len = s.length();

        digits = vector<int>(len);

        ans = 1;
        long long smaller = 9;
        for (int i = 0; i < len; ++i) {
        	digits[i] = s[i]-'0';
        	n = n * 10 + digits[i];
        	ans *= 10;
            
            if (i > 1)
                smaller = smaller * 10 + 9;
        }

        if (n < 11)
        	return to_string(n-1);
        
        ++ans;
        mind = ans - n;
        
        if (check(smaller))
            update(smaller);
 
 		vector<int> plan((len+1)/2);
        dfs(0, 0, plan);

        return to_string(ans);
    }

    void update(long long cur) {
        if (cur == n)
            return;
        
    	if (abs(cur-n) < mind) {
    		mind = abs(cur-n);
    		ans = cur;
    	} else if (abs(cur-n) == mind && cur < ans)
                ans = cur;
    }
    
    bool check(long long cur) {
        vector<int> d;
        while (cur > 0) {
            d.push_back(cur%10);
            cur/=10;
        }
        
        int i = 0, j = d.size()-1;
        while (i < j) {
            if (d[i] != d[j])
                return false;
            ++i;
            --j;
        }
        
        return true;
    }

    void dfs(int idx, long long cur, vector<int>& plan) {
    	if (idx == plan.size()) {
    		
    		int maxi = plan.size()-1;
    		if (len&1)
    			--maxi;

    		long long tmp = cur;
    		for (int i = maxi; i >= 0; --i)
    			tmp = tmp * 10 + plan[i];

    		update(tmp);
    		return;
    	}

	    for (int i = -1; i <= 1 ; ++i) {
	    	int v = digits[idx] + i;
	    	if (idx == 0 && v == 0)
	    		continue;
	    	if (v >= 0 && v <= 9) {
	    		plan[idx] = v;
	    		dfs(idx+1, cur * 10 + v, plan);
	    	}
	    }
    }
};