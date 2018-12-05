// Binary search + Verify the number.
// Too much trouble.

class Solution {
public:
	vector<int> p;

    int findKthNumber(int m, int n, int k) {
        if (k == 1)
        	return 1;
        if (k == m * n)
        	return k;

        if (m > n)
        	swap(m, n);

        p.push_back(2);
        int lim = floor(sqrt(n));
        vector<bool> isPrime(n+1, true);
        for (int i = 3; i <= lim; ++i)
        	if (isPrime[i]) {
        		p.push_back(i);

        		for (int j = i*3; j <= n; j += 2*i)
        			isPrime[j] = false;
        	}
        
        for (int i = lim+1; i <= n; ++i)
            if (isPrime[i])
                p.push_back(i);

        int lo = 1, hi = m*n;
        while (lo < hi) {
        	int mid = lo + ((hi-lo)>>1);

        	int a = countLessEqual(mid, m, n);
            // printf("%d %d\n", mid, a);
        	if (a == k) {
                if (isLegal(mid, n))
        		    return mid;
                else
                    hi = mid-1;
            } else {
                if (a > k)
                    hi = mid;
                else
                    lo = mid+1;
            }
        }
        
        return lo;
    }

    int countLessEqual(int t, int m, int n) {
    	int res = 0;
    	for (int i = 1; i <= m && i <= t; ++i)
            res += min(t/i, n);
        
    	return res;
    }

    bool isLegal(int cur, int n) {
        if (cur <= n)
            return true;
        
        // printf("cur:%d\n", cur);
    	for (int i = 0; i < p.size() && p[i] <= cur; ++i)
    		if (cur % p[i] == 0) {
                // printf("p:%d\n",p[i]);
                if (p[i]*p[i] > n && cur % (p[i] * p[i]) == 0)
                    return false;
                
    			while (cur % p[i] == 0)
    				cur /= p[i];
    		}

    	// printf("cur:%d\n", cur);
        return cur == 1;
    }
};