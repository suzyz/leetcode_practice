// Binary search.

class Solution {
public:

    int findKthNumber(int m, int n, int k) {
        if (k == 1)
        	return 1;
        if (k == m * n)
        	return k;

        if (m > n)
        	swap(m, n);

        int lo = 1, hi = m*n;
        while (lo < hi) {
        	int mid = lo + ((hi-lo)>>1);

        	int a = countLessEqual(mid, m, n);
            if (a >= k)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return lo;
    }

    int countLessEqual(int t, int m, int n) {
    	int res = 0;
    	for (int i = 1; i <= m && i <= t; ++i)
            res += min(t/i, n);
        
    	return res;
    }
};